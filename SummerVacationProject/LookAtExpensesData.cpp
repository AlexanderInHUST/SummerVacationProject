#include "stdafx.h"
#include "SummerVacationProject.h"

// LookAtExpensesDataProc��������
// ���ܣ����ƹ��ڲ鿴���нɷѶԻ��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK LookAtExpensesDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	struct Student *student;
	struct Expenses *expenses;
	HWND hListView = GetDlgItem(hDlg, IDC_L_E_LIST);
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

		int count = 0;
		building = head;
		while (building->nextBuilding != NULL){
			building = building->nextBuilding;
			student = building->firstStudent;
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
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_L_E_NEW:{
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_I_E), hDlg, insertExpensesDataProc);
			EndDialog(hDlg, LOWORD(wParam));
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_E), GetParent(hDlg), LookAtExpensesDataProc);
			return (INT_PTR)TRUE;
		}
		case IDC_L_E_EDIT:{
			if (setExpensesCondition(hListView) == -1){
				MessageBox(hDlg, L"��ѡ��һ����Ϣ", L"��ʾ", MB_OK);
			}
			else{
				DialogBox(GetModuleHandle(NULL),
					MAKEINTRESOURCE(IDD_E_E), hDlg, editExpensesDataProc);
			}
			EndDialog(hDlg, LOWORD(wParam));
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_E), GetParent(hDlg), LookAtExpensesDataProc);
			return (INT_PTR)TRUE;
		}
		case IDC_L_E_DEL:{
			if (MessageBox(hDlg, L"�Ƿ�ȷ��Ҫɾ������Ϣ", L"��ʾ", MB_OKCANCEL) == IDOK){
				deleteExpensesData(head, hListView, hDlg);
				EndDialog(hDlg, LOWORD(wParam));
				DialogBox(GetModuleHandle(NULL),
					MAKEINTRESOURCE(IDD_L_E), GetParent(hDlg), LookAtExpensesDataProc);
			}
			break;
		}
		case IDC_L_E_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}