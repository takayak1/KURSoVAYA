// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ProgressionSubsystem.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig)
class BOOLALGEBRATRAINER_API UProgressionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	static UProgressionSubsystem* Get();
	
	UProgressionSubsystem();

	UFUNCTION(BlueprintCallable, Category=ProgressionSubsystem)
	void InitializeUnlockedContent();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=ProgressionSubsystem)
	bool IsContentUnlocked(const FName& InContentUID);

	UFUNCTION(BlueprintCallable, Category=ProgressionSubsystem)
	void UnlockContent(const FName& InContentUID);
	
	UFUNCTION(BlueprintCallable, Category=ProgressionSubsystem)
	void UnlockMultipleContent(const TArray<FName>& InContentUIDs);

	UFUNCTION(BlueprintCallable, Category=ProgressionSubsystem)
	void LockContent(const FName& InContentUID);
	
protected:
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config, Config)
	TSet<FName> ContentToUnlockOnStart;
};
