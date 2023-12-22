// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PrimaryGameLayout.h"
#include "UISubsystem.generated.h"

class UCommonActivatableWidget;
class UPrimaryGameLayout;
/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class BOOLALGEBRATRAINER_API UUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UUISubsystem();

	UFUNCTION(BlueprintCallable, Category = "UISubsystem", meta = (WorldContext = "WorldContextObject"))
	void InitializePrimaryGameLayout(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "UISubsystem")
	UCommonActivatableWidget* PushContentToLayer(EWidgetLayoutLayer LayerName, UPARAM(meta = (AllowAbstract = false)) TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "UISubsystem")
	void PopContentFromLayer(UCommonActivatableWidget* ActivatableWidget);
	
protected:

	UPROPERTY()
	UPrimaryGameLayout* PrimaryGameLayout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Settings")
	TSoftClassPtr<UPrimaryGameLayout> PrimaryGameLayoutClass;
	
};
