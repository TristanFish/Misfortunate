// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Misfortunate/Public/CustomAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomAnimInstance() {}
// Cross Module References
	MISFORTUNATE_API UClass* Z_Construct_UClass_UCustomAnimInstance_NoRegister();
	MISFORTUNATE_API UClass* Z_Construct_UClass_UCustomAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Misfortunate();
	MISFORTUNATE_API UClass* Z_Construct_UClass_APlayerCharacter_NoRegister();
// End Cross Module References
	void UCustomAnimInstance::StaticRegisterNativesUCustomAnimInstance()
	{
	}
	UClass* Z_Construct_UClass_UCustomAnimInstance_NoRegister()
	{
		return UCustomAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UCustomAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharPlayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharPlayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_direction_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_direction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_oldMovementDir_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_oldMovementDir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackwardDir_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BackwardDir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsInAir_MetaData[];
#endif
		static void NewProp_IsInAir_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsInAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsCrawling_MetaData[];
#endif
		static void NewProp_IsCrawling_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsCrawling;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsCrouched_MetaData[];
#endif
		static void NewProp_IsCrouched_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsCrouched;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Misfortunate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance AnimInstance" },
		{ "IncludePath", "CustomAnimInstance.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_CharPlayer_MetaData[] = {
		{ "Category", "CustomAnimInstance" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_CharPlayer = { "CharPlayer", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomAnimInstance, CharPlayer), Z_Construct_UClass_APlayerCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_CharPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_CharPlayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Generic" },
		{ "Comment", "/*!Handles the speed of the animation*/" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
		{ "ToolTip", "!Handles the speed of the animation" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomAnimInstance, speed), METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_direction_MetaData[] = {
		{ "Category", "Generic" },
		{ "Comment", "/*!Handles the direction of the animation*/" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
		{ "ToolTip", "!Handles the direction of the animation" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_direction = { "direction", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomAnimInstance, direction), METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_direction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_oldMovementDir_MetaData[] = {
		{ "Category", "Generic" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_oldMovementDir = { "oldMovementDir", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomAnimInstance, oldMovementDir), METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_oldMovementDir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_oldMovementDir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_BackwardDir_MetaData[] = {
		{ "Category", "Generic" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_BackwardDir = { "BackwardDir", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomAnimInstance, BackwardDir), METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_BackwardDir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_BackwardDir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir_MetaData[] = {
		{ "Category", "Generic" },
		{ "Comment", "/*!Updated when player is/isnt in air (Used for jumping)*/" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
		{ "ToolTip", "!Updated when player is/isnt in air (Used for jumping)" },
	};
#endif
	void Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir_SetBit(void* Obj)
	{
		((UCustomAnimInstance*)Obj)->IsInAir = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir = { "IsInAir", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomAnimInstance), &Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling_MetaData[] = {
		{ "Category", "Generic" },
		{ "Comment", "/*!Updated when player is/isnt crawling*/" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
		{ "ToolTip", "!Updated when player is/isnt crawling" },
	};
#endif
	void Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling_SetBit(void* Obj)
	{
		((UCustomAnimInstance*)Obj)->IsCrawling = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling = { "IsCrawling", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomAnimInstance), &Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched_MetaData[] = {
		{ "Category", "Generic" },
		{ "Comment", "/*!Updated when player is/isnt crawling*/" },
		{ "ModuleRelativePath", "Public/CustomAnimInstance.h" },
		{ "ToolTip", "!Updated when player is/isnt crawling" },
	};
#endif
	void Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched_SetBit(void* Obj)
	{
		((UCustomAnimInstance*)Obj)->IsCrouched = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched = { "IsCrouched", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomAnimInstance), &Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_CharPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_direction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_oldMovementDir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_BackwardDir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsInAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrawling,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomAnimInstance_Statics::NewProp_IsCrouched,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomAnimInstance_Statics::ClassParams = {
		&UCustomAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCustomAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::PropPointers),
		0,
		0x008000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomAnimInstance, 2190174969);
	template<> MISFORTUNATE_API UClass* StaticClass<UCustomAnimInstance>()
	{
		return UCustomAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomAnimInstance(Z_Construct_UClass_UCustomAnimInstance, &UCustomAnimInstance::StaticClass, TEXT("/Script/Misfortunate"), TEXT("UCustomAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
