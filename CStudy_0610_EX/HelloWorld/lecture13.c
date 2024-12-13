/*
*   작성자   : 김동훈
*   작성일   : 2024-06-26
*   학습목표 : break, continue;
*
*/

/*
*   for 반복문, while 반복문
*   반복적인 내용을 간결하게 표현.
*   break, continue.. (반복문, 조건문 - 제어문) 제어해주는 방법
*   for, while, do while, switch 사용을 합니다.
*/

/*
*  break   : 제어흐름에서 벗어나기 위해 사용합니다. break 선언되면 해당 제어문에서 빠져 나옵니다.
* continue : 제어흐름을 유지한 상태로 해당 코드의 실행만 건너 뛰는 기능을 합니다.
*/

#include "lectures.h"

void lecture13()
{
	// printf 10번 반복하는 코드를 for 반복문.
	// 0번 부터 ~ 특정 숫자까지 반복해서 아래의 코드를 실행하는데,
	// 내가 원하는 목표값에 도달하면
	for (int i = 0; i < 10; i++)
	{
		printf("Hi %d\n", i);

		if (i == 7)
		{
			printf("i가 7일 때 출력됨\n");
			break;
		}

	}
	int index = 0;
	for (; ;)  // 무한 반복문. ctrl + c
	{
		index++;
		printf("hi %d\n", index);
		if (index == 7)
		{
			printf("7이 출력되었습니다. \n");
			break;
		}
	}

	// 
	int targetNumber;  // 여러분이 출력하고자 하는 목표 숫자(scanf_s)
	//int counter = 0;   // 반복문에서 targetnumber를 찾기 위한 변수	  
	//scanf_s("%d", &targetNumber);
	//
	//for (; ;)
	//{
	//	counter++;
	//	if (targetNumber == counter)
	//	{
	//		printf("원하는 결과 값이 출력되었습니다. %d\n", targetNumber);
	//		break;
	//	}
	//}

	// while 반복문
	scanf_s("%d", &targetNumber);
	int w_counter = 0;
	//while (1) // 무한 반복문
	//{
	//	w_counter++;
	//	if (targetNumber == w_counter)
	//	{
	//		printf("원하는 결과 값이 출력되었습니다. %d\n", targetNumber);
	//		break;
	//	}
	//	// for 반복문에서 타겟넘버를 찾는 코드와 같은 내용을 구현해보세요.
	//	// break를 사용을 하셔야 합니다.
	//}

	// continue 사용 예시
	int w_num = 0;
	while (w_num < 10)
	{
		w_num++;
		if (w_num % 2 == 0)
		{
			continue;
		}
		printf("%d \n", w_num);
	}

	// 주사위를 굴릴거에요. 주사위에는 12개의 면이 있습니다. Scanf_s 여러분이 주사위의 눈을 조작하세요. (완료)
	// 만약에 주사위가 짝수가 나온다면, 현재 여러분이 갖고 있는 돈에 소지금이 2배가 되고,	  (분기 구현 완료)
	// 만약에 홀수가 나온다면, 여러분이 갖고 있는 소지금이 0원이 되는 코드를 작성해보세요.  ( 소지금 코드 구현)
	// 만약에 소지금이 0원이 된다면 프로그램을 종료해주는 프로그램을 만들어 본다.

	printf("주사위 예제 시작 \n");

	// 0 ~ 12숫자를 scanf_s 출력
	printf("여러분이 지금 타짜여서 주사위의 숫자를 골라주세요(0 ~ 12) : ");
	int diceNum, gameMoney;
	// 지금 코드의 문제점 12 보다 큰숫자, 0보다 작은 숫자를 입력하면 그 숫자가 diceNum에 출력이 됩니다. 이것을 수정하는 코드
	scanf_s("%d", &diceNum);
	gameMoney = 1000;  // 기본 소지금 1000원

	while (1) // while 탈출 조건을 
	{
		if (diceNum < 1 || diceNum > 12)
		{
			printf("잘못된 주사위의 크기를 입력했습니다. \n 주사위 크기를 다시 입력해주세요 : \n");
			scanf_s("%d", &diceNum);
		}
		else
		{
			// 짝수인지 홀수인지 판별하는 코드를 작성해야 한다. 1 ~ 12
			if (diceNum % 2 == 0)  // 짝수
			{
				gameMoney = gameMoney * 2;

				if (gameMoney > 5000) // 게임 승리 조건 
				{
					printf("게임에서 승리했습니다. 보유 금액은 : %d 입니다.\n", gameMoney);
					break;
				}
				else 
				{
					printf("현재 보유 중인 금액 : %d \n", gameMoney);
					scanf_s("%d", &diceNum);
				}
			}
			else // 홀수
			{
				gameMoney = 0;
				printf("당신은 게임에서 졌습니다. 보유 금액은 : %d \n", gameMoney);
				break;
			}
		}
	}
	

}