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

#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_RPC_WRAPPERS
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_RPC_WRAPPERS_NO_PURE_DECLS
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAScareEventManager(); \
	friend struct Z_Construct_UClass_AScareEventManager_Statics; \
public: \
	DECLARE_CLASS(AScareEventManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_INCLASS \
private: \
	static void StaticRegisterNativesAScareEventManager(); \
	friend struct Z_Construct_UClass_AScareEventManager_Statics; \
public: \
	DECLARE_CLASS(AScareEventManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_STANDARD_CONSTRUCTORS \
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


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AScareEventManager(AScareEventManager&&); \
	NO_API AScareEventManager(const AScareEventManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AScareEventManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AScareEventManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AScareEventManager)


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_PRIVATE_PROPERTY_OFFSET
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_22_PROLOG
#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_INCLASS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_ScareEventManager_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class AScareEventManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_ScareEventManager_h


#define FOREACH_ENUM_SCARETYPE(op) \
	op(Whisper) \
	op(Wind) \
	op(Footsteps) \
	op(SingingNoises) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
