/*
* 작성일 : 2024-07-15
* 작성자 : 정현준
* 학습목표 : 2차원 배열의 이해
*/

// 1. 선언
// 자료형 배열이름 [세로크기Y][가로크기X] = { };

#include "lectures.h"

void lectures22()
{
	// 2차원 배열에 초기화 표현 방법
	int numarr[3][4] = 
	{
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	int numarr2[3][4] = { 0 }; // 1차원 배열에 벽 30x30

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