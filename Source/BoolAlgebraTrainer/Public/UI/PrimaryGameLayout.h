// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "PrimaryGameLayout.generated.h"

class UCommonActivatableWidgetStack;
class UCommonActivatableWidget;

UENUM()
enum EWidgetLayoutLayer
{
	Game UMETA(DisplayName = "Game"),
	Menu UMETA(DisplayName = "Menu"),
	Modal UMETA(DisplayName = "Modal")
};


/**
 * 
 */
UCLASS()
class BOOLALGEBRATRAINER_API UPrimaryGameLayout : public UCommonUserWidget
{
	GENERATED_BODY()


public:

	// Widget Stack for HUD-like widgets
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* GameLayerStack;

	// Widget Stack for menus (Level Selection, Settings, etc.)
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* MenuLayerStack;

	// Widget Stack for modal menus
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* ModalLayerStack;

	// Creates and pushes Widget to specified Layer Widget Stack
	UFUNCTION(BlueprintCallable, Category=UI)
	UCommonActivatableWidget* PushWidgetToLayer(TSubclassOf<UCommonActivatableWidget> WidgetClass, EWidgetLayoutLayer Layer);

	// Finds and Removes Widget from any layer
	UFUNCTION(BlueprintCallable, Category=UI)
	void RemoveWidgetFromLayer(UCommonActivatableWidget* ActivatableWidget);

};
