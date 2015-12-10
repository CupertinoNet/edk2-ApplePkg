//
// Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
//
// This program and the accompanying materials have not been licensed.
// Neither is its usage, its redistribution, in source or binary form,
// licensed, nor implicitely or explicitely permitted, except when
// required by applicable law.
//
// Unless required by applicable law or agreed to in writing, software
// distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
// OR CONDITIONS OF ANY KIND, either express or implied.
//

///
/// @file      Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.c
///
///            
///
/// @author    Download-Fritz
/// @date      15/03/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#include <AppleEfi.h>

#include <EfiDriverLib.h>

#include <IndustryStandard/AppleHid.h>

#include <Protocol/AppleKeyMapAggregator.h>

#include <Library/AppleKeyMapAggregatorLib.h>

// mAppleKeyMapAggregator
APPLE_KEY_MAP_AGGREGATOR_PROTOCOL *mAppleKeyMapAggregator;

// GetAppleKeyStrokes
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
GetAppleKeyStrokes (
	OUT APPLE_MODIFIER_MAP  *Modifiers,
	OUT UINTN               *NoKeys,
	OUT APPLE_KEY           **Keys
	) // sub_1015
{
	EFI_STATUS Status;

	Status = EFI_UNSUPPORTED;

	if (mAppleKeyMapAggregator != NULL) {
		Status = EFI_INVALID_PARAMETER;

		if ((Modifiers != NULL) && (NoKeys != NULL) && (Keys != NULL)) {
			*NoKeys = 0;
			*Keys   = NULL;
			Status  = mAppleKeyMapAggregator->GetKeyStrokes (mAppleKeyMapAggregator, Modifiers, NoKeys, NULL);

			if (Status == EFI_BUFFER_TOO_SMALL) {
				if (*NoKeys == 0) {
					*Keys = NULL;
				} else {
					*Keys = (APPLE_KEY *)EfiLibAllocatePool (*NoKeys * sizeof (**Keys));

					if (*Keys == NULL) {
						*NoKeys = 0;
						Status  = EFI_OUT_OF_RESOURCES;
					} else {
						Status = mAppleKeyMapAggregator->GetKeyStrokes (mAppleKeyMapAggregator, Modifiers, NoKeys, *Keys);

						if (EFI_ERROR (Status)) {
							gBS->FreePool ((VOID *)*Keys);

							*Keys   = NULL;
							*NoKeys = 0;
						}
					}
				}
			}
		}
	}

	return Status;
}

// GetModifierStrokes
/// 
///
/// @param 
///
/// @return 
/// @retval 
APPLE_MODIFIER_MAP
GetModifierStrokes (
	VOID
	) // sub_FDA
{
	APPLE_MODIFIER_MAP Modifiers;

	EFI_STATUS         Status;
	UINTN              NoKeys;
	APPLE_KEY          *Keys;

	Status = GetAppleKeyStrokes (&Modifiers, &NoKeys, &Keys);

	if (!EFI_ERROR (Status)) {
		gBS->FreePool ((VOID *)Keys);
	} else {
		Modifiers = 0;
	}

	return Modifiers;
}