// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EscapeGame/Pickup2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickup2() {}
// Cross Module References
	ESCAPEGAME_API UClass* Z_Construct_UClass_APickup2_NoRegister();
	ESCAPEGAME_API UClass* Z_Construct_UClass_APickup2();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_EscapeGame();
	ESCAPEGAME_API UFunction* Z_Construct_UFunction_APickup2_GetItemName();
	ESCAPEGAME_API UFunction* Z_Construct_UFunction_APickup2_GetPickupTexture();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void APickup2::StaticRegisterNativesAPickup2()
	{
		UClass* Class = APickup2::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetItemName", &APickup2::execGetItemName },
			{ "GetPickupTexture", &APickup2::execGetPickupTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APickup2_GetItemName_Statics
	{
		struct Pickup2_eventGetItemName_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APickup2_GetItemName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Pickup2_eventGetItemName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickup2_GetItemName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickup2_GetItemName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APickup2_GetItemName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Pickup2.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APickup2_GetItemName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickup2, nullptr, "GetItemName", nullptr, nullptr, sizeof(Pickup2_eventGetItemName_Parms), Z_Construct_UFunction_APickup2_GetItemName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickup2_GetItemName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APickup2_GetItemName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APickup2_GetItemName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APickup2_GetItemName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APickup2_GetItemName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APickup2_GetPickupTexture_Statics
	{
		struct Pickup2_eventGetPickupTexture_Parms
		{
			UTexture2D* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Pickup2_eventGetPickupTexture_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Returns the Texture of our Pickup*/" },
		{ "ModuleRelativePath", "Pickup2.h" },
		{ "ToolTip", "Returns the Texture of our Pickup" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickup2, nullptr, "GetPickupTexture", nullptr, nullptr, sizeof(Pickup2_eventGetPickupTexture_Parms), Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APickup2_GetPickupTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APickup2_GetPickupTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APickup2_NoRegister()
	{
		return APickup2::StaticClass();
	}
	struct Z_Construct_UClass_APickup2_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ItemName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupSM_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupSM;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickup2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_EscapeGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APickup2_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APickup2_GetItemName, "GetItemName" }, // 1211977760
		{ &Z_Construct_UFunction_APickup2_GetPickupTexture, "GetPickupTexture" }, // 1592971243
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup2_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Pickup2.h" },
		{ "ModuleRelativePath", "Pickup2.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup2_Statics::NewProp_ItemName_MetaData[] = {
		{ "Category", "PickupProperties" },
		{ "Comment", "/*The name of the item*/" },
		{ "ModuleRelativePath", "Pickup2.h" },
		{ "ToolTip", "The name of the item" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_APickup2_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickup2, ItemName), METADATA_PARAMS(Z_Construct_UClass_APickup2_Statics::NewProp_ItemName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup2_Statics::NewProp_ItemName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup2_Statics::NewProp_PickupTexture_MetaData[] = {
		{ "Category", "PickupProperties" },
		{ "Comment", "/*The Texture of the item */" },
		{ "ModuleRelativePath", "Pickup2.h" },
		{ "ToolTip", "The Texture of the item" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APickup2_Statics::NewProp_PickupTexture = { "PickupTexture", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickup2, PickupTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APickup2_Statics::NewProp_PickupTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup2_Statics::NewProp_PickupTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup2_Statics::NewProp_PickupSM_MetaData[] = {
		{ "Category", "Pickup2" },
		{ "Comment", "/*The Static Mesh of the pickup*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Pickup2.h" },
		{ "ToolTip", "The Static Mesh of the pickup" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APickup2_Statics::NewProp_PickupSM = { "PickupSM", nullptr, (EPropertyFlags)0x00200800000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickup2, PickupSM), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APickup2_Statics::NewProp_PickupSM_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup2_Statics::NewProp_PickupSM_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APickup2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup2_Statics::NewProp_ItemName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup2_Statics::NewProp_PickupTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup2_Statics::NewProp_PickupSM,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickup2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickup2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APickup2_Statics::ClassParams = {
		&APickup2::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APickup2_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APickup2_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APickup2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APickup2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickup2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APickup2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickup2, 2876971370);
	template<> ESCAPEGAME_API UClass* StaticClass<APickup2>()
	{
		return APickup2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickup2(Z_Construct_UClass_APickup2, &APickup2::StaticClass, TEXT("/Script/EscapeGame"), TEXT("APickup2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickup2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
