#include "stdafx.h"
#include "SummerVacationProject.h"

// CountGenderProc��������
// ���ܣ����ƹ���ͳ������Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK CountIncomeProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_S_I_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//����¥��
		vcl.pszText = L"����¥��";
		vcl.cx = 140;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//����
		vcl.pszText = L"������";
		vcl.cx = 300;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);

		LVITEM vitem;
		vitem.mask = LVIF_TEXT;
		fillCountIncome(hListView, vitem);
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