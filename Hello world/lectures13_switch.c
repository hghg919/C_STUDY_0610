/*
* if ~ else if ~ else 코드를 제어하는 방법을 배웠습니다.
* 
* 또다른 조건문 switch ~ break;
* 
* switch (변수)
* {
*     case 변수의 값 :
*     실행되는 코드
*     break;
*     ...
*     ...
*     ...
*     default :
*     break;
* }
* 
* 형식이 균일한, 처리해야 할 조건이 다양할 때 사용하는 조건문 입니다.
*/

#include "lectures.h"

void lectures13_switch()
{
	int num;
	scanf_s("%d", &num);

	switch (num)
	{
	case 0:
		printf("num은 0입니다. \n");
		break;
	case 1:
		printf("num은 1입니다. \n");
		break;
	case 2:
		printf("num은 2입니다. \n");
		break;
	default:
		printf("num은 0~2 이외의 값입니다. \n");
		break;
	}

	//if (num == 0)
	//	printf("num은 0입니다. \n");
	//else if (num == 1)
	//	printf("num은 1입니다. \n");
	//else if (num == 2)
	//	printf("num은 2입니다. \n");
	//else
	//	printf("num은 0~2 이외의 값입니다. \n");

	// switch문의 기본 사용법에 대해 학습하였습니다.
	// break가 없으면 어떻게 될까요?

	switch (num)
	{
	case 0:
	case 1:
		printf("0,1의 값이 나올 확률 : \n");
		break;
	case 2:
	case 3:
	case 4:
		printf("2,3,4의 값이 나올 확률 : \n");
	default:
		printf("num은 0~2 이외의 값입니다. \n");
	}


	// switch( ) // int 정수를 입력했습니다.
	// ( ) 안에 올 수 있는 데이터 타임은 정수형!
	// flaot, double 실수형 데이터 타임의 값을 넣으면 에러가 발생합니다.

	char d_num = 1;
	switch (d_num)  // case ( ) : case와 세미콜론(;) 사이에 들어가는 값은. 정수가 아니고, 정수의 값으로 반환되는 식이여도 상관이 없다.
	{               // 가능은 하지만, switch ~ case무을 사용하는 이유는 가독성을 위해서 사용을 합니다.
	case 2+3+3+2+3:
		break;
	case 65:
		break;
	}
}