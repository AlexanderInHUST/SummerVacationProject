// SummerVacationProject.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SummerVacationProject.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

struct Building *head;

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SUMMERVACATIONPROJECT, szWindowClass, MAX_LOADSTRING);
	head = createBuildingData("head", "head", "head", -1, -1, -1, NULL, NULL, 0);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SUMMERVACATIONPROJECT));

	// ����Ϣѭ��: 
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
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
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
			break;
		}
		case IDM_L_S:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_S), hWnd, LookAtStudentDataProc);
			break;
		}
		case IDM_L_F:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_E), hWnd, LookAtExpensesDataProc);
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
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
		DrawText(ps.hdc, L"haiya", -1, &(ps.rcPaint), DT_CENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������

