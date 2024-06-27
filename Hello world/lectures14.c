/*
*  작성자   : 정현준
*  작성일   : 2024-06-27
*  학습목표 : 함수
*/

/*
* 왜 함수를 써야하는가?
* c언어는 절차(procedual)지향(orient) 프로그래밍 언어.
* 절차 = 함수. c언어. 함수를 지향하는 언어.
*/

/*
* 1. main 함수에 시작되는 프로그래밍에 코드 내용이 길어질수록
* 코드를 파악하기 힘들고, 기능 유지 보소가 힘들어 지고, 반복적인 코드가 계속 발생.
*/

/*
* 함수를 사용해서.
* - 코드를 파악하기 쉽게 만든다.
* - 유지 보수를 쉽게 만든다.
* - 반복적인 코드를 줄인다.
*/

/*
* 함수의 선언
* 반환값이 있는지 없는지 
* 매개변수가 있는지 없는지
*/

// (반환하고 싶은 데이터 형식)(함수의 이름)( 매개변수? ) : 함수의 선언
// {
//    함수의 본체;
// }

// 유형1. 반환값이 있고 매개변수도 있는 함수
// 매개 변수 작성 법
// 위치 : 반환값 함수이름( 매개변수를 작성하는 곳 )
// 데이터 형식 매개 변수의 이름을 작성
int addtwonumber(int a, int b)
{
	int result = a + b;
	// 함수의 목표를 원래 위치로 반환하는 방법 : return을 사용한다.
	printf("a의 값은 : %d 이다\n", result);
	return result;
}

// 유형2. 반환값이 없고 매개변수도 없는 함수
void showresult(void)
{
	printf("결과를 출력하겠습니다.");
	printf("게임을 종료합니다.\n");
}

// 유형3. 반환값은 없고 매개변수는 있는 함수
void changeresult(int result)
{
	printf("결과가 변경되었습니다. %d\n", result);
}

// 유형4. 반환값이 있고 매개변수는 없는 함수
int inputnumber()
{
	int number;
	scanf_s("%d", &number);
	return number;
}

//문제1.
// 함수를, 두 수를 비교해서 큰 수를 리턴하는 함수를 만들어보세요.
// 두개의 변수를 매개변수로 받는 함수.
// 두 수를 비교해서 큰 값을 리턴하는 함수를 만들어보세요.
// 이름 : compare // 정수형 데이터를 비교, 실수형 데이터도 가능
int compare(int a_num, int b_num)
{
	if (a_num > b_num)
	{
		return a_num;
	}
	else
	{
		return b_num;
	}
}

//문제2.변수 하나를 받아서 그 수를 절대값으로 변경해주는 함수를 만들어보세요.
// 음수 , 양수, 0
int absolutenum(int ab_num)
{
	if (ab_num < 0) // 음수
	{
		return ab_num * (-1);
	}
	else // 0과 양수
	{
		return ab_num;
	}
}

// 문제3 절대값으로 변경한 / 두 수를 비교하는 함수를 구현해보세요. 2개의 함수


#include "lectures.h"

void lectures14() // 함수의 선언
{
	// 함수 호출하는 법
	// 함수 이름( );
	// 
	// 5 + 7 결과를 a라는 정수형 변수에 넣는 코드를 작성해보세요.
	int a = 5 + 7;
	//printf("a의 값은 : %d 이다\n", a);
	a = addtwonumber(5, 7);
	//printf("a의 값은 : %d 이다\n", a);
	showresult();
	// a변수를 매개변수로 changeresult 함수를 호출해보세요.
	changeresult(addtwonumber(5, 7));

	int c = inputnumber();
	printf("%d 값이 출력되었습니다.\n", c);

	// 아래에 함수를 호출해보세요.
	// 두 수의 절대값 중 큰 값을 반환하는 함수

	int firstnum, secondnum;
	firstnum = inputnumber();
	secondnum = inputnumber();

	int compare_value = compare(absolutenum(firstnum), absolutenum(secondnum));
	printf("두 수를 절대값으로 변환한 값 중 큰값 : %d", compare_value);
}