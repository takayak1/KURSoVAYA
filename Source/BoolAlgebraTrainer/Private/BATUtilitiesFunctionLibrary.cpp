// Fill out your copyright notice in the Description page of Project Settings.


#include "BATUtilitiesFunctionLibrary.h"

#include "ProgressionSaveGame.h"

UProgressionSaveGame* UBATUtilitiesFunctionLibrary::GetDefaultSave()
{
	return UProgressionSaveGame::GetOrCreateDefaultSave();
}

void UBATUtilitiesFunctionLibrary::SaveToDefaultSlot(USaveGame* SaveGame)
{
	UProgressionSaveGame::SaveToDefaultSlot(SaveGame);
}
