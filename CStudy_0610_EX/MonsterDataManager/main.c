#include <stdio.h>
#include <string.h>
#include "Function.h"
#define filename "C:\\Users\\Administrator\\Desktop\\CStudy_0610\\MonsterDataManager\\monsterData.txt"

#include <stdlib.h>

// 1. Monster name, region, grade, level ����ü ������ �����ؼ� printf ���.
// 2. ����ü �迭. ����� ���� �ݺ������� ���� �迭 ���.
// 3. �迭���ٰ� ����ü �迭 �����͸� �־�� ����.
// 4. char name[100][30] = Monster.name;


// �Լ��� �����  ���α׷����� ���� �е��� �н��ϰ� �ս��ϴ�.
// ��ȯ�� �Լ��̸�() {}
// Call by value vs Call by reference 

// Monster ����
void ShowAllMonsterData(Monster monster[100], int total)
{
	for (int i = 0; i < total; ++i) {
		printf("���� %d ��°�� �̸� : %s ���� : %s ��� : %s\n", i, monster[i].name, monster[i].region, monster[i].grade);
	}
}

void SearchMonsterByname(Monster monster[100], int* totalMonsterCount)
{
	// 0 ~ 99 0 nullPtr
	// monstergroup[i] i>totalMonsterCount  

	char searchName[30];
	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", searchName, 30);  // �����Ҵ�, ���α׷� ���� �ڿ� �˻��ϰ� ���� �ܾ searchName ������ ����.

	for (int i = 0; i < *totalMonsterCount; ++i)
	{
		if (Compare(monster[i].name, searchName)) {
			printf("�ش� �ϴ� ���͸� ã�ҽ��ϴ�.\n");
			printf(" ������ �̸� : %s, ������ ���� : %s, ������ ��� : %s\n", monster[i].name, monster[i].region, monster[i].grade);
		}
	}
}

void DeleteMonsterByName(Monster monster[100], int* totalCount)
{
	// 0,1,2,3,4, ...  0,1, <-,3  2->�� ������
	// �迭�� �缱���ؼ� �������� �ٽ� �����͸� �Է������ �Ѵ�.
	// ���� ->  -1; 
	// �� -> �������

}

void PrintMonsterList(Monster* monsterList, int totatlCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("���� ���� ����!\n");
	}

	for (int i = 0; i < totatlCount; ++i)
	{
		fprintf(fp, "%s %s %s\n", monsterList[i].name, monsterList[i].region, monsterList[i].grade);
	}

	fclose(fp);
}

void LoadMonsterData(Monster* monsterList, int* totalCount)
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("���� �б� ����!\n");
	}
	
	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}
	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�
	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);	    // 
		if (ch == '\n') {
			count++;
		}
	}
	fseek(fp, 0, SEEK_SET);

	*totalCount = count;

	for (int i = 0; i < count; ++i)
	{
		fscanf_s(fp, "%s %s %s", (monsterList + i)->name, 30, (monsterList + i)->region, 30, (monsterList + i)->grade, 30);
	}

	fclose(fp);
}

int main(void)
{
	int playerInput = 0;

	Monster monsterGroup[100] = {0}; // ������ ���� 100���� �����ϴ� Monster ����ü

	//char monster_name[100][30];
	//char monster_region[100][30];
	//char monster_grade[100][30];
	
	int totalMonsterCount = 0; // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		// 1. ���� ������ �߰�
		// 2. ���� ������ ����
		// 3. ���� ������ ����
		// 4. ���α׷� ����
		printf("1. ���� ������ �߰�\n");
		printf("2. ���� ������ �̸����� �˻�\n");
		printf("3. ���� �� ������ ���\n");
		printf("4. ���� ������ ����\n");
		printf("5. ���α׷� â ����\n");
		printf("6. ���α׷� ����\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 1) {
			AddMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 2) {
			SearchMonsterByname(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 3) {
			ShowAllMonsterData(monsterGroup, totalMonsterCount);
		}

		if (playerInput == 5) {
			system("cls");
		}

		if (playerInput == 6) {										
			break;
		}
	}

	PrintMonsterList(monsterGroup, totalMonsterCount);

	return 0;
}