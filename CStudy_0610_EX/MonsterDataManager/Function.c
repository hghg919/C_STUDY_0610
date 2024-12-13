#include "Function.h"

int Compare(char* str1, char* str2)	 // 반환하는 값이 0이면 다르다. 1이면 같다.
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;  // 같으면 1은 반환한다.

	return 0;
}

void AddMonsterInfo(Monster monster[100], int* monsterIndexPtr)
{
	char newName[30];
	char region[30];
	char grade[30];
	printf("추가할 몬스터 이름을 입력해주세요 : ");
	scanf_s("%s", newName, 30);
	printf("추가할 몬스터 지역을 입력해주세요 : ");
	scanf_s("%s", region, 30);
	printf("추가할 몬스터 등급을 입력해주세요 : ");
	scanf_s("%s", grade, 30);

	strcpy_s(monster[*monsterIndexPtr].name, 30, newName);
	strcpy_s(monster[*monsterIndexPtr].region, 30, region);
	strcpy_s(monster[*monsterIndexPtr].grade, 30, grade);

	(*monsterIndexPtr)++;
}

