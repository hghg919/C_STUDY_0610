#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다.  // 시스템 폴더의 헤더파일을 불러온다.
#include "Console.h" // 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라
#include <stdbool.h>
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

	while (true) // 무한 루프
	{
		Clear();       // 이전 위치를 지우고 새로 그리기 위해서


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

		Sleep(100); // 숫자만큼 기다렸다가 다시 실행한다.
	}

}