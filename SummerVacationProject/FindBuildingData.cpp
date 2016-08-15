#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK FindBuildingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HWND hListView = GetDlgItem(hDlg, IDC_F_D_LIST);
	struct Building *head = getHead();
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
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_F_D_SERACH:{
			ListView_DeleteAllItems(hListView);
			HWND editBox = GetDlgItem(hDlg, IDC_F_D_EDIT);
			LPWSTR buildingInfo = (LPWSTR)malloc(sizeof(LPWCH) * 6);
			GetWindowText((HWND)editBox, buildingInfo, 6);
			char *buildingInfoString = (char*)malloc(sizeof(char) * 6);
			USES_CONVERSION;
			buildingInfoString = W2A(buildingInfo);
			if (strlen(buildingInfoString) == 0){
				MessageBox(hDlg, L"����������������¥��¥��", L"��ʾ", MB_OK);
			}
			else{
				building = queryBuilding(buildingInfoString, head);
				if (building == NULL){
					MessageBox(hDlg, L"û����Ӧ������¥��Ϣ", L"��ʾ", MB_OK);
				}
				else{
					LVITEM vitem;
					vitem.mask = LVIF_TEXT;
					vitem.iItem = 0;
					fillBuildingList(hListView, vitem, building, 0);
				}
			}
			break;
		}
		case IDC_F_D_OK:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		}
	}
	}
	return (INT_PTR)FALSE;
}