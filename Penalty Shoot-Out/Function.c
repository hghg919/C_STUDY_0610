#include <stdio.h>
#include "Function.h"
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define filePath "C:\\Users\\Jung\\Documents\\GitHub\\C_STUDY_0610\\Penalty Shoot-Out\\save\\highscores.txt"

int selected_pair[2] = { 0, 0 }; // 전역 변수 정의
int lives = 3;
int score = 0; // 점수 변수 추가

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

void PK_kicker(int x, int y)
{
	GotoXY(x, y);
	printf(" ⓚ \n");
	GotoXY(x, y + 1);
	printf("/||\\ \n");
	GotoXY(x, y + 2);
	printf(" /\\ \n");
}

void Ball(int x, int y)
{
	GotoXY(x, y);
	printf("ⓑ");
}

void GK(int x, int y)
{
	GotoXY(x, y);
	printf(" ⓖ \n");
	GotoXY(x, y + 1);
	printf("-||- \n");
	GotoXY(x, y + 2);
	printf(" /\\ \n");
}

void DisplayLives() 
{
	GotoXY(54, 0); // 하트 표시할 위치
	for (int i = 0; i < lives; i++) {
		printf("♥");
	}
	for (int i = lives; i < 3; i++) {
		printf("♡");
	}

	GotoXY(0, 0); // 점수 표시할 위치
	printf("Score: %d", score);
}

void GameOver(void)
{
	Clear();
	char name[50];
	
	// 게임 오버 메시지 표시
	GotoXY(15, 10);
	printf("게임 오버! 점수를 저장하세요.");
	GotoXY(15, 11);
	printf("이름을 입력하세요 : ");

	// fgets를 사용하여 이름 입력 받기
	if (fgets(name, sizeof(name), stdin) != NULL) 
	{
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
	}
	else 
	{
		// 입력 실패 시 처리
		name[0] = '\0'; // 빈 문자열 처리
	}

	// 점수를 파일에 저장
	FILE* file = fopen(filePath, "a");
	if (file != NULL) 
	{
		fprintf(file, "Name: %s, Score: %d\n", name, score);
		fclose(file);
	}
	else 
	{
		GotoXY(20, 24);
		printf("파일 열기 실패! 경로를 확인하세요.");
	}

	Sleep(2000); // 메시지를 2초 동안 표시
	exit(0); // 프로그램 종료
}

void GameRecord(void)
{
	Clear();


	// 파일 열기
	FILE* file = fopen(filePath, "r");
	if (file == NULL) 
	{
		printf("기록이 없습니다.\n");
	}
	else 
	{
		char line[100];
		while (fgets(line, sizeof(line), file)) 
		{
			printf("%s", line);
		}
		fclose(file);
	}

	printf("\n\n[ESC] 돌아가기\n");
	while (1) {
		if (GetAsyncKeyState(VK_ESCAPE) & 8001) {
			Clear();
			GameStart();
			return;
		}
		Sleep(100);
	}
}


void select_random_pair()
{
	int pairs[8][2] =
	{
		{1, 5},
		{2, 5},
		{3, 5},
		{4, 8},
		{5, 8},
		{6, 8},
		{7, 8},
		{9, 8}
	};

	srand((unsigned int)time(NULL)); // 난수 초기화

	// 무작위로 하나의 쌍을 선택
	int index = rand() % 8;
	selected_pair[0] = pairs[index][0];
	selected_pair[1] = pairs[index][1];
}

void number_plate()
{
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
	int x = 21;
	int y = 3;
	GotoXY(x, y);
	printf(">");
	
	select_random_pair(); // 선택할 숫자를 무작위로 결정

	while (1)
	{
	if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (y > 3)
		{
			GotoXY(x, y);
			printf(" ");
			GotoXY(x, y -= 3);
			printf(">");
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (y < 9)
		{
			GotoXY(x, y);
			printf(" ");
			GotoXY(x, y += 3);
			printf(">");
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (x > 22)
		{
			GotoXY(x , y);
			printf(" ");
			x -= 7; // 7칸 왼쪽으로 이동 (열의 간격에 맞추기 위해)
			GotoXY(x, y);
			printf(">");
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (x < 35)
		{
			GotoXY(x , y);
			printf(" ");
			x += 7; // 7칸 오른쪽으로 이동 (열의 간격에 맞추기 위해)
			GotoXY(x, y);
			printf(">");
		}
	}
	else if (GetAsyncKeyState(VK_SPACE) & 8001) // 선택키
	{
		int selected_number = (x - 21) / 7 + 1 + (y - 3) / 3 * 3; // 선택한 번호 계산 (1~9)

		// 결과 출력
		if (selected_number == selected_pair[0] || selected_number == selected_pair[1]) // or연산자
		{
			GotoXY(13, 13);
			printf("실패! 선택한 숫자는 %d입니다.", selected_number);
			lives--; // 목숨 감소
			DisplayLives(); // 목숨 업데이트
		}
		else
		{
			GotoXY(13, 13);
			printf("성공! 선택한 숫자는 %d입니다.", selected_number);
			score += 100; // 성공 시 점수 증가
			DisplayLives(); // 점수 업데이트
		}

		// 선택된 숫자 출력
		GotoXY(13, 15); // 다음 줄로 이동
		printf("컴퓨터가 선택한 숫자는 %d와 %d입니다.", selected_pair[0], selected_pair[1]);

		Sleep(1000); // 메시지를 1초 동안 표시
		
		select_random_pair();

		if (lives <= 0)
		{
			GameOver();
		}
	}

	Sleep(100);
	}
}

void Gamescreen1(void) // 게임 메인 화면 경기장과 골대
{
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // 골대 가로 크기 조정
	Penalty_area(8, 12, 43, 6); // 위에 맞춰서 조정
	PK_kicker(25, 25);
	Ball(27, 22);
	GK(27, 8);
}

void Gamescreen2(void) // 게임 메인 화면 경기장과 골대
{
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // 골대 가로 크기 조정
	Penalty_area(8, 12, 43, 6); // 위에 맞춰서 조정
	PK_kicker(25, 25);
	Ball(27, 22);
	number_plate();
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
					return;
				}
				if (y == 19)
				{
					Clear();
					GameRecord(); // 게임 기록 화면 호출
					return;
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
	DisplayLives(); // 게임 시작 시 목숨 과 스코어 표시
	Gamescreen2();
}
