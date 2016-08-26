#include "stdafx.h"
#include "SummerVacationProject.h"

// FindExpensesDataByClassProc��������
// ���ܣ����ƹ��ڸ��ݰ༶��ѯ�ɷѶԻ��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK FindExpensesDataByClassProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_E_C_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	struct Building *head = getHead();
	struct Student *studentHead = createStudentData("1", "2", '3', "4", "5", -1, "6", "7", "8", "9", "0", NULL, NULL, -1);;
	struct Student *student;
	struct Expenses *expenses;
	char copyClass[20];
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
			int count = 0;
			HWND editBox = GetDlgItem(hDlg, IDC_F_E_C_EDIT);
			char *classInfoString = getDataFromEditBox(editBox, 11);
			strcpy(copyClass, classInfoString);
			if (strlen(classInfoString) == 0){
				MessageBox(hDlg, L"����������Ϣ�İ༶����", L"��ʾ", MB_OK);
			}
			else{

				// ����һ������ͷ���İ༶��������ѯ��ѧ��������

				struct Building *building = head;
				struct Student *studentByClass;
				struct Student *queryStudent;
				studentByClass = studentHead;
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					queryStudent = building->firstStudent;
					while (queryStudent->nextStudent != NULL){
						queryStudent = queryStudent->nextStudent;
						if (strcmp(queryStudent->clazz, copyClass) == 0){
							struct Student *temp =
								createStudentData(queryStudent->id, queryStudent->name, queryStudent->gender, queryStudent->birth, queryStudent->category, queryStudent->size, queryStudent->inTime, queryStudent->clazz, queryStudent->building, queryStudent->room, queryStudent->tel, queryStudent->firstExpenses, NULL, -1);
							studentByClass->nextStudent = temp;
							studentByClass = studentByClass->nextStudent;
						}
					}
				}
				student = studentHead;
				if (studentHead->nextStudent == NULL){
					MessageBox(hDlg, L"û����Ӧ�İ༶��Ϣ", L"��ʾ", MB_OK);
				}
				else{
					bool found = false;
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						expenses = student->firstExpenses;
						while (expenses->nextExpenses != NULL){
							found = true;
							expenses = expenses->nextExpenses;
							LVITEM vitem;
							vitem.mask = LVIF_TEXT;
							vitem.iItem = count;
							fillExpensesList(hListView, vitem, expenses, count++);
						}
					}
					if (!found){
						MessageBox(hDlg, L"û����Ӧ�Ľɷ���Ϣ", L"��ʾ", MB_OK);
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