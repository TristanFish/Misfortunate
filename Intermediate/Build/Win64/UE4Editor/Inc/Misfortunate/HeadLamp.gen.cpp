// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/HeadLamp.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeadLamp() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_AHeadLamp_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AHeadLamp();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
// End Cross Module References
	void AHeadLamp::StaticRegisterNativesAHeadLamp()
	{
	}
	UClass* Z_Construct_UClass_AHeadLamp_NoRegister()
	{
		return AHeadLamp::StaticClass();
	}
	struct Z_Construct_UClass_AHeadLamp_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_lightMid_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_lightMid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_lightLeft_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_lightLeft;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_lightRight_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_lightRight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_flashlightArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_flashlightArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnOffSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OnOffSound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeadLamp_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HeadLamp.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_SceneComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_SceneComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightMid_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "Comment", "/*Head Lamp Components*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
		{ "ToolTip", "Head Lamp Components" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightMid = { "lightMid", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, lightMid), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightMid_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightMid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightLeft_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightLeft = { "lightLeft", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, lightLeft), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightLeft_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightLeft_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightRight_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightRight = { "lightRight", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, lightRight), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightRight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightRight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_flashlightArm_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_flashlightArm = { "flashlightArm", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, flashlightArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_flashlightArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_flashlightArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLamp_Statics::NewProp_OnOffSound_MetaData[] = {
		{ "Category", "HeadLamp" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeadLamp_Statics::NewProp_OnOffSound = { "OnOffSound", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeadLamp, OnOffSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::NewProp_OnOffSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::NewProp_OnOffSound_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHeadLamp_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_SceneComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightMid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightLeft,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_lightRight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_flashlightArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeadLamp_Statics::NewProp_OnOffSound,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeadLamp_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeadLamp>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeadLamp_Statics::ClassParams = {
		&AHeadLamp::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AHeadLamp_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AHeadLamp_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLamp_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeadLamp()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeadLamp_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeadLamp, 1005843258);
	template<> MISFORTUNATE_API UClass* StaticClass<AHeadLamp>()
	{
		return AHeadLamp::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeadLamp(Z_Construct_UClass_AHeadLamp, &AHeadLamp::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AHeadLamp"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeadLamp);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
