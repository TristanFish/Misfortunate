// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMPlayerController;
#ifdef MISFORTUNATE_MisfortunateGameMode_generated_h
#error "MisfortunateGameMode.generated.h already included, missing '#pragma once' in MisfortunateGameMode.h"
#endif
#define MISFORTUNATE_MisfortunateGameMode_generated_h

#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_SPARSE_DATA
#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_RPC_WRAPPERS
#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_EVENT_PARMS \
	struct MisfortunateGameMode_eventInitPlayerInfo_Parms \
	{ \
		AMPlayerController* player; \
	};


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_CALLBACK_WRAPPERS
#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMisfortunateGameMode(); \
	friend struct Z_Construct_UClass_AMisfortunateGameMode_Statics; \
public: \
	DECLARE_CLASS(AMisfortunateGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AMisfortunateGameMode)


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAMisfortunateGameMode(); \
	friend struct Z_Construct_UClass_AMisfortunateGameMode_Statics; \
public: \
	DECLARE_CLASS(AMisfortunateGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Misfortunate"), NO_API) \
	DECLARE_SERIALIZER(AMisfortunateGameMode)


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMisfortunateGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMisfortunateGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMisfortunateGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMisfortunateGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMisfortunateGameMode(AMisfortunateGameMode&&); \
	NO_API AMisfortunateGameMode(const AMisfortunateGameMode&); \
public:


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMisfortunateGameMode(AMisfortunateGameMode&&); \
	NO_API AMisfortunateGameMode(const AMisfortunateGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMisfortunateGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMisfortunateGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMisfortunateGameMode)


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ConnectedPlayers() { return STRUCT_OFFSET(AMisfortunateGameMode, ConnectedPlayers); } \
	FORCEINLINE static uint32 __PPO__ConnectedPlayerInfos() { return STRUCT_OFFSET(AMisfortunateGameMode, ConnectedPlayerInfos); }


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_20_PROLOG \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_EVENT_PARMS


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_RPC_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_CALLBACK_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_INCLASS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_SPARSE_DATA \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_CALLBACK_WRAPPERS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_INCLASS_NO_PURE_DECLS \
	Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MISFORTUNATE_API UClass* StaticClass<class AMisfortunateGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Misfortunate_Source_Misfortunate_Public_MisfortunateGameMode_h


#define FOREACH_ENUM_UGAMESTATE(op) \
	op(Lobby) \
	op(Exploration) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
