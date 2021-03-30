// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/MisfortunateHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMisfortunateHUD() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_AMisfortunateHUD_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AMisfortunateHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
// End Cross Module References
	void AMisfortunateHUD::StaticRegisterNativesAMisfortunateHUD()
	{
	}
	UClass* Z_Construct_UClass_AMisfortunateHUD_NoRegister()
	{
		return AMisfortunateHUD::StaticClass();
	}
	struct Z_Construct_UClass_AMisfortunateHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMisfortunateHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMisfortunateHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "MisfortunateHUD.h" },
		{ "ModuleRelativePath", "Public/MisfortunateHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMisfortunateHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMisfortunateHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMisfortunateHUD_Statics::ClassParams = {
		&AMisfortunateHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMisfortunateHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMisfortunateHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMisfortunateHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMisfortunateHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMisfortunateHUD, 2605367954);
	template<> MISFORTUNATE_API UClass* StaticClass<AMisfortunateHUD>()
	{
		return AMisfortunateHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMisfortunateHUD(Z_Construct_UClass_AMisfortunateHUD, &AMisfortunateHUD::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AMisfortunateHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMisfortunateHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
