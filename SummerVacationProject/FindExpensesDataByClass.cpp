#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindExpensesDataByClassProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_E_C_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//学号
		vcl.pszText = L"学号";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//姓名
		vcl.pszText = L"姓名";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//缴费日期
		vcl.pszText = L"缴费日期";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//缴费金额
		vcl.pszText = L"缴费金额";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//用途
		vcl.pszText = L"用途";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//收款人
		vcl.pszText = L"收款人";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_F_E_C_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}