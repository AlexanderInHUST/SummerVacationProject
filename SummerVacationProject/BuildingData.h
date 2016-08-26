#include "stdafx.h"
#include "SummerVacationProject.h"

// 寝室楼信息的结构体
// 两个指针是指向下一个结点的
// rec是指这个结点的唯一ID，nextRec是下一个寝室楼的唯一ID，firstStudentRec是指第一个学生信息（头结点）的唯一ID

struct Building{
	char num[5];
	char administrator[20];
	char tel[20];
	short rooms;
	short beds;
	float cost;
	struct Student *firstStudent;
	struct Building *nextBuilding;

	int rec;
	int nextRec;
	int firstStudentRec;
};

struct Building* createBuildingData(
	char num[5],
	char administrator[20],
	char tel[20],
	short rooms,
	short beds,
	float cost,
	struct Student *firstStudent,
	struct Building *nextBuilding,
	int rec);


// 统计宿舍楼信息时的特殊结构体
// 使用时，使用连续内存来做成动态的数组，方便排序
// 就没有指针来进行链接

struct countDocumentory{
	char num[10];
	int amount;
	int occupied;
	float ratio;
};