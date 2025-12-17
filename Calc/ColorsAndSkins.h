#pragma once
#include <Windows.h>

CONST CHAR g_sz_WINDOW_CLASS[] = "Calc PV_521";

CONST INT g_i_WINDOW_COLOR = 0;
CONST INT g_i_DISPLAY_COLOR = 1;
CONST INT g_i_FONT_COLOR = 2;
CONST COLORREF g_clr_COLORS[3][3] =
{
	{RGB(160, 180, 200), RGB(100, 120, 140), RGB(168, 60, 9)},
	{RGB(0, 0, 150), RGB(0, 0, 100), RGB(255, 0, 0)},
	{RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0)}
};
CONST CHAR* g_sz_SKIN[] = { "Metal_mistral", "Square_blue", "Mu_button"};