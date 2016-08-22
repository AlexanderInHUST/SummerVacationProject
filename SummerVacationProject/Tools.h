#include "stdafx.h"
#include "SummerVacationProject.h"

void initialID();
int getID();
char* intToString(int number);
LPWSTR stringToLPWSTR(char* string);
LPWSTR charToLPWSTR(char ch);
char* floatToString(float number);
char* getDataFromEditBox(HWND editBox, int length);
void setDataToEditBox(HWND editBox, char* resource);
int cmp(const void *a, const void *b);