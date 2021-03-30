// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef MISFORTUNATE_EventZone_generated_h
#error "EventZone.generated.h already included, missing '#pragma once' in EventZone.h"
#endif
#define MISFORTUNATE_EventZone_generated_h

#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEventZone(); \
	friend struct Z_Construct_UClass_AEventZone_Statics; \
public: \
	DECLARE_CLASS(AEventZone, ATriggerVolume, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AEventZone)


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAEventZone(); \
	friend struct Z_Construct_UClass_AEventZone_Statics; \
public: \
	DECLARE_CLASS(AEventZone, ATriggerVolume, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AEventZone)


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEventZone(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEventZone) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEventZone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEventZone); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEventZone(AEventZone&&); \
	NO_API AEventZone(const AEventZone&); \
public:


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEventZone(AEventZone&&); \
	NO_API AEventZone(const AEventZone&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEventZone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEventZone); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEventZone)


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_PRIVATE_PROPERTY_OFFSET
#define Misfortunate_Source_Misfortunate_Public_EventZone_h_19_PROLOG
#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_INCLASS \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_EventZone_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_EventZone_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class AEventZone>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_EventZone_h


#define FOREACH_ENUM_EVENTZONELEVEL(op) \
	op(I) \
	op(II) \
	op(III) \
	op(IV) \
	op(V) \
	op(VI) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
