#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountClassProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_C_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//班级
		vcl.pszText = L"班级";
		vcl.cx = 140;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//学生人数
		vcl.pszText = L"学生人数";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//欠费人数
		vcl.pszText = L"欠费人数";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);

		LVITEM vitem;
		vitem.mask = LVIF_TEXT;
		vitem.iItem = 0;
		fillCountClass(hListView, vitem);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_S_C_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}