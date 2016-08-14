#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindBuildingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_D_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//宿舍楼号
		vcl.pszText = L"宿舍楼号";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//栋长姓名
		vcl.pszText = L"栋长姓名";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//值班员姓名
		vcl.pszText = L"值班员姓名";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//房间数
		vcl.pszText = L"房间数";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//床位数
		vcl.pszText = L"床位数";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//每床位年住宿费
		vcl.pszText = L"每床位年住宿费";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_F_D_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}