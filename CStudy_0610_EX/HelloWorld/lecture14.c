/*
*  작성자  : 김동훈
*  작성일  : 2024-06-27
* 학습목표 : 함수
*/

// 왜 함수를 써야하는가?
// C언어는 절차(Procedual)지향(Orient) 프로그래밍 언어.
// 절차 = 함수. C언어. 함수를 지향하는 언어.

// 1. Main 함수에 시작되는 프로그래밍에 코드 내용이 길어질수록
// 코드를 파악하기 힘들고, 기능 유지 보수가 힘들어 지고, 반복적인 코드가 계속 발생.

// 함수를 사용해서. 
// - 코드를 파악하기 쉽게 만든다.
// - 유지 보수를 쉽게 만든다.
// - 반복적인 코드를 줄인다.

// 함수의 선언
// 반환값이 있는지 없는지
// 매개변수가 있는지 없는지

// (반환하고 싶은 데이터 형식)(함수의 이름)( ) : 함수의 선언
// {
//      함수의 본체;  
// }

// 유형1. 반환값이 있고 매개변수도 잇는 함수
// 매개 변수 작성 법 :
// 위치 : 반환값 함수이름( 매개변수를 작성하는 곳 )
// 데이터 형식 매개 변수의 이름을 작성

// 유형2. 반환값이 없고 매개변수도 없는 함수
void ShowResult(void)
{
	printf("결과를 출력하겠습니다.");
	printf("게임을 종료합니다.\n");
}

// 유형3. 반환값이 없고 매개변수는 있는 함수
void ChangeResult(int result)
{
	printf(" %d로 결과가 변경되었습니다.\n", result);
}

// 유형4.반환값이 있고 매개변수는 없는 함수
int InputNumber()
{
	int number;
	scanf_s("%d", &number);
	return number;
}

#include "lectures.h"

void lecture14() 
{
	// 전역 변수 선언
	

	// 함수 호출하는 법
	// 함수 이름( );
	
	// 5 + 7 결과를 a라는 정수형 변수에 넣는 코드를 작성해보세요.
	int a = 5 + 7;
	//printf("a의 값은 :%d 이다\n", a);
	//a = AddTwoNumber(5,7);
	//printf("a의 값은 :%d 이다\n", a);
	ShowResult();
	// a변수를 매개변수로 ChangeResult 함수를 호출해보세요.
	ChangeResult(AddTwoNumber(5, 7));

	int c = InputNumber();
	printf("%d 값이 출력되었습니다.\n", c);

	// 아래에 함수를 호출해보세요. 
	// 두 수의 절대값 중 큰 값을 반환하는 함수

	int firstNum, secondNum;
	firstNum = InputNumber();
	secondNum = InputNumber();

	int compareAbsValue = Compare( AbsoluteNum(firstNum) , AbsoluteNum(secondNum) );
	printf("두 수를 절대값으로 변환한 값 중 큰 값 : %d", compareAbsValue);
}
									
int AddTwoNumber(int a, int b)
{
	int result = a + b;
	// 함수의 목표를 원래 위치로 반환하는 방법 : return을 사용한다.
	printf("a의 값은 :%d 이다\n", a);
	return result;
}

// 두 개의 변수를 매개변수로 받는 함수.
// 두 수를 비교해서 큰 값을 리턴하는 함수를 만들어보세요.
// 이름 : Compare // 정수형 데이터를 비교, 실수형 데이터
int Compare(int a, int b) 
{
	// 문제 1. 두 수를 비교해서 큰 수를 리턴하는 함수를 만들어보세요.
	if (a < b) 
	{
		return b;
	}
	else
	{
		return a;
	}
}
// 이름 : AbsoluteNum
int AbsoluteNum(int num) 
{
	// 문제 2. 변수 하나를 받아서 그 수를 절대값으로 변경해주는 함수를 만들어보세요.
	// 음수, 양수, 0

	if (num < 0) // 음수 
	{
		return num * (-1);
	}
	else // 0과 양수 
	{
		return num;
	}
}
// 문제 3. 절대값으로 변경한 두 수를 비교하는 함수를 구현해보세요. 