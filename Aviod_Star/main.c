#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다.  // 시스템 폴더의 헤더파일을 불러온다.
#include "Console.h" // 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라
#include <stdbool.h>
#include "time.h"
#include <stdlib.h>

#define MAX 30 // 전처리기로 MAX 숫자의 값을 10으로 전부 치환하는 코드 (컴파일 시점에)

// main함수에서 사용할 수 있게 키워드를 작성해주세요.

int main()
{
	// 콘솔창에 게임의 맵의 크기를 만들어 줘야 합니다.

	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);

	// 맵의 크기를 만들었다. 그 다음에 무엇을 하고 싶나요?
	// 캐릭터 + 움직인다.
	// 캐릭터의 위치 (14,28);

	// 플레이어의 총알 구현 (Bullet)
	// GotoXY, pinrtf 함수를 사용해서 총알을 화면에 출력해보세요.
	
	int X = 14, Y = 28; // 플레이어의 XY 좌표
	int bx = 0, by = 0; // 총알의 XY 좌표
	bool bullet = false; // 현재 총알이 생성되지 않앗다면 false, 생성되었으면 true

#if false // 코드 작동 안됨 // 별을 한개씩 떨어리는 코드(비활성화)
	int ex = 0, ey = 0; // 별(몬스터)의 x, y 좌표
	bool enemy = false; // 몬스커가 시작할때 false, 생성될 때 true
#endif
	
	// 배열로 별을 생성하는 코드
	int ex[MAX] = { 0 };
	int ey[MAX] = { 0 };
	bool enemy[MAX] = { false };
	srand(time(NULL)); // rand() 랜덤 함수의 seed 값을 현재 시간에 따라서 변경 시켜주는.
	// (rand() % 15); // rand() => 0 ~ 25947 랜덤 숫자 반환 // 0 ~14 반환해주는 값

	while (true) // 무한 루프
	{
		Clear();       // 이전 위치를 지우고 새로 그리기 위해서

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
				ey[i] = 0;
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
		printf("^오^");

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
			printf(" ↑");

			if (by < 1)
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
				GotoXY(ex[i], ey[i]);
				printf("★");
				ey[i]++;
			}

			if (ey[i] > 28)
				enemy[i] = false;
		}

		Sleep(100); // 숫자만큼 기다렸다가 다시 실행한다.
	}

}