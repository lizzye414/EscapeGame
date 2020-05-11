// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EscapeGame/InventorySlotWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySlotWidget() {}
// Cross Module References
	ESCAPEGAME_API UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister();
	ESCAPEGAME_API UClass* Z_Construct_UClass_UInventorySlotWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_EscapeGame();
	ESCAPEGAME_API UFunction* Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem();
	ESCAPEGAME_API UFunction* Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture();
	ESCAPEGAME_API UClass* Z_Construct_UClass_APickup2_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	void UInventorySlotWidget::StaticRegisterNativesUInventorySlotWidget()
	{
		UClass* Class = UInventorySlotWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetEquippedItem", &UInventorySlotWidget::execSetEquippedItem },
			{ "SetItemTexture", &UInventorySlotWidget::execSetItemTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "UI" },
		{ "Comment", "/*Tells the player the equip the represented item from this widget*/" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
		{ "ToolTip", "Tells the player the equip the represented item from this widget" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidget, nullptr, "SetEquippedItem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics
	{
		struct InventorySlotWidget_eventSetItemTexture_Parms
		{
			APickup2* Item;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventorySlotWidget_eventSetItemTexture_Parms, Item), Z_Construct_UClass_APickup2_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::NewProp_Item,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "UI" },
		{ "Comment", "/*Sets the item texture*/" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
		{ "ToolTip", "Sets the item texture" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidget, nullptr, "SetItemTexture", nullptr, nullptr, sizeof(InventorySlotWidget_eventSetItemTexture_Parms), Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventorySlotWidget_NoRegister()
	{
		return UInventorySlotWidget::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySlotWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemTexture;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySlotWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_EscapeGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventorySlotWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventorySlotWidget_SetEquippedItem, "SetEquippedItem" }, // 676555717
		{ &Z_Construct_UFunction_UInventorySlotWidget_SetItemTexture, "SetItemTexture" }, // 3296599291
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InventorySlotWidget.h" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemTexture_MetaData[] = {
		{ "Category", "InventorySlotWidget" },
		{ "Comment", "/*Holds a reference to the item texture*/" },
		{ "ModuleRelativePath", "InventorySlotWidget.h" },
		{ "ToolTip", "Holds a reference to the item texture" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemTexture = { "ItemTexture", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySlotWidget, ItemTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemTexture_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidget_Statics::NewProp_ItemTexture,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySlotWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams = {
		&UInventorySlotWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventorySlotWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventorySlotWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventorySlotWidget, 1528359604);
	template<> ESCAPEGAME_API UClass* StaticClass<UInventorySlotWidget>()
	{
		return UInventorySlotWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventorySlotWidget(Z_Construct_UClass_UInventorySlotWidget, &UInventorySlotWidget::StaticClass, TEXT("/Script/EscapeGame"), TEXT("UInventorySlotWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySlotWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
