#include "FileFunc.h"
#include <stdio.h>

void WriteFile()
{
	FILE* fp = fopen(filename, "w"); // a.txt���ϰ� �ü�� ���� ��Ʈ���� ����

	// fopen ��Ʈ���� �������ִ� �Լ��� ���������� ������� ���� ��
	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Hello World!!\n", fp); // fputs (�Է��ϰ� ���� ��, ��Ʈ��);

	// FILE* ���� ��Ʈ���� �����ϴ� ����ü, stdout : ����Ϳ� �������ִ� ��Ʈ��
	fputs("Hello World!!\n", stdout);

	fclose(fp);
}

void Readfile()
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("\a������ �о���µ� �����߽��ϴ�!");
		return 0;
	}

	// string, char 
	// fgetc : �Ѱ��� �о���� �Լ�
	// fgets : ���ڿ��� �о���� �Լ�

	char buffer[100]; // ���� : �����͸� �ӽ������� �����ߴٰ� �ʿ��� �� ������ ���� �뵵

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}

void WriteFileByStruct()
{
	Person People[3] =
	{   {"�̼���", 31},
		{"������", 32},
		{"�庸��", 33}

	};

	for (int i = 0; i < 3;++i)
	{
		printf("�̸� : %s, ���� : %d\n", People[i].name, People[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("write error!!\n");
		return 0;
	}

	for (int i = 0; i < 3;++i)
	{
		fprintf(fp, "�̸� : %s, ���� : %d\n", People[i].name, People[i].age);
	}
	fclose(fp);
}

void ReadFileByStruct()
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("read error\n");
		return 0;
	}

	Person People[3];

	fscanf_s(fp, "�̸� : %s, ���� : %d", People[0].name, 30, &People[0].age);

	printf("�̸� : %s ���� : %d", People[0].name, People[0].age);
	fclose(fp);
}