// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
#ifdef MISFORTUNATE_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define MISFORTUNATE_PlayerCharacter_generated_h

#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_RPC_WRAPPERS \
	virtual bool Client_SetMisfortune_Validate(const float ); \
	virtual void Client_SetMisfortune_Implementation(const float Misfortune_); \
	virtual bool Server_ThrowGlowstick_Validate(); \
	virtual void Server_ThrowGlowstick_Implementation(); \
	virtual bool Multi_UpdateLookRotation_Validate(FRotator ); \
	virtual void Multi_UpdateLookRotation_Implementation(FRotator rot); \
	virtual bool Server_TriggerHeadLamp_Validate(); \
	virtual void Server_TriggerHeadLamp_Implementation(); \
 \
	DECLARE_FUNCTION(execClient_SetMisfortune); \
	DECLARE_FUNCTION(execServer_ThrowGlowstick); \
	DECLARE_FUNCTION(execMulti_UpdateLookRotation); \
	DECLARE_FUNCTION(execServer_TriggerHeadLamp); \
	DECLARE_FUNCTION(execTickStamina);


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool Client_SetMisfortune_Validate(const float ); \
	virtual void Client_SetMisfortune_Implementation(const float Misfortune_); \
	virtual bool Server_ThrowGlowstick_Validate(); \
	virtual void Server_ThrowGlowstick_Implementation(); \
	virtual bool Multi_UpdateLookRotation_Validate(FRotator ); \
	virtual void Multi_UpdateLookRotation_Implementation(FRotator rot); \
	virtual bool Server_TriggerHeadLamp_Validate(); \
	virtual void Server_TriggerHeadLamp_Implementation(); \
 \
	DECLARE_FUNCTION(execClient_SetMisfortune); \
	DECLARE_FUNCTION(execServer_ThrowGlowstick); \
	DECLARE_FUNCTION(execMulti_UpdateLookRotation); \
	DECLARE_FUNCTION(execServer_TriggerHeadLamp); \
	DECLARE_FUNCTION(execTickStamina);


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_EVENT_PARMS \
	struct PlayerCharacter_eventClient_SetMisfortune_Parms \
	{ \
		float Misfortune_; \
	}; \
	struct PlayerCharacter_eventMulti_UpdateLookRotation_Parms \
	{ \
		FRotator rot; \
	};


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_CALLBACK_WRAPPERS
#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Misfortune=NETFIELD_REP_START, \
		NETFIELD_REP_END=Misfortune	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Misfortune=NETFIELD_REP_START, \
		NETFIELD_REP_END=Misfortune	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public:


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter)


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_PRIVATE_PROPERTY_OFFSET
#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_27_PROLOG \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_EVENT_PARMS


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_CALLBACK_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_INCLASS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_CALLBACK_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_PlayerCharacter_h


#define FOREACH_ENUM_CRAWLSTATES(op) \
	op(Stand) \
	op(Crouch) \
	op(Crawl) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
