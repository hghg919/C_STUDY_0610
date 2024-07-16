/*
* �ۼ��� : 2024-07-16
* �ۼ��� : ������
* �н���ǥ
* - �������� ���ڸ� �Լ��� ����Ѵ�.
* - call by value�� cell by refefrence�� ���ؼ� �����Ѵ�.
*/

// ���� - ��, �ּ�, &�ּҿ�����
// ������ ���� - �ּ� ����, *������ ������
// ������ ���� ���ϱ� ����. sizeof(������)
// �迭�� ��� ������ : ������ �ּҸ� �������� ���ϰ� �ϴ� ��. constant pointer
// ����� ����Ű�� ������ : ���� �������� ���Ѵ�. pointer to constant

// �迭�� �Ű� ������ ���� ���ؼ� ������ ����.

// �迭�� �����ϴ� �� : int arr[10]; ó�� �����Ҷ� ũ����� ����� ����մϴ�.
// int arr[?} = �����ϴ� �ڵ尡 �Ұ����ϴ�.
// �迭�� ���������.
// int arr2[10];
// arr = arr2;

// ���� �� ũ�⿡ ���� ���Ѵ�.
// ������ �� ���� �ʱ�ȭ ���־�� �Ѵ�.

void addarrayelement(int* arr, int len, int add) // �迭 ����� ���� n��ŭ ���ϴ� �Լ��� �����غ�����.
{
	for (int i = 0; i < len ; ++i)
	{
		arr[i] += add;
		printf("%d", arr[i]);
	}
	printf("\n");
}

// call by value VS call by reference
// �Լ��� ����� �� ���� ��ȯ�Ѵ�.
// return;   -- �� �������� �Լ��� �����Ű�� �Լ��� ȣ���� ������ ���ư���.
// return 0; -- �Լ��� �����ϴ� ������ 0�� ��ȯ�Ѵ�.

// ��ȯ���� ���� ��� void
// ��ȯ���� �ִ� ��� : ��ȯ�ϰ� ���� ���������� �Է����ָ� �ȴ�.

void call_by_value(int _num)
{
	_num = _num += 10;
}

void call_by_reference(int* _numptr)
{
	*_numptr = *_numptr + 10;
}

// call_by_value ���� ���� ȣ�� : �Լ� ȣ�� �� �⺻������ �ܺο� ������ ���� �ʽ��ϴ�.
// �����Ͷ�� �༮�� *(������ ������) ����Ͽ� �Լ� �ܺ� �ּҸ� �����ؼ� ���� ������ �� �־����ϴ�.

#include "lectures.h"

void squarebyvalue_20(int num)
{
	num = num += 10;
	printf("�Լ� �ȿ��� ���� �� ��� : %d \n", num);
}

void squarebyref_20(int* numptr)
{
	*numptr = *numptr * (*numptr);
}

void changeelement(int *a,int *b ,int *c)
{
	int temp = *a;
	*a = *b, *b = *c, *c = temp;// a -> b, b->c, c->a ���� �����ϴ� �Լ��� ����� ���ø� �˴ϴ�.
	//temp ����ϸ� �˴ϴ�.
}

void changeelement_2(int a, int b, int c)
{
	int temp = a;
	a = b, b= c, c = temp;
	printf("call by value �Լ� : %d %d %d\n", a, b, c);
}

// ���� ����, ���� ���� 
// �������� : {} �ȿ� �ۼ��Ǵ� ����. {} ������ ����ɶ� ������ ���� �Ҹ�ȴ�.
// �������� : 

int global_val_l20 = 30; // �������� // ���� : ����óġ, while()�Լ�, ����������.

void dublepointercallbyref(int** ref)
{
	*ref = &global_val_l20;
}

void decimaltobinaray(int num) // 10 1010(2)
{
	int binaray[20] = {0};
	int pos = 0;
	
	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;

		if (num == 0)
		{
			break;
		}
	}

	// binaray[pos] <- ������ ����?

	for (int i = pos; i >= 0; --i)
	{
		printf("%d", binaray[i]);
	}
}

void lectures20()
{
	int arr[3] = { 0.1,2 }; // 5,6,7
	addarrayelement(arr, 3, 5);

	int a = 10;
	int num = a;
	int* numptr = &num;

	call_by_value(num);
	printf("call_By_value num�� �� : %d\n", num);
	call_by_reference(numptr);
	printf("call_By_reference num�� �� : %d\n\n", num);

	printf("��������1\n");
	int b = 3;
	squarebyvalue_20(b); // ���� ������� �ʴ°�
	printf("b�� �� : %d\n", b);
	squarebyref_20(&b); // ���� ������ �Ǽ� ����� �ǵ��� ����� �ּ���.
	printf("b�� �� : %d\n\n", b);

	printf("��������2\n");
	int t1 = 10, t2 = 20, t3 = 30;
	changeelement(&t1, &t2, &t3);
	changeelement_2(t1, t2, t3);
	printf("%d %d %d\n\n", t1, t2, t3);

	printf("���� ������\n"); // ������(�ּ�)���� - �ּ�
	int p1 = 10;
	int p2 = 20;
	int* p1ptr = &p1;
	int* p2ptr = &p2;
	int* p3ptr = NULL;

	p3ptr = &global_val_l20; // ���� ������ : �ּҸ� ����Ű�� �ִ� ������ �ּ� - 0x11111

	dublepointercallbyref(&p1ptr);
	printf("%d\n\n", *p1ptr); // ����

	printf("���� ���� 3\n");
	// 10������ 2������ ��ȯ�ؼ� ����ϴ� �Լ��� �����.

	int input;
	scanf_s("%d", &input);

	decimaltobinaray(input);

	// 11�� 2������ ����¹�
	// 11/2 = 5 + 1
	// 5/2 = 2 + 1
	// 2/2 + 1 + 0 
	// 1/2 = 0 + 1
	// 1011(2) : 1+2+8 = 11 
}