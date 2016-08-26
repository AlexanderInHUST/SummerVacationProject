#include "stdafx.h"
#include "SummerVacationProject.h"

// CountArrearageProc��������
// ���ܣ����ƹ���ͳ��Ƿ��ѧ���Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK CountArrearageProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_A_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
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

		LVITEM vitem;
		vitem.mask = LVIF_TEXT;
		vitem.iItem = 0;
		if (fillCountArrearage(hListView, vitem) == 0){
			MessageBox(hDlg, L"û���κ�Ƿ����Ϣ", L"��ʾ", MB_OK);
		}
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