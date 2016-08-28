#include "stdafx.h"
#include "SummerVacationProject.h"

// LookAtBuildingDataProc函数介绍
// 功能：控制关于查看所有宿舍楼对话框里面的一切活动
// 返回值：对话框的结果，用于windows的某些判断


INT_PTR CALLBACK LookAtBuildingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_L_D_LIST);
	ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);
	struct Building *head = getHead();
	struct Building *building;
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//宿舍楼号
		vcl.pszText = L"宿舍楼号";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//栋长姓名
		vcl.pszText = L"栋长姓名";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//值班员电话
		vcl.pszText = L"值班员电话";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//房间数
		vcl.pszText = L"房间数";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//床位数
		vcl.pszText = L"床位数";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//每床位年住宿费
		vcl.pszText = L"每床位年住宿费";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);

		int count = 0;
		building = head;
		while (building->nextBuilding != NULL){
			building = building->nextBuilding;
			LVITEM vitem;
			vitem.mask = LVIF_TEXT;
			vitem.iItem = count;
			fillBuildingList(hListView, vitem, building, count++);
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_L_D_NEW:{

			// 打开插入新的宿舍楼信息的对话框

		    DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_I_B), hDlg, insertBuidlingDataProc);
			EndDialog(hDlg, LOWORD(wParam));
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_D), GetParent(hDlg), LookAtBuildingDataProc);
			return (INT_PTR)TRUE;
		}
		case IDC_L_D_EDIT:{

			// 打开编辑宿舍楼信息的对话框

			if (setBuildingCondition(hListView) == -1){
				MessageBox(hDlg, L"请选中一条信息", L"提示", MB_OK);
			}
			else{
				DialogBox(GetModuleHandle(NULL),
					MAKEINTRESOURCE(IDD_E_B), hDlg, editBuidlingDataProc);
			}
			EndDialog(hDlg, LOWORD(wParam));
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_D), GetParent(hDlg), LookAtBuildingDataProc);
			return (INT_PTR)TRUE;
		}
		case IDC_L_D_DEL:{

			// 直接删除一条信息

			if (MessageBox(hDlg, L"是否确认要删除该信息", L"提示", MB_OKCANCEL) == IDOK){
				deleteBuildingData(head, hListView, hDlg);
				EndDialog(hDlg, LOWORD(wParam));
				DialogBox(GetModuleHandle(NULL),
					MAKEINTRESOURCE(IDD_L_D), GetParent(hDlg), LookAtBuildingDataProc);
			}
			break;
		}
		case IDC_L_D_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}