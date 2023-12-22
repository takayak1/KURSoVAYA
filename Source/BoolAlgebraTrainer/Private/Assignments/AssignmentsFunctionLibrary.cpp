// Fill out your copyright notice in the Description page of Project Settings.


#include "Assignments/AssignmentsFunctionLibrary.h"

#include "ISettingsModule.h"
#include "ProgressionSaveGame.h"
#include "Assignments/AssignmentTypes.h"
#include "Assignments/AssignmentInstanceWidget.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Progression/ProgressionSubsystem.h"

UAssignmentsFunctionLibrary::UAssignmentsFunctionLibrary()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings")))
	{
		SettingsModule->RegisterSettings("Project", "Game", "AssignmentsConfig",
			FText::FromString("Assignments Config"),
			FText::FromString(""),
			GetMutableDefault<ThisClass>());
	}
}

UDataTable* UAssignmentsFunctionLibrary::GetAssignments()
{
	return GetDefault<ThisClass>()->AssignmentsDataTable.LoadSynchronous();
}

TArray<UAssignmentsContainer*> UAssignmentsFunctionLibrary::GetFreePlayAssignments()
{
	TArray<UAssignmentsContainer*> LoadedContainer;
	for (auto FreePlayAssignment : GetDefault<ThisClass>()->FreePlayAssignments)
	{
		LoadedContainer.Add(FreePlayAssignment.LoadSynchronous());
	}
	return LoadedContainer;
}

TSubclassOf<UAssignmentInstanceWidget> UAssignmentsFunctionLibrary::GetAssignmentInstanceWidgetClass(const UCheckableAssignmentInstance* AssignmentInstance)
{
	const auto FoundWidgetClass = *GetDefault<ThisClass>()->AssignmentWidgetClasses.Find(TSoftClassPtr<UCheckableAssignmentInstance>(AssignmentInstance->GetClass()));
	return TSubclassOf<UAssignmentInstanceWidget>(FoundWidgetClass.LoadSynchronous());
}

FAssignmentSaveData UAssignmentsFunctionLibrary::GetAssignmentSaveData(const FName& InAssignmentUID)
{
	return UProgressionSaveGame::GetOrCreateDefaultSave()->AssignmentsSaveData.FindOrAdd(InAssignmentUID);
}

void UAssignmentsFunctionLibrary::UpdateAssignmentSaveData(const FName& InAssignmentUID,
                                                           const FAssignmentSaveData& InSaveData)
{
	auto* SaveGame = UProgressionSaveGame::GetOrCreateDefaultSave();
	SaveGame->AssignmentsSaveData.FindOrAdd(InAssignmentUID) = InSaveData;
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}

void UAssignmentsFunctionLibrary::HandleAssignmentCompleted(const FAssignmentData& AssignmentData)
{
	UProgressionSubsystem::Get()->UnlockMultipleContent(AssignmentData.ContentToUnlock);
}
