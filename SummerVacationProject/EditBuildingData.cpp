#include "stdafx.h"
#include "SummerVacationProject.h"

// editBuidlingDataProc��������
// ���ܣ����ƹ��ڱ༭����¥�Ի��������һ�л
// ����ֵ���Ի���Ľ��������windows��ĳЩ�ж�

INT_PTR CALLBACK editBuidlingDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	struct Building *head = getHead(); 
	struct Building *building;
	char *condition = getBuildingCondition(); // ���֮ǰѡ�е�����¥�ı�ʶ��num
	building = head;

	// ��ʼ�����е�editBox���Ա��������

	HWND numEditBox = GetDlgItem(hDlg, IDC_E_B_NUM);
	HWND adminEditBox = GetDlgItem(hDlg, IDC_E_B_ADMIN);
	HWND telEditBox = GetDlgItem(hDlg, IDC_E_B_TEL);
	HWND roomEditBox = GetDlgItem(hDlg, IDC_E_B_ROOM);
	HWND bedEditBox = GetDlgItem(hDlg, IDC_E_B_BED);
	HWND costEditBox = GetDlgItem(hDlg, IDC_E_B_COST);
	switch (message)
	{
	case WM_INITDIALOG:{

		// ��ʼ����ʱ����ݻ�ȡ����num���������������

		while (building->nextBuilding != NULL){
			building = building->nextBuilding;
		 	if (strcmp(building->num, condition) == 0){
				setDataToEditBox(numEditBox, building->num);
				setDataToEditBox(adminEditBox, building->administrator);
				setDataToEditBox(telEditBox, building->tel);
				setDataToEditBox(roomEditBox, intToString(building->rooms));
				setDataToEditBox(bedEditBox, intToString(building->beds));
				setDataToEditBox(costEditBox, floatToString(building->cost));
			}
		}
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
		case IDC_E_B_OK:{

			// ��ȡ����editbox�ڵ����ݣ�����ת��Ϊ�ַ���

			char *numInfo = (char*)malloc(sizeof(char) * 6);
			strcpy(numInfo, getDataFromEditBox(numEditBox, 5));
			char *adminInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(adminInfo, getDataFromEditBox(adminEditBox, 20));
			char *telInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(telInfo, getDataFromEditBox(telEditBox, 20));
			char *roomInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(roomInfo, getDataFromEditBox(roomEditBox, 20));
			char *bedInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(bedInfo, getDataFromEditBox(bedEditBox, 20));
			char *costInfo = (char*)malloc(sizeof(char) * 21);
			strcpy(costInfo, getDataFromEditBox(costEditBox, 20));
			if (strlen(numInfo) == 0 || strlen(adminInfo) == 0 || strlen(telInfo) == 0 ||
				strlen(roomInfo) == 0 || strlen(bedInfo) == 0 || strlen(costInfo) == 0){
				MessageBox(hDlg, L"���������е�����", L"��ʾ", MB_OK);
			}
			else{
				while (building->nextBuilding != NULL){
					building = building->nextBuilding;
					if (strcmp(building->num, condition) == 0){
						strcpy(building->num, numInfo);
						strcpy(building->administrator, adminInfo);
						strcpy(building->tel, telInfo);
						building->rooms = atoi(roomInfo);
						building->beds = atoi(bedInfo) * atoi(roomInfo);
						building->cost = atof(costInfo);
						MessageBox(hDlg, L"�޸ĳɹ�", L"��ʾ", MB_OK);
						EndDialog(hDlg, LOWORD(wParam));
						break;
					}
				}
			}
			break;
		}
		case IDC_E_B_CANCEL:{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		break;
	}
	}
	return (INT_PTR)FALSE;
}