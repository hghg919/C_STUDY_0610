#include <stdio.h>
#include "Function.h"
#include <windows.h>


void GameStart(void)
{
	while (1) // 정해진 숫자만 입력하게 <0 : 게임종료> <1 : 게임시작> 그외 숫자는 숫자를 다시 입력하게
	{
		printf("승부차기 게임\n\n");
		printf("게임시작(1)\n"); // 수를 입력하는 것이 아닌 게임시작과 게임종료를 선택해서 고를 수는 없을까
		printf("게임종료(0)\n");
		int start_num;
		scanf_s("%d", &start_num);
		Clear();

		if (start_num == 0)
		{
			printf("게임을 종료합니다.");
			exit(0); //return; : 함수의 실행을 종료시킴 값반환x // return 0; : 정수 값을 반환시킴, 함수종료 // exit(0); : 프로그램을 종료시킴
		}
		else if (start_num == 1)
		{
			break;
		}
		else
		{

		}
	}
}

void Clear(void)
{
	system("cls");
}

void SetTitle(char* _szConsoleName)
{
	SetConsoleTitleA(_szConsoleName);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, 100, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}