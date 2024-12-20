/*
* 작성자   : 정현준
* 작성일   : 2024-06-18
* 학습목표 : 컴퓨터가 데이터를 표현하는 방식
* 
* 진법
* 2진법, 10진법, 16진법에 대해서 이해해보자.
* 진법이란 수를 표현하기 위한 방법으로, n진법은 n개의 기호로 수를 표현하는 방식이다.
* 2진법 : 0,1 수를 표현하는 방식
* 10진법 : 0~9(10)개, 16진법(0~15)개
* 진법으로 수의 계산
* 2진법계산 : 각 자리의 수에 0 또는 1이 들어간다. 2의 n승으로 표현된 덧셈으로 10진수를 표현할 수 있다.
* 14수를 2진법으로 표현을 해보기.
* 16진법 왜 쓸까요? 2진법으로 16진법을 표현하기 쉽기 때문입니다.
* 
* 컴퓨터가 문자를 표현하는 비밀
* ASCII (amreican standard code for information interaction) 아스키코드
* 1byte : 2의 8승 만큼 수를 표현할 수 있다. 256개.
* 
*/

#include "lectures.h"

void lectures7()
{
	//문자를 표현하는 방식.
	// char 데이터를 지정하는 방법 : 'n' (따음표 안에 문자 작성)
	char firstcharacter = 'a';
	printf("문자를 출력해 봅시다. %c\n\n", firstcharacter);

	// 문자를 하나 변수에 지정하고 printf 그 문자를 출력해보세요.
	char sencharacter = 'b';
	printf("문자를 하나 더 출력해 봅시다. %c\n\n", sencharacter);

	char y = 65;
	printf("char 데어터 형식에 정수를 넣으면 무엇이 나올까. %c\n\n", y);

	// 정수형 변수
	int sint = 'A';
	printf("정수형 변수에 문자를 담았을 때 출력되는 결과 : %d\n\n", sint);

	//한글은 어떻게 숫자로 표현을 하고 있을까?
	
	printf("데이터 출력 문제 1\n");

	int fint = 128;
	unsigned char fchar = fint;
	printf("%u\n\n", fchar);
	// 예상하는 값 : 128
	// 나오는 값   : - 128(char %d [오버플로우]) -> 128(unsigned char %u)

	// 양의 정수를 표현하는 방법
	// 1바이트 (8비트) 공간에서 부호 있는 정수를 표현하는 방법
	// MSN(MOST SIGNIFICANT NUMBER) : 0이면 양수 1이면 음수. 

	// 음의 정수를 표현하는 방법
	// MSN 1을 넣은 다음에 나머지 공간을 숫자로 표현하면 그것이 음수가 된다.
	// 2의 보수 방식으로 구할 수 있다.
	// 2의 보수 방식이란. 모든 비트 공간에 0과 1을 뒤바꾸어 준 후 1을 더해준다.

	// 오버 플로우
	// 데이터가 넘쳐흐르는 현상. 제한된 메모리를 초과해서 표현할 수 있는 범위를 넘어서면 엉뚱한 결과가 나온느 현상.
	// 오버플로우가 발생했다.

	printf("오버플로우 예시\n");
	char o_a, o_b, o_c;
	o_a = 100;
	o_b = 300;       // 128 양의 정수 표현 초과하면 -128 출력, 순서대로.
	o_c = o_a + o_b; // 100 + 44 = 144 ( -127, -126, -125 ...... -113)
	printf("오버플로우 결과 확인 : %d\n\n", o_c);

	// 문제1. ACSII 'a'와 'Z'를 숫자를 이용해서 출력해보세요.
	char aa = 97;
	char ZZ = 90;
	printf("a와 z를 숫자로 표현 : %c, %c \n\n", aa, ZZ);

	char korea_c = 'ㄱ';
	printf("한글을 표현이 돼나요 : %c \n\n", korea_c); //안되네요.

	// 문제2. -255를 비트로 표현해보세요.
	// -> 255의 2의 보수의 방식으로 비트롤 표현하세요와 같은 말.
	
	/*
     ChatGPT
     -255를 8비트 이진수로 표현하려면, 먼저 -255을 2진수로 변환한 후에 8비트로 맞춰주어야 합니다.
     
     먼저 255을 8비트 이진수로 표현합니다:
     
     255의 이진수 표현: 11111111 (8비트에서는 8개의 1로 표현됨)
     이진수를 2의 보수로 변환합니다:
     
     2의 보수는 원래 수를 반전시킨 후에 1을 더하는 것입니다.
     255의 이진수인 11111111을 반전시키면 00000000이 됩니다.
     여기에 1을 더하면 00000001이 됩니다.
     따라서 -255의 이진수는 11111111이 됩니다.
     따라서 -255를 8비트 이진수로 표현하면 다음과 같습니다:
     
     11111111
     이는 8비트에서의 -255의 이진 표현입니다.
     */

	// 문제3. src 변수에 scanf_s를 이용해서 숫자를 입력을 받고, 
	int src;
	scanf_s("%d", &src);
	printf("아스키 문자로 표현 : %c\n\n", src);   //아스키 문자로 출력할 수 있는 printf 변환을 작성해보세요.
	                                             //printf.. 서식문자를 %c를 써서 scanf_s로 받은 숫자를 아스키문자로 출력해서 표현.

}