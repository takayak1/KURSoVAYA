// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssignmentTypes.h"
#include "Assignments/AssignmentInstanceWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssignmentsFunctionLibrary.generated.h"

class UProgressionSaveGame;
class UCheckableAssignmentInstance;
class UAssignmentInstanceWidget;
/**
 * 
 */
// TODO SUBSYSTEM
UCLASS(Config=Game, DefaultConfig)
class BOOLALGEBRATRAINER_API UAssignmentsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UAssignmentsFunctionLibrary();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="AssignmentsFunctionLibrary")
	static UDataTable* GetAssignments();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="AssignmentsFunctionLibrary")
	static TArray<UAssignmentsContainer*> GetFreePlayAssignments();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="AssignmentsFunctionLibrary")
	static TSubclassOf<UAssignmentInstanceWidget> GetAssignmentInstanceWidgetClass(const UCheckableAssignmentInstance* AssignmentInstance);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="AssignmentsFunctionLibrary")
	static FAssignmentSaveData GetAssignmentSaveData(const FName& InAssignmentUID);

	UFUNCTION(BlueprintCallable, Category="AssignmentsFunctionLibrary")
	static void UpdateAssignmentSaveData(const FName& InAssignmentUID, const FAssignmentSaveData& InSaveData);

	UFUNCTION(BlueprintCallable, Category="AssignmentsFunctionLibrary")
	static void HandleAssignmentCompleted(const FAssignmentData& AssignmentData);
	
protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Config)
	TSoftObjectPtr<UDataTable> AssignmentsDataTable;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Config)
	TMap<TSoftClassPtr<UCheckableAssignmentInstance>, TSoftClassPtr<UAssignmentInstanceWidget>> AssignmentWidgetClasses;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Config)
	TArray<TSoftObjectPtr<UAssignmentsContainer>> FreePlayAssignments;
};
