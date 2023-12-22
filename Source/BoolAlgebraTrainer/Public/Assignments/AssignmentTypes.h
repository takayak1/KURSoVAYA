// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssignmentTypes.generated.h"


UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable, CollapseCategories)
class UCheckableAssignmentInstance : public UObject
{
	GENERATED_BODY()

public:
	
};


UCLASS()
class UExpressionAssignmentInstance : public UCheckableAssignmentInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText Expression;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	int32 ExpectedResult;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=AssignmentInstance)
	virtual bool CheckIsCorrect(int32 Answer) { return Answer == ExpectedResult; };
};

USTRUCT(BlueprintType)
struct FTruthTableColumnElement
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	bool Value;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	bool bInputField = false;
};

USTRUCT(BlueprintType)
struct FTruthTableColumn
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText ColumnName;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config, meta=(ShowOnlyInnerProperties))
	TArray<FTruthTableColumnElement> Elements;
	
	bool operator==(const FTruthTableColumn& Column) const
	{
		for (int32 Index = 0; Index < Elements.Num(); ++Index)
		{
			if(Elements[Index].Value != Column.Elements[Index].Value)
			{
				return false;
			}
		}
		
		return true;
	};
};

USTRUCT(BlueprintType)
struct FTruthTable
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	TArray<FTruthTableColumn> TableColumns;
	
	bool operator==(const FTruthTable& TruthTable) const
	{
		for (int32 Index = 0; Index < TableColumns.Num(); ++Index)
		{
			if(TableColumns[Index] != TruthTable.TableColumns[Index])
			{
				return false;
			}
		}
		return true;
	};
};

UCLASS()
class UTableAssignmentInstance : public UCheckableAssignmentInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config, meta=(ShowOnlyInnerProperties))
	FTruthTable TruthTable;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=AssignmentInstance)
	virtual bool CheckIsCorrect(const FTruthTable& InTruthTable) { return TruthTable == InTruthTable; };
};


UCLASS(BlueprintType)
class UAssignmentsContainer : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=AssignmentsContainer)
	TArray<UCheckableAssignmentInstance*> GetAssignments() const;

	
protected:
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced)
	TArray<UCheckableAssignmentInstance*> Assignments;
};

USTRUCT()
struct BOOLALGEBRATRAINER_API FAssignmentData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FName AssignmentUID;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText Symbol;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText ShortDescription;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText FullDescription;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	FText WebResourceLink;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	UAssignmentsContainer* AssignmentsContainer;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	TArray<FName> ContentToUnlock;
};

UENUM()
enum class EAssignmentState : uint8
{
	None,
	NotStarted,
	Failed,
	Completed
};

USTRUCT(BlueprintType)
struct BOOLALGEBRATRAINER_API FAssignmentSaveData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=Config)
	EAssignmentState AssignmentState = EAssignmentState::NotStarted;
};
