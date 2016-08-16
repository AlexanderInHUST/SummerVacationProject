#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountIncomeProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_I_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//Àﬁ…·¬•∫≈
		vcl.pszText = L"Àﬁ…·¬•∫≈";
		vcl.cx = 140;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//–’√˚
		vcl.pszText = L" ’»ÎΩ∂Ó";
		vcl.cx = 300;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_S_I_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}