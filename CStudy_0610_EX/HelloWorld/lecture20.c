/*
*   작성일 : 2024-07-16
*   작성자 : 김동훈
*   학습목표
* 	-포인터의 인자를 함수에 사용한다.
*   -Call by Value와 Call by Reference에 대해서 이해한다.
*/

// 정리.
// 변수 - 값, 주소. &주소연산자
// 포인터 변수 - 주소 저장. *역참조연산자
// 포인터 변수 더하기 빼기. sizeof(데이터)
// 배열이 상수 포인터 : 저장한 주소를 변경하지 못하게 하는 것. Constant pointer
// 상수를 가리키는 포인터 : 값을 변경하지 못한다. pointer to constant

// 배열을 매개 변수로 쓰기 위해서 포인터 변수.

// 배열을 선언하는 법 : int arr[10]; 처음 선언할 때 크기까지 만들어 줘야합니다.
// int arr[?] = 대입하는 코드가 불가능하다.
// 배열은 상수포인터.
// int arr2[10];
// arr = arr2; 

// 값이 그 크기에 따라서 변한다.
// 시작할 때 값을 초기화해주어야 한다.

void AddArrayElement(int* arr, int len, int add) // 배열 요소의 값을 n만큼 더하는 함수로 변경해보세요.
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] += add;
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Call by Value vs Call by Reference
// 함수가 종료될 때 값을 반환한다.
// return;   -- 그 시점에서 함수를 종료시키고 함수를 호출한 곳으로 돌아간다. 
// return 0; -- 함수를 종료하는 시점에 0을 반환한다.

// 반환값이 없는 경우 void
// 반환값이 있는 경우 : 반환 하고 싶은 데이터형을 입력해주면 된다.

void Call_by_Value(int _num)
{
	_num = _num + 10;
}

void Call_by_Reference(int* _numPtr)
{
	_numPtr = _numPtr + 1;
}

// Call_by_Value 값에 의한 호출 : 함수 호출 시 기본적으로 외부에 영향을 주지 않습니다.
// 포인터라는 녀석은 *(역참조 연산자)사용하여 함수 외부 주소를 참조해서 값을 변경할 수 있었습니다.

#include "lectures.h"


void SquareByValue_20(int num) 
{
	num = num * num;
	printf("함수 안에서 실행 된 결과 : %d \n", num);
}

void SquareByRef_20(int* numPtr)
{
	*numPtr = *numPtr * (*numPtr);
}


void ChangeElement(int* a,int* b,int* c)
{
	// a -> b, b -> c, c - >a 값을 변경하는 함수를 만들어 보시면 되겠습니다.
	// temp 사용하면 됩니다.
	int temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
}

void ChangeElement_2(int a, int b, int c)
{
	int temp = a;
	a = b;
	b = c;
	c = temp;
	printf("Call by Value 함수 : %d %d %d\n", a, b, c);
}

// 전역 변수 , 지역 변수
// 지역 변수 : { } 안에 작성되는 변수. { } 스택이 종료될 때 변수도 같이 소멸된다.
// 전역 변수 : 

int global_val_l20 = 30;	  //  점수 몬스터 처치. While() 점수. 아이템 점수.

void DoublePointerCallByRef(int** ref) 
{
	*ref = &global_val_l20;
}

void DecimalToBinaray(int num) // 10 1010(2)
{
	int binaray[1000000] = {0};	  // 2
	int pos = 0;

	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;
		
		if (num ==0)
			break;
	}

	// binaray[pos] <- 이진수 대입

	for (int i = pos - 1; i >= 0; --i) {
		printf("%d", binaray[i]);
	}
}

void lecture20()
{
	int arr[3] = { 0,1,2 };		  // 5,6,7
	AddArrayElement(arr, 3, 5);   // 포인터 배우기 전에는 왜 함수로 바꾸는 것을 안했을 까?


	int a = 10;
	int num = a;
	int* numptr = &num;

	Call_by_Value(num);
	printf("Call_by_Value num의 값 :%d\n", num);
	Call_by_Reference(numptr);
	printf("Call_by_Reference num의 값 :%d\n", num);

	printf("예제 문제 1\n");
	int b = 3;
	SquareByValue_20(b);  // 값이 변경되지 않는 것
	printf("b의 값 : %d\n", b);
	SquareByRef_20(&b);   // 값이 제곱이 되서 출력이 되도록 만들어 주세요.
	printf("b의 값 : %d\n", b);

	printf("예제 문제 2\n");

	int t1 = 10, t2 = 20, t3 = 30;
	ChangeElement_2(t1, t2, t3);
	ChangeElement(&t1, &t2, &t3);
	printf("%d %d %d\n", t1, t2, t3);

	printf("이중 포인터\n"); //   포인터 (주소)변수 - 주소

	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	p3Ptr = &global_val_l20; // 이중 포인터 : 주소로 가리키고 있는 변수의 주소 = 0x11111

	DoublePointerCallByRef(&p1Ptr);
	printf("%d", *p1Ptr);


	printf("예제 문제 3\n");
	// 10진수를 2진수로 변환해서 출력하는 함수를 만들 것.

	int input;
	scanf_s("%d", &input);
	
	// binaray[pos] <- 이진수 대입

	DecimalToBinaray(input);

	// 11을 2진수로 만드는 법
	// 11/2   =  5 + 1
	// 5/2    = 2 + 1
	// 2/2    = 1  +  0
	// 1/2    = 0 + 1
	// 1011(2) :  1+2+8 = 11

}