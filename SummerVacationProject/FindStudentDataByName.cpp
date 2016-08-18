#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindStudentDataByNameProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_S_N_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	struct Building *head = getHead();
	struct Student *headStudent = createStudentData("1", "2" , '3', "4", "5", -1, "7", "8", "9", "0", "a", NULL, NULL, -1);
	struct Student *student;
	char copyName[12];
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
		case IDC_F_S_N_SERACH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_S_N_EDIT);
			int count = 0;
			char *nameInfoString;
			nameInfoString = getDataFromEditBox(editBox, 11);
			strcpy(copyName, nameInfoString);
			if (strlen(nameInfoString) == 0){
				MessageBox(hDlg, L"����������", L"��ʾ", MB_OK);
			}
			else{
				struct Building *building = head;
				struct Student *studentByName;
				struct Student *queryStudent;
				studentByName = headStudent;
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					queryStudent = building->firstStudent;
					while (queryStudent->nextStudent != NULL){
						queryStudent = queryStudent->nextStudent;
						if (strcmp(queryStudent->name, copyName) == 0){
							struct Student *temp =
								createStudentData(queryStudent->id, queryStudent->name, queryStudent->gender, queryStudent->birth, queryStudent->category, queryStudent->size, queryStudent->inTime, queryStudent->clazz, queryStudent->building, queryStudent->room, queryStudent->tel, queryStudent->firstExpenses, NULL, -1);
							studentByName->nextStudent = temp;
							studentByName = studentByName->nextStudent;
						}
					}
				}
				student = headStudent;
				if (headStudent == NULL){
					MessageBox(hDlg, L"û����Ӧ��ѧ����Ϣ", L"��ʾ", MB_OK);
				}
				else{
					while (student->nextStudent != NULL){
						student = student->nextStudent;
						LVITEM vitem;
						vitem.mask = LVIF_TEXT;
						vitem.iItem = count;
						fillStudentList(hListView, vitem, student, count++);
					}
				}
			}
			break;
		}
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