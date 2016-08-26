#include "stdafx.h"
#include "SummerVacationProject.h"

// FindExpensesDataByClassProc函数介绍
// 功能：控制关于根据班级查询缴费对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断

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
		//学号
		vcl.pszText = L"学号";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//姓名
		vcl.pszText = L"姓名";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//缴费日期
		vcl.pszText = L"缴费日期";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//缴费金额
		vcl.pszText = L"缴费金额";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//用途
		vcl.pszText = L"用途";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//收款人
		vcl.pszText = L"收款人";
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
				MessageBox(hDlg, L"请输入所信息的班级名称", L"提示", MB_OK);
			}
			else{

				// 构成一个包含头结点的班级都是所查询的学生的链表

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
					MessageBox(hDlg, L"没有相应的班级信息", L"提示", MB_OK);
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
						MessageBox(hDlg, L"没有相应的缴费信息", L"提示", MB_OK);
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