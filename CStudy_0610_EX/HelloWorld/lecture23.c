#include "lectures.h"


void ChangeDoubleArrValue(int(*tPArr)[4], int addValue)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			tPArr[i][j] += addValue;
		}
	}
}

// char ������� tPArr�� ���� �����ϴ� �Լ��� �ۼ��غ�����.

void ChangeCharValueInDoubleArr(char(*cPArr)[4], char inputChar)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cPArr[i][j] = inputChar;
		}
	}
}

void lecture23()
{
	// ������ ���� : int, num, 10
	int num = 10;
	// ������ ���� : numPtr
	int* numPtr = &num;
	// �������� ������ : numpPtr
	int** numpPtr = &numPtr;

	printf("���� : %d, �����ͷ� ���� �� ȣ�� : %d, �������� ������ �� ȣ�� %d \n", num, *numPtr, **numpPtr);

	int arr[3] = { 1,2,3 };
	int* aPtr = arr;

	for (int i = 0; i < 3; i++)
	{
		printf("arr �迭�� �� : %d \n", *(aPtr + i));
		printf("arr[i] �� ��� : %d \n", aPtr[i]);
	}

	// 2���� �迭

	int arr2[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	// �迭�� �ּҸ� �������� ��
	//int* parr[3] = &arr;
	//int(*parr)[3] = &arr;
	//int** doublePtr = &arr2;

	// 2���� �迭�� �����Ϳ� �ֱ�
	// int (*������ �̸�)[���� ũ��]; // ����ũ�Ⱑ n�� �迭�� ����Ű�� ������.

	int(*parr2)[4] = arr2;
	int** doublePtr = arr2;

	printf("arr2�� �ּ� : %p\n", arr2);
	printf("parr2�� �ּ� : %p\n", parr2);
	printf("doublePtr�� �ּ� : %p\n", doublePtr);

	// ������ ������ ũ��� Ȯ���� �غ���
	printf("arr2�� ũ�� : %d\n", sizeof(arr2));
	printf("parr2�� ũ�� : %d\n", sizeof(parr2));
	printf("dobulePtr�� ũ�� : %d\n", sizeof(doublePtr));

	// 2���� �迭���� �迭�� �����ͷ� ǥ���غ���.
	int arr3[3][4] = { 0 };

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("arr3�� ���� �� : %d\n", arr3[i][j]);
		}
	}

	ChangeDoubleArrValue(arr3, 1);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("arr3 ���� �� : %d\n", arr3[i][j]);
		}
	}


	// arr[x][y] == (*(arr+x))[y] == *(*(arr+x)+y) //  A ġȯ�Ѵ� : *(arr+x)  // A[y] // A�ٽ� ġȯ�Ѱ��� �ִ´�.

	// 2���� �迭�� �����ͷ� ǥ���ϰ� ������ ����ϱ�

	printf("2���� �迭�� �� : %d \n", arr2[1][2]);
	printf("2���� �迭�� �����ͷ� ǥ���� �� : %d \n", *(*(arr2 + 1) + 2));

	printf("2���� �迭���� ������ ũ���� �ּҸ� ��� : %p\n", (*(arr2 + 1)));
	printf("2���� ... ������ ũ�Ⱑ 1�̰�, �ű⼭ intũ�⸸ŭ +2�� �ּ� : %p\n", (*(arr2 + 1) + 2));

	// int arr[3][4]����
	//  arr[i]�� �ǹ� : ũ�Ⱑ 4�� int�迭�� 3�� �ִµ�. �� �߿��� i��° �迭�� �����Ѷ�.
	// doublePtr : �ּ��� �ּҸ� arr[3][4] ǥ�ø� ��������, 2���� �迭�� ǥ���� �� ����.
	// ������ �迭 int (*arr[����ũ��])[����ũ��]; 
	// �������� �迭 : int* arr[ũ��] :: �ǹ� .. ������ �������� �迭

	// ����
	// 2���� �迭�� �����ͷ� ǥ���ϱ� ���ؼ���, �ݵ�� �迭�� ������ �������� �Ѵ�.
	// ������Ÿ�� (*�����ͺ����̸�)(�迭ũ��) = ���� �������� �ּҸ� ������ �� �ִ�.

	// ChangeCharValueInDoubleArr �Լ��� ȣ���ؼ�, �ȿ� �ִ� ���� #,$ ���ϵ��� �ۼ��غ�����.

	char map[3][4] = { 0 };

	ChangeCharValueInDoubleArr(map, '#');

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("map�� �� : %c\n", map[i][j]);
		}
	}

}