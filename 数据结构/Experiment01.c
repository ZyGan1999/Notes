#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef ElemType * Triplet;
Status InitTriplet(Triplet * T, ElemType v1, ElemType v2, ElemType v3) {
	//构造三元组T，元素e1,e2,e3分别被赋以参数v1,v2,v3的值
	(*T) = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!(*T))exit(OVERFLOW);//分配存储空间失败
	(*T)[0] = v1; (*T)[1] = v2; (*T)[2] = v3;
	return OK;
}
Status DestroyTriplet(Triplet * T) {
	//销毁三元组T
	free(*T); *T = NULL;
	return OK;
}
Status Get(Triplet * T, int i, ElemType * e) {
	//用e返回T的第i元的值
	if (i < 1 || i>3)return ERROR;
	(*e) = (*T)[i - 1];
	return OK;
}
Status Put(Triplet * T, int i, ElemType e) {
	//置T的第i元的值为e
	if (i < 1 || i>3)return ERROR;
	(*T)[i - 1] = e;
	return OK;
}
Status isAscending(Triplet T) {
	//是否升序排序
	return T[0] <= T[1] && T[1] <= T[2];
}
Status isDescending(Triplet T) {
	//是否降序排序
	return T[0] >= T[1] && T[1] >= T[2];
}
Status Max(Triplet T, ElemType * e) {
	//将最大值用e指向
	(*e) = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2])
		: ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}
Status Min(Triplet T, ElemType * e) {
	//将最小值用e指向
	(*e) = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2])
		: ((T[1] <= T[2]) ? T[1] : T[2]);
}

Status Add(Triplet T1, Triplet T2, Triplet * T3) {
	//用T1加上T2，并将结果存储在T3中
	InitTriplet(T3, T1[0] + T2[0], T1[1] + T2[1], T1[2] + T2[2]);
	return OK;
}

Status Minus(Triplet T1, Triplet T2, Triplet * T3) {
	//用T1减去T2，并将结果存储在T3中
	InitTriplet(T3, T1[0] - T2[0], T1[1] - T2[1], T1[2] - T2[2]);
	return OK;
}
void show(Triplet T) {
	printf("[%d, %d, %d]\n", T[0], T[1], T[2]);
}

void Choose(Triplet * T, int c) {
	switch (c)
	{
	case 1: {
		printf("请输入三元分别的值:\n");
		ElemType v1, v2, v3;
		scanf("%d %d %d", &v1, &v2, &v3);
		InitTriplet(T, v1, v2, v3);
		break;
	}
	case 2: {
		DestroyTriplet(T);
		break;
	}
	case 3: {
		printf("请输入要查询的是第几元:\n");
		int num;
		ElemType e;
		scanf("%d", &num);
		Get(T, num, &e);
		printf("第%d元的值是:%d\n", num, e);
		system("pause");
		break;
	}
	case 4: {
		printf("请输入要改变的是第几元和改变后的值:\n");
		int num; ElemType e;
		scanf("%d %d", &num, &e);
		Put(T, num, e);
		break;
	}
	case 5: {
		if (isAscending(*T)) {
			printf("Yes\n");
		}
		else printf("No\n");
		system("pause");
		break;
	}
	case 6: {
		if (isDescending(*T)) {
			printf("Yes\n");
		}
		else printf("No\n");
		system("pause");
		break;
	}
	case 7: {
		ElemType max;
		Max(*T, &max);
		printf("最大值是%d\n", max);
		system("pause");
		break;
	}
	case 8: {
		ElemType min;
		Min(*T, &min);
		printf("最小值是%d\n", min);
		system("pause");
		break;
	}
	case 9: {
		Triplet Ta = NULL;
		Triplet Tr = NULL;
		printf("请输入作为另一和数的三元组的三元各值:\n");
		ElemType e1, e2, e3;
		scanf("%d %d %d", &e1, &e2, &e3);
		InitTriplet(&Ta, e1, e2, e3);
		Add(*T, Ta, &Tr);
		printf("计算结果是:\n");
		show(Tr);
		printf("是否覆盖？(1/0)\n");
		int c; scanf("%d", &c);
		if (c) {
			for (int i = 1; i <= 3; i++) {
				Put(T, i, Tr[i - 1]);
			}
		}
		break;
	}
	case 10: {
		Triplet Ta = NULL;
		Triplet Tr = NULL;
		printf("请输入作为减数的三元组的三元各值:\n");
		ElemType e1, e2, e3;
		scanf("%d %d %d", &e1, &e2, &e3);
		InitTriplet(&Ta, e1, e2, e3);
		Minus(*T, Ta, &Tr);
		printf("计算结果是:\n");
		show(Tr);
		printf("是否覆盖？(1/0)\n");
		int c; scanf("%d", &c);
		if (c) {
			for (int i = 1; i <= 3; i++) {
				Put(T, i, Tr[i - 1]);

			}
		}
		break;
	}
	case 11: {
		printf("当前三元组为:\n");
		show(*T);
		system("pause");
		break;
	}
	default:
		break;
	}
}
void printMenu() {
	printf("1.初始化三元组\n");
	printf("2.销毁当前三元组\n");
	printf("3.查询某一元的值\n");
	printf("4.更改某一元的值\n");
	printf("5.检测当前三元组是否升序排序\n");
	printf("6.检测当前三元组是否降序排序\n");
	printf("7.查询三元中的最大值\n");
	printf("8.查询三元中的最小值\n");
	printf("9.三元组加法\n");
	printf("10.三元组减法\n");
	printf("11.显示当前三元组\n");
	printf("请选择需要进行的操作\n");
}
int main() {
	Triplet Tt = NULL;
	int choice;
	while (TRUE) {
		printMenu();
		scanf("%d", &choice);
		Choose(&Tt, choice);
		system("cls");
	}

	return 0;
}

