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
	MISFORTUNATE_API UEnum* Z_Construct_UEnum_Misfortunate_ScareType();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AScareEventManager_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AScareEventManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
// End Cross Module References
	static UEnum* ScareType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Misfortunate_ScareType, Z_Construct_UPackage__Script_Misfortunate(), TEXT("ScareType"));
		}
		return Singleton;
	}
	template<> MISFORTUNATE_API UEnum* StaticEnum<ScareType>()
	{
		return ScareType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ScareType(ScareType_StaticEnum, TEXT("/Script/Misfortunate"), TEXT("ScareType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Misfortunate_ScareType_Hash() { return 2833520036U; }
	UEnum* Z_Construct_UEnum_Misfortunate_ScareType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Misfortunate();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ScareType"), 0, Get_Z_Construct_UEnum_Misfortunate_ScareType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Whisper", (int64)Whisper },
				{ "Wind", (int64)Wind },
				{ "Footsteps", (int64)Footsteps },
				{ "SingingNoises", (int64)SingingNoises },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Footsteps.Name", "Footsteps" },
				{ "ModuleRelativePath", "Public/ScareEventManager.h" },
				{ "SingingNoises.Name", "SingingNoises" },
				{ "Whisper.Name", "Whisper" },
				{ "Wind.Name", "Wind" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Misfortunate,
				nullptr,
				"ScareType",
				"ScareType",
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
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_scares_ValueProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_scares_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_scares_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_scares;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScareAttenuation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ScareAttenuation;
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
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_ValueProp = { "scares", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UEnum_Misfortunate_ScareType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_Key_KeyProp = { "scares_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData[] = {
		{ "Category", "ScareEventManager" },
		{ "Comment", "// Map that enables us to add Sound cue's in engine and map then to a scare type\n" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
		{ "ToolTip", "Map that enables us to add Sound cue's in engine and map then to a scare type" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares = { "scares", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AScareEventManager, scares), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareAttenuation_MetaData[] = {
		{ "Category", "ScareEventManager" },
		{ "Comment", "// Used to determine different 3D audio settings\n" },
		{ "ModuleRelativePath", "Public/ScareEventManager.h" },
		{ "ToolTip", "Used to determine different 3D audio settings" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareAttenuation = { "ScareAttenuation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AScareEventManager, ScareAttenuation), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareAttenuation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareAttenuation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AScareEventManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_scares,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AScareEventManager_Statics::NewProp_ScareAttenuation,
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
	IMPLEMENT_CLASS(AScareEventManager, 2725660151);
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
