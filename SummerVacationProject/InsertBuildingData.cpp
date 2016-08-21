#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK insertBuidlingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead();
	struct Building *building;
	building = head;
	switch (message)
	{
	case WM_INITDIALOG:{
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_I_B_OK:{
			HWND numEditBox = GetDlgItem(hDlg, IDC_I_B_NUM);
			HWND adminEditBox = GetDlgItem(hDlg, IDC_I_B_ADMIN);
			HWND telEditBox = GetDlgItem(hDlg, IDC_I_B_TEL);
			HWND roomEditBox = GetDlgItem(hDlg, IDC_I_B_ROOM);
			HWND bedEditBox = GetDlgItem(hDlg, IDC_I_B_BED);
			HWND costEditBox = GetDlgItem(hDlg, IDC_I_B_COST);
			char *numInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(numInfo, getDataFromEditBox(numEditBox, 5));
			char *adminInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(adminInfo, getDataFromEditBox(adminEditBox, 20));
			char *telInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(telInfo, getDataFromEditBox(telEditBox, 20));
			char *roomInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(roomInfo, getDataFromEditBox(roomEditBox, 20));
			char *bedInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(bedInfo,	getDataFromEditBox(bedEditBox, 20));
			char *costInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(costInfo, getDataFromEditBox(costEditBox, 20));
			if (strlen(numInfo) == 0 || strlen(adminInfo) == 0 || strlen(telInfo) == 0 ||
				strlen(roomInfo) == 0 || strlen(bedInfo) == 0 || strlen(costInfo) == 0){
				MessageBox(hDlg, L"请填完所有的数据", L"提示", MB_OK);
			}
			else{
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
				}
				struct Building *newBuilding = createBuildingData(numInfo, adminInfo, telInfo, atoi(roomInfo), atoi(bedInfo), atof(costInfo), NULL, NULL, building->nextRec);
				building->nextBuilding = newBuilding;
				MessageBox(hDlg, L"添加成功", L"提示", MB_OK);
				EndDialog(hDlg, LOWORD(wParam));
			}
			break;
		}
		case IDC_I_B_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}