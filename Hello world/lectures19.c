/*
*  작성일 : 2024-07-15
*  작성자 : 정현준
* 학습 목표 : 배열과 포인터의 차이 => "상수" 포인터
*/

// 1. 배열과 포인터의 차이
// (1) sizeof(배열) , sizeof(포인터변수) 각각의 값이 다르게 나왔다.
// (2) 배열은 상수 포인터다.

// 2. 포인터와 상수
// (1) 상수를 가르키는 포인터 pointer to constant
// (2) 포인터 그 자체가 상수 constant pointer
// (3) 상수를 가리키는 그 자체가 상수인 포터 constant pointer to constant


#include "lectures.h"

void ShowData(const int* ptr)	// const int* arr의 의미를 한번 생각해보시고.
{
	const int* rPtr = ptr;
	printf("%d \n", *rPtr);
	//*rPtr = 20;
}

void ShowAllData(int* const arr, int len)
{
	// for 반복문으로 arr의 길이 만큼 배열요소를 printf 함수를 만들어 보시고.

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

}

void lectures19()
{
	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_arr[4] = { 1,2,3,4 };
	int* s_arrPtr = s_arr;

	ShowAllData(s_arrPtr, 3);  // sizeof(arr) -> 4 *sizeof(int)/sizeof(int)

	// (1) sizeof 연산자
	int arr[3] = { 1 };  // 100
	int* arrPtr = arr; // &arr[0] 표현할 수 있다.

	printf("배열의 크기 : %d \n", sizeof(arr));	    //   siezof(int) x 100 = 400(바이트)
	printf("포인터의 크기 : %d ", sizeof(arrPtr));	//   16진수. 32비트, 64비트	   8 x 4비트 (32) , 16 x 4비트 (64)			 

	// 포인터로 코드를 작성하는 것. 실수가 많아질 가능성 높아지고, 이해하기도 난해하다.
	// 4000바이트 8바이트 표현할 수 가 있다.
	// 포인터 문법 사용하지 않는 언어.

	// Constant (상수)
	// Pi = 3.14; 
	// 코드의 안정성을 더해주는 한정자. 뒤에 선언되는 변수는 바뀔 수 없다.
	//const int Pi = 3.14;
	//pi = 3.5;

	//(1) 상수를 가르키는 포인터 pointer to constant
	// num의 값을 변경하지 못하게 막아준다.
	// const int* 포인터 변수도 그 값을 변경하지 못한다.  역참조 연산자로 값을 못바꾼다.
	const int num = 10;
	//num = 15;
	const int* numPtr = &num;  // int const* numPtr = &num;
	//*numPtr = 15;

	// (2) 포인터 그 자체가 상수 constant pointer

	int num1 = 20;
	int num2 = 30;
	int* const numCptr = &num1;	 // 상수 포인터의 선언. 배열이 상수 포인터.
	*numCptr = 40;
	//numCptr = &num2;             // 상수 포인터. 주소를 변경하지 못한다.
								   // 배열은 상수 포인터. 배열의 선언 이 후 배열의 주소를 변경할 수 없다.

	// (3) 상수를 가리키는 그 자체가 상수인 포터 constant pointer to constant
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCptr2 = &num3;
	//*numCptr2 = 50;
	//numCptr2 = &num4;


	// 정리
	// 포인터. 변수.
	// 변수 - 값, 주소(&)
	// 포인터 - 주소, 값(*)

	// 포인터 선언
	// + Const
	// 값 const, 주소 const
	// 값 const - 상수 포인터             costant pointer								    
	// 주소 const - 상수를 가리키는 포인터 pointer to constant
	// Const 포인터에 사용하는 이유?
	// 포인터 변수가 절대로 변경되지 않기를 컴파일러 단계에서 보장하기 위해서 (안정성을 보장하기 위해서)

}