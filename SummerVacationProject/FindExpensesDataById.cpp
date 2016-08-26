#include "stdafx.h"
#include "SummerVacationProject.h"

// FindExpensesDataByIdProc��������
// ���ܣ����ƹ��ڸ���ѧ�Ų�ѯ�ɷѶԻ��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK FindExpensesDataByIdProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Student *student;
	struct Expenses *expenses;
	HWND hListView = GetDlgItem(hDlg, IDC_F_E_I_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
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
		//�ɷ�����
		vcl.pszText = L"�ɷ�����";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//�ɷѽ��
		vcl.pszText = L"�ɷѽ��";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//��;
		vcl.pszText = L"��;";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//�տ���
		vcl.pszText = L"�տ���";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_F_E_I_SERACH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_E_I_EDIT);
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
					expenses = student->firstExpenses;
					while (expenses->nextExpenses != NULL){
						expenses = expenses->nextExpenses;
						LVITEM vitem;
						vitem.mask = LVIF_TEXT;
						vitem.iItem = count;
						fillExpensesList(hListView, vitem, expenses, count++);
					}
					if (expenses->rec == student->firstExpensesRec){
						MessageBox(hDlg, L"û�и�ѧ���Ľɷ���Ϣ", L"��ʾ", MB_OK);
					}
				}
			}
			break;
		}
		case IDC_F_E_I_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}