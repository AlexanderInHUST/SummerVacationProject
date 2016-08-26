#include "stdafx.h"
#include "SummerVacationProject.h"
#include "time.h"
#include "math.h"

// initialID��������
// ���ܣ�����ǰUNIXʱ�����ΪΨһID�Ļ����ŵ�ID.dat֮��
// ����ֵ����

void initialID(){
	FILE *file;
	file = fopen("ID.dat", "w");
	fprintf(file, "%d", time(NULL));
	fclose(file);
	return;
}

// initialID��������
// ���ܣ���ID.dat��ȡ��Ŀǰ��ΨһID������ʹ���1���ٷ����ȥ
// ����ֵ��ΨһID

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

// intToString��������
// ���ܣ���intת��Ϊ�ַ���
// ����ֵ���ַ������׵�ַ

char* intToString(int number){
	char* string;
	string = (char*)malloc(sizeof(char) * 20);
	itoa(number, string, 10);
	return string;
}

// floatToString��������
// ���ܣ���floatת��Ϊ�ַ���
// ����ֵ���ַ������׵�ַ

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

// stringToLPWSTR��������
// ���ܣ����ַ���ת��ΪLPWSTR
// ����ֵ��LPWSTR

LPWSTR stringToLPWSTR(char* string){
	int dwLen = strlen(string) + 1;
	int nwLen = MultiByteToWideChar(CP_ACP, 0, string, dwLen, NULL, 0);
	LPWSTR result = new WCHAR[dwLen];
	MultiByteToWideChar(CP_ACP, 0, string, dwLen, result, nwLen);
	return result;
}

// charToLPWSTR��������
// ���ܣ���charת��ΪLPWSTR
// ����ֵ��LPWSTR

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

// getDataFromEditBox��������
// ���ܣ���editBox֮����ȡ���ݣ����ҷ����ַ���
// ����ֵ���ַ������׵�ַ

char* getDataFromEditBox(HWND editBox, int length){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (length + 1));
	GetWindowText((HWND)editBox, info, length + 1);
	char *stringInfo = (char*)malloc(sizeof(char) * length + 1);
	USES_CONVERSION;
	stringInfo = T2A(info);
	return stringInfo;
}

// setDataToEditBox��������
// ���ܣ����ַ������뵽eidtBox֮��
// ����ֵ����

void setDataToEditBox(HWND editBox, char* resource){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (strlen(resource) + 1));
	USES_CONVERSION;
	info = A2T(resource);
	SetWindowText(editBox, info);
}

// cmp��������
// ���ܣ��ȽϺ������ṩ��qsort������ʵ���ܹ�������ס�ʸߵͽ�������
// ����ֵ���ȽϽ��

int cmp(const void *a, const void *b){
	if ((((struct countDocumentory*)a)->ratio * 1000 - ((struct countDocumentory*)b)->ratio * 1000) > 0)
		return 1;
	else if ((((struct countDocumentory*)a)->ratio * 1000 - ((struct countDocumentory*)b)->ratio * 1000) < 0)
		return -1;
	else
		return 0;
}