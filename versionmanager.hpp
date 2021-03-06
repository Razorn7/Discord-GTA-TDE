/*
	File: versionmanager.hpp - Author: LemonHaze
	https://github.com/LemonHaze420/GTA-TDE-UE4-SDK/blob/master/VersionManager.hpp
*/

#include "pch.h"
#include "SDK.h"

#pragma once

enum class Version {
	INVALID,

	III_V01_00,
	III_V01_01,

	VC_V01_00,
	VC_V01_01,

	SA_V01_00,
	SA_V01_01
};

// San Andreas
#define SA_V01_00_VER_STRING	0x42CF760
#define SA_V01_00_OBJECTS		0x4EC81B0	
#define SA_V01_00_NAMES			0x5554200

#define SA_V01_01_VER_STRING	0x42D0940
#define SA_V01_01_OBJECTS		0x4ECBCB0	
#define SA_V01_01_NAMES			0x5555200	

// Vice City
#define VC_V01_00_VER_STRING	0x4090008
#define VC_V01_00_OBJECTS		0x4C6CA50
#define VC_V01_00_NAMES			0x526AB80

#define VC_V01_01_VER_STRING	0x4092AF0
#define VC_V01_01_OBJECTS		0x4C73E60	
#define VC_V01_01_NAMES			0x526FB80	

// III
#define III_V01_00_VER_STRING	0x40399E0
#define III_V01_00_OBJECTS		0x4C1DB40
#define III_V01_00_NAMES		0x520FD40

#define III_V01_01_VER_STRING	0x403A438
#define III_V01_01_OBJECTS		0x4C21360
#define III_V01_01_NAMES		0x5211D40

// ++UE4+Release-4.26-CL-0

Version getGameVersion() {
	Version theVersion = Version::INVALID;
	uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(NULL));
	if (base) {
		// SA
		if (!memcmp((void*)(base + SA_V01_00_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) { 
			theVersion = Version::SA_V01_00;
			printf("Detected version SA - V01.00\n");
		}
		else if (!memcmp((void*)(base + SA_V01_01_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) {
			theVersion = Version::SA_V01_01;
			printf("Detected version SA - V01.01\n");
		}
		// VC
		else if (!memcmp((void*)(base + VC_V01_00_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) {
			theVersion = Version::VC_V01_00;
			printf("Detected version VC - V01.00\n");
		}
		else if (!memcmp((void*)(base + VC_V01_01_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) {
			theVersion = Version::VC_V01_01;
			printf("Detected version VC - V01.01\n");
		}
		// III
		else if (!memcmp((void*)(base + III_V01_00_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) {
			theVersion = Version::III_V01_00;
			printf("Detected version III - V01.00\n");
		}
		else if (!memcmp((void*)(base + III_V01_01_VER_STRING), "\x2B\x00\x2B\x00\x55\x00\x45\x00", 8)) {
			theVersion = Version::III_V01_01;
			printf("Detected version III - V01.01\n");
		}
	}
	return theVersion;
}