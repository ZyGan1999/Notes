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
	//������Ԫ��T��Ԫ��e1,e2,e3�ֱ𱻸��Բ���v1,v2,v3��ֵ
	(*T) = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!(*T))exit(OVERFLOW);//����洢�ռ�ʧ��
	(*T)[0] = v1; (*T)[1] = v2; (*T)[2] = v3;
	return OK;
}
Status DestroyTriplet(Triplet * T) {
	//������Ԫ��T
	free(*T); *T = NULL;
	return OK;
}
Status Get(Triplet * T, int i, ElemType * e) {
	//��e����T�ĵ�iԪ��ֵ
	if (i < 1 || i>3)return ERROR;
	(*e) = (*T)[i - 1];
	return OK;
}
Status Put(Triplet * T, int i, ElemType e) {
	//��T�ĵ�iԪ��ֵΪe
	if (i < 1 || i>3)return ERROR;
	(*T)[i - 1] = e;
	return OK;
}
Status isAscending(Triplet T) {
	//�Ƿ���������
	return T[0] <= T[1] && T[1] <= T[2];
}
Status isDescending(Triplet T) {
	//�Ƿ�������
	return T[0] >= T[1] && T[1] >= T[2];
}
Status Max(Triplet T, ElemType * e) {
	//�����ֵ��eָ��
	(*e) = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2])
		: ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}
Status Min(Triplet T, ElemType * e) {
	//����Сֵ��eָ��
	(*e) = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2])
		: ((T[1] <= T[2]) ? T[1] : T[2]);
}

Status Add(Triplet T1, Triplet T2, Triplet * T3) {
	//��T1����T2����������洢��T3��
	InitTriplet(T3, T1[0] + T2[0], T1[1] + T2[1], T1[2] + T2[2]);
	return OK;
}

Status Minus(Triplet T1, Triplet T2, Triplet * T3) {
	//��T1��ȥT2����������洢��T3��
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
		printf("��������Ԫ�ֱ��ֵ:\n");
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
		printf("������Ҫ��ѯ���ǵڼ�Ԫ:\n");
		int num;
		ElemType e;
		scanf("%d", &num);
		Get(T, num, &e);
		printf("��%dԪ��ֵ��:%d\n", num, e);
		system("pause");
		break;
	}
	case 4: {
		printf("������Ҫ�ı���ǵڼ�Ԫ�͸ı���ֵ:\n");
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
		printf("���ֵ��%d\n", max);
		system("pause");
		break;
	}
	case 8: {
		ElemType min;
		Min(*T, &min);
		printf("��Сֵ��%d\n", min);
		system("pause");
		break;
	}
	case 9: {
		Triplet Ta = NULL;
		Triplet Tr = NULL;
		printf("��������Ϊ��һ��������Ԫ�����Ԫ��ֵ:\n");
		ElemType e1, e2, e3;
		scanf("%d %d %d", &e1, &e2, &e3);
		InitTriplet(&Ta, e1, e2, e3);
		Add(*T, Ta, &Tr);
		printf("��������:\n");
		show(Tr);
		printf("�Ƿ񸲸ǣ�(1/0)\n");
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
		printf("��������Ϊ��������Ԫ�����Ԫ��ֵ:\n");
		ElemType e1, e2, e3;
		scanf("%d %d %d", &e1, &e2, &e3);
		InitTriplet(&Ta, e1, e2, e3);
		Minus(*T, Ta, &Tr);
		printf("��������:\n");
		show(Tr);
		printf("�Ƿ񸲸ǣ�(1/0)\n");
		int c; scanf("%d", &c);
		if (c) {
			for (int i = 1; i <= 3; i++) {
				Put(T, i, Tr[i - 1]);

			}
		}
		break;
	}
	case 11: {
		printf("��ǰ��Ԫ��Ϊ:\n");
		show(*T);
		system("pause");
		break;
	}
	default:
		break;
	}
}
void printMenu() {
	printf("1.��ʼ����Ԫ��\n");
	printf("2.���ٵ�ǰ��Ԫ��\n");
	printf("3.��ѯĳһԪ��ֵ\n");
	printf("4.����ĳһԪ��ֵ\n");
	printf("5.��⵱ǰ��Ԫ���Ƿ���������\n");
	printf("6.��⵱ǰ��Ԫ���Ƿ�������\n");
	printf("7.��ѯ��Ԫ�е����ֵ\n");
	printf("8.��ѯ��Ԫ�е���Сֵ\n");
	printf("9.��Ԫ��ӷ�\n");
	printf("10.��Ԫ�����\n");
	printf("11.��ʾ��ǰ��Ԫ��\n");
	printf("��ѡ����Ҫ���еĲ���\n");
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

