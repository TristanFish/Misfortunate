// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/MisfortunateGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMisfortunateGameMode() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_AMisfortunateGameMode_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AMisfortunateGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AMPlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	MISFORTUNATE_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerInfo();
// End Cross Module References
	static FName NAME_AMisfortunateGameMode_EveryoneUpdate = FName(TEXT("EveryoneUpdate"));
	void AMisfortunateGameMode::EveryoneUpdate()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMisfortunateGameMode_EveryoneUpdate),NULL);
	}
	static FName NAME_AMisfortunateGameMode_InitPlayerInfo = FName(TEXT("InitPlayerInfo"));
	void AMisfortunateGameMode::InitPlayerInfo(AMPlayerController* player)
	{
		MisfortunateGameMode_eventInitPlayerInfo_Parms Parms;
		Parms.player=player;
		ProcessEvent(FindFunctionChecked(NAME_AMisfortunateGameMode_InitPlayerInfo),&Parms);
	}
	void AMisfortunateGameMode::StaticRegisterNativesAMisfortunateGameMode()
	{
	}
	struct Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMisfortunateGameMode, nullptr, "EveryoneUpdate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::NewProp_player = { "player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MisfortunateGameMode_eventInitPlayerInfo_Parms, player), Z_Construct_UClass_AMPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::NewProp_player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMisfortunateGameMode, nullptr, "InitPlayerInfo", nullptr, nullptr, sizeof(MisfortunateGameMode_eventInitPlayerInfo_Parms), Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMisfortunateGameMode_NoRegister()
	{
		return AMisfortunateGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMisfortunateGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventChance_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_EventChance;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConnectedPlayers_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConnectedPlayers_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ConnectedPlayers;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ConnectedPlayerInfos_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConnectedPlayerInfos_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ConnectedPlayerInfos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMisfortunateGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMisfortunateGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMisfortunateGameMode_EveryoneUpdate, "EveryoneUpdate" }, // 1374026688
		{ &Z_Construct_UFunction_AMisfortunateGameMode_InitPlayerInfo, "InitPlayerInfo" }, // 3386991816
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MisfortunateGameMode.h" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData[] = {
		{ "Category", "MisfortunateGameMode" },
		{ "Comment", "// The percent chance that a player will be scared by a event\n" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
		{ "ToolTip", "The percent chance that a player will be scared by a event" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance = { "EventChance", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMisfortunateGameMode, EventChance), METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers_Inner = { "ConnectedPlayers", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers_MetaData[] = {
		{ "Category", "MisfortunateGameMode" },
		{ "Comment", "// List of connected players\n" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
		{ "ToolTip", "List of connected players" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers = { "ConnectedPlayers", nullptr, (EPropertyFlags)0x0020080000000004, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMisfortunateGameMode, ConnectedPlayers), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos_Inner = { "ConnectedPlayerInfos", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPlayerInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos_MetaData[] = {
		{ "Category", "MisfortunateGameMode" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos = { "ConnectedPlayerInfos", nullptr, (EPropertyFlags)0x0020080000000004, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMisfortunateGameMode, ConnectedPlayerInfos), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMisfortunateGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_ConnectedPlayerInfos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMisfortunateGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMisfortunateGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMisfortunateGameMode_Statics::ClassParams = {
		&AMisfortunateGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMisfortunateGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::PropPointers),
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMisfortunateGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMisfortunateGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMisfortunateGameMode, 416544278);
	template<> MISFORTUNATE_API UClass* StaticClass<AMisfortunateGameMode>()
	{
		return AMisfortunateGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMisfortunateGameMode(Z_Construct_UClass_AMisfortunateGameMode, &AMisfortunateGameMode::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AMisfortunateGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMisfortunateGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
