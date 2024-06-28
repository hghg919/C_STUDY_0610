/*
* 작성자 : 정현준
* 작성일 : 2024-06-28
* 학습목표 : 지역 변수와 전역 변수의 이해
*/

/*
* 지역 변수 (Local variable) : 중괄호 내부에서 생성되는 변수. 지역변순느 선언된 지역내에서만 유효하다.
*/

// 변수의 존재기간 : 중괄호가 끝날 때 변수가 사라진다. 지역 변수가 저장되는 공간(메모리 공간)을 스택(stack)이라고 한다.

// 변수의 접근 범위 : 범위 밖에서 선언된 변수와 범위 안에서 선언된 변수의 이름이 같을 때 어떤 변수를 사용할까?

// 같은 지역 내에서 같은 이름의 변수를 선언할 수 있나요? no - 컴파일러가 같은 이름의 변수에 대해서 어떤 변수를 사용해야 할지 모르기 때문

// 범위가 다른 곳에서 같은 이름의 변수가 선언이 되었다면, 가장 가까운 범위의 변수를 사용한다.

/*
* 전역 변수(Global Variable) : 중괄호 { } 밖에 선언된 변수
*/

int count; // 전역 변수의 선언. 전역 변수는 선언 시에 0으로 초기화 된다. 전역 변수는 사용을 지양해야 합니다.
           // 유닛을 뽑을 때 마다, 인구수가 1씩 증가하는 로직.
           // int num; num++ 지역 변수이기 때문에 num 값이 저장되지 않습니다.
           // count

#include "lectures.h"

void Plusone(int a, int b) // 호출할때 마다 count를 1증가시키는 함수
{
	static int static_num;
	count++;
	a++;
	b++;
}

void lectures15()
{
	int num = 17;
	//num의 값은 17입니다.

	printf("전역 변수에 초기화 값을 입력하지 않았을때 정망로 0인가요 : %d\n", count);

	count = 10;
	printf("%d\n", count);
	simplefunc(); // 11;
	printf("num의 값 : %d\n", num); // 17, 11
	printf("count의 값 : %d\n", count); 
	int count1 = 4, count2 = 6;

	Plusone(count1, count2);
	Plusone(count1, count2);

	printf("count1의 값 : %d, count2의 값 : %d", count1, count2);
}

int simplefunc()
{
	count = 12;
	printf("count : %d\n", count);
	int num = 10;
	num++;
	count++; // 전역변수의 값을 변경
	return num;
}