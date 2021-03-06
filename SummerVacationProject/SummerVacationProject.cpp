// SummerVacationProject.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "SummerVacationProject.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
BITMAP bminfo;
HBITMAP hbm;
bool save = true;

struct Building *head;

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


//作为其他函数获得head的唯一方法
struct Building* getHead(){
	return head;
}

void setSave(){
	save = false;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;


	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SUMMERVACATIONPROJECT, szWindowClass, MAX_LOADSTRING);
	initialID();
	hbm = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP));
	GetObject(hbm, sizeof(bminfo), &bminfo);
	head = createBuildingData("head", "head", "head", -1, -1, -1, NULL, NULL, 0);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SUMMERVACATIONPROJECT));
	head = loadAllData();

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;


	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SUMMERVACATIONPROJECT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SUMMERVACATIONPROJECT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,
      CW_USEDEFAULT, 0, bminfo.bmWidth + 20, bminfo.bmHeight + 81, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_EXIT:{
			if (!save){
				int exitChoice = MessageBox(hWnd, L"是否保存修改", L"提示", MB_YESNOCANCEL);
				switch (exitChoice){
				case IDYES:{
					saveAllData(head);
				}
				case IDNO:{
					PostQuitMessage(0);
					break;
				}
				case IDCANCEL:{
					break;
				}
				}
			}
			else{
				PostQuitMessage(0);
			}
			break;
		}
		case IDM_SAVE:{
			saveAllData(head);
			MessageBox(hWnd, L"保存成功", L"提示", MB_OK);
			save = true;
			break;
		}
		case IDM_ABOUT:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		}
		case IDM_F_D:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_F_D), hWnd, FindBuildingDataProc);
			break;
		}
		case IDM_F_FC:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_F_E_C), hWnd, FindExpensesDataByClassProc);
			break;
		}
		case IDM_F_FI:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_F_E_I), hWnd, FindExpensesDataByIdProc);
			break;
		}
		case IDM_F_SI:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_F_S_I), hWnd, FindStudentDataByIdProc);
			break;
		}
		case IDM_F_SN:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_F_S_N), hWnd, FindStudentDataByNameProc);
			break;
		}
		case IDM_L_D:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_D), hWnd, LookAtBuildingDataProc);
			save = false;
			break;
		}
		case IDM_L_S:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_S), hWnd, LookAtStudentDataProc);
			save = false;
			break;
		}
		case IDM_L_F:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_E), hWnd, LookAtExpensesDataProc);
			save = false;
			break;
		}
		case IDM_S_A:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_S_A), hWnd, CountArrearageProc);
			break;
		}
		case IDM_S_D:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_S_D), hWnd, CountDormitoryProc);
			break;
		}
		case IDM_S_G:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_S_G), hWnd, CountGenderProc);
			break;
		}
		case IDM_S_I:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_S_I), hWnd, CountIncomeProc);
			break;
		}
		case IDM_S_C:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_S_C), hWnd, CountClassProc);
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:{
		hdc = BeginPaint(hWnd, &ps);
		HDC memdc = CreateCompatibleDC(hdc);
		SelectObject(memdc, hbm);
		BitBlt(hdc, 0, 0, bminfo.bmWidth, bminfo.bmHeight, memdc, 0, 0, SRCCOPY);
		DeleteDC(memdc);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_CLOSE:
		if (!save){
			int exitChoice = MessageBox(hWnd, L"是否保存修改", L"提示", MB_YESNOCANCEL);
			switch (exitChoice){
			case IDYES:{
				saveAllData(head);
			}
			case IDNO:{
				PostQuitMessage(0);
				break;
			}
			case IDCANCEL:{
				break;
			}
			}
		}
		else{
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


