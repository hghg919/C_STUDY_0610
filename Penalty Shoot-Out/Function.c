#include <stdio.h>
#include "Function.h"
#include <windows.h>
#include <stdbool.h>

//#define ROWS 30	 // 가로
//#define COLS 30	 // 세로   Collums(기둥)
//char map[COLS][ROWS] = { 0 };	   // 맵 안에있는 데이터
//// ROWS + 1 : 개행 문자 '\n' 더해준 것.
//// (COLS x ROWS)+1 : 널 문자 '\0' 더해준 것.
//char mapString[(COLS * (ROWS + 1)) + 1]; // 데이터로 부터 출력하는 문자열
//
//void MakeMap(char Wall, char(*map)[ROWS]) // 2차원 배열. 맵에 존재하는 데이터 설정
//{
//	for (int i = 0; i < COLS; ++i)	  // 세로 x 가로 빈 공간
//	{
//		for (int j = 0; j < ROWS; ++j)
//		{
//			map[i][j] = ' ';
//		}
//	}
//
//	for (int i = 0; i < COLS; ++i)	// 가로0, 가로 ROWS -1 세로 그려라
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
//void RenderMap() // 만들어진 맵을 그리는 함수
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
	printf("\n"); // 줄 끝에 줄 바꿈 추가
}

void goal_post(int x, int y, int width, int height) {
	// 상단
	GotoXY(x, y);
	for (int j = 0; j < width; j++) {
		printf("#");
	}

	// 측면
	for (int i = 1; i < height - 1; i++) {
		GotoXY(x, y + i);
		printf("#");
		GotoXY(x + width - 1, y + i);
		printf("#");
	}
}

void Penalty_area(int x, int y, int width, int height) {
	// 측면 (왼쪽과 오른쪽)
	for (int i = 0; i < height; i++) {
		GotoXY(x, y + i);
		printf("#");
		GotoXY(x + width - 1, y + i);
		printf("#");
	}

	// 하단
	GotoXY(x, y + height - 1);
	for (int j = 0; j < width; j++) {
		printf("#");
	}
}

void Gamescreen(void) // 게임 메인 화면 경기장과 골대
{

}

void GameStart(void)  //커서 제거 추가
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
		printf("  게 임 시 작 \n"); // 게임시작과 게임종료를 키로 선택하여 실행
		GotoXY(x, y + 1);
		printf("  게 임 기 록 \n");
		GotoXY(x, y + 2);
		printf("  게 임 종 료 \n");
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
			else if (GetAsyncKeyState(VK_SPACE) & 8001) // 선택키 // 게임시작 선택시 게임화면으로
			{
				if (y == 18)
				{
					Clear();
					printf("게임 시작!\n");
					// 새로운 게임 로직을 여기에 추가하세요
					return; // 현재 GameStart 함수 종료
				}
				if (y == 19)
				{
					Clear();
					printf("게임 기록 화면.\n 개발중~");
					while (1)
					{
						if (GetAsyncKeyState(VK_ESCAPE) & 8001) // Escape Key
						{
							Clear();
							GameStart(); // 시작 화면으로 돌아가기
							return; // 현재 GameRecord 함수 종료
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

void GameMain(void) // 각종 아스키 아트 추가 // 골대 9분할 // 시스템 구축 //esc선택시 게임종료 선택하게 게임종료 선택시 종료후 콘솔창 끄기
{
	Clear();
	SetConsoleSize(60, 30);
	printf("스테이지:1");
	GotoXY(54, 0);
	printf("♥♥♥");
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // 골대 가로 크기 조정
	Penalty_area(8, 12, 43, 6); // 위에 맞춰서 조정
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
