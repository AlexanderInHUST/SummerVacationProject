#include "stdafx.h"
#include "SummerVacationProject.h"
#include "time.h"
#include "math.h"

// initialID函数介绍
// 功能：将当前UNIX时间戳作为唯一ID的基础放到ID.dat之中
// 返回值：无

void initialID(){
	FILE *file;
	file = fopen("ID.dat", "w");
	fprintf(file, "%d", time(NULL));
	fclose(file);
	return;
}

// initialID函数介绍
// 功能：从ID.dat中取出目前的唯一ID，并且使其加1后再放入回去
// 返回值：唯一ID

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

// intToString函数介绍
// 功能：将int转换为字符串
// 返回值：字符串的首地址

char* intToString(int number){
	char* string;
	string = (char*)malloc(sizeof(char) * 20);
	itoa(number, string, 10);
	return string;
}

// floatToString函数介绍
// 功能：将float转换为字符串
// 返回值：字符串的首地址

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

// stringToLPWSTR函数介绍
// 功能：将字符串转换为LPWSTR
// 返回值：LPWSTR

LPWSTR stringToLPWSTR(char* string){
	int dwLen = strlen(string) + 1;
	int nwLen = MultiByteToWideChar(CP_ACP, 0, string, dwLen, NULL, 0);
	LPWSTR result = new WCHAR[dwLen];
	MultiByteToWideChar(CP_ACP, 0, string, dwLen, result, nwLen);
	return result;
}

// charToLPWSTR函数介绍
// 功能：将char转换为LPWSTR
// 返回值：LPWSTR

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

// getDataFromEditBox函数介绍
// 功能：从editBox之中提取数据，并且返回字符串
// 返回值：字符串的首地址

char* getDataFromEditBox(HWND editBox, int length){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (length + 1));
	GetWindowText((HWND)editBox, info, length + 1);
	char *stringInfo = (char*)malloc(sizeof(char) * length + 1);
	USES_CONVERSION;
	stringInfo = T2A(info);
	return stringInfo;
}

// setDataToEditBox函数介绍
// 功能：将字符串输入到eidtBox之中
// 返回值：无

void setDataToEditBox(HWND editBox, char* resource){
	LPWSTR info = (LPWSTR)malloc(sizeof(WCHAR) * (strlen(resource) + 1));
	USES_CONVERSION;
	info = A2T(resource);
	SetWindowText(editBox, info);
}

// cmp函数介绍
// 功能：比较函数，提供给qsort函数，实现能够按照入住率高低进行排序
// 返回值：比较结果

int cmp(const void *a, const void *b){
	if ((((struct countDocumentory*)a)->ratio * 1000 - ((struct countDocumentory*)b)->ratio * 1000) > 0)
		return 1;
	else if ((((struct countDocumentory*)a)->ratio * 1000 - ((struct countDocumentory*)b)->ratio * 1000) < 0)
		return -1;
	else
		return 0;
}