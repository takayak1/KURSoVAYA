// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameEventsListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBoolSettingChangedSignature, bool, Value);

/**
 * 
 */
UCLASS()
class BOOLALGEBRATRAINER_API UGameEventsListener : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	static UGameEventsListener* Get();

	
	UPROPERTY(BlueprintAssignable, Category=Sound)
	FBoolSettingChangedSignature OnEnableUISound;

	UPROPERTY(BlueprintAssignable, Category=Sound)
	FBoolSettingChangedSignature OnEnableMusic;
};
