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
/// @file      Protocol/AppleKeyMapAggregator/AppleKeyMapAggregator.c
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

// gAppleKeyMapAggregatorProtocolGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleKeyMapAggregatorProtocolGuid = APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleKeyMapAggregatorProtocolGuid, "Key Map Aggregator", "Apple Key Map Aggregator Protocol");