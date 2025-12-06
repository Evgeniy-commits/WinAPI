//#define _CRT_SECURE_NO_WARNINGS
//#include <Windows.h>
//#include "resource.h"
//#include <string>
//#include <sstream>
//
//CONST CHAR g_sz_WINDOW_CLASS[] = "Calc PV_521";
//
//CONST INT g_i_BUTTON_SIZE = 50;
//CONST INT g_i_INTERVAL = 1;
//CONST INT g_i_DOUBLE_BUTTON_SIZE = g_i_BUTTON_SIZE * 2 + g_i_INTERVAL;
//CONST INT g_i_DISPLAY_WIDTH = g_i_BUTTON_SIZE * 5 + g_i_INTERVAL * 4;
//CONST INT g_i_DISPLAY_HEIGHT = 22;
//CONST INT g_i_START_X = 10;
//CONST INT g_i_START_Y = 10;
//CONST INT g_i_BUTTON_START_X = g_i_START_X;
//CONST INT g_i_BUTTON_START_Y = g_i_START_Y + g_i_DISPLAY_HEIGHT + g_i_INTERVAL;
//
//CONST INT g_i_WINDOW_WIDTH = g_i_DISPLAY_WIDTH + g_i_START_X * 2 + 16;
//CONST INT g_i_WINDOW_HEIGHT = g_i_DISPLAY_HEIGHT + g_i_START_Y + (g_i_INTERVAL + g_i_BUTTON_SIZE) * 4 + 48;
//
//#define X_BUTTON_POSITION(position) g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * (position) 
//#define Y_BUTTON_POSITION(position) g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * (position)
//
//CONST CHAR g_OPERATIONS[] = "+-*/";
//
////HINSTANCE hInstance;
//HWND hDisplay;
//DOUBLE numFirst = 0.0;
//DOUBLE numSecond = 0.0;
//CHAR operation = 0;
//BOOL numNew = true;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//void digitAdd(int digit);
//void operationSet(char op);
//void Calculate();
//void Clear();
//
//INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
//{
//	//1)Регистрация класса окна:
//	WNDCLASSEX wClass;
//	ZeroMemory(&wClass, sizeof(wClass));
//
//	wClass.style = 0;
//	wClass.cbSize = sizeof(wClass);
//	wClass.cbClsExtra = 0;
//	wClass.cbWndExtra = 0;
//
//	wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//
//	wClass.hInstance = hInstance;
//	wClass.lpszMenuName = NULL;
//	wClass.lpfnWndProc = WndProc;
//	wClass.lpszClassName = g_sz_WINDOW_CLASS;
//
//	if (RegisterClassEx(&wClass) == NULL)
//	{
//		MessageBox(NULL, "Класс не зарегистрирован", NULL, MB_OK | MB_ICONERROR);
//		return 0;
//	}
//	//2)Создание окна:
//
//	HWND hwnd = CreateWindowEx
//	(
//		NULL,
//		g_sz_WINDOW_CLASS,
//		g_sz_WINDOW_CLASS,
//		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
//		//WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		g_i_WINDOW_WIDTH, g_i_WINDOW_HEIGHT,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//	);
//	if (hwnd == NULL)
//	{
//		MessageBox(NULL, "Window Creation failed", NULL, MB_OK | MB_ICONERROR);
//		return 0;
//	}
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//
//	//3)Запуск цикла сообщений:
//
//	MSG msg = {};
//	while (GetMessage(&msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return (int)msg.wParam;
//
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_CREATE:
//	{
//		hDisplay = CreateWindowEx
//		(
//			NULL,
//			"Edit",
//			"",
//			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
//			10, 10,
//			g_i_DISPLAY_WIDTH, g_i_DISPLAY_HEIGHT,
//			hwnd,
//			(HMENU)IDC_DISPLAY,
//			GetModuleHandle(NULL),
//			NULL
//		);
//
//		CHAR sz_button[2] = {};
//		for (int i = 6; i >= 0; i -= 3)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				sz_button[0] = i + j + '1';
//				CreateWindowEx
//				(
//					NULL, "Button", sz_button,
//					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//					X_BUTTON_POSITION(j), Y_BUTTON_POSITION(2 - i / 3),
//					/*g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * j,
//					g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * (2 - i / 3),*/
//					g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
//					hwnd,
//					HMENU(IDC_BUTTON_1 + i + j),
//					GetModuleHandle(NULL),
//					NULL
//				);
//			}
//		}
//		CreateWindowEx
//		(
//			NULL, "Button", "0",
//			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//			X_BUTTON_POSITION(0), Y_BUTTON_POSITION(3),
//			/*g_i_BUTTON_START_X, g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 3,*/
//			g_i_DOUBLE_BUTTON_SIZE, g_i_BUTTON_SIZE,
//			hwnd,
//			(HMENU)IDC_BUTTON_0,
//			GetModuleHandle(NULL),
//			NULL
//		);
//		CreateWindowEx
//		(
//			NULL, "Button", ".",
//			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//			X_BUTTON_POSITION(2), Y_BUTTON_POSITION(3),
//			/*g_i_BUTTON_START_X + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 2,
//			g_i_BUTTON_START_Y + (g_i_BUTTON_SIZE + g_i_INTERVAL) * 3,*/
//			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
//			hwnd,
//			(HMENU)IDC_BUTTON_POINT,
//			GetModuleHandle(NULL),
//			NULL
//		);
//
//		CHAR sz_operations[2] = "";
//		for (int i = 0; i < 4; i++)
//		{
//			sz_operations[0] = g_OPERATIONS[i];
//			CreateWindowEx
//			(
//				NULL, "Button", sz_operations,
//				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//				X_BUTTON_POSITION(3), Y_BUTTON_POSITION(3 - i),
//				g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
//				hwnd,
//				HMENU(IDC_BUTTON_PLUS + i),
//				GetModuleHandle(NULL),
//				NULL
//			);
//		}
//
//		CreateWindowEx
//		(
//			NULL, "Button", "<-",
//			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//			X_BUTTON_POSITION(4), Y_BUTTON_POSITION(0),
//			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
//			hwnd,
//			(HMENU)IDC_BUTTON_BSP,
//			GetModuleHandle(NULL),
//			NULL
//		);
//
//		CreateWindowEx
//		(
//			NULL, "Button", "C",
//			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//			X_BUTTON_POSITION(4), Y_BUTTON_POSITION(1),
//			g_i_BUTTON_SIZE, g_i_BUTTON_SIZE,
//			hwnd,
//			(HMENU)IDC_BUTTON_CLR,
//			GetModuleHandle(NULL),
//			NULL
//		);
//
//		CreateWindowEx
//		(
//			NULL, "Button", "=",
//			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//			X_BUTTON_POSITION(4), Y_BUTTON_POSITION(2),
//			g_i_BUTTON_SIZE, g_i_DOUBLE_BUTTON_SIZE,
//			hwnd,
//			(HMENU)IDC_BUTTON_EQUAL,
//			GetModuleHandle(NULL),
//			NULL
//		);
//		return 0;
//	}
//	break;
//	case WM_COMMAND:
//	{
//		INT wmID = LOWORD(wParam);
//		switch (wmID)
//		{
//			case IDC_BUTTON_0: digitAdd(0); break;
//			case IDC_BUTTON_1: digitAdd(1); break;
//			case IDC_BUTTON_2: digitAdd(2); break;
//			case IDC_BUTTON_3: digitAdd(3); break;
//			case IDC_BUTTON_4: digitAdd(4); break;
//			case IDC_BUTTON_5: digitAdd(5); break;
//			case IDC_BUTTON_6: digitAdd(6); break;
//			case IDC_BUTTON_7: digitAdd(7); break;
//			case IDC_BUTTON_8: digitAdd(8); break;
//			case IDC_BUTTON_9: digitAdd(9); break;
//
//			case IDC_BUTTON_POINT: digitAdd('.'); break;
//			case IDC_BUTTON_PLUS:  operationSet('+'); break;
//			case IDC_BUTTON_MINUS: operationSet('-'); break;
//			case IDC_BUTTON_ASTER: operationSet('*'); break;
//			case IDC_BUTTON_SLASH: operationSet('/'); break;
//
//			case IDC_BUTTON_EQUAL: Calculate(); break;
//			case IDC_BUTTON_CLR: Clear(); break;
//		}
//			break;
//	}
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
//	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
//	}
//	return 0;
//}
//
//void digitAdd(int digit)
//{
//	if (numNew)
//	{
//		SetWindowText(hDisplay, "");
//		numNew = false;
//		CHAR buffer[256] = "";
//		GetWindowText(hDisplay, buffer, 256);
//
//		std::stringstream ss;
//		ss << buffer << digit;
//		SetWindowText(hDisplay, ss.str().c_str());
//	}
//}
//
//void operationSet(char op)
//{
//	operation = op;
//	CHAR text[256];
//	GetWindowText(hDisplay, text, 256);
//	numFirst = std::stod(std::string(text));
//
//	numNew = true;
//
//	CHAR operStr[2] = { op, '\0' };
//	SetWindowText(hDisplay, operStr);
//
//}
//
//void Calculate()
//{
//	CHAR text[256];
//	GetWindowText(hDisplay, text, 256);
//	numSecond = std::stod(std::string(text));
//
//	DOUBLE result = 0.0;
//
//	switch (operation)
//	{
//	case '+': result = numFirst + numSecond; break;
//	case '-': result = numFirst - numSecond; break;
//	case '*': result = numFirst * numSecond; break;
//	case '/':
//		if (numSecond != 0.0)
//		{
//			result = numFirst / numSecond;
//		}
//		else
//		{
//			SetWindowText(hDisplay, "Error");
//			return;
//		}
//		break;
//	default: result = numFirst; break;
//	}
//
//	std::stringstream ss;
//	ss << result;
//	SetWindowText(hDisplay, ss.str().c_str());
//
//	numNew = true;
//	operation = 0;
//}
//
//void Clear()
//{
//	numFirst = 0.0;
//	numSecond = 0.0;
//	operation = 0;
//	numNew = true;
//	SetWindowText(hDisplay, "0");
//}