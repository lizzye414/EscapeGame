// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef ESCAPEGAME_EscapeGameProjectile_generated_h
#error "EscapeGameProjectile.generated.h already included, missing '#pragma once' in EscapeGameProjectile.h"
#endif
#define ESCAPEGAME_EscapeGameProjectile_generated_h

#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_SPARSE_DATA
#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEscapeGameProjectile(); \
	friend struct Z_Construct_UClass_AEscapeGameProjectile_Statics; \
public: \
	DECLARE_CLASS(AEscapeGameProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAEscapeGameProjectile(); \
	friend struct Z_Construct_UClass_AEscapeGameProjectile_Statics; \
public: \
	DECLARE_CLASS(AEscapeGameProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeGame"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEscapeGameProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEscapeGameProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameProjectile(AEscapeGameProjectile&&); \
	NO_API AEscapeGameProjectile(const AEscapeGameProjectile&); \
public:


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameProjectile(AEscapeGameProjectile&&); \
	NO_API AEscapeGameProjectile(const AEscapeGameProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEscapeGameProjectile)


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AEscapeGameProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AEscapeGameProjectile, ProjectileMovement); }


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_9_PROLOG
#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_RPC_WRAPPERS \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_INCLASS \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_SPARSE_DATA \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_INCLASS_NO_PURE_DECLS \
	EscapeGame_Source_EscapeGame_EscapeGameProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEGAME_API UClass* StaticClass<class AEscapeGameProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeGame_Source_EscapeGame_EscapeGameProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
