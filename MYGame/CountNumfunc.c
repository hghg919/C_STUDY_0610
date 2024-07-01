#include <stdio.h>
#include "CountNumFunc.h"
#include "windows.h"
#include <stdlib.h>
#include <time.h>

void GameWin()
{
	// 승리했을 때는 색상을 붉은색으로 표시한다.

	printf("축하합니다! 게임을 클리어하셨습니다.\n");
}

// 함수 이름 쉽게 변경하는 방법 : Ctrl + R + R

void StartGameSetting()
{
	int playerHP = InputNumber(5); // ?
	printf("환영합니다.");
	printf("숫자를 입력하면 게임이 시작됩니다.");
}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void GameStart()
{
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ★☆★☆★☆★☆★☆★☆★☆★☆★ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★숫자 게임!★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ★☆★☆★☆★☆★☆★☆★☆★☆★ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆★☆ |\n\n");

	while (1) // 정해진 숫자만 입력하게 <0 : 게임종료> <1 : 게임시작> 그외 숫자는 숫자를 다시 입력하게
	{
		printf("게임을 시작하려면 1을 입력하세요.\n");
		printf("게임을 종료하려면 0을 입력하세요.\n");
		int start_num;
		printf("입력 : ");
		scanf_s("%d", &start_num);

		if (start_num == 0)
		{
			printf("게임을 종료합니다.\n\n");
			exit(0); //return; : 함수의 실행을 종료시킴 값반환x // return 0; : 정수 값을 반환시킴, 함수종료 // exit(0); : 프로그램을 종료시킴
		}
		else if (start_num == 1)
		{
			printf("게임 시작!\n\n");
			break;
		}
		else
		{
			printf("잘못된 입력입니다. 0 또는 1을 입력해주세요.\n\n");
		}
	}
}

int InputNumber() // ?
{
	int retrunNumber;
	return scanf_s("%d", &retrunNumber);
}

int Fail(int playerHP) // ???
{
	//어떤 특별한 변수, 체력을 빼야합니다.
	int currentPlayHP = playerHP - 1;
}

// ConSole 함수 모음?
void Clear_ConSole() // 위에 창을 없앰
{
	system("cls");
}

int getUserInput(int uservalsue)
{
	int uservalue;
	while (1) // 함수화
	{
		printf("1 ~ 100 범위의 플레이어의 값을 넣어주세요.\n"); // 게임 도중에도 적용되게, 범위 밖의 값을 넣을 시 카운트는 제거 되지 않도록
		printf("입력 : ");
		scanf_s("%d", &uservalue);

		if (uservalue < 1 || 100 < uservalue)
		{
			printf("\n");
			printf("잘못된 입력입니다.\n");
		}
		else
		{
			printf("\n");
			break;
		}
	}
	return uservalue;
}
