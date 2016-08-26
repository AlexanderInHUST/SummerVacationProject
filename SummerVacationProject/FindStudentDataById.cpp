#include "stdafx.h"
#include "SummerVacationProject.h"

// FindStudentDataByIdProc��������
// ���ܣ����ƹ��ڸ���ѧ�Ų�ѯѧ���Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK FindStudentDataByIdProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_S_I_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	struct Building *head = getHead();
	struct Student *student;
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
		case IDC_F_S_I_SERACH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_S_I_EDIT);
			int count = 0;
			char *idInfoString;
			idInfoString = getDataFromEditBox(editBox, 13);
			if (strlen(idInfoString) == 0){
				MessageBox(hDlg, L"����������ѯ��ѧ��", L"��ʾ", MB_OK);
			}
			else{
				student = queryStudentById(idInfoString, head);
				if (student == NULL){
					MessageBox(hDlg, L"û����Ӧ��ѧ����Ϣ", L"��ʾ", MB_OK);
				}
				else{
					LVITEM vitem;
					vitem.mask = LVIF_TEXT;
					vitem.iItem = 0;
					fillStudentList(hListView, vitem, student, 0);
				}
			}
			break;
		}
		case IDC_F_S_I_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}