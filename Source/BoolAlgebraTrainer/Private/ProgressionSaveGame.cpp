// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressionSaveGame.h"

#include "GameEventsListener.h"
#include "Kismet/GameplayStatics.h"


UProgressionSaveGame* UProgressionSaveGame::GetOrCreateDefaultSave()
{
	USaveGame* SaveGame = UGameplayStatics::LoadGameFromSlot(TEXT("Default"), 0);
	
	if (!SaveGame)
	{
		SaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
		UGameplayStatics::SaveGameToSlot(SaveGame, TEXT("Default"), 0);
	}
	
	return Cast<UProgressionSaveGame>(SaveGame);
}

void UProgressionSaveGame::SaveToDefaultSlot(USaveGame* SaveGame)
{
	UGameplayStatics::SaveGameToSlot(SaveGame, TEXT("Default"), 0);
}

void UProgressionSaveGame::SetEnableUISound(bool bEnable)
{
	bEnableUISound = bEnable;
	SaveToDefaultSlot(this);
	UGameEventsListener::Get()->OnEnableUISound.Broadcast(bEnable);
}

void UProgressionSaveGame::SetEnableMusic(bool bEnable)
{
	bEnableMusic = bEnable;
	SaveToDefaultSlot(this);
	UGameEventsListener::Get()->OnEnableMusic.Broadcast(bEnable);
}
