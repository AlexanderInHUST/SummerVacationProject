#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK LookAtStudentDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head;
	struct Building *building;
	struct Student *student;
	HWND hListView = GetDlgItem(hDlg, IDC_L_S_LIST);
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
		//性别
		vcl.pszText = L"性别";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//出生日期
		vcl.pszText = L"出生日期";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//类型
		vcl.pszText = L"类型";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//学制
		vcl.pszText = L"学制";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);
		//入学日期
		vcl.pszText = L"入学日期";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 6, &vcl);
		//班级
		vcl.pszText = L"班级";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 7, &vcl);
		//宿舍楼号
		vcl.pszText = L"宿舍楼号";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 8, &vcl);
		//房间号
		vcl.pszText = L"房间号";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 9, &vcl);
		//联系电话
		vcl.pszText = L"联系电话";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 10, &vcl);
		
		head = getHead();
		building = head;
		int count = 0;
		while (building->nextBuilding != NULL){
			building = building->nextBuilding;
			student = building->firstStudent;
			while (student->nextStudent != NULL){
				student = student->nextStudent;
				LVITEM vitem;
				vitem.mask = LVIF_TEXT;
				vitem.iItem = count;
				fillStudentList(hListView, vitem, student, count++);
			}
		}
		return (INT_PTR)TRUE;
	}

	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_L_S_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}