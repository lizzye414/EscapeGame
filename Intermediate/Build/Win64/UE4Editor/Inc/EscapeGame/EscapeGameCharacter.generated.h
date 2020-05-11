// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPEGAME_EscapeGameCharacter_generated_h
#error "EscapeGameCharacter.generated.h already included, missing '#pragma once' in EscapeGameCharacter.h"
#endif
#define ESCAPEGAME_EscapeGameCharacter_generated_h

#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_SPARSE_DATA
#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHandleInventoryInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInventoryInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPickupItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PickupItem(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleInventoryInput) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInventoryInput(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPickupItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PickupItem(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEscapeGameCharacter(); \
	friend struct Z_Construct_UClass_AEscapeGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AEscapeGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameCharacter)


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAEscapeGameCharacter(); \
	friend struct Z_Construct_UClass_AEscapeGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AEscapeGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameCharacter)


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEscapeGameCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEscapeGameCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameCharacter(AEscapeGameCharacter&&); \
	NO_API AEscapeGameCharacter(const AEscapeGameCharacter&); \
public:


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameCharacter(AEscapeGameCharacter&&); \
	NO_API AEscapeGameCharacter(const AEscapeGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEscapeGameCharacter)


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AEscapeGameCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AEscapeGameCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AEscapeGameCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AEscapeGameCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AEscapeGameCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AEscapeGameCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AEscapeGameCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AEscapeGameCharacter, L_MotionController); } \
	FORCEINLINE static uint32 __PPO__RaycastRange() { return STRUCT_OFFSET(AEscapeGameCharacter, RaycastRange); } \
	FORCEINLINE static uint32 __PPO__Inventory() { return STRUCT_OFFSET(AEscapeGameCharacter, Inventory); } \
	FORCEINLINE static uint32 __PPO__PickupBPRef() { return STRUCT_OFFSET(AEscapeGameCharacter, PickupBPRef); }


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_14_PROLOG
#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_RPC_WRAPPERS \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_INCLASS \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_INCLASS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_EscapeGameCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEGAME_API UClass* StaticClass<class AEscapeGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeGame_Source_EscapeGame_EscapeGameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
