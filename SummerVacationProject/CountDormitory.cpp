#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK CountDormitoryProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_D_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//����¥��
		vcl.pszText = L"����¥��";
		vcl.cx = 110;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//��סѧ����
		vcl.pszText = L"��סѧ����";
		vcl.cx = 110;
		vcl.iSubItem = 1;
		ListView_InsertColumn(hListView, 1, &vcl);
		//��סѧ����
		vcl.pszText = L"��סѧ����";
		vcl.cx = 110;
		vcl.iSubItem = 2;
		ListView_InsertColumn(hListView, 2, &vcl);
		//�մ�λ��
		vcl.pszText = L"�մ�λ��";
		vcl.cx = 110;
		vcl.iSubItem = 3;
		ListView_InsertColumn(hListView, 3, &vcl);
		//��ס��
		vcl.pszText = L"��ס�ٷֱ�";
		vcl.cx = 110;
		vcl.iSubItem = 4;
		ListView_InsertColumn(hListView, 4, &vcl);

		LVITEM vitem;
		vitem.mask = LVIF_TEXT;
		vitem.iItem = 0;
		fillCountDormitory(hListView, vitem);
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