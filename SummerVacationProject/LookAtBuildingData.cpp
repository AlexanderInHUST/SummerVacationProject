#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK LookAtBuildingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_L_D_LIST);
	struct Building *head;
	struct Building *building;
	switch (message){
	case WM_INITDIALOG:{
		LVCOLUMN vcl;
		vcl.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
		//����¥��
		vcl.pszText = L"����¥��";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 0, &vcl);
		//��������
		vcl.pszText = L"��������";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 1, &vcl);
		//ֵ��Ա�绰
		vcl.pszText = L"ֵ��Ա�绰";
		vcl.cx = 100;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 2, &vcl);
		//������
		vcl.pszText = L"������";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 3, &vcl);
		//��λ��
		vcl.pszText = L"��λ��";
		vcl.cx = 80;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 4, &vcl);
		//ÿ��λ��ס�޷�
		vcl.pszText = L"ÿ��λ��ס�޷�";
		vcl.cx = 150;
		vcl.iSubItem = 0;
		ListView_InsertColumn(hListView, 5, &vcl);

		int count = 0;
		head = getHead();
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
		case IDC_L_D_CLOSE:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}