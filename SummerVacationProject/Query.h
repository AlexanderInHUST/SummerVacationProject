#include "stdafx.h"
#include "SummerVacationProject.h"

struct Building* queryBuilding(char num[5], struct Building *head);
struct Student* queryStudentById(char id[12], struct Building *head);
struct Student* queryStudentListByName(char name[12], struct Building *head);
struct Student* queryStudentListByClass(char clazz[10], struct Building *head);
struct Expenses* queryHeadExpensesByStudent(char id[12], struct Building *head);