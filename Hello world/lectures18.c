/*
* 작성자 : 정현준
* 작성일 : 2024.07.12
* 학습목표 : 포인터의 연산
*/

/*
*  1. 포인터 주소의 연산자?
*/

#include "lectures.h"

void lectures18()
{
	printf("18강이야 18강\n");


	// num 변수 10. 정수형 포인터 numptr
	// num - numptr 연결. numptr num에 들어간 값을
	// 1 증가시켜서 출력
	int num = 10;
	int* numptr = &num; // 주소를 초기화
	(*numptr)++; // 역삼조연산자 : 주소가 가르키는 값을 반환

	printf("num의 값 : %d\n\n", num); // num의 값 : 11

	// 이 코드를 그대로 작성하면 에러가 발생. *(numptr++);

	// 16진수로 포인터 변수에 값을 넣어서 주소의 값을 지정.
	int* numptrA = 0x100000;
	int* numptrB = 0x100000;

	numptrA = numptrA + 1; // numptrA++;
	numptrB = numptrB + 2; // numptrB+=2;

	printf("ptrA의 값 : %p\n", numptrA); // 0x100004
	printf("ptrB의 값 : %p\n", numptrB); // 0x100008


	// 주소의 크기를 구해보자.
	printf("포인터 변수의 크기 : %d\n", sizeof(numptrA)); // x86 : 4 ?오류?
	printf("포인터 변수의 크기 : %d\n", sizeof(numptrA)); // x64 : 8

	// 포인터 변수의 크기가 다른 이유
	// 주소르 저장하는 변수. 크기를 가집니다.
	// 16진수 1개의 바이트 공간. 8개 - 4비트 x 8 = 32
	// x86 : 왜 32비트? intel 8086 개인컴퓨터 32비트 아키텍처 제공
	// x86 = 32비트.

	// int* // 4바이트 - 정수. 주소는 첫번째 바이트에 저장. 시작부터 크기까지 공간을 확보해서 저장.
	// 
	// 포인터와 배열
	// int형 데이터 타임 int num1, num2, num3, num4 ...:
	// 배열을 어떻게 사용할 수 있는가?
	int numarr[5] = { 11,22,33,44,55 };

	int index = 0;

	// numarr 33의 값을 출력해주는 코드를 printf 작성해보새요.
	printf("numarr 3번째 요소 출력 : %d\n", numarr[index + 2]); // 배열의 시작 0부터.

	//index의 값에 더하기 또는 빼기 연산자를 사용해서 numarr을 반복문으로 출력해보세요.

	printf("numarr 정방향 출력 :");
	for (int i = 0; i < 5; i++)
	{
		printf("%d", numarr[i]);
	}

	printf("\n");

	printf("numarr 역방향 출력 :");
	for (int i = 4; i >= 0; i--)
	{
		printf("%d", numarr[i]);
	}

	printf("\n\n");

	// 배열의 index가 배열이 가지고 있는 값을 가리키고 있다.
	// 배열을 포인터로 바꿀 수 있지 않을까?

	int arr1[3] = { 0.1,2 };
	printf("배열의 이름 : %p\n", arr1);

	for (int i = 0; i < 3;i++)
	{
		printf("배열의 요소 : %d 요소 : %p\n", i, &arr1[i]);
	}

	/*
	* 정리
	* 배열의 첫번째 요소의 값의 주소를 반환을 했더니
	* 그 결과값이 배열의 이름의 주소와 같다.
	* 배열의 이름은 포인터였습니다.
	*/

	// 배열에서 포인터 연산자. &, *;

	// 정리.
	// int 포인터 변수 +1 : 주소의 값이 4만큼 크기가 커졌습니다.

	char* charptr = 0x1000000;
	charptr++;
	printf("%p\n", charptr); // 0x1000001 .. char 1바이트
	short* shortptr = 0x1000000;
	printf("%p\n", shortptr); // 0x1000002 .. char 2바이트

	// 포인터 연산의 공식
	// sizeof(char)* : 데이터의 크기
	charptr += 10; // 0x1000000 + 10(1x10);
	shortptr += 10; // 0x1000000 + 20(2x10);

	// int포인터 10만큼 증가 4x10
	// 포인터의 연산은 sizeof(데이터형) x n(더해준 수) 크기가 증가한다.

	int arr2[3] = { 0,1,2 };
	// 배열도 포인터, 포인터 변수 선언 배열을 연걸.
	int* s_ptr = arr2;
	int* s_ptr2 = &arr2[0];

	&arr2[0]; // 주소 arr2 배열 1번째 주소
	&arr2[1]; // 2번째 주소
	&arr2[2]; // 3번째 주소

	printf("주소의 연산 후 역참조 : %d\n", *(s_ptr + 1)); // s_ptr 포인터 변수. s_ptr가리키고 있는 주소 4를 증가시켰습니다.
	printf("역참조 후 값 덧셈 : %d\n\n", (*s_ptr2)++);

	// printf("주소의 연산 후 역참조 : %d\n", *(s_ptr++)); // s_ptr 포인터 변수. s_ptr가리키고 있는 주소 4를 증가시켰습니다.

	// 예제 문제

	// 길이가 5인 배열 선언. firstarr {1,2,3,4,5]
	// firstarr이름을 firstarrptr 포인터 변수에 넣어주세요. firstarrptr =
	// firstarrptr 연산을 이용해서 해당 주소의 값을 3을 증가해주시면 됩니다.
	// 반복문을 사용해서 1-> 4, 2->5...

	int firstarr[5] = { 1,2,3,4,5 };
	int* firstarrptr = firstarr; // 배열은 주소 연산자 없음데 주소입니다. &주소.
	// 포인터 변수. 주소의 변수. 주소.
// 포인터 덧셈(연산)
// sizeof(type). +1 다음 배열 요소를 가리킨다.
// firstarr[i] =+3; i+1; << 포인터 변수로 표현
	for (int i = 0; i < 5; i++)
	{
		*firstarrptr += 3; // firstarr[i] += 3;
		firstarrptr++; // i+1; 
	}

	for (int i = 0 ; i < 5 ; i++)
	{
		printf("배열의 요소에 3을 증가시킨 값 : %d\n", firstarr[i]);
	}

	printf("\n");

	// 정리
	// int num = 10;
	// *(ptr)++; 포인터 덧셋의 의미 : 포인터가 가리키고 있는 참조값 반환 그 값에 1을 더해라. num = 10; 1을 더해서 11이 반환된다.
	// *(ptr + 1); 의미의 차이점 : 포인터가 가리키고 있는 주소 type 크기를 더해서. 현재 가키리고 있는 주소를 변경시킨다.

	// 배열과 포인터. 완벽하게 같나요?

	int exarr[5] = { 0 };
	int* arrptr2 = exarr;
	printf("배열의 크기 : %d \n", sizeof(exarr));
	printf("포인터의 크기 : %d \n", sizeof(arrptr2));

	// 최대한 메모리르 아껴 쓰자.
	// arr[1000] -> 4 x 1000; 8

	// 예제 문제2. 포인터 연산의 뺄셈을 사용해서 배열의 큰 수 부터 작은 수를 출력하도록.
	int secondarr[5] = {1,2,3,4,5}; // 정수형 배열 5개 선언 및 초기화
	int* secondarrptr = secondarr;  // 포인터(주소를 저장하는 변수) 배열의 이름 자체가 포인터. &secondarr : 주소의 주소
	secondarrptr += 4;              // 포인터 변수 +4 : sizeof(int) * n
	
	printf("예제문제 2 풀이 : \n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d", * secondarrptr);
		secondarrptr--;
	}

	// 정리
	// 변수 - 값, 주소
	// &주소연산자, 포인터 int *
	// 포인터 변수 역참조연산자 * 포인터변수
	// 포인터 변수 ++
	// 16진수 0x1000; +1 sizeof(int)
	// 배열의 이름 -- 포인터 변수

	// 정리(2)
	printf("%d");

	int o_arr[3] = { 1,2,3 };
	int* o_arrptr = o_arr;
	
	for (int i = 0; i < 3; i++)
	{
		printf("*(ptr + i) : %d", *(o_arrptr + i));
		printf("*(arr+i) : %d ", *(o_arr + i));
		printf("arr[1] : %d", o_arr[i]);
		printf("ptr[i] : %d\n", o_arrptr[i]);
	}

	// 배열과 포인터 정리
	/*
	* (ptr +0)(ptr+1)(ptr+2) // 포인터 변수 주소의 연산
	* (arr+0)(arr+1)(arr+2) // 배열 이름(주소) 연산
	* ptr[0] = *(ptr+0);
	* arr[0] = *(arr+0);
	* ptr[0] ptr[1] ptr[2]
	* arr[0] arr[1] arr[2]
	* 
	* 배열과 포인터 사이의 공식 : arr[1] = *(arr + i)
	*/

	// 잘못된 포인터의 사용, 널 포인터
	int* o_numptra = 0x100000; // int num = 0;

	printf("%p", o_numptra); //0x100000 메모리 주소에 여기에 값이 있을수도 있고 없을수도 있죠.
	//printf("%d", *o_numptra); //포인터 직접 주소 배정해주는 것은 위험하다. 오류가 발생할 가능성이 높다.

	int* o_numptra = 0;    // NULL : 널포인터. 이주소가 아무것도 가리키고 있지 않다.
	int* o_numptra = NULL; 

	// 예제 문제3. 길이가 6인 배열을 선언해서 1.2.3.4.5.6 => 6,5,4,3,2,1 출력하게 하는 코드를 작성.

	int t_arr[6] = { 1,2,3,4,5,6 }; // 1,2,3,4,5,6 정수형 선언 초기화
	int* frontptr = (t_arr + 0);
	int* backptr = (t_arr + 5);
	int temp;

	printf("바꾸기 이전의 값\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d", t_arr[i]);
	}

	printf("\n");
	printf("바꾸기 이후의 값\n");
	for (int i = 0 ; i < 3 ; i++); // 베열의 길이(6) 나누기 2 한 값 : 3
	{
		temp = *frontptr;
		*frontptr = *backptr;
		*backptr = temp;
		frontptr++;
		backptr--;
	}

	// ctrl + c == ctrl + v 하기

}