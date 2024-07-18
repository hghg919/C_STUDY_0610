
#include <stdio.h>
#include <stdbool.h>
#include "Console.h";


char map[100] = "############";


void GameInfo()	// 게임의 정보를 출력하는 함수를 담당.
{

}


void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1이 되면 true ,0 false
	{
		if (*x < 1) *x = 1;
		*x -= 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 27) *x = 27;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 1) *y = 1;
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


int main()
{
	printf("Hello World!\n");
	Clear(); // 콘솔을 전부 지워주는 기능

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// 플레이어의 정보
	int playerX = 15, playerY = 15;     // 플레이어의 시작 좌표
	bool itemFound = false; // 아이템을 발견하면 true만들어 준다.

	int itemX = 8, itemY = 8;

	while (1) // 게임이 시작하자 마자 종료되는 이슈. -> 무한 반복문
	{
		Clear();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY); // 플레이어의 입력을 받아서 움직이는 함수.
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player위치 item위치 같을 때
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 30, "아이템을 획득했습니다.");
		}

		Sleep(50);
	}


}
