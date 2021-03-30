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
// End Cross Module References
	void AMisfortunateGameMode::StaticRegisterNativesAMisfortunateGameMode()
	{
	}
	UClass* Z_Construct_UClass_AMisfortunateGameMode_NoRegister()
	{
		return AMisfortunateGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMisfortunateGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DistanceThreshold_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DistanceThreshold;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventChance_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_EventChance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMisfortunateGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_DistanceThreshold_MetaData[] = {
		{ "Category", "MisfortunateGameMode" },
		{ "Comment", "// Hold's the distance the players need to go away from each other until scare event's have the possibility of happening\n" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
		{ "ToolTip", "Hold's the distance the players need to go away from each other until scare event's have the possibility of happening" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_DistanceThreshold = { "DistanceThreshold", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMisfortunateGameMode, DistanceThreshold), METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_DistanceThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_DistanceThreshold_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData[] = {
		{ "Category", "MisfortunateGameMode" },
		{ "Comment", "// The percent chance that a player will be scared by a event\n" },
		{ "ModuleRelativePath", "Public/MisfortunateGameMode.h" },
		{ "ToolTip", "The percent chance that a player will be scared by a event" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance = { "EventChance", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMisfortunateGameMode, EventChance), METADATA_PARAMS(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMisfortunateGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_DistanceThreshold,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMisfortunateGameMode_Statics::NewProp_EventChance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMisfortunateGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMisfortunateGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMisfortunateGameMode_Statics::ClassParams = {
		&AMisfortunateGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMisfortunateGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
	IMPLEMENT_CLASS(AMisfortunateGameMode, 1480284101);
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
