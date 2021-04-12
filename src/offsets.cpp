#pragma once

#include "offsets.h"


RelocPtr<float> g_havokWorldScale(0x15B78F4);
RelocPtr<float> g_inverseHavokWorldScale(0x15ADFE8);

// Alternatively, 0x30008E0 + 0x78
// Even better, (*0x2FC60C0) + 0x78
RelocPtr<bhkSimpleShapePhantom *> g_pickSphere(0x3000958);

RelocPtr<CrosshairPickData *> g_pickData(0x2FC60C0);

RelocPtr<float> g_deltaTime(0x1EC8278);

RelocPtr<float> g_globalTimeMultiplier(0xC42710);

RelocPtr<float> fMaxTime(0x1EC82B0);
RelocPtr<float> fMaxTimeComplex(0x1EC8448);

RelocPtr<float> g_secondsSinceLastFrame_WorldTime_CheckPaused(0x2FEB794); // like the one below, but is 0 if in menu mode (paused)
RelocPtr<float> g_secondsSinceLastFrame_WorldTime(0x30C3A08); // is multiplied by timeMultiplier
RelocPtr<float> g_secondsSinceLastFrame_Unmultiplied(0x30C3A0C); // is not multiplied by timeMultiplier
RelocPtr<int> g_sceneComplexCounter(0x2FEB76C);

RelocPtr<ProcessLists *> g_processLists(0x1F831B0);

RelocPtr<BSAudioManager *> g_audioManager(0x30C1D30);

RelocPtr<ShadowSceneNode *> g_shadowSceneNode(0x3423080);

RelocPtr<float> g_minSoundVel(0x1E94F78); // it's an ini setting


RelocAddr<_CreateDetectionEvent> CreateDetectionEvent(0x656140);

RelocAddr<_ShadowSceneNode_UpdateNodeList> ShadowSceneNode_UpdateNodeList(0x12F89E0);

RelocAddr<_IsInMenuMode> IsInMenuMode(0x009F32A0);

RelocAddr<_ObjectReference_SetActorCause> ObjectReference_SetActorCause(0x9D1830);

RelocAddr<_ObjectReference_Activate> ObjectReference_Activate(0x009CD750);

RelocAddr<_TESObjectREFR_Activate> TESObjectREFR_Activate(0x2A8300);

RelocAddr<_TESObjectREFR_SetScale> TESObjectREFR_SetScale(0x29E3E0);

RelocAddr<_EffectShader_Play> EffectShader_Play(0x9BCAF0);

RelocAddr<_EffectShader_Stop> EffectShader_Stop(0x9BCC20);

RelocAddr<_VisualEffect_Play> VisualEffect_Play(0x9A4E00);

RelocAddr<_VisualEffect_Stop> VisualEffect_Stop(0x9A4F80);

RelocAddr<_Sound_Play> Sound_Play(0x9EF150);

RelocAddr<_BSExtraDataList_RemoveOwnership> BSExtraDataList_RemoveOwnership(0x1309A0);

RelocAddr<_BSExtraDataList_SetOwnerForm> BSExtraDataList_SetOwnerForm(0x11E0C0);

RelocAddr<_TESObjectREFR_SetActorOwner> TESObjectREFR_SetActorOwner(0x9D18C0);

RelocAddr<_hkpWorld_getCurrentTime> hkpWorld_getCurrentTime(0xAB74F0);

RelocAddr<_hkpWorld_CastRay> hkpWorld_CastRay(0x00AB5B20);

RelocAddr<_hkpWorld_LinearCast> hkpWorld_LinearCast(0x00AB5EC0);

RelocAddr<_hkpWorld_GetPenetrations> hkpWorld_GetPenetrations(0x00AB6AA0);

RelocAddr<_hkpWorld_GetClosestPoints> hkpWorld_GetClosestPoints(0xAB62D0);

RelocAddr<_hkpWorld_AddEntity> hkpWorld_AddEntity(0xAB0CB0);

RelocAddr<_hkpWorld_RemoveEntity> hkpWorld_RemoveEntity(0xAB0E50);

RelocAddr<_hkpWorld_addContactListener> hkpWorld_addContactListener(0xAB5580);

RelocAddr<_hkpWorld_removeContactListener> hkpWorld_removeContactListener(0xC9F180);

RelocAddr<_bhkWorld_addContactListener> bhkWorld_addContactListener(0xDA5C50);

RelocAddr<_hkpWorld_UpdateCollisionFilterOnEntity> hkpWorld_UpdateCollisionFilterOnEntity(0xAB3110);

RelocAddr<_bhkWorld_UpdateCollisionFilterOnEntity> bhkWorld_UpdateCollisionFilterOnEntity(0xDFFE50);

RelocAddr<_ContactListener_PreprocessContactPointEvent> ContactListener_PreprocessContactPointEvent(0xE41AB0); // Checks some shape key stuff and sets disabled on the contact point properties if it wants to

RelocAddr<_hkpSimpleContactConstraintUtil_calculateSeparatingVelocity> hkpSimpleContactConstraintUtil_calculateSeparatingVelocity(0xAAF250);

RelocAddr<_hkpEntity_activate> hkpEntity_activate(0xAA7130);

RelocAddr<_bhkRigidBody_setActivated> bhkRigidBody_setActivated(0xE085D0);

RelocAddr<_hkpEntity_setPositionAndRotation> hkpEntity_setPositionAndRotation(0xAA9030);

RelocAddr<_hkpEntity_setTransform> hkpEntity_setTransform(0xAA9060);

RelocAddr<_hkpEntity_getNumConstraints> hkpEntity_getNumConstraints(0xAA73B0);

RelocAddr<_hkpEntity_addContactListener> hkpEntity_addContactListener(0xAA6FE0);

RelocAddr<_hkpEntity_removeContactListener> hkpEntity_removeContactListener(0xAA7080);

RelocAddr<_hkpRigidBody_ctor> hkpRigidBody_ctor(0xAA89C0);

RelocAddr<_hkpRigidBodyCinfo_ctor> hkpRigidBodyCinfo_ctor(0xAC5FE0); // just sets all the fields to defaults

RelocAddr<_hkpBoxShape_ctor> hkpBoxShape_ctor(0xA93600);

RelocAddr<_hkpTriggerVolume_ctor> hkpTriggerVolume_ctor(0xAFFCE0);

RelocAddr<_hkpKeyFrameUtility_applyHardKeyFrame> hkpKeyFrameUtility_applyHardKeyFrame(0xAF6DD0);
RelocAddr<_hkpKeyFrameUtility_applyHardKeyFrame> hkpKeyFrameUtility_applyHardKeyFrameAsynchronously(0xAF7100);

RelocAddr<_hkpKeyFrameUtility_applySoftKeyFrame> hkpKeyFrameUtility_applySoftKeyFrame(0xAF6AF0);

RelocAddr<_hkpConstraintInstance_setPriority> hkpConstraintInstance_setPriority(0xAC05B0);

RelocAddr<_hkpMotion_approxTransformAt> hkpMotion_approxTransformAt(0xAAB6E0);

RelocAddr<_bhkCollisionFilter_CompareFilterInfos> bhkCollisionFilter_CompareFilterInfos(0xDD6A80);

RelocAddr<_hkpRigidBody_setMotionType> hkpRigidBody_setMotionType(0xAA9530);

RelocAddr<_bhkRigidBody_setMotionType> bhkRigidBody_setMotionType(0xE08040);

RelocAddr<_bhkRigidBody_MoveToPositionAndRotation> bhkRigidBody_MoveToPositionAndRotation(0xE09210);

RelocAddr<_bhkCollisionObject_SetNodeTransformsFromWorldTransform> bhkCollisionObject_SetNodeTransformsFromWorldTransform(0xE1ACB0);

RelocAddr<_bhkEntity_setPositionAndRotation> bhkEntity_setPositionAndRotation(0xE08350);

RelocAddr<_FindCollidableRef> FindCollidableRef(0x003B4940);

RelocAddr<_FindCollidableNode> FindCollidableNode(0xE01FE0);

RelocAddr<_GetWorld> GetWorld(0x276A90);

RelocAddr<_ActivatePickRef> ActivatePickRef(0x6CBCE0);

RelocAddr<_TESObjectREFR_GetMass> TESObjectREFR_GetMass(0x9CED20);

RelocAddr<_NiAVObject_GetMass> NiAVObject_GetMass(0x3B5B50);

RelocAddr<_StartGrabObject> StartGrabObject(0x006CC000);

RelocAddr<_AddRemoveConstraintFunctor> AddRemoveConstraintFunctor(0x9AB270);

RelocAddr<_AddHavokBallAndSocketConstraint> AddHavokBallAndSocketConstraint(0x9ABAB0);

RelocAddr<_RemoveHavokConstraints> RemoveHavokConstraints(0x9ABD40);

RelocAddr<_TESObjectREFR_SetPosition> TESObjectREFR_SetPosition(0x2A8010);

RelocAddr<_TESObjectREFR_SetRotation> TESObjectREFR_SetRotation(0x2A7C50);

RelocAddr<_NiAVObject_UpdateObjectUpwards> NiAVObject_UpdateObjectUpwards(0xC9BC10);

RelocAddr<_hkReferencedObject_addReference> hkReferencedObject_addReference(0xA01280);

RelocAddr<_hkReferencedObject_removeReference> hkReferencedObject_removeReference(0xA01340);

RelocAddr<_GetMaterialType> GetMaterialType(0x2D8B60);

RelocAddr<_BGSImpactDataSet_GetImpactData> BGSImpactDataSet_GetImpactData(0x2D4C00);

RelocAddr<_BSAudioManager_InitSoundData> BSAudioManager_InitSoundData(0xC29D20);

RelocAddr<_SoundData_SetPosition> SoundData_SetPosition(0xC287D0);

RelocAddr<_SoundData_SetNode> SoundData_SetNode(0xC289C0);

RelocAddr<_SoundData_Play> SoundData_Play(0xC283E0);

RelocAddr<_BSExtraList_GetCount> BSExtraList_GetCount(0x123D90);

RelocAddr<_EquipManager_EquipEntryData> EquipManager_EquipEntryData(0x641720);

RelocAddr<_TESObjectBOOK_LearnSpell> TESObjectBOOK_LearnSpell(0x23B240);

RelocAddr<_NiMatrixToNiQuaternion> NiMatrixToNiQuaternion(0xCB4460);

RelocAddr<_MatrixFromForwardVector> MatrixFromForwardVector(0xC4C1E0);

//bhkWorld_Update(0xDFB460);

//BipedAnim_RemoveAllParts(0x1D6530);

// 1st arg: ptr to BipedAnim. 2nd arg: ptr to NiNode
//CreateArmorNode(0x1DB680);


struct BGSImpactManager
{
	void *vtbl; // 00
	BSTEventSink<void> combatImpactEventSink; // 08 - BSTEventSink<BGSCombatImpactEvent>
	BSTEventSink<void> collisionSoundEventSink; // 10 - BSTEventSink<BGSCollisionSoundEvent>
	// sound event passes in ptr to skyrimhavokmaterial id in rdx (actually it's the 2 material ids, then at 0x14 (I think?) is the magnitude of the impact or something - it's used to determine which sound to play, high or low)
};
RelocPtr<BGSImpactManager> g_impactManager(0x2FEBD60);
