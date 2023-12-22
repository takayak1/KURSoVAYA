﻿// Copyright 2023 Yvidge. All Rights Reserved.


#include "ColorPickerPaletteUserSettings.h"

#include "ColorPickerPaletteDeveloperSettings.h"

const UColorPickerPaletteUserSettings* UColorPickerPaletteUserSettings::Get()
{
	return GetDefault<UColorPickerPaletteUserSettings>();
}

UColorPickerPaletteUserSettings* UColorPickerPaletteUserSettings::GetMutable()
{
	return GetMutableDefault<UColorPickerPaletteUserSettings>();
}

void UColorPickerPaletteUserSettings::PostCDOContruct()
{
	Super::PostCDOContruct();

	RegenerateUserData();

	GetMutableDefault<UColorPickerPaletteDeveloperSettings>()->OnSettingChanged().AddWeakLambda(this, [this](UObject*, FPropertyChangedEvent&)
	{
		RegenerateUserData();
	});
}

void UColorPickerPaletteUserSettings::RegenerateUserData()
{
	const auto& RegisteredPalettes = UColorPickerPaletteDeveloperSettings::Get()->RegisteredPalettes;
	
	for (auto& UserData : PalettesUserData)
	{
		if(!RegisteredPalettes.Contains(UserData.Key))
		{
			PalettesUserData.Remove(UserData.Key);
		}
	}
	
	for (const auto& Palette : RegisteredPalettes)
	{
		if(!PalettesUserData.Contains(Palette.Key))
		{
			PalettesUserData.Add(Palette.Key);
		}
	}

	SaveConfig();
}

bool UColorPickerPaletteUserSettings::AreColorWarningsEnabled() const
{
	return bEnableColorWarnings;
}

bool UColorPickerPaletteUserSettings::IsColorInWhitelist(const FLinearColor& Color) const
{
	for (const FLinearColor& RegisteredColor : ColorWhitelist)
	{
		if(RegisteredColor == Color)
		{
			return true;
		}
	}
	return false;
}

bool UColorPickerPaletteUserSettings::IsColorInWhitelist(const FColor& Color, bool bSRGB) const
{
	for (const FLinearColor& RegisteredColor : ColorWhitelist)
	{
		if(RegisteredColor.ToFColor(bSRGB) == Color)
		{
			return true;
		}
	}
	return false;
}

const FColorPickerPaletteUserData& UColorPickerPaletteUserSettings::GetPaletteUserData(const FName& PaletteUID) const
{
	return PalettesUserData[PaletteUID];
}

void UColorPickerPaletteUserSettings::SaveConfig()
{
	TryUpdateDefaultConfigFile(GEditorPerProjectIni);
}
