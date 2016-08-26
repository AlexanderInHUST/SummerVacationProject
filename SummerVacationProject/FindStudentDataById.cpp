#include "stdafx.h"
#include "SummerVacationProject.h"

// FindStudentDataByIdProc函数介绍
// 功能：控制关于根据学号查询学生对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断

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
				MessageBox(hDlg, L"请输入所查询的学号", L"提示", MB_OK);
			}
			else{
				student = queryStudentById(idInfoString, head);
				if (student == NULL){
					MessageBox(hDlg, L"没有相应的学生信息", L"提示", MB_OK);
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