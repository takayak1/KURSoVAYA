// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PrimaryGameLayout.h"
#include "CommonActivatableWidget.h"


UCommonActivatableWidget* UPrimaryGameLayout::PushWidgetToLayer(TSubclassOf<UCommonActivatableWidget> WidgetClass, EWidgetLayoutLayer Layer)
{
	if (!WidgetClass) return nullptr;

	UCommonActivatableWidgetStack* TargetStack;

	switch (Layer)
	{
	case Game: TargetStack = GameLayerStack; break;
	case Menu: TargetStack = MenuLayerStack; break;
	case Modal: TargetStack = ModalLayerStack; break;
	default: return nullptr;
	}

	return TargetStack->AddWidget(WidgetClass);


}

void UPrimaryGameLayout::RemoveWidgetFromLayer(UCommonActivatableWidget* ActivatableWidget)
{
	GameLayerStack->RemoveWidget(*ActivatableWidget);
	MenuLayerStack->RemoveWidget(*ActivatableWidget);
	ModalLayerStack->RemoveWidget(*ActivatableWidget);
}
