// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BATUtilitiesFunctionLibrary.generated.h"

class USaveGame;
class UProgressionSaveGame;

/**
 * 
 */
UCLASS()
class BOOLALGEBRATRAINER_API UBATUtilitiesFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=BATUtilitiesFunctionLibrary)
	static UProgressionSaveGame* GetDefaultSave();

	UFUNCTION(BlueprintCallable, Category=BATUtilitiesFunctionLibrary)
	static void SaveToDefaultSlot(USaveGame* SaveGame);
};
