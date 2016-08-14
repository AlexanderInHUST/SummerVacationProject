#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountArrearageProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_A_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//ѧ��
		vcl.pszText = L"ѧ��";
		vcl.cx = 140;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//����
		vcl.pszText = L"����";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//����¥��
		vcl.pszText = L"����¥��";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//Ƿ�ѽ��
		vcl.pszText = L"Ƿ�ѽ��";
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