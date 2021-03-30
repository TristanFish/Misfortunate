// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/Glowstick.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGlowstick() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_AGlowstick_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_AGlowstick();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
// End Cross Module References
	void AGlowstick::StaticRegisterNativesAGlowstick()
	{
	}
	UClass* Z_Construct_UClass_AGlowstick_NoRegister()
	{
		return AGlowstick::StaticClass();
	}
	struct Z_Construct_UClass_AGlowstick_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlowstickMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GlowstickMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StoredMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StoredMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynamicMatInst_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DynamicMatInst;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGlowstick_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGlowstick_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Glowstick.h" },
		{ "ModuleRelativePath", "Public/Glowstick.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGlowstick_Statics::NewProp_GlowstickMesh_MetaData[] = {
		{ "Category", "Glowstick" },
		{ "Comment", "// Mesh that is used to represent a glowstick\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Glowstick.h" },
		{ "ToolTip", "Mesh that is used to represent a glowstick" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGlowstick_Statics::NewProp_GlowstickMesh = { "GlowstickMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGlowstick, GlowstickMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGlowstick_Statics::NewProp_GlowstickMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGlowstick_Statics::NewProp_GlowstickMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGlowstick_Statics::NewProp_StoredMaterial_MetaData[] = {
		{ "Category", "Glowstick" },
		{ "Comment", "// Material that will be applied to the GlowstickMesh\n" },
		{ "ModuleRelativePath", "Public/Glowstick.h" },
		{ "ToolTip", "Material that will be applied to the GlowstickMesh" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGlowstick_Statics::NewProp_StoredMaterial = { "StoredMaterial", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGlowstick, StoredMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGlowstick_Statics::NewProp_StoredMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGlowstick_Statics::NewProp_StoredMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGlowstick_Statics::NewProp_DynamicMatInst_MetaData[] = {
		{ "Category", "Glowstick" },
		{ "Comment", "// Used to control and change variables of the materials shader at runtime\n" },
		{ "ModuleRelativePath", "Public/Glowstick.h" },
		{ "ToolTip", "Used to control and change variables of the materials shader at runtime" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGlowstick_Statics::NewProp_DynamicMatInst = { "DynamicMatInst", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGlowstick, DynamicMatInst), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGlowstick_Statics::NewProp_DynamicMatInst_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGlowstick_Statics::NewProp_DynamicMatInst_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGlowstick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGlowstick_Statics::NewProp_GlowstickMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGlowstick_Statics::NewProp_StoredMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGlowstick_Statics::NewProp_DynamicMatInst,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGlowstick_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGlowstick>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGlowstick_Statics::ClassParams = {
		&AGlowstick::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGlowstick_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGlowstick_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGlowstick_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGlowstick_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGlowstick()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGlowstick_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGlowstick, 2421617536);
	template<> MISFORTUNATE_API UClass* StaticClass<AGlowstick>()
	{
		return AGlowstick::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGlowstick(Z_Construct_UClass_AGlowstick, &AGlowstick::StaticClass, TEXT("/Script/Misfortunate"), TEXT("AGlowstick"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGlowstick);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
