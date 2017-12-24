// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadingScreenGameInstance.h"

#include "MoviePlayer.h"

void ULoadingScreenGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULoadingScreenGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadingScreenGameInstance::EndLoadingScreen);
}

void ULoadingScreenGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void ULoadingScreenGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}
