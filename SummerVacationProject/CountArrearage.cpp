#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountArrearageProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_A_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//Ñ§ºÅ
		vcl.pszText = L"Ñ§ºÅ";
		vcl.cx = 140;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//ÐÕÃû
		vcl.pszText = L"ÐÕÃû";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//ËÞÉáÂ¥ºÅ
		vcl.pszText = L"ËÞÉáÂ¥ºÅ";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//Ç··Ñ½ð¶î
		vcl.pszText = L"Ç··Ñ½ð¶î";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_S_A_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}