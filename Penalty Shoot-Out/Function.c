#include <stdio.h>
#include "Function.h"
#include <windows.h>


void GameStart(void)  //Ŀ�� ���� �߰�
{
		printf("\n \n \n \n");
		printf("    ######   ######   #    #     ##     #         #####    #   #          #####   #    #     ##       ##      #####              ###    #    #    #####\n");
	    printf("    ##   ##  #        ##   #    #  #    #           #      #   #         ##   ##  #    #    #  #     #  #       #               ## ##   #    #      #\n");
	    printf("    ##   ##  #        # #  #   #    #   #           #      #   #         ##       #    #   #    #   #    #      #              ##   ##  #    #      #\n");
		printf("    ######   ####     #  # #   ######   #           #       ###           #####   ######   #    #   #    #      #     ## ###   ##   ##  #    #      #\n");
		printf("    ##       #        #   ##   #    #   #           #        #                ##  #    #   #    #   #    #      #      ### ##  ##   ##  #    #      #\n");
		printf("    ##       #        #    #   #    #   #           #        #           ##   ##  #    #    #  #     #  #       #               ## ##   #    #      #\n");
		printf("    ##       ######   #    #   #    #   ######      #        #            #####   #    #     ##       ##        #                ###     ####       #\n");
		
		int x = 67;
		int y = 18;

		GotoXY(x,y);
		printf("  �� �� �� �� \n"); // ���ӽ��۰� �������Ḧ Ű�� �����Ͽ� ����
		GotoXY(x,y+1);
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
				if (y < 19)
				{
					GotoXY(x - 2, y);
					printf(" ");
					GotoXY(x - 2, ++y);
					printf(">");
				}
			}
			else if (GetAsyncKeyState(VK_SPACE) & 8001) // ����Ű // ���ӽ��� ���ý� ����ȭ������ // �������� ���ý� ������ �ܼ�â ����
			{
				if (y == 18)
				{
					Clear();
					printf("���� ȭ���Դϴ�.\n ������~");
				}
				if (y == 19)
				{
					exit(0);
				}
			}
			// else if (GetAsyncKeyState(VK_ESCAPE) & 8001) // ����Ű
			// {
			// 	exit(0);
			// 	FreeConsole();
			// }
		    Sleep(100);
		}
}
	
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

void GameMain(void)
{

}