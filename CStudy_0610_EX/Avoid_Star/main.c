#include <stdio.h> // printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��ϴ�.	// �ý��� ������ ��������� �ҷ��´�.
#include "Console.h" // ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�
#include <stdbool.h>
#include "time.h"
#include <stdlib.h>
#include <conio.h> // consodle input ouput

#define MAX 30  // ��ó����� MAX ���ڿ� ���� 10���� ���� ġȯ�ϴ� �ڵ� (������ ������)
#define BG 15 

// main�Լ����� ����� �� �ְ� Ű���带 �ۼ����ּ���.


void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("�����ϱ�");
		GotoXY(10, 20);
		printf("Ű�� �Է��Ͽ� �����ϼ���.");

		if ( _kbhit() )
			break;
	}
}

void GameOver(void)
{
	int temp;
	printf("�÷��̾ ����߽��ϴ�.\n ������ �����ϸ� �ƹ� ����Ű�� �Է� �� ���͸� ���ּ���.");
	scanf_s("%d", &temp);
}

int main()
{
   // �ܼ�â�� ������ ���� ũ�⸦ ����� ��� �մϴ�.
	SetTitle("�����ϱ�_�赿��");
	SetColor(BG, 0);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// ���� ũ�⸦ �������. �� ������ ������ �ϰ� �ͳ���?
	// ĳ���� + �����δ�.
	// ĳ������ ��ġ (14,28);

	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY, Printf �Լ��� ����ؼ� �Ѿ��� ȭ�鿡 ����غ�����

	int score = 0;

	bool IsPlayerDead = false;	// �÷��̾ ���� ���� ������ ��Ÿ��
	int x = 14, y = 28;	  // �÷��̾��� x , y ��ǥ
	int bx = 0, by = 0;	  // �Ѿ��� bx , by ��ǥ
	bool bullet = false;  // ���� �Ѿ��� �������� �ʾ����� false, ���������� true

#if false // ���� �Ѱ� �� ����߸��� �ڵ�( ��Ȱ��ȭ )
	int ex = 0, ey = 0;   // ��(����)�� x, y ��ǥ
	bool enemy = false;   // ���Ͱ� ������ �� False, ������ �� True
#endif
   // �迭�� ���� �����ϴ� �ڵ�
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL)); // rand() ���� �Լ��� Seed ���� ���� �ð��� ���� ���� �����ִ�.


	StartMenu();

#if true // �÷��̾��� �̵� ����
	while (true) // ���� ����
	{
		Clear();      // ���� ��ġ�� ����� ���� �׸��� ���ؼ�

		GotoXY(0, 0);
		printf("Score %d ", score);  // Score : 100				  
		score++;
#if false
		// ��(Enemy) ����
		if (!enemy)	 // enemy�� ������ �����ض�
		{
			// ( rand() % 15 ) //    rand( ) => 0 ~ 25947 �������ڹ�ȯ // 0 ~ 14 ��ȯ���ִ� ��
			ex = (rand() % 15) * 2;
			ey = 0;
			enemy = true;
		}
#endif
		for (int i = 0; i < MAX; i++) {
			if (!enemy[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 1;
				enemy[i] = true;
				break;
		    }
		}


		if (GetAsyncKeyState(VK_LEFT) & 8001) // ���� Ű�� ������ ��
		{
			if (x < 1) x = 1;
			x-=2;          //
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001) 
		{
			if (x > 27) x = 27;
			x+=2;          //
		}
		else if (GetAsyncKeyState(VK_UP) & 8001) 
		{
			if (y < 2) y = 2;
			y--;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (y > 28) y = 28;
			y++;
		}
#endif

#if true // �Ѿ�
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!bullet)	 // !bullet�� bullet == false ���� �ǹ�
			{
				bx = x;
				by = y - 1;
				bullet = true;
			}
		}

		if (bullet)	// �Ѿ��� �����Ǿ� ���� ��쿡��
		{
			by--; // �� ĭ���� �����̰�
			GotoXY(bx, by);
			printf("��");

			if (by < 1)	    // �Ѿ��� ȭ�� ���� ���� �Ѿ�� �� �Ѿ��� ��Ȱ��ȭ�ȴ�.
				bullet = false;
		}
#endif
#if false
		// ��(Enemy) �̵� ����
		if (enemy)
		{
			GotoXY(ex, ey);
			printf("��");
			ey++;

			if (ey > 28)
				enemy = false;

		}
#endif
		for (int i = 0; i < MAX; i++)
		{
			if (enemy[i])
			{
				SetColor(BG, rand() % 15);
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;

				// bx,by �Ѿ˰� ���� ��ǥ�� ������ bullet, enemy�� bool�� false
				if (bx == ex[i] && by == ey[i] && bullet)
				{
					bullet = false;
					enemy[i] = false;
				}

#if true // �÷��̾�� ���� �浹 ó��
				if (x == ex[i] && y == ey[i])	// �÷��̾ �浹�ߴ�
				{
					if (!IsPlayerDead) // �÷��̾ �׾��� �� �۵��ϴ� ����
					{
						GotoXY(x, y);
						printf("��");
						IsPlayerDead = true;
					}
				}
#endif
				if (ey[i] > 28)
					enemy[i] = false;
			}
		}
	    // �÷��̾ ������� �� ���� �÷��̾��� ��ġ�� �� ��� ���ִ� �ڵ�
		if (!IsPlayerDead)
		{
			SetColor(BG, 12);
			GotoXY(x, y);
			printf("��");
		}
		else 
		{
			GotoXY(x, y);
			printf("��");
			break;
		}


		Sleep(100); // ���ڸ�ŭ ��ٷȴٰ� �ٽ� �����Ѵ�.

	}

	GameOver();
}