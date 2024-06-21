/*
* 작성자 : 정현준
* 작성일 : 2024.06.20
* 학습목표 : C언어 기본 자료형 + 상수
* 
* question : 자료형이 무엇인가요?
* -> 변수 (자료형) (변수이름)
* 자료형은 변수를 만들기 위해서 필요한거다.
* 수를 구분할 필요가 있다. <정수, 실수>
* 정수를 사용하기로 정했습니다. 얼마만큼 데이터를 저장할 것인가?
* char 변수이름 = 0b00000001; 1바이트
* int 변수이름 = 0b 00000000 00000000 00000000 00000001; 4바이트
* long long 변수이름 = 0b 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001; 8바이트
* 데이터가 저장될 메모리의 크기를 지정하기 위해 사용한다.
* 어떤 데이터 타임(정수,실수) 사용할 지 저장한 후 그 데이터의 크기를 저장한 키워드를 data type(자료형)이라 한다.
* "int" : 4바이트 공간, 정수형 데이터 저장할 공간 -> 변수 이름.
*/

/*
* 기본 자료형의 종류와 데이터의 표현범위
* (1)정수형
* char      : 1바이트(8비트) 2e8(256) / -2e7 ~ 2e7 -1 (-128 ~ 127 : 256개)
* short     : 2바이트(16비트) -2e15 ~ 2e15 -1
* int       : 4바이트(32비트) -2e31 ~ 2e31 -1
* long      : 4바이트(32비트)
* long long : 8바이트(64비트) -2e61 ~ 2e61 -1 / 2e62
* 
* ANSI : american national standards instiue
* c언어의 표준을 정하는 협회. 컴파이러. 사람. 65 'A'. int = 4바이트 정수형. int = 6바이트.
* 컴파일러가 데이터 형의 최소 크기를 지켜라.
* 
* (2)실수형
* float      : 4바이트. 부호. 지수부.가수부 // 소수점 6자리 표현.
* double     : 8바이트. 소수점 15자리 표현
* long float : 8바이트. 소수점 16자리 표현
*/

/*
* 1부호(MSB) 0, 1, 음수, 양수...
* 부호가 필요 없다. unsigned
* unsigned char (변수 이름) : 0 ~ 2e8개 저장. 부호 없는 정수 표현식.
* unsigned int (변수 이름)  : 0 ~ 2e32개 저장.
*/

/*
* sizeof 연산자 .. 정수 (n)바이트..
* int i_num = sizeof(int); //4
* int i_num = sizeof a;    // sizeof () 한다고해서 함수가 아니다.
* int i_num = sizeof(a);   // 일반적으로 ()와 함께 사용한다.
*/

/*
* 상수
* 변하지 않는 수.
* 변수(변하는 수) - 자료형.
* 
* 종류 : 이름을 갖는 상수, 이름을 갖지 않는 상수
* 리터럴 상수 (literal) 문자 그대로 변하지 않는 수.
* double my_double = 3.15;
* my_double = 2.96;
* 
* 
* int my_int = 10;    // int
* char my_char = 5;   // int
* short my_short = 7; // int
* int my_int = 30억 보다 큰수. 21억... 2e31-1 // long long
* 
* 리터럴 상수에서
* 정수는 기본 자료형이 int입니다.
* int보다 큰 수가 입력이 되면 자동으로 int보다 큰 데이터형이 선택이 됩니다.
* 
* int보다 작은, char, short는 왜 int로 컴파일러가 지정을 하나요?
* 가장 많이 처리하는 타입 int.
* short -> char // int계산된 녀석들과 연산을 해야 하는 경우가 잦습니다.
* 컴퓨터가 처리할 수 있는 가장 빠른 단위(int) 지정해서 데이터 타입을 바꾸어 주고 있다. 컴파일러, 사람.
* 
* 실수는 기본 자료형이 double을 사용하고 있습니다.
* my_double = 3.15;
* float my_float = 3.15f?;
* 
* my_long = 3.15l;
* ul  : unsigned long
* ll  : long long
* ull : unsigned long long
* 
* f : float
* l : long float
*/

/*
* 이름 있는 상수 : 심볼릭 상수.
* 중력의 크기 : -9.8f;
* 파이        : 3.141592........
* 
* const float gravity = -9.8f;
* const 선언과 동시에 초기화를 해줘야 합니다.
* 
* 전처리기가 컴파일하기 전에 garavity라는 변수를 전부 -9.8로 변환시킨다.
* #befine gravity = -9.8f;
* 
* 상수를 작성할 때 이름 명명 방법.
* 대문자로 작성을 해주되, 띄어쓰기는 "_" 표시한다.
* 예시) GET_TIME_PRICPLE
*/

#include "lectures.h"

void lectures9()
{
	printf("기본 자료형 예제 문제 \n\n");
	
	// sizeof 연산자를 사용해서 데이터형을 출력하기 .. 
	// char, short int, long, long long, float, double, long float

	//이렇게 했으면 경고를 해결해 볼 수도 있을겁니다.
	int sizenum = sizeof(char);
	printf("char 데이터 크기 : %d \n", sizenum);
	
	sizenum = sizeof(short);
	printf("short 데이터 크기 : %d \n", sizenum);
	
	sizenum = sizeof(int);
	printf("int 데이터 크기 : %d \n", sizenum);

	sizenum = sizeof(long);
	printf("long 데이터 크기 : %d \n", sizenum);

	sizenum = sizeof(long long);
	printf("long long 데이터 크기 : %d \n", sizenum);

	sizenum = sizeof(float);
	printf("float 데이터 크기 : %d \n", sizenum);

	sizenum = sizeof(double);
	printf("double 데이터 크기 : %d \n", sizenum);

	sizenum = sizeof(long float);
	printf("long float 데이터 크기 : %d \n\n", sizenum);

	sizenum = sizeof(double);
	double my_double = 2.45;
	printf("double 데이터 크기 : %d \n", sizenum);
	sizenum = sizeof(long double);
	printf("long double 데이터 크기 : %d \n\n", sizenum);

	// 문제2. 리터럴 상수를 sizeof 연산자로 출력해보세요.
	// 3.15, 3.15f, 10, 어떤 데이터를 출력하는지 파악해보기
	// 예를 들어 sizeof(5); 어떤 값이 출력하는 함수를 표현해보기.
	sizenum = sizeof(10);
	printf("정수형 리터럴 정수 크기 : %d\n", sizenum);
	sizenum = sizeof(3.14);
	printf("리터럴 상수의 실수 표현의 기본 자료형 : %d\n", sizenum);
	sizenum = sizeof('A');
	printf("문자의 상수 표현의 기본 크기 : %d\n", sizenum);

	sizenum = sizeof(3.15);
	printf("3.15의 값 : %d \n", sizenum); // long float
	sizenum = sizeof(3.15f);
	printf("3.15f의 값 : %d \n", sizenum); // float
	sizenum = sizeof(10);
	printf("10의 값 : %d \n\n", sizenum); // int

	// 문제3. 직사각형의 넓이를 구하는 프로그램을 작성을 해보세요.
	// 첫번째 조건 : 좌표를 두개 지정받아야 합니다. (xpos1,ypos1) (xpos2,ypos2)
	// 두번째 조건 : xpos2가 xpos1보다 커야합니다.
	// xpos2 - xpos1 길이로 하는 직사각형을 구하시면 됩니다.
	// (4,6) (6,8) 2x2 = 4
	int xpos1, ypos1, xpos2, ypos2, result;
	printf("좌표를 순서대로 입력하세요 (xpos2,ypos2가 xpos1,ypos1보다 커야합니다) : (xpos1,ypos1) (xpos2,ypos2)\n");
	// 두번째 조건을 printf로 안내해주세요. (위에 표시) 좌표1과 좌표2를 따로 입력시키기 및 상세 설명
	scanf_s("%d %d %d %d", &xpos1, &ypos1, &xpos2, &ypos2);
	result = (xpos2 - xpos1) * (ypos2 - ypos1);
	
	/* chatgpt
	if (xpos1 > xpos2)
	{
		int temp = xpos1;
		xpos1 = xpos2;
		xpos2 = temp;
	}

	if (ypos1 > ypos2)
	{
		int temp = ypos1;
		ypos1 = ypos2;
		ypos2 = temp;
	}
	*/

	printf("직사각형의 넓이 : %d \n\n", result);

	// 심볼릭 상수 문제1.
	// const 키워드를 사용하여 파이를 PI로 저장하고 그 값을 3.14로 한다.
	// 원의 넓이를 구하는 코드를 상수를 사용하여 표현하세요
	const double PI = 3.14;
	int AREA;
	scanf_s("%d", &AREA);
	scanf_s("%f", &PI); //필요하지는 않음
	printf("원의 넓이 : %f", AREA * PI);
}