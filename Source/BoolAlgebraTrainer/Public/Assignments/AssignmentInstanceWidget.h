// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AssignmentInstanceWidget.generated.h"

class UCheckableAssignmentInstance;
/**
 * 
 */
UCLASS(BlueprintType)
class BOOLALGEBRATRAINER_API UAssignmentInstanceWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void InitializeWithAssignmentInstance(UCheckableAssignmentInstance* AssignmentInstance);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool CheckAnswer();

	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintImplementableEvent)
	bool IsFilled();

protected:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnswerCommitted);
	UPROPERTY(BlueprintReadWrite, BlueprintCallable, BlueprintAssignable)
	FOnAnswerCommitted OnAnswerCommitted;
};
