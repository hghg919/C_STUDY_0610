/*
* �ۼ��� : 2024-07-15
* �ۼ��� : ������
* �н���ǥ : 2���� �迭�� ����
*/

// 1. ����
// �ڷ��� �迭�̸� [����ũ��Y][����ũ��X] = { };

#include "lectures.h"

void lectures22()
{
	// 2���� �迭�� �ʱ�ȭ ǥ�� ���
	int numarr[3][4] = 
	{
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	int numarr2[3][4] = { 0 }; // 1���� �迭�� �� 30x30

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			numarr2[i][j] = 10;
			printf("%d ", numarr[i][j]);
		}
	}

	printf("\n\n");

	char map[10][10] = { 0 };

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			map[i][j] = ' ';
			printf("%c ", map[i][j]);
		}	
		printf("\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		map[i][0] = '#';
		map[i][9] = '#';
	}

	for (int j = 0; j < 10; ++j)
	{
		map[0][j] = '#';
		map[9][j] = '#';
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

}