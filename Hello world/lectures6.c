/* 
  작성자  : 정현준
* 작성일   : 2024-06-17
* 학습목표 : 디버깅
* 
*  디버깅
*  - 디버깅을 해야 하는 이유
*  - 프로그래밍을 하면서 작성한 논리적인 문제를 해결하기 위해서
*  - 문제가 의심가는 부분에 코드의 중단점을 생성하고 실제로 컴퓨터의 계산결과를 눈으로 확인할 수 있다.
*  - 문제를 해결 하기 위한 방법이다(With Computer Debuging System)
*  단축키
*/

// Operator 연산자
// 대입, 산술 연산자
// '=', -, +, x, / , % 
// "=" : A = B 같다.(논리 연산자 - 수학)	(대입 연산자);
// int num = 30;   // Left Value = Right Value; 오른쪽 값을 왼쪽 변수에 넣어주는 기능
// 결합 순서가 (a <- b ) 정해져있다.

/*복합 대입 연산자
* 종류 :  a = a + b;	   a += b;
*        a = a - b;    a -= b;
*        a = a * b;    a *= b;
*        a = a >> b;   a >>= b;
*        a = a & b;    a &= b;
*        a = a | b;    a |= b;
*/

/* 증가, 감소 연산자
*  num++;
* ++num;
* num--;
* --num;
*  ++ : 변수 +=1와 같은 뜻.
*  -- : 변수 -=1와 같은 뜻.
*
*  전위 증가(감소) : 변수에 1을 먼저 더 해준 후, 문장의 연산을 진행한다.
*  후위 증가(감소) : 문장의 연산을 먼저 진행 후 변수의 값을 변화 시킨다.
*
*/



/* 관계 연산자
*  비교 연산자. 두 개의 값을 비교하여 그 관계를 표현하는 연산자.
*  a ,  b , result ;
*  a = 10, b = 12
*  결과 값이 True(참), False(거짓)으로 나옵니다.
*  True : 1,  False : 0
*  result = (a > b);
*  result의 값이 true면 1이, false면 0이 들어간다.
*/

/* 논리 연산자
*  AND, OR, NOT
*  AND : && (shift + 7)	       ->  A와 B가 모두 참이면 결과를 참인 결과를 반환한다. "1"
*  OR  : || (Shift + \(달러))  ->  A와 B중 하나라도 참이면 1인 결과를 반환한다.
*  NOT : !변수 	               -> A가 True이면 False 반환, False이면 True 반환한다.
*/

// 연산 결합 순위
// int A = (a == 10 && b == 12);
// int B = (a < 12 || b > 12);
// int C = !a; 

#include "lectures.h"

void lectures6()
{
	printf("디버깅 예제 문제\n");
	char a, b, c;
	a = 100;
	b = 300;
	c = a + b;
	printf("%d + %d = %d\n\n", a, b, c);

	printf("연산자 예제 문제\n\n");

	// 9 + 2 = 11, 9 - 2 = 7; 자동 호출스택

	int num1, num2, num3, result;
	result = 0;
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("계산 결과(l-value) = %d x %d + %d = %d\n", num1, num2, num3, num1 * num2 + num3);
	printf("복합대입 연산자(결과 = %d += %d)\n\n", result, num1);

	printf("증가, 감소 연산자 예제 문제\n");
	int plusa = 10;
	int plusb = (plusa++) + 2;
	printf("plusb의 값은 무엇이 나올 까요? : %d \n", plusb);
	printf("plusa의 값이 얼마나 나올 까요? : %d \n\n", plusa);

	printf("결과 값 = %d \n\n", num1 < num3);

	printf("연산자 우선 순위 마지막 예제\n");

	//문제 : 변수 a의 값은 3 + 4 X 5 이며, 변수 b의 값은 7 / 3 % 2 이다.
	//변수 a와 b의 값을 비교한 값을 result 변수에 대입하여 출력하여 보세요.

	int variablea; // 3 + 4 X 5;
	int variableb; // 7 / 3 % 2;
	int final; // variablea와 variableb를 관계연산자를 사용하여 final 대입해보세요.

	// scanf 작업 데이터의 할당

	int cal1, cal2, cal3;
	scanf_s("%d %d %d\n", &cal1, &cal2, &cal3);
	variablea = cal1 + cal2 * cal3;
	printf("variablea의 값 : %d \n", variablea);
	variableb = 7 / 3 % 2;
	final = (variablea < variableb);

	printf("variablea가 variableb 보다 작나요? ture이면 1을 출력 false이면 0을 출력합니다 : %d\n", final);
}