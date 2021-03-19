#include <vector>

#include "pluginapi.h"
#include "version.h"
#include "papyrusapi.h"
#include "grabber.h"

using namespace HiggsPluginAPI;

// A message used to fetch HIGGS's interface
struct HiggsMessage {
	enum { kMessage_GetInterface = 0xF9279A57 }; // Randomly generated
	void * (*getApiFunction)(unsigned int revisionNumber) = nullptr;
};

// Interface classes are stored statically
HiggsInterface001 g_interface001;

// Constructs and returns an API of the revision number requested
void * GetApi(unsigned int revisionNumber) {
	switch (revisionNumber) {
	case 1:	_MESSAGE("Interface revision 1 requested"); return &g_interface001;
	}
	return nullptr;
}

// Handles skse mod messages requesting to fetch API functions from VRIK
void HiggsPluginAPI::ModMessageHandler(SKSEMessagingInterface::Message * message) {
	if (message->type == HiggsMessage::kMessage_GetInterface) {
		HiggsMessage * higgsMessage = (HiggsMessage*)message->data;
		higgsMessage->getApiFunction = GetApi;
		_MESSAGE("Provided HIGGS plugin interface to \"%s\"", message->sender);
	}
}

// HIGGS build numbers are made up as follows: V01.00.05.00
constexpr int higgsBuildNumber = FPVR_VERSION_MAJOR * 1000000 + FPVR_VERSION_MINOR * 10000 + FPVR_VERSION_PATCH * 100 + FPVR_VERSION_BETA;

// Fetches the HIGGS version number
unsigned int HiggsInterface001::GetBuildNumber() {
	return higgsBuildNumber;
}

void HiggsInterface001::AddPulledCallback(PulledCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	pulledCallbacks.push_back(callback);
}

void HiggsInterface001::AddGrabbedCallback(GrabbedCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	grabbedCallbacks.push_back(callback);
}

void HiggsInterface001::AddDroppedCallback(DroppedCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	droppedCallbacks.push_back(callback);
}

void HiggsInterface001::AddStashedCallback(StashedCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	stashedCallbacks.push_back(callback);
}

void HiggsInterface001::AddConsumedCallback(ConsumedCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	consumedCallbacks.push_back(callback);
}

void HiggsInterface001::AddCollisionCallback(CollisionCallback callback) {
	if (!callback) return;
	std::scoped_lock lock(addCallbackLock);
	collisionCallbacks.push_back(callback);
}


void HiggsPluginAPI::TriggerPulledCallbacks(bool isLeft, TESObjectREFR *pulledRefr) {
	for (auto callback : g_interface001.pulledCallbacks) {
		callback(isLeft, pulledRefr);
	}

	PapyrusAPI::OnPullEvent(pulledRefr, isLeft);
}

void HiggsPluginAPI::TriggerGrabbedCallbacks(bool isLeft, TESObjectREFR *grabbedRefr) {
	for (auto callback : g_interface001.grabbedCallbacks) {
		callback(isLeft, grabbedRefr);
	}

	PapyrusAPI::OnGrabEvent(grabbedRefr, isLeft);
}

void HiggsPluginAPI::TriggerDroppedCallbacks(bool isLeft, TESObjectREFR *droppedRefr) {
	for (auto callback : g_interface001.droppedCallbacks) {
		callback(isLeft, droppedRefr);
	}

	PapyrusAPI::OnDropEvent(droppedRefr, isLeft);
}

void HiggsPluginAPI::TriggerStashedCallbacks(bool isLeft, TESForm *stashedForm) {
	for (auto callback : g_interface001.stashedCallbacks) {
		callback(isLeft, stashedForm);
	}

	PapyrusAPI::OnStashEvent(stashedForm, isLeft);
}

void HiggsPluginAPI::TriggerConsumedCallbacks(bool isLeft, TESForm *consumedForm) {
	for (auto callback : g_interface001.consumedCallbacks) {
		callback(isLeft, consumedForm);
	}

	PapyrusAPI::OnConsumeEvent(consumedForm, isLeft);
}

void HiggsPluginAPI::TriggerCollisionCallbacks(bool isLeft, float mass, float separatingVelocity) {
	for (auto callback : g_interface001.collisionCallbacks) {
		callback(isLeft, mass, separatingVelocity);
	}
}

void HiggsInterface001::GrabObject(TESObjectREFR *object, bool isLeft)
{
	Grabber *grabber = isLeft ? g_leftGrabber : g_rightGrabber;

	grabber->externalGrabRequestedObject = object;
	grabber->externalGrabRequested = true;
}

TESObjectREFR * HiggsInterface001::GetGrabbedObject(bool isLeft)
{
	Grabber *grabber = isLeft ? g_leftGrabber : g_rightGrabber;

	if (grabber->HasHeldObject()) {
		UInt32 handle = grabber->selectedObject.handle;
		// To be somewhat thread-safe, check again if we're in held after getting the handle
		if (grabber->HasHeldObject()) {
			NiPointer<TESObjectREFR> grabbedObj;
			if (LookupREFRByHandle(handle, grabbedObj)) {
				return grabbedObj;
			}
		}
	}

	return nullptr;
}

bool HiggsInterface001::CanGrabObject(bool isLeft)
{
	Grabber *grabber = isLeft ? g_leftGrabber : g_rightGrabber;
	return grabber->CanGrabObject();
}

void HiggsInterface001::DisableHand(bool isLeft)
{
	if (isLeft) {
		leftDisableCount++;
	}
	else {
		rightDisableCount++;
	}
}

void HiggsInterface001::EnableHand(bool isLeft)
{
	if (isLeft) {
		leftDisableCount--;
	}
	else {
		rightDisableCount--;
	}
}

bool HiggsInterface001::IsDisabled(bool isLeft)
{
	if (isLeft) {
		return leftDisableCount > 0;
	}
	else {
		return rightDisableCount > 0;
	}
}