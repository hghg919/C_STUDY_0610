// ���� �����
// printf scanf
// Ű������ �Է� ����Ϳ� ���

#include "lectures.h"

#define filename "C:\\Users\\Jung\\Documents\\GitHub\\people.txt"
#define filename1 "C:\\Users\\Jung\\Documents\\GitHub\\C_STUDY_0610\\Hello world\\Test\\Cprogram.txt"

// ������ ����Ǵ� ��ġ.
// 

// printf : ����Ϳ� ����� �ϰ� �ֽ��ϴ�.
// scanf  : Ű����� ���� �Է¹޴� ���� �ּҸ� �����ؼ� �ּҿ� ����.
// fopen  : ������ ���ų� ���� ���ؼ� �ü���� �������ִ� �Լ�
// ������,������,�� - �ü���� ������ �ִ�.
// Ű����,���콺,����� ... �ϵ��� ��ǻ�Ϳ��� �۵��ϵ��� �������ش�.
// �ϵ��� ȸ�簡 ���� �پ��ϰ�,
// ��Ʈ�� : �����,<- Ű����,<- ���콺 - ���� �ٸ� �ϵ��� �������ִ� ��.

// ������ ����. -> RAM : �ֹ߼� �޸� : ��ǻ�� �Ǵ� ���α׷��� ����Ǹ� ������� �޸�
// ���ֹ߼� �޸� : ���α׷��� ����ǰ� ��ǻ�Ͱ� ����ǵ� ����Ǵ� �޸�
// �����͸� �����ϰ� �ʹ�.
// �ü�� �ٸ���, ������ �ٸ� �� �����͸� �����Ϸ���, ���� ��Ʈ�� ���������� �մϴ�.
// ����ü File

typedef struct Person
{
	char name[30];
	int age;
}Person;

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

void WriteFile1()
{
	FILE* fp1 = fopen(filename1, "w"); // a.txt���ϰ� �ü�� ���� ��Ʈ���� ����

	// fopen ��Ʈ���� �������ִ� �Լ��� ���������� ������� ���� ��
	if (fp1 == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Today is 2024-07-31\n", fp1); // fputs (�Է��ϰ� ���� ��, ��Ʈ��);

	// FILE* ���� ��Ʈ���� �����ϴ� ����ü, stdout : ����Ϳ� �������ִ� ��Ʈ��
	fputs("Today is 2024-07-31\n", stdout);

	fclose(fp1);
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


void lectures26()
{
	//WriteFile(); ������ �Ἥ �����ϴ� �Լ�
	//Readfile();
	//WriteFile1();
	//WriteFileByStruct();

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

// Test ���� �ȿ�, cprogram �̸����� ������ today is 2024-07-31 �ؽ�Ʈ�� ��µǵ��� ������ �ϳ� �������ݴϴ�.
// ������ ������ �о�ͼ� �ܼ�â�� ��µǵ��� ���ּ���.
// test/cprogram.txt �ִ� ���� Ȯ�����ֽð� �ܼ�â�� �����ְ� today is 2024-07-31 ��µǵ��� �����غ�����.
