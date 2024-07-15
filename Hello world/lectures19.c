/*
* 작성일 : 2024-07-15
* 작성자 : 정현준
* 학습 목표 : 배열과 포인터의 차이 => "상수" 포인터
*/

// 1. 배열과 포인터의 차이
// (1) sizeof(배열), sizeof(포인터변수) 각각의 값이 다르게 나왔다.
// (2) 배열은 상수 포인터다. 

/* 2. 포인터와 상수
* (1) 상수를 가르키는 포인터 pointer to constant
* (2) 포인터 그 자체가 상수 constant pointer
* (3) 상수를 가리키는 그자체가 상수인 포인터 constant pointer to constant
*/

#include "lectures.h"

void lectures19()
{
	// (1) sizeof 연산자
	int arr[3] = { 1,2,3 };
	int* arrptr = arr; // &arr[0] 표현할 수 있다.

	printf("배열의 크기 : %d \n", sizeof(arr)); // sizeof(int) x 3 =12
	printf("포인터의 크기 : %d", sizeof(arrptr)); // 16진수. 32비트, 64비트 8x4 32비트, 16x4 64비트

	// 포인터로 코드를 작성하는 것. 실수가 많아질 가능성 높아지고, 이해하기도 난해하다.
	// 4000바이트 8바이트 표현할 수 있다.
	// 포인터 문법 사용하지 않는 언어.

	// constant (상수)
	// pi = 3.14;
	// 코드의 안전성을 더해주는 한정자. 뒤에 선언된느 변수는 바뀔 수 없다.
	// const int pi = 3.14;
	//pi = 3.5;

	// (1) 상수를 가르키는 포인터 pointer to constant
	// num의 값을 변경하지 못하게 막아준다.
	// const int* 포인터 변수도 그 값을 변경하지 못한다. 역참조 연산자로 값을 변경하지 못한다.
	const int num = 10;
	// num = 15;
	const int* numptr = &num; // int const* numptr = &num
	// *numptr = 15;

	// (2) 포인터 그 자체가 상수 constant pointer

	int num1 = 20;
	int num2 = 30;
	int* const numcptr = &num1; // 상수 포인터의 선언. 배열이 상수 포인터.
	// numcptr = &num2;         // 상수 포인터. 주소를 변경하지 못한다.
	                            // 배열은 상수 포인터. 배열의 선언 이 후 주소를 변경할 수 없다.

	// (3) 상수를 가리키는 그자체가 상수인 포인터 constant pointer to constant
	const int num3 = 40;
	const int nmm4 = 50;
	int* const numcptr2 = &num3;
}