/*
* 작성자   : 정현준
* 작성일   : 2024-07-11
* 학습목표 : 포인터에 대한 이해
*/

// 포인터의 선언
// (데이터타임) * 이름;

/* 
* 포인터가 뭔가
* 포인터 변수. 변하는  값(주소)을 저장
*/

/*
* 메모리를 구하는 연산자 : 주소연산자 &
* 사용법 : 변수를 먼저 선언. &num
* 의미 : num이 가지고 있는 주소를 반환하라.
*/

/*
* 주소를 16진수 8개 or 16개 비트 공간을 사용해서 메모리 주소 표현.
* 주소를 표현할때 [16진수 4비트]
* 
* 
*/

/*
* 메모리의 주소저장
* int * numPointer; (줄인말 numptr) 변수의 이름
* 포인터 변수를 선언하는 것
*/

// 우리는 포인터를 왜 써야 하는가?

#include "lectures.h"

void lectures17()
{
	printf("아녕!");

	int num; // 변수의 선언
	int num2;

	scanf_s("%d", &num);
	printf("num의 값 출력 : %d\n\n", num);

	// 포인터에 대해서 익숙해지자
	// 포인터 * 의 위치는 상관없다.
	int* numptr = &num; // int * numptr 포인터 변수 선언과 초기화
	int * numptr2 = &num;
	int *numptr3 = &num;

	printf("%p\n", numptr);
	printf("%p\n", numptr2);
	printf("%p\n", numptr3);

	printf("%d\n", *numptr);
	printf("%d\n", *numptr2);
	printf("%d\n\n", *numptr3);

	// 포인터를 출력 - 16진수 주소가 출력된다.

	// 주소에 저장된 값을 출력하는 방법.
	// 역참조 연산자
	// '*' 이항연사자 : 곱하기
	// 단항연산자 : 이미 선언된 포인터 변수 앞에. *numptr
	// numptr의 가리키고 있는 값을 참조한다.
	// int sum = 2 * 4;

	// 실습> 정수 int number 20을 할당해주세요, 정수형 포인터 변수 numberptr 선언하고, numberdp 있는 주소를 할당해주세요
	// printf를 사용해서 numberptr에 있는 값을 출력해보시면 됩니다. (*연산자 사용해주세요)
	
	// 변수 -> 값 + 주소.

	// 0. 변수 선언 및 초기화
	int number = 20; // number이름 20값. number 주소

	// 1. 포인터 변수를 선언하는 방법 : <int*>
	int* numberptr = &number;

	// 2. 변수의 주소를 반환하는 연산자 주소 연산자 : <&>
	// 포인터 변수
	// 포인터 변수의 값 : 주소, 주소가 가르키고 있는 데이터(참조)
	printf("numberptr 주소 : %p\n", numberptr);

	// 3. 포인터 변수가 가리키고 있는 참조를 반환하는 연산자 : <*>
	printf("numberptr의 참조 값 : %d\n", *numberptr);

	// 주소가 참고하고 있는 값을 수정하는 법
	// 포인터 주소가 참조하고
	// 주소를 이용해서 값을 변경하는 작업 : 익숙해져야 합니다.
	printf("기존 number의 값 :%d\n", number);
	*numberptr = 30;
	printf("number의 값 : %d\n\n", number);

	// 한번 더 정리
	// 1. 변수 num 1 = 10; 변수의 특징 : 메모리 주소를 몰라도 값을 가져오거나 저장할 수 있다.
	// 2. 주소 연산자& : 변수의 메모리주소를 구하는 녀석. &num1 : 변수로 부터 주소를 구할 수 있다. 0xABCD ;
	// 3. 역참조 연산자* : 포인터 변수가 참조하고 있는(메모리 상에 가리키고) 값에 접근할 수 있다.
	// *numptr <<- 역참조, 포인터 선언?

	// int * numptr : 포인터 변수 선언
	// *numptr      : 포인터 변수의 참조 값을 호출, numptr의 포인터 변수다.
	// *numptr = 30; : 포인터 가리키고 있는 참조의 값을 변경한다. 포인터가 가르키고 있는 변수의 값이 변한다.

	int a_num = 10;
	int* a_numptr = &a_num;
	int* b_numptr = a_numptr;

	(*a_numptr)++; // *a_numptr = 11
	(*b_numptr)++; // *b_numptr = 12
	printf("%d \n", a_num);

	// 예제 문제
	int e_num1 = 10, e_num2 = 20; // 변수 이름 e_num1, e_num2 선언해서 10, 20 할당해주세요.
	int* e_num1ptr = &e_num1;
	int* e_num2ptr = &e_num2; // e_num1, e_num2를 가리키는 포인터 e_num1ptr, e_num2ptr를 선언 후 대입해주세요.
    // int* temp 포인터 하나 선언을 하시고,
	// temp에 e_num1ptr 대입, e_num2에 -> e_num1, e_num2 temp값 받아오기.
	

	// swap 구현

	printf("%d %d\n", *e_num1ptr, *e_num2ptr); // 본래의 값 출력
	int* temp;// int* temp 포인터 하나 선언을 하시고,
	temp = e_num1ptr;// temp에 e_num1ptr 대입, e_num2에 -> e_num1, e_num2 temp값 받아오기.
	e_num1ptr = e_num2ptr;
	e_num2ptr = temp;

	printf("%d %d\n", *e_num1ptr, *e_num2ptr); // 변경한 값 출력

	// 복습
	int exam_num1 = 10, exam_num = 20, temp_num;

	// num1, num2 바꿔서 출력하세요
}