#include <stdio.h>
#include "Function.h"
#include <windows.h>


void GameStart(void)
{
	while (1) // ������ ���ڸ� �Է��ϰ� <0 : ��������> <1 : ���ӽ���> �׿� ���ڴ� ���ڸ� �ٽ� �Է��ϰ�
	{
		printf("�º����� ����\n\n");
		printf("���ӽ���(1)\n"); // ���� �Է��ϴ� ���� �ƴ� ���ӽ��۰� �������Ḧ �����ؼ� �� ���� ������
		printf("��������(0)\n");
		int start_num;
		scanf_s("%d", &start_num);
		Clear();

		if (start_num == 0)
		{
			printf("������ �����մϴ�.");
			exit(0); //return; : �Լ��� ������ �����Ŵ ����ȯx // return 0; : ���� ���� ��ȯ��Ŵ, �Լ����� // exit(0); : ���α׷��� �����Ŵ
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