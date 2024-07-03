#include <stdio.h> // printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��ϴ�.  // �ý��� ������ ��������� �ҷ��´�.
#include "Console.h" // ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�
#include <stdbool.h>
#include "time.h"
#include <stdlib.h>
#include <conio.h> // �ܼ� input output

#define MAX 30 // ��ó����� MAX ������ ���� 10���� ���� ġȯ�ϴ� �ڵ� (������ ������)
#define BG 15

// main�Լ����� ����� �� �ְ� Ű���带 �ۼ����ּ���.

void startmanu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("�����ϱ�");
		GotoXY(10,20);
		printf("Ű�� �Է��Ͽ� �����ϼ���");

		if ( _kbhit() )
			break;
	}
}

void gameover(void)
{
	int temp;
	printf("�÷��̾ ����޽��ϴ� .\n ������ �����ҷ��� �ƹ� Ű�� �����ּ���.\n");
	scanf_s("%d", &temp);
}

int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ����� ��� �մϴ�.
	SetTitle("�����ϱ� ����");
	SetColor(BG, 0);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// ���� ũ�⸦ �������. �� ������ ������ �ϰ� �ͳ���?
	// ĳ���� + �����δ�.
	// ĳ������ ��ġ (14,28);

	// �÷��̾��� �Ѿ� ���� (Bullet)
	// GotoXY, pinrtf �Լ��� ����ؼ� �Ѿ��� ȭ�鿡 ����غ�����.
	
	int score = 0;

	bool isplayerdead = false;  // �÷��̾ ���� �ʾ����� ��Ÿ��
	int X = 14, Y = 28; // �÷��̾��� XY ��ǥ
	int bx = 0, by = 0; // �Ѿ��� XY ��ǥ
	bool bullet = false; // ���� �Ѿ��� �������� �ʾѴٸ� false, �����Ǿ����� true

#if false // �ڵ� �۵� �ȵ� // ���� �Ѱ��� ����� �ڵ�(��Ȱ��ȭ)
	int ex = 0, ey = 0; // ��(����)�� x, y ��ǥ
	bool enemy = false; // ��Ŀ�� �����Ҷ� false, ������ �� true
#endif
	
	// �迭�� ���� �����ϴ� �ڵ�
	int ex[MAX] = { 0 };
	int ey[MAX] = { 1 };
	bool enemy[MAX] = { false };
	srand(time(NULL)); // rand() ���� �Լ��� seed ���� ���� �ð��� ���� ���� �����ִ�.
	// (rand() % 15); // rand() => 0 ~ 25947 ���� ���� ��ȯ // 0 ~14 ��ȯ���ִ� ��

	startmanu();

	while (true) // ���� ����
	{
		Clear();       // ���� ��ġ�� ����� ���� �׸��� ���ؼ�

		GotoXY(0, 0);
		printf("score : %d", score); // score 100
		score++;
		GotoXY(27, 0);
		printf("��");
		

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
				ey[i] = 1;
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
			if(X > 27) X = 27;
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
			printf("��");

			if (by < 1) // �Ѿ��� ȭ�� ���� ���� �Ѿ���� �Ѿ��� ��Ȱ��ȭ �ȴ�.
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
				SetColor(BG, rand() % 15);
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;
			}

			if (bx == ex[i] && by == ey[i] && bullet == true) // bx,by �Ѿ˰� ���� ��ǥ�� ������  bullet�� enemy�� bool�� false
			{
				bullet = false;
				enemy[i] = false;
				score += 100;
			}

			if (X == ex[i] && Y == ey[i]) // �÷��̾�� ���� �浹 ó��
			{
				if (isplayerdead)//�÷��̾ �׾����� �۵��ϴ� ����
				{
					isplayerdead = true;
				}

				Clear();
				SetColor(BG, 5);
				GotoXY(10, 9);
				printf("Game Over! Your score: %d\n", score);
				//GotoXY(X, Y);
				//printf("@");
				//break;
				exit(0);  // ���� ����
			}

			if (ey[i] > 28)
				enemy[i] = false;
		}

		if (isplayerdead)
		{
			SetColor(BG, 14);
			GotoXY(X, Y);
			printf("@");
		}
		else
		{
			SetColor(BG, 13);
			GotoXY(X, Y); // �÷��̾ ��������� ���� �÷��̾��� ��ġ��@
			printf("��");
			//break;
		}

		Sleep(100); // ���ڸ�ŭ ��ٷȴٰ� �ٽ� �����Ѵ�.
	}

	gameover();

}