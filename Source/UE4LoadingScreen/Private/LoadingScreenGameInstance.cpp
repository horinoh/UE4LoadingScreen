// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadingScreenGameInstance.h"

#include "MoviePlayer.h"
#include "Kismet/GameplayStatics.h"

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
#ifdef USE_FADE
		FadeOut(1.0f);
#else
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
#endif
	}
}

void ULoadingScreenGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
#ifdef USE_FADE
	FadeIn(1.0);
#endif
}

void ULoadingScreenGameInstance::FadeIn(const float Duration)
{
	const auto World = GetWorld();
	if (nullptr != World)
	{
		const auto PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(World, 0);
		if (nullptr != PlayerCameraManager)
		{
			PlayerCameraManager->StartCameraFade(1.0f, 0.0f, Duration, FColor::Black, false, true);
		}
	}
}

void ULoadingScreenGameInstance::FadeOut(const float Duration)
{
	const auto World = GetWorld();
	if (nullptr != World)
	{
		const auto PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(World, 0);
		if (nullptr != PlayerCameraManager)
		{
			PlayerCameraManager->StartCameraFade(0.0f, 1.0f, Duration, FColor::Black, false, true);
		}
	}
}
