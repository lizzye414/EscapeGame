// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APickup2;
#ifdef ESCAPEGAME_InventorySlotWidget_generated_h
#error "InventorySlotWidget.generated.h already included, missing '#pragma once' in InventorySlotWidget.h"
#endif
#define ESCAPEGAME_InventorySlotWidget_generated_h

#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_SPARSE_DATA
#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetItemTexture) \
	{ \
		P_GET_OBJECT(APickup2,Z_Param_Item); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetItemTexture(Z_Param_Item); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEquippedItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEquippedItem(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetItemTexture) \
	{ \
		P_GET_OBJECT(APickup2,Z_Param_Item); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetItemTexture(Z_Param_Item); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetEquippedItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetEquippedItem(); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventorySlotWidget(); \
	friend struct Z_Construct_UClass_UInventorySlotWidget_Statics; \
public: \
	DECLARE_CLASS(UInventorySlotWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(UInventorySlotWidget)


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUInventorySlotWidget(); \
	friend struct Z_Construct_UClass_UInventorySlotWidget_Statics; \
public: \
	DECLARE_CLASS(UInventorySlotWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(UInventorySlotWidget)


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventorySlotWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySlotWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySlotWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySlotWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventorySlotWidget(UInventorySlotWidget&&); \
	NO_API UInventorySlotWidget(const UInventorySlotWidget&); \
public:


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventorySlotWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventorySlotWidget(UInventorySlotWidget&&); \
	NO_API UInventorySlotWidget(const UInventorySlotWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySlotWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySlotWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySlotWidget)


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ItemTexture() { return STRUCT_OFFSET(UInventorySlotWidget, ItemTexture); }


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_13_PROLOG
#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_RPC_WRAPPERS \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_INCLASS \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_INCLASS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_InventorySlotWidget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEGAME_API UClass* StaticClass<class UInventorySlotWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeGame_Source_EscapeGame_InventorySlotWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
