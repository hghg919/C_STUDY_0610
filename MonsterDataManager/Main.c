#include <stdio.h>
#include <string.h>

typedef struct Monster {
	char name[30];
	char region[30];
	char grade[30];
	int level;
}Monster;

// 1. Monster name, region, grade, level ����ü ������ �����ؼ� printf ���.
// 2. ����ü �迭. ����� ���� �ݺ������� ���� �迭 ���.
// 3. �迭���ٰ� ����ü �迭 �����͸� �־�� ����.
// 4. char name[100][30] = Monster.name;

int AddMonster(char(*monster_name)[30], char(*monster_region)[30], char(*monster_grade)[30],
	int level, int* totalCount, Monster* monsterPtr)
{

}

int SearchMonster();	 // compare �Լ� ������ �մϴ�.
int ShowAllMonster();	 // printf( �迭�� �ִ� ��� ��� Monster[i].name)...
int DeleteMonster();	 // Ư�� �迭 ��� �˻��ؼ� �����Ͱ� ������ �ش� �����͸� null, 0 ����

int main()
{
	int playerInput = 0;

	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];
	int monster_level[100];

	int totalMonsterCount; // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

	while (1)
	{
		system("cls");
		printf("1. ���� ������ �߰�\n");

		// 1. ���� ������ �߰�
		// 2. ���� ������ ����
		// 3. ���� ������ ����
		// 4. ���α׷� ����
		printf("4. ���α׷� ����\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 4) {
			break;
		}

	}


}