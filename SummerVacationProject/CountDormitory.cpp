#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountDormitoryProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_D_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//��סѧ����
		vcl.pszText = L"��סѧ����";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//��סѧ����
		vcl.pszText = L"��סѧ����";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//�մ�λ��
		vcl.pszText = L"�մ�λ��";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//��ס��
		vcl.pszText = L"��ס��";
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