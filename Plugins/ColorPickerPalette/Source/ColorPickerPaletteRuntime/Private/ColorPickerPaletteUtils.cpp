﻿// Copyright 2023 Yvidge. All Rights Reserved.


#include "ColorPickerPaletteUtils.h"

#include "ColorPaletteRuntimeTypes.h"
#include "ColorPickerPaletteDeveloperSettings.h"


bool UColorPickerPaletteUtils::IsLinearColorRegistered(const FLinearColor& Color)
{
	for (const auto& RegisteredPalette : GetRegisteredPalettes())
	{
		for (const FLinearColor& RegisteredColor : RegisteredPalette.Value.PaletteColors)
		{
			if(RegisteredColor == Color)
			{
				return true;
			}
		}
	}
	
	return false;
}

bool UColorPickerPaletteUtils::IsColorRegistered(const FColor& Color, bool bSRGB)
{
	for (const auto& RegisteredPalette : GetRegisteredPalettes())
	{
		for (const FLinearColor& RegisteredColor : RegisteredPalette.Value.PaletteColors)
		{
			if(RegisteredColor.ToFColor(bSRGB) == Color)
			{
				return true;
			}
		}
	}
	
	return false;
}

TMap<FName, FColorPalette> UColorPickerPaletteUtils::GetRegisteredPalettes()
{
	return UColorPickerPaletteDeveloperSettings::Get()->RegisteredPalettes;
}

FColorPalette UColorPickerPaletteUtils::GetColorPaletteByUID(const FName& PaletteUID)
{
	const auto& Palettes = UColorPickerPaletteDeveloperSettings::Get()->RegisteredPalettes;
	if (Palettes.Contains(PaletteUID))
	{
		return Palettes[PaletteUID];
	}
	return FColorPalette();
}

