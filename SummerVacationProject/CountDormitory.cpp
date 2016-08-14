#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountDormitoryProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_D_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//可住学生数
		vcl.pszText = L"可住学生数";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//在住学生数
		vcl.pszText = L"在住学生数";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//空床位数
		vcl.pszText = L"空床位数";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//入住率
		vcl.pszText = L"入住率";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_S_D_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}