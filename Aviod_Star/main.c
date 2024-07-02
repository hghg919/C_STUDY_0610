#include <stdio.h> // printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��ϴ�.  // �ý��� ������ ��������� �ҷ��´�.
#include "Console.h" // ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�
#include <stdbool.h>
#include "time.h"
#include <stdlib.h>

#define MAX 30 // ��ó����� MAX ������ ���� 10���� ���� ġȯ�ϴ� �ڵ� (������ ������)

// main�Լ����� ����� �� �ְ� Ű���带 �ۼ����ּ���.

int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ����� ��� �մϴ�.

	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// ���� ũ�⸦ �������. �� ������ ������ �ϰ� �ͳ���?
	// ĳ���� + �����δ�.
	// ĳ������ ��ġ (14,28);

	// �÷��̾��� �Ѿ� ���� (Bullet)
	// GotoXY, pinrtf �Լ��� ����ؼ� �Ѿ��� ȭ�鿡 ����غ�����.
	
	int X = 14, Y = 28; // �÷��̾��� XY ��ǥ
	int bx = 0, by = 0; // �Ѿ��� XY ��ǥ
	bool bullet = false; // ���� �Ѿ��� �������� �ʾѴٸ� false, �����Ǿ����� true

#if false // �ڵ� �۵� �ȵ� // ���� �Ѱ��� ����� �ڵ�(��Ȱ��ȭ)
	int ex = 0, ey = 0; // ��(����)�� x, y ��ǥ
	bool enemy = false; // ��Ŀ�� �����Ҷ� false, ������ �� true
#endif
	
	// �迭�� ���� �����ϴ� �ڵ�
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL)); // rand() ���� �Լ��� seed ���� ���� �ð��� ���� ���� �����ִ�.
	// (rand() % 15); // rand() => 0 ~ 25947 ���� ���� ��ȯ // 0 ~14 ��ȯ���ִ� ��

	while (true) // ���� ����
	{
		Clear();       // ���� ��ġ�� ����� ���� �׸��� ���ؼ�

#if false
		// ��(enemy) ����
		if (!enemy)  // enemy�� ������ �����϶�
		{
			srand(time(NULL)); // rand() ���� �Լ��� seed ���� ���� �ð��� ���� ���� �����ִ�.
			// (rand() % 15); // rand() => 0 ~ 25947 ���� ���� ��ȯ // 0 ~14 ��ȯ���ִ� ��
			ex = (rand() % 15) * 2;
			ey = 0;
			enemy = true;
		}
#endif

		for (int i = 0 ; i < MAX ; i ++) // ��(enemy) �迭 ����
		{
			if (!enemy[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 0;
				enemy[i] = true;
				break;
			}
			
		}

#if true // �÷��̾��� �̵� ����
		if (GetAsyncKeyState(VK_LEFT) & 8001) //���� Ű�� �������� // && X > 0
		{
			if (X < 1) X = 1;
			X--;           // 
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if(X > 25) X = 25;
			X++;           // 
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (Y > 28) Y = 28;
			Y++;           // ;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001) // && Y > 0
		{
			if (Y < 1) Y = 1;
			Y--;           // 
		}
#endif

		GotoXY(X, Y);
		printf("^��^");

#if true // �Ѿ�
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!bullet) // !bullet �� bullet == false ���� �ǹ�
			{
				bx = X;
				by = Y - 1;
				bullet = true;
			}
		}

		if (bullet) // �Ѿ��� �����ǰ� ��������
		{
			by--;
			GotoXY(bx, by);
			printf(" ��");

			if (by < 1)
				bullet = false;
		}
#endif

#if false
		// �� �̵� ����
		if (enemy)
		{
			GotoXY(ex, ey);
			printf("��");
			ey++;

			if (ey > 28)
				enemy = false;
		}
#endif

		for (int i = 0 ; i < MAX ; i++)  // �� �迭 �̵� ����
		{
			if (enemy[i])
			{
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;
			}

			if (ey[i] > 28)
				enemy[i] = false;
		}

		Sleep(100); // ���ڸ�ŭ ��ٷȴٰ� �ٽ� �����Ѵ�.
	}

}