#include <stdio.h>
#include <string.h>
#include "Function.h"

// 1. Monster name, region, grade, level ����ü ������ �����ؼ� printf ���.
// 2. ����ü �迭. ����� ���� �ݺ������� ���� �迭 ���.
// 3. �迭���ٰ� ����ü �迭 �����͸� �־�� ����.
// 4. char name[100][30] = Monster.name;


// �Լ��� �����  ���α׷����� ���� �е��� �н��ϰ� �ս��ϴ�.
// ��ȯ�� �Լ��̸�() {}
// Call by value vs Call by reference 

void ShowInfo(int data) {
	printf("%d", data);
}

// Monster ����

int SearchMonster();	 // compare �Լ� ������ �մϴ�.
int ShowAllMonster();	 // printf( �迭�� �ִ� ��� ��� Monster[i].name)...
int DeleteMonster();	 // Ư�� �迭 ��� �˻��ؼ� �����Ͱ� ������ �ش� �����͸� null, 0 ����

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

int main()
{
	int playerInput = 0;

	Monster monsterGroup[100] = { 0 }; // ������ ���� 100���� �����ϴ� Monster ����ü

	//char monster_name[100][30];
	//char monster_region[100][30];
	//char monster_grade[100][30];

	int totalMonsterCount = 0; // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

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


}