/*
*  if ~ else if ~ else 코드를 제어하는 방법을 배웠습니다.
* 
*  또다른 조건문 Switch -  break;
* 
*  Switch( 변수 )
*  {
*	   case 변수의 값 : 
*	   실행되는 코드
       break;
       ...
       ...
       ...
       default :
       break;
*  }
* 
*  형식이 균일한, 처리해야할 조건이 다양할 때 사용하는 조건문 입니다.
*/

#include "lectures.h"

void lecture13_2()
{
    int num;
    scanf_s("%d", &num);

    // 아래 switch문을 if ~ else if ~ else로 바꾸어 보세요
    switch (num)
    {
        case 0 :
            printf("num은 0입니다.\n");
            break;
        case 1 :
            printf("num은 1입니다.\n");
            break;
        case 2:
            printf("num은 2입니다.\n");
            break;
        default :
            printf("num은 0 ~ 2 이외의 값입니다.\n");
            break;
    }

    //if(num == 0)
    //    printf("num은 0입니다.\n");
    //else if(num == 1)
    //    printf("num은 1입니다.\n");
    //else if(num == 2)
    //    printf("num은 2입니다.\n");
    //else
    //    printf("num은 0 ~ 2 이외의 값입니다.\n");

    // swtich문의 기본 사용법에 대해 학습하였습니다.
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
        printf("num은 0 ~ 2 이외의 값입니다.\n");
    }


    // switch( )   // int 정수를 입력했습니다.
    // ( ) 안에 올 수 있는 데이터 타입은 정수형!
    // float, dobule 실수형 데이터 타입의 값을 넣으면 에러가 발생합니다.

    char d_num = 1;
    
    switch (d_num)     // case :  case와 :(콜론) 사이에 들어가는 값은. 정수가 아니고,  정수의 값으로 반환되는 식이여도 상관이 없다.  
                       // 가능은 하지만, switch ~ case문을 사용하는 이유는 가독성을 사용을 합니다.
    {
    case 'W':
        break;
    case 'A':
        break;
    case 'D':
        break;
    case 'S':
        break;
    }
}