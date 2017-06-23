/** @file
  Copyright (c) 2005 - 2017, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2017, CupertinoNet.  All rights reserved.<BR>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
**/

#ifndef APPLE_SMBIOS_H_
#define APPLE_SMBIOS_H_

#include <IndustryStandard/SmBios.h>

#pragma pack (1)

#define APPLE_SMBIOS_TYPE_FIRMWARE_INFORMATION  128

#define APPLE_NUMBER_OF_FIRMWARE_VOLUMES  8

enum {
  AppleFvTypeConventional = 0,
  AppleFvTypeRecovery     = 1,
  AppleFvTypeMain         = 2,
  AppleFvTypeNvStorage    = 3
};

// APPLE_FIRMWARE_VOLUME_MAP
typedef PACKED struct {
  UINT32 BaseAddress;
  UINT32 TopAddress;
} APPLE_FIRMWARE_VOLUME_MAP;

// APPLE_SMBIOS_TABLE_TYPE128
typedef PACKED struct {
  EFI_SMBIOS_TABLE_HEADER   Header;
  UINT8                     NumberOfFirmwareVolumes;
  UINT8                     Reserved[3];
  UINT32                    FirmwareFeatures;
  UINT32                    FirmwareFeaturesMask;
  UINT8                     FrimwareVolumeTypeMap[APPLE_NUMBER_OF_FIRMWARE_VOLUMES];
  APPLE_FIRMWARE_VOLUME_MAP FirmwareVolumes[APPLE_NUMBER_OF_FIRMWARE_VOLUMES];
  UINT32                    ExtendedFirmwareFeatures;
  UINT32                    ExtendedFirmwareFeaturesMask;
} APPLE_SMBIOS_TABLE_TYPE128;

// APPLE_SMBIOS_STRUCTURE_POINTER
typedef PACKED union {
  SMBIOS_STRUCTURE           *Hdr;
  SMBIOS_TABLE_TYPE0         *Type0;
  SMBIOS_TABLE_TYPE1         *Type1;
  SMBIOS_TABLE_TYPE2         *Type2;
  SMBIOS_TABLE_TYPE3         *Type3;
  SMBIOS_TABLE_TYPE4         *Type4;
  SMBIOS_TABLE_TYPE5         *Type5;
  SMBIOS_TABLE_TYPE6         *Type6;
  SMBIOS_TABLE_TYPE7         *Type7;
  SMBIOS_TABLE_TYPE8         *Type8;
  SMBIOS_TABLE_TYPE9         *Type9;
  SMBIOS_TABLE_TYPE10        *Type10;
  SMBIOS_TABLE_TYPE11        *Type11;
  SMBIOS_TABLE_TYPE12        *Type12;
  SMBIOS_TABLE_TYPE13        *Type13;
  SMBIOS_TABLE_TYPE14        *Type14;
  SMBIOS_TABLE_TYPE15        *Type15;
  SMBIOS_TABLE_TYPE16        *Type16;
  SMBIOS_TABLE_TYPE17        *Type17;
  SMBIOS_TABLE_TYPE18        *Type18;
  SMBIOS_TABLE_TYPE19        *Type19;
  SMBIOS_TABLE_TYPE20        *Type20;
  SMBIOS_TABLE_TYPE21        *Type21;
  SMBIOS_TABLE_TYPE22        *Type22;
  SMBIOS_TABLE_TYPE23        *Type23;
  SMBIOS_TABLE_TYPE24        *Type24;
  SMBIOS_TABLE_TYPE25        *Type25;
  SMBIOS_TABLE_TYPE26        *Type26;
  SMBIOS_TABLE_TYPE27        *Type27;
  SMBIOS_TABLE_TYPE28        *Type28;
  SMBIOS_TABLE_TYPE29        *Type29;
  SMBIOS_TABLE_TYPE30        *Type30;
  SMBIOS_TABLE_TYPE31        *Type31;
  SMBIOS_TABLE_TYPE32        *Type32;
  SMBIOS_TABLE_TYPE33        *Type33;
  SMBIOS_TABLE_TYPE34        *Type34;
  SMBIOS_TABLE_TYPE35        *Type35;
  SMBIOS_TABLE_TYPE36        *Type36;
  SMBIOS_TABLE_TYPE37        *Type37;
  SMBIOS_TABLE_TYPE38        *Type38;
  SMBIOS_TABLE_TYPE39        *Type39;
  SMBIOS_TABLE_TYPE40        *Type40;
  SMBIOS_TABLE_TYPE41        *Type41;
  SMBIOS_TABLE_TYPE42        *Type42;
  SMBIOS_TABLE_TYPE43        *Type43;
  SMBIOS_TABLE_TYPE126       *Type126;
  SMBIOS_TABLE_TYPE127       *Type127;
  APPLE_SMBIOS_TABLE_TYPE128 *Type128;
  UINT8                      *Raw;
} APPLE_SMBIOS_STRUCTURE_POINTER;

#pragma pack ()

#endif // APPLE_SMBIOS_H_