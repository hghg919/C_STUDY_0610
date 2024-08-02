// ___.h : 함수의 원형을 선언합니다.
// (데이터 타입) 1.void 2.(반환값 데이터형) <- int, duoble, char, int* .......
// int 정수이름(); :: 반환값이 int이고 함수이름

// 구조체 헤더 파일에 가져올 때. 구조체도 본문내용을  작성을 안해도 될까요? 아니요. 구조체의 내용물도 전부 작성해줘야 한다.

#include <stdio.h>
#define filename "C:\\Users\\Jung\\Documents\\GitHub\\people.txt"

typedef struct Person
{
	char name[30];
	int age;
}Person;

void WriteFile();

void Readfile();

void WriteFileByStruct();

void ReadFileByStruct();