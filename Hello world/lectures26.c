// 파일 입출력
// printf scanf
// 키보드의 입력 모니터에 출력

#include "lectures.h"

#define filename "C:\\Users\\Jung\\Documents\\GitHub\\people.txt"
#define filename1 "C:\\Users\\Jung\\Documents\\GitHub\\C_STUDY_0610\\Hello world\\Test\\Cprogram.txt"

// 파일이 저장되는 위치.
// 

// printf : 모니터에 출력을 하고 있습니다.
// scanf  : 키보드로 부터 입력받는 값을 주소를 전달해서 주소에 저장.
// fopen  : 파일을 열거나 쓰기 위해서 운영체제가 지원해주는 함수
// 윈도우,리눅스,맥 - 운영체제가 여러개 있다.
// 키보드,마우스,모니터 ... 하드웨어가 컴퓨터에서 작동하도록 관리해준다.
// 하드웨어도 회사가 정말 다양하고,
// 스트림 : 모니터,<- 키보드,<- 마우스 - 서로 다른 하드웨어를 연결해주는 것.

// 변수를 저장. -> RAM : 휘발성 메모리 : 컴퓨터 또는 프로그램이 종료되면 사라지는 메모리
// 비휘발성 메모리 : 프로그램이 종료되고 컴퓨터가 종료되도 저장되는 메모리
// 데이터를 저장하고 싶다.
// 운영체제 다르고, 종류도 다른 이 데이터를 저장하려면, 파일 스트림 연결시켜줘야 합니다.
// 구조체 File

typedef struct Person
{
	char name[30];
	int age;
}Person;

void WriteFile()
{
	FILE* fp = fopen(filename, "w"); // a.txt파일과 운영체제 파일 스트림과 연결

	// fopen 스트림을 연결해주는 함수가 정상적으로 실행되지 않을 때
	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Hello World!!\n", fp); // fputs (입력하고 싶은 값, 스트림);

	// FILE* 파일 스트림을 저장하는 구조체, stdout : 모니터에 연결해주는 스트림
	fputs("Hello World!!\n", stdout);

	fclose(fp);
}

void WriteFile1()
{
	FILE* fp1 = fopen(filename1, "w"); // a.txt파일과 운영체제 파일 스트림과 연결

	// fopen 스트림을 연결해주는 함수가 정상적으로 실행되지 않을 때
	if (fp1 == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Today is 2024-07-31\n", fp1); // fputs (입력하고 싶은 값, 스트림);

	// FILE* 파일 스트림을 저장하는 구조체, stdout : 모니터에 연결해주는 스트림
	fputs("Today is 2024-07-31\n", stdout);

	fclose(fp1);
}

void Readfile()
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("\a파일을 읽어오는데 실패했습니다!");
		return 0;
	}

	// string, char 
	// fgetc : 한개씩 읽어오는 함수
	// fgets : 문자열로 읽어오는 함수

	char buffer[100]; // 버퍼 : 데이터를 임시적으로 보관했다가 필요할 때 꺼내서 쓰는 용도

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}

void WriteFileByStruct()
{
	Person People[3] =
	{   {"이순신", 31},
		{"강감찬", 32},
		{"장보고", 33}

	};

	for (int i = 0; i < 3;++i)
	{
		printf("이름 : %s, 나이 : %d\n", People[i].name, People[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("write error!!\n");
		return 0;
	}

	for (int i = 0; i < 3;++i)
	{
		fprintf(fp, "이름 : %s, 나이 : %d\n", People[i].name, People[i].age);
	}
	fclose(fp);
}


void lectures26()
{
	//WriteFile(); 파일을 써서 저장하는 함수
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

	fscanf_s(fp, "이름 : %s, 나이 : %d", People[0].name, 30, &People[0].age);

	printf("이름 : %s 나이 : %d", People[0].name, People[0].age);
	fclose(fp);
}

// Test 폴더 안에, cprogram 이름으로 내용은 today is 2024-07-31 텍스트가 출력되도록 파일을 하나 생성해줍니다.
// 생성된 파일으 읽어와서 콘손창에 출력되도록 해주세요.
// test/cprogram.txt 있는 것을 확인해주시고 콘손창이 열려있고 today is 2024-07-31 출력되도록 도전해보세요.
