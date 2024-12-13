#include <stdio.h>
#include <stdbool.h>
#include "Console.h"
#include "MyGameFunc.h"

#define ROWS 30	 // 가로
#define COLS 30	 // 세로   Collums(기둥)
#define filename "C:\\Users\\Administrator\\Desktop\\CStudy_0610\\ConsoleAdventure\\playerData.txt"

char map[COLS][ROWS] = { 0 };	   // 맵 안에있는 데이터
// ROWS + 1 : 개행 문자 '\n' 더해준 것.
// (COLS x ROWS)+1 : 널 문자 '\0' 더해준 것.
char mapString[(COLS * (ROWS + 1)) + 1]; // 데이터로 부터 출력하는 문자열

void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1이 되면 true ,0 false
	{
		if (*x < 2) *x = 2;
		*x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 28) *x = 28;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 2) *y = 2;
		*y -= 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*y > 28) *y = 28;
		*y += 1;
	}
}

void InteractOther(int* playerX, int* playerY, int* itemX, int* itemY, bool* item)
{
	// 플레이어와 아이템의 위치가 같은지 판별
	if (*playerX == *itemX && *playerY == *itemY)
	{
		*item = true;
	}

}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

void MakeMap(char Wall, char(*map)[ROWS]) // 2차원 배열. 맵에 존재하는 데이터 설정
{
	for (int i = 0; i < COLS; ++i)	  // 세로 x 가로 빈 공간
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	// 가로0, 가로 ROWS -1 세로 그려라
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;
	}
	for (int i = 0; i < ROWS; ++i)
	{
		map[0][i] = Wall;
		map[COLS - 1][i] = Wall;
	}
}

void RenderMap() // 만들어진 맵을 그리는 함수
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j];
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
}

typedef struct PlayerData
{
	char name[30]; // 이름을 저장하기 위한 배열
	int score;     // 정수 형태로 점수를 저장한다.
}PlayerData;

typedef enum Level
{
	Easy, Normal, Hard
}Level;

typedef struct GameMode
{
	Level level;
}GameMode;

void CountScoreMethod(int* score, GameMode game)
{
	switch (game.level)
	{
	case Easy :
		*score = *score;
		break;
	case Normal:
		*score = (*score) * 2;
		break;
	case Hard:
		*score = (*score) * 3;
		break;
	default:
		break;
	}
}


void SavePlayerData(PlayerData* player, int totatlCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("파일 쓰기 실패!\n");
	}

	for (int i = 0; i < totatlCount; ++i)
	{
		fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	}

	fclose(fp);
}

void LoadPlayerData(PlayerData* player, int* totalCount)
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("파일 읽기 실패!\n");
		return;
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}
	fseek(fp, 0, SEEK_SET); // fp가 가리키는 주소를 파일의 시작으로 이동
	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);	    // 
		if (ch == '\n') {
			count++;
		}
	}
	fseek(fp, 0, SEEK_SET);

	*totalCount = count;

	for (int i = 0; i < count; ++i)
	{
		fscanf_s(fp, "%s %d ", (player + i)->name, 30, &(player + i)->score);
	}

	fclose(fp);
}

// 플레이어 데이터를 어떤 방식으로 저장할지


int main()
{
	PlayerData allPlayerData[10];
	int totalCount = 0;

	LoadPlayerData(allPlayerData, &totalCount);
	printf("%s %d ", allPlayerData[0].name, allPlayerData[0].score);

	SelectStartMenu();

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// 플레이어의 정보
	int playerX = 15, playerY = 15;     // 플레이어의 시작 좌표
	bool itemFound = false; // 아이템을 발견하면 true만들어 준다.
	bool canMove = true;	// canMove가 true일 때만 움직여라.

	int itemX = 8, itemY = 8;

	// 게임 맵 세팅

	// 테두리(외벽) 설정
	MakeMap('#', map);
	// 내벽 데이터 넣어주기.
	map[10][10] = '#';

	RenderMap();


	// 게임이 시작하자 마자 종료되는 이슈. -> 무한 반복문
	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY); // 플레이어의 입력을 받아서 움직이는 함수.
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player위치 item위치 같을 때
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 31, "아이템을 획득했습니다.");
		}

#if false
		GoToTargetPos(0, 30, "###############################");
		GoToTargetPos(0, 0, "###############################");

		for (int i = 0; i < 30; ++i)
		{
			GoToTargetPos(30, i, "#");
			GoToTargetPos(0, i, "#");
		}

#endif
		// 화면 밖을 나가면 @ (0,0)으로 움직이는 현상도 막아보세요


		Sleep(50);
		}


	}