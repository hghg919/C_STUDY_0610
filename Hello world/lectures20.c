/*
* 작성일 : 2024-07-16
* 작성장 : 정현준
* 학습목표
* - 포인터의 인자를 함수에 사용한다.
* - call by value와 cell by refefrence에 대해서 이해한다.
*/

// 변수 - 값, 주소, &주소연산자
// 포인터 변수 - 주소 저장, *역참조 연산자
// 포인터 변수 더하기 빼기. sizeof(데이터)
// 배열이 상수 포인터 : 저장한 주소를 변경하지 못하게 하는 것. constant pointer
// 상수를 가리키는 포인터 : 값을 변경하지 못한다. pointer to constant

// 배열을 매개 변수로 쓰기 위해서 포인터 변수.

// 배열을 선언하는 법 : int arr[10]; 처음 선언할때 크기까지 만들어 줘야합니다.
// int arr[?} = 대입하는 코드가 불가능하다.
// 배열은 상수포인터.
// int arr2[10];
// arr = arr2;

// 값이 그 크기에 따라서 변한다.
// 시작할 때 값을 초기화 해주어야 한다.

void addarrayelement(int* arr, int len, int add) // 배열 요소의 값을 n만큼 더하는 함수로 변경해보세요.
{
	for (int i = 0; i < len ; ++i)
	{
		arr[i] += add;
		printf("%d", arr[i]);
	}
	printf("\n");
}

// call by value VS call by reference
// 함수가 종료될 때 값을 반환한다.
// return;   -- 그 시점에서 함수를 종료시키고 함수를 호출한 곳으로 돌아간다.
// return 0; -- 함수를 종료하는 시점에 0을 반환한다.

// 반환값이 없는 경우 void
// 반환값이 있는 경우 : 반환하고 싶은 데이터형을 입력해주면 된다.

void call_by_value(int _num)
{
	_num = _num += 10;
}

void call_by_reference(int* _numptr)
{
	*_numptr = *_numptr + 10;
}

// call_by_value 값에 의한 호출 : 함수 호출 시 기본적으로 외부에 영향을 주지 않습니다.
// 포인터라는 녀석은 *(역참조 연산자) 사용하여 함수 외부 주소를 참조해서 값을 변경할 수 있었습니다.

#include "lectures.h"

void squarebyvalue_20(int num)
{
	num = num += 10;
	printf("함수 안에서 실행 된 결과 : %d \n", num);
}

void squarebyref_20(int* numptr)
{
	*numptr = *numptr * (*numptr);
}

void changeelement(int *a,int *b ,int *c)
{
	int temp = *a;
	*a = *b, *b = *c, *c = temp;// a -> b, b->c, c->a 값을 변경하는 함수를 만들어 보시면 됩니다.
	//temp 사용하면 됩니다.
}

void changeelement_2(int a, int b, int c)
{
	int temp = a;
	a = b, b= c, c = temp;
	printf("call by value 함수 : %d %d %d\n", a, b, c);
}

// 전역 변수, 지역 변수 
// 지역변수 : {} 안에 작성되는 변수. {} 스택이 종료될때 변수도 같이 소멸된다.
// 전역변수 : 

int global_val_l20 = 30; // 전역변수 // 점수 : 몬스터처치, while()함수, 아이템점수.

void dublepointercallbyref(int** ref)
{
	*ref = &global_val_l20;
}

void decimaltobinaray(int num) // 10 1010(2)
{
	int binaray[20] = {0};
	int pos = 0;
	
	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;

		if (num == 0)
		{
			break;
		}
	}

	// binaray[pos] <- 이진수 대입?

	for (int i = pos; i >= 0; --i)
	{
		printf("%d", binaray[i]);
	}
}

void lectures20()
{
	int arr[3] = { 0.1,2 }; // 5,6,7
	addarrayelement(arr, 3, 5);

	int a = 10;
	int num = a;
	int* numptr = &num;

	call_by_value(num);
	printf("call_By_value num의 값 : %d\n", num);
	call_by_reference(numptr);
	printf("call_By_reference num의 값 : %d\n\n", num);

	printf("예제문제1\n");
	int b = 3;
	squarebyvalue_20(b); // 값이 변경되지 않는것
	printf("b의 값 : %d\n", b);
	squarebyref_20(&b); // 값이 제곱이 되서 출력이 되도록 만들어 주세요.
	printf("b의 값 : %d\n\n", b);

	printf("예제문제2\n");
	int t1 = 10, t2 = 20, t3 = 30;
	changeelement(&t1, &t2, &t3);
	changeelement_2(t1, t2, t3);
	printf("%d %d %d\n\n", t1, t2, t3);

	printf("이중 포인터\n"); // 포인터(주소)변수 - 주소
	int p1 = 10;
	int p2 = 20;
	int* p1ptr = &p1;
	int* p2ptr = &p2;
	int* p3ptr = NULL;

	p3ptr = &global_val_l20; // 이중 포인터 : 주소를 가리키고 있는 변수의 주소 - 0x11111

	dublepointercallbyref(&p1ptr);
	printf("%d\n\n", *p1ptr); // 오류

	printf("예제 문제 3\n");
	// 10진수를 2진수로 변환해서 출력하는 함수를 만들것.

	int input;
	scanf_s("%d", &input);

	decimaltobinaray(input);

	// 11을 2진수로 만드는법
	// 11/2 = 5 + 1
	// 5/2 = 2 + 1
	// 2/2 + 1 + 0 
	// 1/2 = 0 + 1
	// 1011(2) : 1+2+8 = 11 
}