#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountGenderProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_G_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//���
		vcl.pszText = L"ѧ������";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//����
		vcl.pszText = L"������ռ����";
		vcl.cx = 170;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//Ů��
		vcl.pszText = L"Ů����ռ����";
		vcl.cx = 170;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_S_G_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}