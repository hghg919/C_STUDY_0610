/*
*  작성자  : 김동훈
*  작성일  : 2024-06-28
* 학습목표 : 지역 변수와 전역 변수의 이해 
*/

/*
*  지역 변수(Local variable) : 중괄호 내부에서 생성되는 변수. 지역변수는 선언된 지역 내에서만 유효하다.
*/

// 변수의 존재기간	: 중괄호가 끝날 때 변수가 사라진다. 지역 변수가 저장되는 공간(메모리 공간)을 스택(Stack)이라고 한다. 

// 변수의 접근 범위  : 범위 밖에서 선언된 변수와 범위 안에서 선언된 변수의 이름이 같을 때 어떤 변수를 사용할까?

// 같은 지역 내에서 같은 이름의 변수를 선언할 수 있나요? No - 컴파일러가 같은 이름의 변수에 대해서 어떤 변수를 사용해야 할지 모르기 때문

// 범위가 다른 곳에서 같은 이름의 변수가 선언이 되었다면, 가장 가까운 범위의 변수를 사용한다.


/*
*  전역 변수(Global variable) : 중괄호 { } 밖에 선언된 변수
*/


int count; // 전역 변수의 선언. 전역변수는 선언 시에 0으로 초기화 된다.	 전역 변수는 사용을 지양해야 합니다.
           // 유닛을 뽑을 때 마다, 인구수가 1씩 증가하는 로직.
           // int num;   num++ 지역변수이기 때문에 num이 값이 저장되지 않습니다.
           // count

#include "lectures.h"

int SimpleFunc()
{
	count++;	   // 전역 변수의 값을 변경
	int num = 10;
	num++;

	return num;
}

void PlusOne(int a, int b) // 호출할 때 마다 static_num를 1증가시키는 함수
{
	a++;
	b++;
}

void lecture15()
{
	int num = 17;
	// num값은 17입니다.

	printf("전역 변수에 초기화값을 입력하지 않았을 때 정말로 0인가요? : %d 입니다. \n", count);

	count = 10;
	printf("count의 값 %d\n", count);

	SimpleFunc();
	printf("num의 값 : %d\n", num); // 
	printf("count의 값 : %d\n", count);
	int count1 = 4, count2 = 6;

	PlusOne(count1, count2);
	printf("%d\n", count);


	static int static_num; // lecutre15 함수 내에서만 사용하는 변수.

	printf("static_num의 값 : %d ", static_num);

	printf("coun1의 값 : %d, count2의 값 : %d\n", count1, count2);
}

