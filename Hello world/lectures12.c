/* 
*  작성자  : 정현준
*  작성일  : 2024-06-25
* 학습목표 : 반복문의 이해와 실습
*/

/*
* 반복문을 써야 하는 이유?
* 불필요한 반복적인 코드를 간결하게 표현할 수 있다.
*/

/*
* 종류 : for 반복문, while 반복문
* 
* for( 초기식 ; 조건식 ; 변화식 ) // 루프 선언문 loop statenment
* {
*     코드 내용;                 // 루프 본체 loop body
* }
* 
* 초기식 : int i = 0, 반복문이 시작할 때 필요한 변수의 선언 및 할당이 이루어지는 공간. ';'
* 조건식 : i < 10, 조건식이 참이면 루프 본체의 코드를 실행한 후 변화식을 실행한다. ';'
* 변화식 : i++, 초기식의 변수 값을 변화시켜서 조건을 탈출할 수 있도록 하는 식입니다.
*/

#include "lectures.h"

void lectures12()
{
	// 1. for 반복문
	// for 반복문의 예제

	// i++ = i = i + 1; ( 대입 연산자 보다 늦게 처리)
	// ++i = i = i + 1; ( 대입 연산자 보다 먼저 연산자 처리)

	// c =  a + b++; // c의 값이 1만 더해진 값
	// c =  a + ++b; // c의 값이 1이 더해진 값

	// hello world 10번 출력
	for (int i = 0 ; i < 10 ; i++)
	{
		printf("hello world!\n");
	}

	printf("\n");

	// 초기식, 변화식의 변화를 준다.
	int index;
	
	for (index = 10 ; index > 0 ; index--)
	{
		printf("index print! %d\n", index);
	}

	printf("\n");

	for (int i_num = 0; i_num < 10; i_num += 2) //세미콜론 쓰지 말기
	{
		printf("i_num print! %d\n", i_num);
	}

	printf("\n");

	// for( 초기식 ; 조건식 ; 변화식); //세미콜론 쓰지 말기
	{
		printf("자 이 코드는 어떻게 작동이 될까요?\n\n");
	}

	// for(~;~;~); 선언문 뒤에 ; 붙이면 아래의 루프 바디와 별개로 작동한다.

	for ( ; ; ) // 해당 코드는 무한 반복문을 표현한 코드이다. 무한 반복문에 빠지지 않도록 유의해야 한다. ctrl + c(강종)
	{
		printf("hi!\n");
	}

}

void lectures12_2()
{
	// for문과 printf 사용해서 i_scanfnum의 현재 값과 "반복문 실습", i_scanfnum의 값은 : \n
	// scanf 몇 번 반복할지 정해주기.
	
	printf("몇 번 반복문을 실행할 것인가요? 숫자를 입력해주세요\n");
	int i_scanfnum;
	scanf_s("%d", &i_scanfnum);
	
	// i_scanfnum의 현재 값과 "반복문 실습", i_scanfnum의 값은 : \n
	// 정수형 변수를 출력을 해라. printf함수로 사용해서. 앞에 "반복문 실습 i_scanfnum의 값은 :"
	
	for (int i = 0; i < i_scanfnum; i++)
	{
		printf("반복문 실습 i_scanfnum의 값은 : %d\n", i_scanfnum);
	}
	
	/*
	for (i_scanfnum = 0; 0 < i_scanfnum; i_scanfnum++) // int i????
	{
		pritnf("%d째 반복문"\n, i_scanfnum);
	}
	*/

	// for 반복문은 반복 횟수가 정해져 있는 코드를 작성할 때 유용합니다.

	// for 예제2.
	printf("반복문 예제 문제2 \n");
	for (int i = 1 ; i < 100 ; i++)
	{
		// 7의 배수와 9의 배수일 때만 아래 코드르 실행하세요
		if( i % 7 == 0 || i % 9 == 0)
		printf("%d \n", i);
	}

	// 1이상 100 미만의 정수들 중에서 7의 배수와 9의 배수를 출력하는 프로그램을 작성해 보세요.
	// 공통된 녀석이 한번만 출력되도록 코드를 작성하세요!(★주의 사항★)

	// while 예제
	// for 예제 1번 문제를 while문으로 바꾸어서 구현을 해보세요.
	// 변수를 새로 선언하셔도 되고, 다른 변수를 선언하셔도 됩니다.

	printf("\n");

	printf("반복문 예제 문제3 \n");
	int w_num;
	scanf_s("%d", &w_num);
	while (0 < w_num) // 조건식을 완성해서 입력한 수 만큼 반복하느 while 반복문을 작성해보세요.
	{
		printf("%d \n", w_num);
		w_num--;
	}
}