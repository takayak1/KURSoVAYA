// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEventsListener.h"

UGameEventsListener* UGameEventsListener::Get()
{
	return GWorld ? GWorld->GetGameInstance()->GetSubsystem<ThisClass>() : nullptr;
}
