// Copyright Epic Games, Inc. All Rights Reserved.

#include "FastTween.h"

#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "FastTweenCore.h"
#include "IContentBrowserSingleton.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Settings/FastTweenSettings.h"
#include "Settings/FastTweenSettingsFactory.h"
#include "UObject/SavePackage.h"

#define LOCTEXT_NAMESPACE "FFastTweenModule"


void FFastTweenModule::StartupModule()
{
	const FString DirectoryPathInFileManager = FPaths::ProjectContentDir() + TEXT("FastTween");
	if(!IFileManager::Get().DirectoryExists(*DirectoryPathInFileManager))
		IFileManager::Get().MakeDirectory(*DirectoryPathInFileManager);
	
	const FString SettingsPath = TEXT("/Game/FastTween/FastTweenSettings");
	const FString PackagePath = TEXT("/Game/FastTween");
	
	UFastTweenSettings* Settings = Cast<UFastTweenSettings>(StaticLoadObject(UFastTweenSettings::StaticClass(), nullptr, *SettingsPath));
	if (!Settings)
	{
		FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
		IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
		
		UPackage* package = CreatePackage(*SettingsPath);
		UFastTweenSettingsFactory* factory = NewObject<UFastTweenSettingsFactory>();
		FString FullPackagePath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("FastTween/FastTweenSettings/FastTweenSettings.uasset"));
		UObject* asset = AssetToolsModule.Get().CreateAsset(TEXT("FastTweenSettings"), PackagePath, UFastTweenSettings::StaticClass(), factory);
		FSavePackageArgs saveArgs;
		
		UPackage::Save(package, asset, *FullPackagePath, FSavePackageArgs());
		
		AssetRegistry.AssetCreated(asset);
		
		TArray<UObject*> Objects;
		Objects.Add(asset);
		ContentBrowserModule.Get().SyncBrowserToAssets(Objects);
	}

	FWorldDelegates::OnPostWorldInitialization.AddStatic(&FFastTweenCore::OnWorldInitialized);
	FWorldDelegates::OnPreWorldFinishDestroy.AddStatic(&FFastTweenCore::OnWorldPreDestroy);
}

void FFastTweenModule::ShutdownModule()
{
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(&FFastTweenCore::OnWorldInitialized);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFastTweenModule, FastTween)