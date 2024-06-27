#include <stdio.h>
#include "CountNumFunc.h"
#include "windows.h"
#include <stdlib.h>
#include <time.h>

void gamewin()
{
	// �¸����� ���� ������ ���������� ǥ���Ѵ�.

	printf("�����մϴ�! ������ Ŭ�����ϼ̽��ϴ�.\n");
}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void GameStart()
{
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