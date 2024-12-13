#include "FileFunc.h"

void WriteFile()
{
	FILE* fp = fopen(filename, "w");	// a.txt파일과 운영체제 파일 스트림과 연결

	// fopen 스트림을 연결해주는 함수가 정상적으로 실행되지 않을 때 
	if (fp == NULL) {
		printf("Write Error!\n");
		return 0;
	}

	fputs("Hello World!!\n", fp); // fputs ( 입력하고 싶은 값, 스트림);
	// FILE* 파일 스트림을 저장하는 구조체, stdout : 모니터에 연결해주는 스트림
	fputs("Hello World!!\n", stdout);
	fclose(fp);
}
void ReadFile()
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("파일을 읽어오는데 실패했습니다!");
		return 0;
	}

	// string, char
	//fgetc : 한개씩 읽어오는 함수
	//fgets	: 문자열로 읽어오는 함수

	char buffer[100]; // 버퍼 : 데이터를 임시적으로 보관했다가 필요할 때 꺼내서 쓰는 용도

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}
void WriteFileByStruct() {
	Person People[3] = {
	   {"이순신", 31},
	   {"강감찬", 32},
	   {"장보고", 33}
	};

	for (int i = 0; i < 3; ++i) {
		printf("이름 : %s 나이 : %d\n", People[i].name, People[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL) {
		printf("Write Error!! \n");
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		fprintf(fp, "이름 : %s 장군님 나이 : %d\n", People[i].name, People[i].age);
	}

	fclose(fp);
}
void ReadFileByStruct()
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("READ ERROR!\n");
		return 0;
	}
	Person People[3];
	fscanf_s(fp, "이름 : %s 장군님 나이 : %d", People[0].name, 30, &People[0].age);
	printf("이름 : %s 장군님 나이 : %d", People[0].name, People[0].age);
}