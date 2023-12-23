// Fill out your copyright notice in the Description page of Project Settings.


#include "Progression/ProgressionSubsystem.h"

#include "ISettingsModule.h"
#include "ProgressionSaveGame.h"
#include "Kismet/GameplayStatics.h"

UProgressionSubsystem* UProgressionSubsystem::Get()
{
	return UGameplayStatics::GetGameInstance(GWorld)->GetSubsystem<ThisClass>();
}

UProgressionSubsystem::UProgressionSubsystem()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings")))
	{
		SettingsModule->RegisterSettings("Project", "Game", "ProgressionConfig",
			FText::FromString("Progression Config"),
			FText::FromString(""),
			GetMutableDefault<ThisClass>());
	}
}

void UProgressionSubsystem::InitializeUnlockedContent()
{
	auto* SaveGame = UProgressionSaveGame::GetOrCreateDefaultSave();
	SaveGame->UnlockedContent.Append(ContentToUnlockOnStart);
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}

bool UProgressionSubsystem::IsContentUnlocked(const FName& InContentUID)
{
	return UProgressionSaveGame::GetOrCreateDefaultSave()->UnlockedContent.Contains(InContentUID);
}

void UProgressionSubsystem::UnlockContent(const FName& InContentUID)
{
	auto* SaveGame = UProgressionSaveGame::GetOrCreateDefaultSave();
	SaveGame->UnlockedContent.Add(InContentUID);
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}

void UProgressionSubsystem::UnlockMultipleContent(const TArray<FName>& InContentUIDs)
{
	auto* SaveGame = UProgressionSaveGame::GetOrCreateDefaultSave();
	SaveGame->UnlockedContent.Append(InContentUIDs);
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}

void UProgressionSubsystem::LockContent(const FName& InContentUID)
{
	auto* SaveGame = UProgressionSaveGame::GetOrCreateDefaultSave();
	SaveGame->UnlockedContent.Remove(InContentUID);
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}
