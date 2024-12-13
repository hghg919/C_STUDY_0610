#include <stdio.h>
#include <string.h>
#include "Function.h"
#define filename "C:\\Users\\Administrator\\Desktop\\CStudy_0610\\MonsterDataManager\\monsterData.txt"

#include <stdlib.h>

// 1. Monster name, region, grade, level 구조체 변수를 선언해서 printf 출력.
// 2. 구조체 배열. 만들어 보고 반복문으로 몬스터 배열 출력.
// 3. 배열에다가 구조체 배열 데이터를 넣어야 겠죠.
// 4. char name[100][30] = Monster.name;


// 함수를 만드는  프로그래밍이 여러 분들이 학습하고 잇습니다.
// 반환값 함수이름() {}
// Call by value vs Call by reference 

// Monster 변수
void ShowAllMonsterData(Monster monster[100], int total)
{
	for (int i = 0; i < total; ++i) {
		printf("몬스터 %d 번째의 이름 : %s 지역 : %s 등급 : %s\n", i, monster[i].name, monster[i].region, monster[i].grade);
	}
}

void SearchMonsterByname(Monster monster[100], int* totalMonsterCount)
{
	// 0 ~ 99 0 nullPtr
	// monstergroup[i] i>totalMonsterCount  

	char searchName[30];
	printf("검색하고 싶은 이름을 입력하세요 : ");
	scanf_s("%s", searchName, 30);  // 동적할당, 프로그램 실행 뒤에 검색하고 싶은 단어를 searchName 공간에 저장.

	for (int i = 0; i < *totalMonsterCount; ++i)
	{
		if (Compare(monster[i].name, searchName)) {
			printf("해당 하는 몬스터를 찾았습니다.\n");
			printf(" 몬스터의 이름 : %s, 몬스터의 지역 : %s, 몬스터의 등급 : %s\n", monster[i].name, monster[i].region, monster[i].grade);
		}
	}
}

void DeleteMonsterByName(Monster monster[100], int* totalCount)
{
	// 0,1,2,3,4, ...  0,1, <-,3  2->빈 데이터
	// 배열을 재선언해서 차곡차곡 다시 데이터를 입력해줘야 한다.
	// 숫자 ->  -1; 
	// 값 -> 비어있음

}

void PrintMonsterList(Monster* monsterList, int totatlCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("파일 쓰기 실패!\n");
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
		perror("파일 읽기 실패!\n");
	}
	
	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}
	fseek(fp, 0, SEEK_SET); // fp가 가리키는 주소를 파일의 시작으로 이동
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

	Monster monsterGroup[100] = {0}; // 몬스터의 정보 100개를 저장하는 Monster 구조체

	//char monster_name[100][30];
	//char monster_region[100][30];
	//char monster_grade[100][30];
	
	int totalMonsterCount = 0; // 몬스터 데이터에 몇번 Index에 저장되었는가

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		// 1. 몬스터 데이터 추가
		// 2. 몬스터 데이터 보기
		// 3. 몬스터 데이터 삭제
		// 4. 프로그램 종료
		printf("1. 몬스터 데이터 추가\n");
		printf("2. 몬스터 데이터 이름으로 검색\n");
		printf("3. 몬스터 총 데이터 출력\n");
		printf("4. 몬스터 데이터 삭제\n");
		printf("5. 프로그램 창 정리\n");
		printf("6. 프로그램 종료\n");

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