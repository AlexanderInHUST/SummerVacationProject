#include "stdafx.h"
#include "SummerVacationProject.h"

// LookAtBuildingDataProc��������
// ���ܣ����ƹ��ڲ鿴��������¥�Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�


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

			// �򿪲����µ�����¥��Ϣ�ĶԻ���

		    DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_I_B), hDlg, insertBuidlingDataProc);
			EndDialog(hDlg, LOWORD(wParam));
			DialogBox(GetModuleHandle(NULL),
				MAKEINTRESOURCE(IDD_L_D), GetParent(hDlg), LookAtBuildingDataProc);
			return (INT_PTR)TRUE;
		}
		case IDC_L_D_EDIT:{

			// �򿪱༭����¥��Ϣ�ĶԻ���

			if (setBuildingCondition(hListView) == -1){
				MessageBox(hDlg, L"��ѡ��һ����Ϣ", L"��ʾ", MB_OK);
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

			// ֱ��ɾ��һ����Ϣ

			if (MessageBox(hDlg, L"�Ƿ�ȷ��Ҫɾ������Ϣ", L"��ʾ", MB_OKCANCEL) == IDOK){
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