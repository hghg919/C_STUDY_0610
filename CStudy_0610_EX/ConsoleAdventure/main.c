#include <stdio.h>
#include <stdbool.h>
#include "Console.h"
#include "MyGameFunc.h"

#define ROWS 30	 // ����
#define COLS 30	 // ����   Collums(���)
#define filename "C:\\Users\\Administrator\\Desktop\\CStudy_0610\\ConsoleAdventure\\playerData.txt"

char map[COLS][ROWS] = { 0 };	   // �� �ȿ��ִ� ������
// ROWS + 1 : ���� ���� '\n' ������ ��.
// (COLS x ROWS)+1 : �� ���� '\0' ������ ��.
char mapString[(COLS * (ROWS + 1)) + 1]; // �����ͷ� ���� ����ϴ� ���ڿ�

void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1�� �Ǹ� true ,0 false
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
	// �÷��̾�� �������� ��ġ�� ������ �Ǻ�
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

void MakeMap(char Wall, char(*map)[ROWS]) // 2���� �迭. �ʿ� �����ϴ� ������ ����
{
	for (int i = 0; i < COLS; ++i)	  // ���� x ���� �� ����
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	// ����0, ���� ROWS -1 ���� �׷���
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

void RenderMap() // ������� ���� �׸��� �Լ�
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
	char name[30]; // �̸��� �����ϱ� ���� �迭
	int score;     // ���� ���·� ������ �����Ѵ�.
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
		perror("���� ���� ����!\n");
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
		perror("���� �б� ����!\n");
		return;
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}
	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�
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

// �÷��̾� �����͸� � ������� ��������


int main()
{
	PlayerData allPlayerData[10];
	int totalCount = 0;

	LoadPlayerData(allPlayerData, &totalCount);
	printf("%s %d ", allPlayerData[0].name, allPlayerData[0].score);

	SelectStartMenu();

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// �÷��̾��� ����
	int playerX = 15, playerY = 15;     // �÷��̾��� ���� ��ǥ
	bool itemFound = false; // �������� �߰��ϸ� true����� �ش�.
	bool canMove = true;	// canMove�� true�� ���� ��������.

	int itemX = 8, itemY = 8;

	// ���� �� ����

	// �׵θ�(�ܺ�) ����
	MakeMap('#', map);
	// ���� ������ �־��ֱ�.
	map[10][10] = '#';

	RenderMap();


	// ������ �������� ���� ����Ǵ� �̽�. -> ���� �ݺ���
	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY); // �÷��̾��� �Է��� �޾Ƽ� �����̴� �Լ�.
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player��ġ item��ġ ���� ��
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 31, "�������� ȹ���߽��ϴ�.");
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
		// ȭ�� ���� ������ @ (0,0)���� �����̴� ���� ���ƺ�����


		Sleep(50);
		}


	}