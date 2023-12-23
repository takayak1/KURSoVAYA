// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Assignments/AssignmentTypes.h"
#include "GameFramework/SaveGame.h"
#include "ProgressionSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class BOOLALGEBRATRAINER_API UProgressionSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	static UProgressionSaveGame* GetOrCreateDefaultSave();
	static void SaveToDefaultSlot(USaveGame* SaveGame);

	UFUNCTION(BlueprintCallable, Category=SaveGame)
	void SetEnableUISound(bool bEnable);

	UFUNCTION(BlueprintCallable, Category=SaveGame)
	void SetEnableMusic(bool bEnable);
	
public:
	
	UPROPERTY()
	TMap<FName, FAssignmentSaveData> AssignmentsSaveData;

	UPROPERTY()
	TSet<FName> UnlockedContent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Sound)
	bool bEnableUISound = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Sound)
	bool bEnableMusic = true;
	
};
