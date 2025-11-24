#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <json/json.h>
#include <Windows.h>
#include "mtg.h"

using namespace std;

#ifndef MAP_HEIGHT
#define MAP_HEIGHT 25 
#define MAP_WIDTH 80

// CMD 색깔
enum E_CMDColor
{
	Black,
	Blue,
	Green,
	Teal, // 청록색
	Red,
	Purple,
	Yellow,
	White,
	Gray,
	BrightBlue,
	BrightGreen,
	BrightTeal,
	BrightRed,
	BrightPurple,
	BrightYellow,
	BrightWhite,
};
#endif