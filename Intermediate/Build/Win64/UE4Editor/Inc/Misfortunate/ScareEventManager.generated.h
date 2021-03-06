// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MISFORTUNATE_ScareEventManager_generated_h
#error "ScareEventManager.generated.h already included, missing '#pragma once' in ScareEventManager.h"
#endif
#define MISFORTUNATE_ScareEventManager_generated_h

#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_73_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FScareAudio_Statics; \
	MISFORTUNATE_API static class UScriptStruct* StaticStruct();


template<> MISFORTUNATE_API UScriptStruct* StaticStruct<struct FScareAudio>();

#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FScareSettings_Statics; \
	MISFORTUNATE_API static class UScriptStruct* StaticStruct();


template<> MISFORTUNATE_API UScriptStruct* StaticStruct<struct FScareSettings>();

#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_RPC_WRAPPERS
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_RPC_WRAPPERS_NO_PURE_DECLS
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAScareEventManager(); \
	friend struct Z_Construct_UClass_AScareEventManager_Statics; \
public: \
	DECLARE_CLASS(AScareEventManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_INCLASS \
private: \
	static void StaticRegisterNativesAScareEventManager(); \
	friend struct Z_Construct_UClass_AScareEventManager_Statics; \
public: \
	DECLARE_CLASS(AScareEventManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AScareEventManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AScareEventManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AScareEventManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AScareEventManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AScareEventManager(AScareEventManager&&); \
	NO_API AScareEventManager(const AScareEventManager&); \
public:


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AScareEventManager(AScareEventManager&&); \
	NO_API AScareEventManager(const AScareEventManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AScareEventManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AScareEventManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CheckForScareTriggerDelay() { return STRUCT_OFFSET(AScareEventManager, CheckForScareTriggerDelay); } \
	FORCEINLINE static uint32 __PPO__ScareDistanceThreshold() { return STRUCT_OFFSET(AScareEventManager, ScareDistanceThreshold); }


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_81_PROLOG
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_INCLASS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_84_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class AScareEventManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_ScareEventManager_h


#define FOREACH_ENUM_SCARELOCATIONTYPE(op) \
	op(Positional) \
	op(NonPositional) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
