/*
	4강. 이스케이프 문자
	작성자   : 정현준
	작성일   : 2024-06-13
	학습목표 : 이스케이프 문자 사용
*/

#include <stdio.h>

void lectures4()
{
	int num6 = 500;
	printf("지금 보유한 금액 : 450원 \n");
	printf("\"지금 보유한 금액 : %d원\" \n", num6);

	// 약속된 규칙으로 문자 출력을 할 수 없는 문자들이 있다.
	// 이러한 문자들을 출력하고 싶을 때 이스케이프 : "\"
	// \ + (약속된 문자) : 새로운 기능을 구현할 수 있다.
	// 종류 : \n , \a ,  \t, \b, \r , \\, \? , \", \'

	/*
	   \n :	한 줄을 띄어준다. 개행. new line
	   \a :	alarm. 윈도우 경고음을 출력한다.
	   \t :	tab 문자 문자사이의 공간을 생성(tab) 기능.
	   \b : backSpace, 콘솔 커서를 한 칸 뒤로 이동시킨다.
	   \r :	캐리지 리턴(return), 마우스 커서를 해당 줄의 맨 처음으로 이동시킨다.
	   \\, \?, \", \' :	시스템 약속 상 기본을 출력할 수 없는 문자를 출력하게 해준다.
	*/

	printf("지금 보유한 금액 : %d원 \n", num6);
	printf("\a");
	printf("hello\b\bhi\n");
	printf("건냥하세요\r안녕\n");
	printf("반갑\t습니다. \n");
	printf("\\ \' \" \? 에러가 발생 하나요? \n");

	// 변수를 이용한 데이터의 저장.
	// 변수를 저장하는 다양한 방법
	// (1) 변수를 선언, 선언 할당
	int num1;
	num1 = 10;
	// (2) 변수 초기화. (선언과 할당)
	int num2 = 20;
	// (3) 변수를 동시에 선언, 단 데이터 형태 같은 것만!
	int num3, num4, num5;
	num3 = 10, num4 = 20, num5 = 30;
	printf("%d %d %d\n\n", num3, num4, num5);
	// (4) 변수를 동시에 선언과 함께 할당;

	// 변수 이름 작성 시 주의 사항(제한 사항)

	// 변수의 첫 글자에 숫자가 들어가면 안된다.
	//int 776num;
	// #,$ 특수 기호를 이름을 사용할 수 없다.
	//int #num;
	// 문자 이름 사이에 띄어쓰기(공백 문자)를 할 수 없다.
	//int your function;
	// 키워드도 이름으로 사용할 수 없다.
	// auto, enum, break, return, void, float, short, while
	//int union;

	// 변수에 이름을 잘 지을 것을 생각을 해야합니다.

	//int abc = 10;
	int playerHP = 100;

// 입력
// Scanf 함수의 실습
// 변수 미리 선언 (입력을 받아서 저장할 변수를 미리 선언)
// 기본 사용법 : Scanf("%d", &변수의 이름);     //shift +7 : &
// Scanf_s("%d, &num);

	int width = 24, height = 12, length = 8;

	int num;
	// 주석을 보고 함수를 사용 Scanf_s
	// 여러분 입력한 숫자를 "num의 들어간 숫자 : n" 형태로 출력하는 프로그래밍입니다.
	printf("예제\n");
	printf("숫자를 입력해주세요\n");
	scanf_s("%d", &num);
	printf("num의 들어간 숫자 : %d\n", num);

	// 변수의 이름 FirstNum1, FirstNum2, FirstNum3
	// 문제 1. " 두 개의 정수를 입력 받아서 두 수의 뺄셈과 곱셈의 결과를 출력해보세요"
	// int FirstNum1, FirstNum2;   
	// 두 수의 뺄셈 : 결과   
	// 두 수의 곱셈 : 결과
	printf("문제1\n");
	int FirstNum1, FirstNum2;
	printf("첫번째 정수를 입력해주세요 :");
	scanf_s(" %d", &FirstNum1);
	printf("두번째 정수를 입력해주세요 :");
	scanf_s(" %d", &FirstNum2);
	printf("두 수의 뺄셈 : %d\n", FirstNum1 - FirstNum2);
	printf("두 수의 곱셈 : %d\n\n", FirstNum1 * FirstNum2);

	// 문제 2. " 3개의 정수를 입력 받아서, SecondNum1 * SecondNum2 + SecondNum3 출력하는 코드를 작성해보세요.
	printf("문제2\n");
	int SecondNum1, SecondNum2, SecondNum3;
	printf("첫번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum1);
	printf("두번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum2);
	printf("세번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum3);

	printf("%d x %d + %d 값 : %d\n\n", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

	// 문제 3. " 두 개의 정수를 입력받아서 몫과 나머지를 출력하는 코드를 작성해보세요.
	// 몫을 구하는 방식 : a / b(나눈 값에서 정수 부분이 몫)
	// a % b =  a를 b로 나눈 나머지 값
	printf("문제3\n");
	int a, b;
	printf("첫번째 정수를 입력해주세요 :");
	scanf_s(" %d", &a);
	printf("두번째 정수를 입력해주세요 :");
	scanf_s(" %d", &b);

	printf("두 수의 몫 : %d \n", a / b);
	printf("두 수의 나머지 값 : %d \n\n", a % b);

	//문제4. " 하나의 정수를 받아서 제곱을 출력하는 코드 작성 "

	printf("문제4\n");
	int c;
	printf("하나의 정수를 입력해주세요 :");
	scanf_s(" %d", &c);

	printf("%d의 제곱 : %d \n\n", c, c * c);
	
	//문제5. 세 개의 정수를 입력을 받아서, {fifthnum1 - fifthnum2} x { fifthnum2 + fifthnum3 } x { fifthnum3 * fifthnum1} 의 결과를 출력하는 코드를 작성해보세요.
	printf("문제5\n");
	int fifthnum1, fifthnum2, fifthnum3;
	printf("첫번째 정수를 입력해주세요 :");
	scanf_s(" %d", &fifthnum1);
	printf("두번째 정수를 입력해주세요 :");
	scanf_s(" %d", &fifthnum2);
	printf("세번째 정수를 입력해주세요 :");
	scanf_s(" %d", &fifthnum3);

	printf("세 정수의 값 : %d \n\n", fifthnum1 - fifthnum2 * fifthnum2 + fifthnum3 * fifthnum3 * fifthnum1);
}