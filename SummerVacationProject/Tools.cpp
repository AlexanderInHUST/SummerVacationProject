#include "stdafx.h"
#include "SummerVacationProject.h"
#include "time.h"
#include "math.h"

void initialID(){
	FILE *file;
	file = fopen("ID.dat", "w");
	fprintf(file, "%d", time(NULL));
	fclose(file);
	return;
}

int getID(){
	FILE *rFile;
	FILE *wFile;
	int id;
	rFile = fopen("ID.dat", "r");
	fscanf(rFile, "%d", &id);
	fclose(rFile);
	wFile = fopen("ID.dat", "w");
	fprintf(rFile, "%d", id + 1);
	fclose(wFile);
	return id;
}

char* intToString(int number){
	char* string;
	string = (char*)malloc(sizeof(char) * 20);
	itoa(number, string, 10);
	return string;
}

char* floatToString(float number){
	char* string;
	char* temp;
	int digital = 0;
	float num = number;
	while (num >= 1){
		num = num / 10;
		digital++;
	}
	string = (char*)malloc(sizeof(char) * (digital + 5));
	temp = (char*)malloc(sizeof(char) * (digital + 5));
	gcvt((double)number, digital + 2, temp);
	int length = strlen(temp);
	if (length == digital + 1){
		sprintf(string, "%s00", temp);
	}
	else if(length == digital + 2){
		sprintf(string, "%s0", temp);
	}
	else{
		sprintf(string, "%s", temp);
	}
	return string;
}

LPWSTR stringToLPWSTR(char* string){
	int dwLen = strlen(string) + 1;
	int nwLen = MultiByteToWideChar(CP_ACP, 0, string, dwLen, NULL, 0);
	LPWSTR result = new WCHAR[dwLen];
	MultiByteToWideChar(CP_ACP, 0, string, dwLen, result, nwLen);
	return result;
}

LPWSTR charToLPWSTR(char ch){
	char string[2];
	string[0] = ch;
	string[1] = '\0';
	int dwLen = strlen(string) + 1;
	int nwLen = MultiByteToWideChar(CP_ACP, 0, string, dwLen, NULL, 0);
	LPWSTR result = new WCHAR[dwLen];
	MultiByteToWideChar(CP_ACP, 0, string, dwLen, result, nwLen);
	return result;
}

char* getDataFromEditBox(HWND editBox, int length){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (length + 1));
	GetWindowText((HWND)editBox, info, length + 1);
	char *stringInfo = (char*)malloc(sizeof(char) * length + 1);
	USES_CONVERSION;
	stringInfo = T2A(info);
	return stringInfo;
}

void setDataToEditBox(HWND editBox, char* resource){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (strlen(resource) + 1));
	USES_CONVERSION;
	info = A2T(resource);
	SetWindowText(editBox, info);
}