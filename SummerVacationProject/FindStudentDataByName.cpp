#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindStudentDataByNameProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_S_N_LIST);
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//ѧ��
		vcl.pszText = L"ѧ��";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//����
		vcl.pszText = L"����";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//�Ա�
		vcl.pszText = L"�Ա�";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//��������
		vcl.pszText = L"��������";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//����
		vcl.pszText = L"����";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//ѧ��
		vcl.pszText = L"ѧ��";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);
		//��ѧ����
		vcl.pszText = L"��ѧ����";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 6, &vcl);
		//�༶
		vcl.pszText = L"�༶";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 7, &vcl);
		//����¥��
		vcl.pszText = L"����¥��";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 8, &vcl);
		//�����
		vcl.pszText = L"�����";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 9, &vcl);
		//��ϵ�绰
		vcl.pszText = L"��ϵ�绰";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 10, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_F_S_N_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}