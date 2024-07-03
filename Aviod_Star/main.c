#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다.  // 시스템 폴더의 헤더파일을 불러온다.
#include "Console.h" // 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라
#include <stdbool.h>
#include "time.h"
#include <stdlib.h>
#include <conio.h> // 콘솔 input output

#define MAX 30 // 전처리기로 MAX 숫자의 값을 10으로 전부 치환하는 코드 (컴파일 시점에)
#define BG 15

// main함수에서 사용할 수 있게 키워드를 작성해주세요.

void startmanu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("별피하기");
		GotoXY(10,20);
		printf("키를 입력하여 시작하세요");

		if ( _kbhit() )
			break;
	}
}

void gameover(void)
{
	int temp;
	printf("플레이어가 사망햇습니다 .\n 게임을 종료할려면 아무 키나 눌러주세요.\n");
	scanf_s("%d", &temp);
}

int main()
{
	// 콘솔창에 게임의 맵의 크기를 만들어 줘야 합니다.
	SetTitle("별파하기 게임");
	SetColor(BG, 0);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// 맵의 크기를 만들었다. 그 다음에 무엇을 하고 싶나요?
	// 캐릭터 + 움직인다.
	// 캐릭터의 위치 (14,28);

	// 플레이어의 총알 구현 (Bullet)
	// GotoXY, pinrtf 함수를 사용해서 총알을 화면에 출력해보세요.
	
	int score = 0;

	bool isplayerdead = false;  // 플레이어가 죽지 않았음을 나타냄
	int X = 14, Y = 28; // 플레이어의 XY 좌표
	int bx = 0, by = 0; // 총알의 XY 좌표
	bool bullet = false; // 현재 총알이 생성되지 않앗다면 false, 생성되었으면 true

#if false // 코드 작동 안됨 // 별을 한개씩 떨어리는 코드(비활성화)
	int ex = 0, ey = 0; // 별(몬스터)의 x, y 좌표
	bool enemy = false; // 몬스커가 시작할때 false, 생성될 때 true
#endif
	
	// 배열로 별을 생성하는 코드
	int ex[MAX] = { 0 };
	int ey[MAX] = { 1 };
	bool enemy[MAX] = { false };
	srand(time(NULL)); // rand() 랜덤 함수의 seed 값을 현재 시간에 따라서 변경 시켜주는.
	// (rand() % 15); // rand() => 0 ~ 25947 랜덤 숫자 반환 // 0 ~14 반환해주는 값

	startmanu();

	while (true) // 무한 루프
	{
		Clear();       // 이전 위치를 지우고 새로 그리기 위해서

		GotoXY(0, 0);
		printf("score : %d", score); // score 100
		score++;
		GotoXY(27, 0);
		printf("♥");
		

#if false
		// 별(enemy) 생성
		if (!enemy)  // enemy가 없으면 생성하라
		{
			srand(time(NULL)); // rand() 랜덤 함수의 seed 값을 현재 시간에 따라서 변경 시켜주는.
			// (rand() % 15); // rand() => 0 ~ 25947 랜덤 숫자 반환 // 0 ~14 반환해주는 값
			ex = (rand() % 15) * 2;
			ey = 0;
			enemy = true;
		}
#endif

		for (int i = 0 ; i < MAX ; i ++) // 별(enemy) 배열 생성
		{
			if (!enemy[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 1;
				enemy[i] = true;
				break;
			}
			
		}

#if true // 플레이어의 이동 조작
		if (GetAsyncKeyState(VK_LEFT) & 8001) //왼쪽 키를 눌렀을때 // && X > 0
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

#if true // 총알
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!bullet) // !bullet 과 bullet == false 같은 의미
			{
				bx = X;
				by = Y - 1;
				bullet = true;
			}
		}

		if (bullet) // 총알이 생성되고 있을때만
		{
			by--;
			GotoXY(bx, by);
			printf("↑");

			if (by < 1) // 총알이 화면 가장 위로 넘어갔을때 총알이 비활성화 된다.
				bullet = false;
		}
#endif

#if false
		// 별 이동 구현
		if (enemy)
		{
			GotoXY(ex, ey);
			printf("★");
			ey++;

			if (ey > 28)
				enemy = false;
		}
#endif

		for (int i = 0 ; i < MAX ; i++)  // 별 배열 이동 구현
		{
			if (enemy[i])
			{
				SetColor(BG, rand() % 15);
				GotoXY(ex[i], ey[i]);
				printf("★");
				ey[i]++;
			}

			if (bx == ex[i] && by == ey[i] && bullet == true) // bx,by 총알과 별의 좌표가 같으면  bullet과 enemy의 bool값 false
			{
				bullet = false;
				enemy[i] = false;
				score += 100;
			}

			if (X == ex[i] && Y == ey[i]) // 플레이어와 별의 충돌 처리
			{
				if (isplayerdead)//플레이어가 죽엇을때 작동하는 로직
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
				exit(0);  // 게임 종료
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
			GotoXY(X, Y); // 플레이어가 살아있을때 현재 플레이어의 위치△@
			printf("△");
			//break;
		}

		Sleep(100); // 숫자만큼 기다렸다가 다시 실행한다.
	}

	gameover();

}