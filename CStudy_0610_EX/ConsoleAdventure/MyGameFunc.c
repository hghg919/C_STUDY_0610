#include "MyGameFunc.h"

void SelectStartMenu() // ���� ���� �޴�
{
	printf("1. ���� ����\n");
	printf("2. ���� ���\n");
	printf("3. ���� ����\n");
	int selectMenu = 1;
	scanf_s("%d", &selectMenu);
	if (selectMenu == 1)
	{
		printf("������ �����߽��ϴ�.\n");
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
		printf("�߸��� ���� �Է��Ͽ����ϴ�\n");
	}
}

void ShowGameRecord()
{

}