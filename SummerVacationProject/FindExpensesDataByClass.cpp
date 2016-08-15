#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindExpensesDataByClassProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_E_C_LIST);
	struct Building *head = getHead();
	struct Student *studentHead;
	struct Student *student;
	struct Expenses *expenses;
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
		case IDC_F_E_C_SEARCH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_E_C_EDIT);
			LPWSTR classInfo = (LPWSTR)malloc(sizeof(LPWCH) * 11);
			int count = 0;
			GetWindowText((HWND)editBox, classInfo, 11);
			char *classInfoString = (char*)malloc(sizeof(char) * 11);
			USES_CONVERSION;
			classInfoString = W2A(classInfo);
			if (strlen(classInfoString) == 0){
				MessageBox(hDlg, L"����������Ϣ�İ༶����", L"��ʾ", MB_OK);
			}
			else{
				studentHead = queryStudentListByClass(classInfoString, head);
				student = studentHead;
				if (studentHead == NULL){
					MessageBox(hDlg, L"û����Ӧ�İ༶��Ϣ", L"��ʾ", MB_OK);
				}
				else{
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						expenses = student->firstExpenses;
						while (expenses->nextExpenses != NULL){
							expenses = expenses->nextExpenses;
							LVITEM vitem;
							vitem.mask = LVIF_TEXT;
							vitem.iItem = count;
							fillExpensesList(hListView, vitem, expenses, count++);
						}
					}
				}
			}
			break;
		}
		case IDC_F_E_C_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}