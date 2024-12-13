#include <stdio.h>
#include "CountNumFunc.h"
#include "windows.h"

// 함수 이름 쉽게 변경하는 방법 : Ctrl + R + R

int InputNumber()
{
	int returnValue;
	scanf_s("%d", &returnValue);
}

void StartGameSetting() // StartGame(); 
{
	int playerHP = 5;   // 잘못된 내용이 있습니다.
	printf("★☆ 환영합니다. ☆★\n");
	printf("숫자를 입력하면 게임이 시작합니다.\n");
}

int SetPlayerHP() 
{
	printf("Player의 체력을 설정해주세요\n");
	return InputNumber();
}

void GameWin()
{
	// 승리했을 때는 색상을 붉은색으로 표시한다.

	printf("컴퓨터의 값과 일치합니다. 축하합니다.\n");

}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

int Fail(int playerHP)
{
	// 어떤 특별한 변수, 체력을 빼야합니다.
	int currentPlayHp = playerHP - 1;
	return currentPlayHp;

}