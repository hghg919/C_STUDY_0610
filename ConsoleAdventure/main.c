
#include <stdio.h>
#include <stdbool.h>
#include "Console.h";


char map[100] = "############";


void GameInfo()	// ������ ������ ����ϴ� �Լ��� ���.
{

}


void InputProcess(int* x, int* y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1�� �Ǹ� true ,0 false
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


int main()
{
	printf("Hello World!\n");
	Clear(); // �ܼ��� ���� �����ִ� ���

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// �÷��̾��� ����
	int playerX = 15, playerY = 15;     // �÷��̾��� ���� ��ǥ
	bool itemFound = false; // �������� �߰��ϸ� true����� �ش�.

	int itemX = 8, itemY = 8;

	while (1) // ������ �������� ���� ����Ǵ� �̽�. -> ���� �ݺ���
	{
		Clear();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY); // �÷��̾��� �Է��� �޾Ƽ� �����̴� �Լ�.
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);

		if (!itemFound) // player��ġ item��ġ ���� ��
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 30, "�������� ȹ���߽��ϴ�.");
		}

		Sleep(50);
	}


}
