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
/// @file      Include/Protocol/AppleBootPolicy.h
///
///            Apple protocol to get a volume's bootable file.
///
/// @author    Download-Fritz
/// @date      19/12/2014: Initial version
/// @date      23/02/2015: Minor tweaks
/// @date      15/03/2015: Updated documentation and restructuring
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_BOOT_POLICY_H__
#define __APPLE_BOOT_POLICY_H__

// APPLE_BOOT_POLICY_PROTOCOL_GUID
/// The GUID of the APPLE_BOOT_POLICY_PROTOCOL.
#define APPLE_BOOT_POLICY_PROTOCOL_GUID \
  { 0x62257758, 0x350C, 0x4D0A, { 0xB0, 0xBD, 0xF6, 0xBE, 0x2E, 0x1E, 0x27, 0x2C } }

// BOOT_POLICY_GET_BOOT_FILE
/// Locates the bootable file of the given volume. Prefered are the values blessed,
/// though if unavailable, hard-coded names are being verified and used if existing.
///
/// The blessed paths are to be determined by the HFS Driver via EFI_FILE_PROTOCOL.GetInfo().
/// The related identifier definitions are to be found in AppleBless.h.
///
/// @param[in]  Device       The Device's Handle to perform the search on.
/// @param[out] BootFilePath A pointer to the device path pointer to set to the file path of the boot file.
///
/// @return                      The status of the operation is returned.
/// @retval EFI_NOT_FOUND        A bootable file could not be found on the given volume.
/// @retval EFI_OUT_OF_RESOURCES The memory necessary to complete the operation could not be allocated.
/// @retval EFI_SUCCESS          The operation completed successfully and the BootFilePath buffer has been filled.
/// @retval other                The status of an operation used to complete this operation is returned.
typedef
EFI_STATUS
(EFIAPI *BOOT_POLICY_GET_BOOT_FILE)(
  IN  EFI_HANDLE            Device,
  OUT FILEPATH_DEVICE_PATH  **BootFilePath
  );

// _APPLE_BOOT_POLICY_PROTOCOL
/// The structure exposed by the APPLE_BOOT_POLICY_PROTOCOL.
typedef struct _APPLE_BOOT_POLICY_PROTOCOL {
  UINTN                     Revision;     ///< The revision of the installed protocol.
  BOOT_POLICY_GET_BOOT_FILE GetBootFile;  ///< A pointer to the function that locates the bootable file of the volume.
} APPLE_BOOT_POLICY_PROTOCOL;

// gAppleBootPolicyProtocolGuid
/// A global variable storing the GUID of the APPLE_BOOT_POLICY_PROTOCOL.
extern EFI_GUID gAppleBootPolicyProtocolGuid;

#endif // ifndef __APPLE_BOOT_POLICY_H__