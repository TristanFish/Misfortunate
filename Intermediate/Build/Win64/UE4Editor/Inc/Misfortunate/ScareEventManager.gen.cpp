// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/ScareEventManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScareEventManager() {}
// Cross Module References
	MISFORTUNATE_API UEnum* Z_Construct_UEnum_Misfortunate_ScareLocationType();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	MISFORTUNATE_API UScriptStruct* Z_Construct_UScriptStruct_FScareAudio();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	MISFORTUNATE_API UScriptStruct* Z_Construct_UScriptStruct_FScareSettings();
	MISFORTUNATE_API UEnum* Z_Construct_UEnum_Misfortunate_ScareType();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AScareEventManager_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AScareEventManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* ScareLocationType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Misfortunate_ScareLocationType, Z_Construct_UPackage__Script_Misfortunate(), TEXT("ScareLocationType"));
		}
		return Singleton;
	}
	template<> MISFORTUNATE_API UEnum* StaticEnum<ScareLocationType>()
	{
		return ScareLocationType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ScareLocationType(ScareLocationType_StaticEnum, TEXT("/Script/Misfortunate"), TEXT("ScareLocationType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Misfortunate_ScareLocationType_Hash() { return 2339255532U; }
	UEnum* Z_Construct_UEnum_Misfortunate_ScareLocationType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Misfortunate();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ScareLocationType"), 0, Get_Z_Construct_UEnum_Misfortunate_ScareLocationType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Positional", (int64)Positional },
				{ "NonPositional", (int64)NonPositional },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Comment", "// Used to determine whether the scare will be in 3D space at a specific location or 2D sound.\n" },
				{ "ModuleRelativePath", "Public/ScareEventManager.h" },
				{ "NonPositional.Name", "NonPositional" },
				{ "Positional.Name", "Positional" },
				{ "ToolTip", "Used to determine whether the scare will be in 3D space at a specific location or 2D sound." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Misfortunate,
				nullptr,
				"ScareLocationType",
				"ScareLocationType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FScareAudio::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MISFORTUNATE_API uint32 Get_Z_Construct_UScriptStruct_FScareAudio_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FScareAudio, Z_Construct_UPackage__Script_Misfortunate(), TEXT("ScareAudio"), sizeof(FScareAudio), Get_Z_Construct_UScriptStruct_FScareAudio_Hash());
	}
	return Singleton;
}
template<> MISFORTUNATE_API UScriptStruct* StaticStruct<FScareAudio>()
{
	return FScareAudio::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FScareAudio(FScareAudio::StaticStruct, TEXT("/Script/Misfortunate"), TEXT("ScareAudio"), false, nullptr, nullptr);
static struct FScriptStruct_Misfortunate_StaticRegisterNativesFScareAudio
{
	FScriptStruct_Misfortunate_StaticRegisterNativesFScareAudio()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ScareAudio")),new UScriptStruct::TCppStructOps<FScareAudio>);
	}
} ScriptStruct_Misfortunate_StaticRegisterNativesFScareAudio;
	struct Z_Construct_UScriptStruct_FScareAudio_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_audioClips_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_audioClips_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_audioClips;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FScareAudio_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FScareAudio_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FScareAudio>();
	}
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips_Inner = { "audioClips", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips_MetaData[] = {
		{ "Category", "ScareAudio" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips = { "audioClips", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FScareAudio, audioClips), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FScareAudio_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FScareAudio_Statics::NewProp_audioClips,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FScareAudio_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
		nullptr,
		&NewStructOps,
		"ScareAudio",
		sizeof(FScareAudio),
		alignof(FScareAudio),
		Z_Construct_UScriptStruct_FScareAudio_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareAudio_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FScareAudio_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareAudio_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FScareAudio()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FScareAudio_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Misfortunate();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ScareAudio"), sizeof(FScareAudio), Get_Z_Construct_UScriptStruct_FScareAudio_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FScareAudio_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FScareAudio_Hash() { return 3478656473U; }
class UScriptStruct* FScareSettings::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MISFORTUNATE_API uint32 Get_Z_Construct_UScriptStruct_FScareSettings_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FScareSettings, Z_Construct_UPackage__Script_Misfortunate(), TEXT("ScareSettings"), sizeof(FScareSettings), Get_Z_Construct_UScriptStruct_FScareSettings_Hash());
	}
	return Singleton;
}
template<> MISFORTUNATE_API UScriptStruct* StaticStruct<FScareSettings>()
{
	return FScareSettings::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FScareSettings(FScareSettings::StaticStruct, TEXT("/Script/Misfortunate"), TEXT("ScareSettings"), false, nullptr, nullptr);
static struct FScriptStruct_Misfortunate_StaticRegisterNativesFScareSettings
{
	FScriptStruct_Misfortunate_StaticRegisterNativesFScareSettings()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ScareSettings")),new UScriptStruct::TCppStructOps<FScareSettings>);
	}
} ScriptStruct_Misfortunate_StaticRegisterNativesFScareSettings;
	struct Z_Construct_UScriptStruct_FScareSettings_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scareType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_scareType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_locationType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_locationType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FScareSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FScareSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FScareSettings>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_scareType_MetaData[] = {
		{ "Category", "ScareSettings" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_scareType = { "scareType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FScareSettings, scareType), Z_Construct_UEnum_Misfortunate_ScareType, METADATA_PARAMS(Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_scareType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_scareType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_locationType_MetaData[] = {
		{ "Category", "ScareSettings" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_locationType = { "locationType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FScareSettings, locationType), Z_Construct_UEnum_Misfortunate_ScareLocationType, METADATA_PARAMS(Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_locationType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_locationType_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FScareSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_scareType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FScareSettings_Statics::NewProp_locationType,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FScareSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
		nullptr,
		&NewStructOps,
		"ScareSettings",
		sizeof(FScareSettings),
		alignof(FScareSettings),
		Z_Construct_UScriptStruct_FScareSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareSettings_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FScareSettings_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FScareSettings_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FScareSettings()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FScareSettings_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Misfortunate();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ScareSettings"), sizeof(FScareSettings), Get_Z_Construct_UScriptStruct_FScareSettings_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FScareSettings_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FScareSettings_Hash() { return 104539285U; }
	void AScareEventManager::StaticRegisterNativesAScareEventManager()
	{
	}
	UClass* Z_Construct_UClass_AScareEventManager_NoRegister()
	{
		return AScareEventManager::StaticClass();
	}
	struct Z_Construct_UClass_AScareEventManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_scares_ValueProp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_scares_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scares_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_scares;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CheckForScareTriggerDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CheckForScareTriggerDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScareDistanceThreshold_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ScareDistanceThreshold;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AScareEventManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ScareEventManager.h" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_ValueProp = { "scares", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FScareAudio, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_Key_KeyProp = { "scares_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FScareSettings, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData[] = {
		{ "Category", "ScareEventManager" },
		{ "Comment", "/*!Map that enables us to add Sound cue's in engine and map then to a scare type*/" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
		{ "ToolTip", "!Map that enables us to add Sound cue's in engine and map then to a scare type" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares = { "scares", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AScareEventManager, scares), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::NewProp_CheckForScareTriggerDelay_MetaData[] = {
		{ "Category", "ScareEventManager" },
		{ "Comment", "/* Holds how often that a Scare Event has a chance of triggering. */" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
		{ "ToolTip", "Holds how often that a Scare Event has a chance of triggering." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_CheckForScareTriggerDelay = { "CheckForScareTriggerDelay", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AScareEventManager, CheckForScareTriggerDelay), METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::NewProp_CheckForScareTriggerDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::NewProp_CheckForScareTriggerDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareDistanceThreshold_MetaData[] = {
		{ "Category", "ScareEventManager" },
		{ "Comment", "/* Hold's the distance the players need to go away from each other until scare event's have the possibility of happening*/" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
		{ "ToolTip", "Hold's the distance the players need to go away from each other until scare event's have the possibility of happening" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareDistanceThreshold = { "ScareDistanceThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AScareEventManager, ScareDistanceThreshold), METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareDistanceThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareDistanceThreshold_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AScareEventManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_CheckForScareTriggerDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareDistanceThreshold,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AScareEventManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AScareEventManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AScareEventManager_Statics::ClassParams = {
		&AScareEventManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AScareEventManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AScareEventManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AScareEventManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AScareEventManager, 2956187197);
	template<> MISFORTUNATE_API UClass* StaticClass<AScareEventManager>()
	{
		return AScareEventManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AScareEventManager(Z_Construct_UClass_AScareEventManager, &AScareEventManager::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AScareEventManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AScareEventManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
