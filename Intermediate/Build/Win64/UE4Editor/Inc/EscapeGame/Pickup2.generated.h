// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
#ifdef ESCAPEGAME_Pickup2_generated_h
#error "Pickup2.generated.h already included, missing '#pragma once' in Pickup2.h"
#endif
#define ESCAPEGAME_Pickup2_generated_h

#define EscapeGame_Source_EscapeGame_Pickup2_h_13_SPARSE_DATA
#define EscapeGame_Source_EscapeGame_Pickup2_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetItemName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetItemName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPickupTexture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=P_THIS->GetPickupTexture(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetItemName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetItemName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPickupTexture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=P_THIS->GetPickupTexture(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickup2(); \
	friend struct Z_Construct_UClass_APickup2_Statics; \
public: \
	DECLARE_CLASS(APickup2, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(APickup2)


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAPickup2(); \
	friend struct Z_Construct_UClass_APickup2_Statics; \
public: \
	DECLARE_CLASS(APickup2, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(APickup2)


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup2(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup2) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup2); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup2); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup2(APickup2&&); \
	NO_API APickup2(const APickup2&); \
public:


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup2(APickup2&&); \
	NO_API APickup2(const APickup2&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup2); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup2); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup2)


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PickupSM() { return STRUCT_OFFSET(APickup2, PickupSM); } \
	FORCEINLINE static uint32 __PPO__PickupTexture() { return STRUCT_OFFSET(APickup2, PickupTexture); } \
	FORCEINLINE static uint32 __PPO__ItemName() { return STRUCT_OFFSET(APickup2, ItemName); }


#define EscapeGame_Source_EscapeGame_Pickup2_h_10_PROLOG
#define EscapeGame_Source_EscapeGame_Pickup2_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_RPC_WRAPPERS \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_INCLASS \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeGame_Source_EscapeGame_Pickup2_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_INCLASS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_Pickup2_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEGAME_API UClass* StaticClass<class APickup2>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeGame_Source_EscapeGame_Pickup2_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
