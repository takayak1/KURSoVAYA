// Fill out your copyright notice in the Description page of Project Settings.


#include "BoolAlgebraTrainer/Public/UI/UISubsystem.h"

#include "CommonActivatableWidget.h"
#include "ISettingsModule.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PrimaryGameLayout.h"


UUISubsystem::UUISubsystem()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings")))
	{
		SettingsModule->RegisterSettings("Project", "Game", "UIConfig",
			FText::FromString("UI Config"),
			FText::FromString(""),
			GetMutableDefault<ThisClass>());
	}
}

void UUISubsystem::InitializePrimaryGameLayout(UObject* WorldContextObject)
{
	if(!PrimaryGameLayout && !PrimaryGameLayoutClass.IsNull())
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
		UPrimaryGameLayout* NewLayoutObject = CreateWidget<UPrimaryGameLayout>(PlayerController, PrimaryGameLayoutClass.LoadSynchronous());
		PrimaryGameLayout = NewLayoutObject;
		NewLayoutObject->AddToViewport(1000);
	}
}

UCommonActivatableWidget* UUISubsystem::PushContentToLayer(EWidgetLayoutLayer LayerName, TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	if(!WidgetClass)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Trying to push invalid widget class"));
		return nullptr;
	}

	if(PrimaryGameLayout)
	{
		return PrimaryGameLayout->PushWidgetToLayer(WidgetClass, LayerName);
	}

	return nullptr;
}

void UUISubsystem::PopContentFromLayer(UCommonActivatableWidget* ActivatableWidget)
{
	if(PrimaryGameLayout && ActivatableWidget)
	{
		PrimaryGameLayout->RemoveWidgetFromLayer(ActivatableWidget);
	}
}
