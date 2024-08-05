#include <stdio.h>
#include "Function.h"
#include <windows.h>
#include <stdbool.h>

//#define ROWS 30	 // ����
//#define COLS 30	 // ����   Collums(���)
//char map[COLS][ROWS] = { 0 };	   // �� �ȿ��ִ� ������
//// ROWS + 1 : ���� ���� '\n' ������ ��.
//// (COLS x ROWS)+1 : �� ���� '\0' ������ ��.
//char mapString[(COLS * (ROWS + 1)) + 1]; // �����ͷ� ���� ����ϴ� ���ڿ�
//
//void MakeMap(char Wall, char(*map)[ROWS]) // 2���� �迭. �ʿ� �����ϴ� ������ ����
//{
//	for (int i = 0; i < COLS; ++i)	  // ���� x ���� �� ����
//	{
//		for (int j = 0; j < ROWS; ++j)
//		{
//			map[i][j] = ' ';
//		}
//	}
//
//	for (int i = 0; i < COLS; ++i)	// ����0, ���� ROWS -1 ���� �׷���
//	{
//		map[i][0] = Wall;
//		map[i][ROWS - 1] = Wall;
//	}
//	for (int i = 0; i < ROWS; ++i)
//	{
//		map[0][i] = Wall;
//		map[COLS - 1][i] = Wall;
//	}
//}
//
//void RenderMap() // ������� ���� �׸��� �Լ�
//{
//	int mapIndex = 0;
//
//	for (int i = 0; i < COLS; ++i)
//	{
//		for (int j = 0; j < ROWS; ++j)
//		{
//			mapString[mapIndex++] = map[i][j];
//		}
//		mapString[mapIndex++] = '\n';
//	}
//	mapString[mapIndex] = '\0';
//}

void Clear(void)
{
	system("cls");
}

void SetTitle(char* _szConsoleName)
{
	SetConsoleTitleA(_szConsoleName);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, 100, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleCursorVisibility(int _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleCursorInfo(hConsole, &curInfo))
	{
		curInfo.bVisible = _bShow;
		SetConsoleCursorInfo(hConsole, &curInfo);
	}
}

void draw_line(int x, int y, int length) {
	GotoXY(x, y);
	for (int i = 0; i < length; i++) {
		printf("#");
	}
	printf("\n"); // �� ���� �� �ٲ� �߰�
}

void goal_post(int x, int y, int width, int height) {
	// ���
	GotoXY(x, y);
	for (int j = 0; j < width; j++) {
		printf("#");
	}

	// ����
	for (int i = 1; i < height - 1; i++) {
		GotoXY(x, y + i);
		printf("#");
		GotoXY(x + width - 1, y + i);
		printf("#");
	}
}

void Penalty_area(int x, int y, int width, int height) {
	// ���� (���ʰ� ������)
	for (int i = 0; i < height; i++) {
		GotoXY(x, y + i);
		printf("#");
		GotoXY(x + width - 1, y + i);
		printf("#");
	}

	// �ϴ�
	GotoXY(x, y + height - 1);
	for (int j = 0; j < width; j++) {
		printf("#");
	}
}

void Gamescreen(void) // ���� ���� ȭ�� ������ ���
{

}

void GameStart(void)  //Ŀ�� ���� �߰�
{
		printf("\n \n \n \n");
		printf("    ######   ######   #    #     ##     #         #####    #   #          #####   #    #     ##       ##      #####              ###    #    #    #####\n");
	    printf("    ##   ##  #        ##   #    #  #    #           #      #   #         ##   ##  #    #    #  #     #  #       #               ## ##   #    #      #\n");
	    printf("    ##   ##  #        # #  #   #    #   #           #      #   #         ##       #    #   #    #   #    #      #              ##   ##  #    #      #\n");
		printf("    ######   ####     #  # #   ######   #           #       ###           #####   ######   #    #   #    #      #     ## ###   ##   ##  #    #      #\n");
		printf("    ##       #        #   ##   #    #   #           #        #                ##  #    #   #    #   #    #      #     ### ##   ##   ##  #    #      #\n");
		printf("    ##       #        #    #   #    #   #           #        #           ##   ##  #    #    #  #     #  #       #               ## ##   #    #      #\n");
		printf("    ##       ######   #    #   #    #   ######      #        #            #####   #    #     ##       ##        #                ###     ####       #\n");
		
		int x = 67;
		int y = 18;

		GotoXY(x,y);
		printf("  �� �� �� �� \n"); // ���ӽ��۰� �������Ḧ Ű�� �����Ͽ� ����
		GotoXY(x, y + 1);
		printf("  �� �� �� �� \n");
		GotoXY(x, y + 2);
		printf("  �� �� �� �� \n");
		GotoXY(x-2, y);
		printf(">");

		while (1)
		{

			if (GetAsyncKeyState(VK_UP) & 8001) // 
			{
				if (y > 18)
				{
					GotoXY(x - 2, y);
					printf(" ");
					GotoXY(x - 2, --y);
					printf(">");
				}
			}
			else if (GetAsyncKeyState(VK_DOWN) & 8001)
			{
				if (y < 20)
				{
					GotoXY(x - 2, y);
					printf(" ");
					GotoXY(x - 2, ++y);
					printf(">");
				}
			}
			else if (GetAsyncKeyState(VK_SPACE) & 8001) // ����Ű // ���ӽ��� ���ý� ����ȭ������
			{
				if (y == 18)
				{
					Clear();
					printf("���� ����!\n");
					// ���ο� ���� ������ ���⿡ �߰��ϼ���
					return; // ���� GameStart �Լ� ����
				}
				if (y == 19)
				{
					Clear();
					printf("���� ��� ȭ��.\n ������~");
					while (1)
					{
						if (GetAsyncKeyState(VK_ESCAPE) & 8001) // Escape Key
						{
							Clear();
							GameStart(); // ���� ȭ������ ���ư���
							return; // ���� GameRecord �Լ� ����
						}
						Sleep(100);
					}
				}
				if (y == 20)
				{
					exit(0);
				}
			}
		    Sleep(100);
		}
}

void GameMain(void) // ���� �ƽ�Ű ��Ʈ �߰� // ��� 9���� // �ý��� ���� //esc���ý� �������� �����ϰ� �������� ���ý� ������ �ܼ�â ����
{
	Clear();
	SetConsoleSize(60, 30);
	printf("��������:1");
	GotoXY(54, 0);
	printf("������");
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // ��� ���� ũ�� ����
	Penalty_area(8, 12, 43, 6); // ���� ���缭 ����
	GotoXY(22, 3);
	printf("1");
	GotoXY(29, 3);
	printf("2");
	GotoXY(36, 3);
	printf("3");
	GotoXY(22, 6);
	printf("4");
	GotoXY(29, 6);
	printf("5");
	GotoXY(36, 6);
	printf("6");
	GotoXY(22, 9);
	printf("7");
	GotoXY(29, 9);
	printf("8");
	GotoXY(36, 9);
	printf("9");

	int a;
	scanf_s("%d", &a);



}
