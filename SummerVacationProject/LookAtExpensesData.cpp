#include "stdafx.h"
#include "SummerVacationProject.h"

INT_PTR CALLBACK LookAtExpensesDataProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch (message){
	case WM_INITDIALOG:{
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND:{
		switch (LOWORD(wParam)){
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