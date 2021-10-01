// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/MisfortunateGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMisfortunateGameInstance() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_UMisfortunateGameInstance_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_UMisfortunateGameInstance();
	ADVANCEDSESSIONS_API UClass* Z_Construct_UClass_UAdvancedFriendsGameInstance();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
// End Cross Module References
	void UMisfortunateGameInstance::StaticRegisterNativesUMisfortunateGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UMisfortunateGameInstance_NoRegister()
	{
		return UMisfortunateGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMisfortunateGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMisfortunateGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAdvancedFriendsGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMisfortunateGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MisfortunateGameInstance.h" },
		{ "ModuleRelativePath", "Public/MisfortunateGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMisfortunateGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMisfortunateGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMisfortunateGameInstance_Statics::ClassParams = {
		&UMisfortunateGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UMisfortunateGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMisfortunateGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMisfortunateGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMisfortunateGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMisfortunateGameInstance, 777908103);
	template<> MISFORTUNATE_API UClass* StaticClass<UMisfortunateGameInstance>()
	{
		return UMisfortunateGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMisfortunateGameInstance(Z_Construct_UClass_UMisfortunateGameInstance, &UMisfortunateGameInstance::StaticClass, TEXT("/Script/Misfortunate"), TEXT("UMisfortunateGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMisfortunateGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
