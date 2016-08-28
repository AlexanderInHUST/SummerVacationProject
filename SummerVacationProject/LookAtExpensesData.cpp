#include "stdafx.h"
#include "SummerVacationProject.h"

// LookAtExpensesDataProc函数介绍
// 功能：控制关于查看所有缴费对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断

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
				MessageBox(hDlg, L"请选中一条信息", L"提示", MB_OK);
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
			if (MessageBox(hDlg, L"是否确认要删除该信息", L"提示", MB_OKCANCEL) == IDOK){
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