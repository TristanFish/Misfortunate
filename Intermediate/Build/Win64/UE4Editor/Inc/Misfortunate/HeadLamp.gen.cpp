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
	MISFORTUNATE_API UClass* Z_Construct_UClass_AHeadLampInfo_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AHeadLampInfo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
// End Cross Module References
	void AHeadLampInfo::StaticRegisterNativesAHeadLampInfo()
	{
	}
	UClass* Z_Construct_UClass_AHeadLampInfo_NoRegister()
	{
		return AHeadLampInfo::StaticClass();
	}
	struct Z_Construct_UClass_AHeadLampInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeadLampInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeadLampInfo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HeadLamp.h" },
		{ "ModuleRelativePath", "Public/HeadLamp.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeadLampInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeadLampInfo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeadLampInfo_Statics::ClassParams = {
		&AHeadLampInfo::StaticClass,
		"ConfigName",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AHeadLampInfo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHeadLampInfo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeadLampInfo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeadLampInfo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeadLampInfo, 3992994973);
	template<> MISFORTUNATE_API UClass* StaticClass<AHeadLampInfo>()
	{
		return AHeadLampInfo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeadLampInfo(Z_Construct_UClass_AHeadLampInfo, &AHeadLampInfo::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AHeadLampInfo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeadLampInfo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
