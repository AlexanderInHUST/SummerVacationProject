#include "stdafx.h"
#include "SummerVacationProject.h"

// FindExpensesDataByIdProc函数介绍
// 功能：控制关于根据学号查询缴费对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断

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
		case IDC_F_E_I_SERACH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_E_I_EDIT);
			int count = 0;
			char *idInfoString;
			idInfoString = getDataFromEditBox(editBox, 13);
			if (strlen(idInfoString) == 0){
				MessageBox(hDlg, L"请输入所查询的学号", L"提示", MB_OK);
			}
			else{
				student = queryStudentById(idInfoString, head);
				if (student == NULL){
					MessageBox(hDlg, L"没有相应的学生信息", L"提示", MB_OK);
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
						MessageBox(hDlg, L"没有该学生的缴费信息", L"提示", MB_OK);
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