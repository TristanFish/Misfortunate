// Copyright Epic Games, Inc. All Rights Reserved.
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
#ifdef MISFORTUNATE_MisfortunateProjectile_generated_h
#error "MisfortunateProjectile.generated.h already included, missing '#pragma once' in MisfortunateProjectile.h"
#endif
#define MISFORTUNATE_MisfortunateProjectile_generated_h

#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMisfortunateProjectile(); \
	friend struct Z_Construct_UClass_AMisfortunateProjectile_Statics; \
public: \
	DECLARE_CLASS(AMisfortunateProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AMisfortunateProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMisfortunateProjectile(); \
	friend struct Z_Construct_UClass_AMisfortunateProjectile_Statics; \
public: \
	DECLARE_CLASS(AMisfortunateProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AMisfortunateProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMisfortunateProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMisfortunateProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMisfortunateProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMisfortunateProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMisfortunateProjectile(AMisfortunateProjectile&&); \
	NO_API AMisfortunateProjectile(const AMisfortunateProjectile&); \
public:


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMisfortunateProjectile(AMisfortunateProjectile&&); \
	NO_API AMisfortunateProjectile(const AMisfortunateProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMisfortunateProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMisfortunateProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMisfortunateProjectile)


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AMisfortunateProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AMisfortunateProjectile, ProjectileMovement); }


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_12_PROLOG
#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_INCLASS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class AMisfortunateProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_MisfortunateProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
