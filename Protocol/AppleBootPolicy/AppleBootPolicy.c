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
/// @file      Protocol/AppleBootPolicy/AppleBootPolicy.c
///
///            Apple protocol to get a volume's bootable file.
///
/// @author    Download-Fritz
/// @date      19/12/2014: Initial version
/// @date      23/02/2015: Minor tweaks
/// @date      15/03/2015: Updated documentation and restructuring
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#include <AppleEfi.h>

#include <Protocol/AppleBootPolicy.h>

// gAppleBootPolicyProtocolGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleBootPolicyProtocolGuid = APPLE_BOOT_POLICY_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleBootPolicyProtocolGuid, "Boot Policy", "Apple Boot Policy Protocol");