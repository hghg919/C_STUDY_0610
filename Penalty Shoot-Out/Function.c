#include <stdio.h>
#include "Function.h"
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define filePath "C:\\Users\\Jung\\Documents\\GitHub\\C_STUDY_0610\\Penalty Shoot-Out\\save\\highscores.txt"

int selected_pair[2] = { 0, 0 }; // ���� ���� ����
int lives = 3;
int score = 0; // ���� ���� �߰�

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

void PK_kicker(int x, int y)
{
	GotoXY(x, y);
	printf(" �� \n");
	GotoXY(x, y + 1);
	printf("/||\\ \n");
	GotoXY(x, y + 2);
	printf(" /\\ \n");
}

void Ball(int x, int y)
{
	GotoXY(x, y);
	printf("��");
}

void GK(int x, int y)
{
	GotoXY(x, y);
	printf(" �� \n");
	GotoXY(x, y + 1);
	printf("-||- \n");
	GotoXY(x, y + 2);
	printf(" /\\ \n");
}

void DisplayLives() 
{
	GotoXY(54, 0); // ��Ʈ ǥ���� ��ġ
	for (int i = 0; i < lives; i++) {
		printf("��");
	}
	for (int i = lives; i < 3; i++) {
		printf("��");
	}

	GotoXY(0, 0); // ���� ǥ���� ��ġ
	printf("Score: %d", score);
}

void GameOver(void)
{
	Clear();
	char name[50];
	
	// ���� ���� �޽��� ǥ��
	GotoXY(15, 10);
	printf("���� ����! ������ �����ϼ���.");
	GotoXY(15, 11);
	printf("�̸��� �Է��ϼ��� : ");

	// fgets�� ����Ͽ� �̸� �Է� �ޱ�
	if (fgets(name, sizeof(name), stdin) != NULL) 
	{
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
	}
	else 
	{
		// �Է� ���� �� ó��
		name[0] = '\0'; // �� ���ڿ� ó��
	}

	// ������ ���Ͽ� ����
	FILE* file = fopen(filePath, "a");
	if (file != NULL) 
	{
		fprintf(file, "Name: %s, Score: %d\n", name, score);
		fclose(file);
	}
	else 
	{
		GotoXY(20, 24);
		printf("���� ���� ����! ��θ� Ȯ���ϼ���.");
	}

	Sleep(2000); // �޽����� 2�� ���� ǥ��
	exit(0); // ���α׷� ����
}

void GameRecord(void)
{
	Clear();


	// ���� ����
	FILE* file = fopen(filePath, "r");
	if (file == NULL) 
	{
		printf("����� �����ϴ�.\n");
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

	printf("\n\n[ESC] ���ư���\n");
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

	srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ

	// �������� �ϳ��� ���� ����
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
	
	select_random_pair(); // ������ ���ڸ� �������� ����

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
			x -= 7; // 7ĭ �������� �̵� (���� ���ݿ� ���߱� ����)
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
			x += 7; // 7ĭ ���������� �̵� (���� ���ݿ� ���߱� ����)
			GotoXY(x, y);
			printf(">");
		}
	}
	else if (GetAsyncKeyState(VK_SPACE) & 8001) // ����Ű
	{
		int selected_number = (x - 21) / 7 + 1 + (y - 3) / 3 * 3; // ������ ��ȣ ��� (1~9)

		// ��� ���
		if (selected_number == selected_pair[0] || selected_number == selected_pair[1]) // or������
		{
			GotoXY(13, 13);
			printf("����! ������ ���ڴ� %d�Դϴ�.", selected_number);
			lives--; // ��� ����
			DisplayLives(); // ��� ������Ʈ
		}
		else
		{
			GotoXY(13, 13);
			printf("����! ������ ���ڴ� %d�Դϴ�.", selected_number);
			score += 100; // ���� �� ���� ����
			DisplayLives(); // ���� ������Ʈ
		}

		// ���õ� ���� ���
		GotoXY(13, 15); // ���� �ٷ� �̵�
		printf("��ǻ�Ͱ� ������ ���ڴ� %d�� %d�Դϴ�.", selected_pair[0], selected_pair[1]);

		Sleep(1000); // �޽����� 1�� ���� ǥ��
		
		select_random_pair();

		if (lives <= 0)
		{
			GameOver();
		}
	}

	Sleep(100);
	}
}

void Gamescreen1(void) // ���� ���� ȭ�� ������ ���
{
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // ��� ���� ũ�� ����
	Penalty_area(8, 12, 43, 6); // ���� ���缭 ����
	PK_kicker(25, 25);
	Ball(27, 22);
	GK(27, 8);
}

void Gamescreen2(void) // ���� ���� ȭ�� ������ ���
{
	draw_line(0, 11, 60);
	goal_post(18, 1, 23, 11); // ��� ���� ũ�� ����
	Penalty_area(8, 12, 43, 6); // ���� ���缭 ����
	PK_kicker(25, 25);
	Ball(27, 22);
	number_plate();
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
					return;
				}
				if (y == 19)
				{
					Clear();
					GameRecord(); // ���� ��� ȭ�� ȣ��
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

void GameMain(void) // ���� �ƽ�Ű ��Ʈ �߰� // ��� 9���� // �ý��� ���� //esc���ý� �������� �����ϰ� �������� ���ý� ������ �ܼ�â ����
{
	Clear();
	SetConsoleSize(60, 30);
	DisplayLives(); // ���� ���� �� ��� �� ���ھ� ǥ��
	Gamescreen2();
}
