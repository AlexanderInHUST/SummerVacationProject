#include "stdafx.h"
#include "SummerVacationProject.h"

// ����¥��Ϣ�Ľṹ��
// ����ָ����ָ����һ������
// rec��ָ�������ΨһID��nextRec����һ������¥��ΨһID��firstStudentRec��ָ��һ��ѧ����Ϣ��ͷ��㣩��ΨһID

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


// ͳ������¥��Ϣʱ������ṹ��
// ʹ��ʱ��ʹ�������ڴ������ɶ�̬�����飬��������
// ��û��ָ������������

struct countDocumentory{
	char num[10];
	int amount;
	int occupied;
	float ratio;
};