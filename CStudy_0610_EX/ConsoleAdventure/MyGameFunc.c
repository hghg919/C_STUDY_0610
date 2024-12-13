#include "MyGameFunc.h"

void SelectStartMenu() // 게임 시작 메뉴
{
	printf("1. 게임 시작\n");
	printf("2. 게임 기록\n");
	printf("3. 게임 종료\n");
	int selectMenu = 1;
	scanf_s("%d", &selectMenu);
	if (selectMenu == 1)
	{
		printf("게임을 시작했습니다.\n");
	}
	else if (selectMenu == 2)
	{
		ShowGameRecord();
	}
	else if (selectMenu == 3)
	{
		exit(0);
	}
	else
	{
		printf("잘못된 값을 입력하였습니다\n");
	}
}

void ShowGameRecord()
{

}