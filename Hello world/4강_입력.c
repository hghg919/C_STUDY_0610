// 입력
// Scanf 함수의 실습
// 변수 미리 선언 (입력을 받아서 저장할 변수를 미리 선언)
// 기본 사용법 : Scanf("%d", &변수의 이름);     //shift +7 : &
// Scanf_s("%d, &num);

#include <stdio.h>

int main(void)
{
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
	printf("두 수의 곱셈 : %d\n", FirstNum1 * FirstNum2);

	// 문제 2. " 3개의 정수를 입력 받아서, SecondNum1 * SecondNum2 + SecondNum3 출력하는 코드를 작성해보세요.
	printf("문제2\n");
	int SecondNum1, SecondNum2, SecondNum3;
	printf("첫번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum1);
	printf("두번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum2);
	printf("세번째 정수를 입력해주세요 :");
	scanf_s(" %d", &SecondNum3);

	printf("%d x %d + %d 값 : %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

	// 문제 3. " 두 개의 정수를 입력받아서 몫과 나머지를 출력하는 코드를 작성해보세요.
	// 몫을 구하는 방식 : a / b(나눈 값에서 정수 부분이 몫)
	// a % b =  a를 b로 나눈 나머지 값
	return 0;
}