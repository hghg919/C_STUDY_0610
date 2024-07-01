#include <stdio.h>
#include "CountNumFunc.h"
#include "windows.h"
#include <stdlib.h>
#include <time.h>

void GameWin()
{
	// �¸����� ���� ������ ���������� ǥ���Ѵ�.

	printf("�����մϴ�! ������ Ŭ�����ϼ̽��ϴ�.\n");
}

// �Լ� �̸� ���� �����ϴ� ��� : Ctrl + R + R

void StartGameSetting()
{
	int playerHP = InputNumber(5); // ?
	printf("ȯ���մϴ�.");
	printf("���ڸ� �Է��ϸ� ������ ���۵˴ϴ�.");
}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void GameStart()
{
	printf("| �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ� |\n");
	printf("| �ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١� |\n");
	printf("| �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ� |\n");
	printf("| �١ڡ١ڡ١ڼ��� ����!�ڡ١ڡ١ڡ� |\n");
	printf("| �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ� |\n");
	printf("| �ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١� |\n");
	printf("| �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ� |\n\n");

	while (1) // ������ ���ڸ� �Է��ϰ� <0 : ��������> <1 : ���ӽ���> �׿� ���ڴ� ���ڸ� �ٽ� �Է��ϰ�
	{
		printf("������ �����Ϸ��� 1�� �Է��ϼ���.\n");
		printf("������ �����Ϸ��� 0�� �Է��ϼ���.\n");
		int start_num;
		printf("�Է� : ");
		scanf_s("%d", &start_num);

		if (start_num == 0)
		{
			printf("������ �����մϴ�.\n\n");
			exit(0); //return; : �Լ��� ������ �����Ŵ ����ȯx // return 0; : ���� ���� ��ȯ��Ŵ, �Լ����� // exit(0); : ���α׷��� �����Ŵ
		}
		else if (start_num == 1)
		{
			printf("���� ����!\n\n");
			break;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է����ּ���.\n\n");
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
	//� Ư���� ����, ü���� �����մϴ�.
	int currentPlayHP = playerHP - 1;
}

// ConSole �Լ� ����?
void Clear_ConSole() // ���� â�� ����
{
	system("cls");
}

int getUserInput(int uservalsue)
{
	int uservalue;
	while (1) // �Լ�ȭ
	{
		printf("1 ~ 100 ������ �÷��̾��� ���� �־��ּ���.\n"); // ���� ���߿��� ����ǰ�, ���� ���� ���� ���� �� ī��Ʈ�� ���� ���� �ʵ���
		printf("�Է� : ");
		scanf_s("%d", &uservalue);

		if (uservalue < 1 || 100 < uservalue)
		{
			printf("\n");
			printf("�߸��� �Է��Դϴ�.\n");
		}
		else
		{
			printf("\n");
			break;
		}
	}
	return uservalue;
}
