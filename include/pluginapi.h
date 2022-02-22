#pragma once

#include <atomic>
#include <mutex>
#include <vector>

#include "skse64/PluginAPI.h"
#include "skse64/GameReferences.h"

#include "higgsinterface001.h"


namespace HiggsPluginAPI {
	// Handles skse mod messages requesting to fetch API functions from HIGGS
	void ModMessageHandler(SKSEMessagingInterface::Message * message);

	// This object provides access to HIGGS's mod support API version 1
	struct HiggsInterface001 : IHiggsInterface001
	{
		virtual unsigned int GetBuildNumber();

		virtual void AddPulledCallback(PulledCallback Callback);
		virtual void AddGrabbedCallback(GrabbedCallback callback);
		virtual void AddDroppedCallback(DroppedCallback callback);
		virtual void AddStashedCallback(StashedCallback callback);
		virtual void AddConsumedCallback(ConsumedCallback callback);
		virtual void AddCollisionCallback(CollisionCallback callback);
		virtual void AddStartTwoHandingCallback(StartTwoHandingCallback callback);
		virtual void AddStopTwoHandingCallback(StopTwoHandingCallback callback);
		virtual void AddCollisionFilterComparisonCallback(CollisionFilterComparisonCallback callback);

		virtual UInt64 GetHiggsLayerBitfield();
		virtual void SetHiggsLayerBitfield(UInt64 bitfield);

		virtual NiObject * GetHandRigidBody(bool isLeft);
		virtual NiObject * GetWeaponRigidBody(bool isLeft);

		virtual NiObject * GetGrabbedRigidBody(bool isLeft);

		virtual void GrabObject(TESObjectREFR *object, bool isLeft);
		virtual TESObjectREFR * GetGrabbedObject(bool isLeft);
		virtual bool IsHandInGrabbableState(bool isLeft);

		virtual void DisableHand(bool isLeft);
		virtual void EnableHand(bool isLeft);
		virtual bool IsDisabled(bool isLeft);

		virtual void DisableWeaponCollision(bool isLeft);
		virtual void EnableWeaponCollision(bool isLeft);
		virtual bool IsWeaponCollisionDisabled(bool isLeft);

		virtual void ForceWeaponCollisionEnabled(bool isLeft);

		virtual bool IsTwoHanding();

		virtual bool CanGrabObject(bool isLeft);


		std::mutex addCallbackLock;
		std::vector<PulledCallback> pulledCallbacks;
		std::vector<GrabbedCallback> grabbedCallbacks;
		std::vector<DroppedCallback> droppedCallbacks;
		std::vector<StashedCallback> stashedCallbacks;
		std::vector<ConsumedCallback> consumedCallbacks;
		std::vector<CollisionCallback> collisionCallbacks;
		std::vector<StartTwoHandingCallback> startTwoHandingCallbacks;
		std::vector<StopTwoHandingCallback> stopTwoHandingCallbacks;
		std::vector<CollisionFilterComparisonCallback> collisionFilterComparisonCallbacks;

		std::atomic<int> rightDisableCount = 0;
		std::atomic<int> leftDisableCount = 0;

		std::atomic<int> rightWeaponDisableCount = 0;
		std::atomic<int> leftWeaponDisableCount = 0;

		// Same as L_WEAPON layer, but + self-collision (layer 56) and - charcontroller collision
		UInt64 higgsLayerBitfield = 0x01053343161b7fff;

		bool forceEnableWeaponCollision[2]{ false, false };
	};

	void TriggerPulledCallbacks(bool isLeft, TESObjectREFR *pulledRefr);
	void TriggerGrabbedCallbacks(bool isLeft, TESObjectREFR *grabbedRefr);
	void TriggerDroppedCallbacks(bool isLeft, TESObjectREFR *droppedRefr);
	void TriggerStashedCallbacks(bool isLeft, TESForm *stashedForm);
	void TriggerConsumedCallbacks(bool isLeft, TESForm *consumedForm);
	void TriggerCollisionCallbacks(bool isLeft, float mass, float separatingVelocity);
	void TriggerStartTwoHandingCallbacks();
	void TriggerStopTwoHandingCallbacks();

	using CollisionFilterComparisonResult = HiggsInterface001::CollisionFilterComparisonResult;
	CollisionFilterComparisonResult TriggerCollisionFilterComparisonCallbacks(void *filter, UInt32 filterInfoA, UInt32 filterInfoB);
}

extern HiggsPluginAPI::HiggsInterface001 g_interface001;
