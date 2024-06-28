/* 주석 정리
* 
	// printf 함수와 scanf 함수를 사용해서 게임의 느낌을 만들어 보도록 합시다.
	// 플레이어를 ★☆ 환영하는 텍스트를 출력해주세요  ★☆
	// printf ( 숫자를 입력하면 게임이 시작합니다. ) [press start any key]
	// scanf -> 입력을 받는다.. 커서가 멈춘 상태로 대기하고 있다.
	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고,
	// 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요.

	// 컴퓨터의 밸류는 ~ 값입니다.
	// 플레이어의 값은 ~ 입니다.

	//printf("컴퓨터의 값은 %d 입니다.\n", computervalue);
	//printf("플레이어의 값은 %d 입니다.\n\n", uservalue);
	//플레이어의 값과 컴퓨터의 값이 같으면 축하합니다. 게임을 클리어하셨습니다.
	//플레이어의 값과 컴퓨터의 값이 다르면 틀렸습니다. 다시 시도해보세요.
	//다시 시도를 하려면 어떻 해야 할까?

	숫자 맞추기 게임 도전사항
	전제 사항  : 조건문과 반복문으로 답 맞추기 구현
	도전 과제1 : 플레이어의 값이 컴퓨터값과 다르면 작으면 작다. 크면 크다라고 출력 되도록 작성
	도전 과제2 : 플레이어가 숫자를 맞출 수 있는 기회를 제공해서. 틀릴 때 마다 기회를 줄이는 코드.

	// 함수화_1 : GameWin() 게임에서 승리를 구현하는 함수를 만들어보세요.
	// 만약 플레이어의 현재 체력이 0보다 작거나 같으면 게임을 종료시켜라.
	// 함수화_2 : 플레이어의 체력을 감소 시키고 숫자를 다시 맞출 기회를 주는 코드를 함수화 시켜 볼겁니다.

	// 게임 시작 전 플레이어의 목숨(기회)를 정할 수 있게 코딩
	// 집에 가서 전반적인 게임의 개선
	// system("cls") 함수로 --> console 함수 // clearconsole함수
	// 함수 간결화 : for -> while 변경 생각해볼만 함
	// 전역 함수 지양하도록 작성
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CountNumFunc.h" // int inputnumber(); 함수를 미리 선언해두는 방식
                          //                    사용이유 : 컴파일러는 코드를 위에서 부터 읽기 때문에 미리 선언되어 있지 않는 함수를
                          //                    c언어에서는

int main(void) // 함수 사용시 변수 에러 해결
{

	SetColor(0, 15); // 0 ~ 15 앞 백그라운드 뒤 글색 15 흰색

	srand(time(NULL));	
	int computervalue = rand() % 100 + 1; // 1 ~ 100의 랜덤한 숫자가 cumputervalue에 입력이 됩니다.
	int uservalue;

	// 지역 변수는 그 범위(Scope)가 끝났을때 메모리에서 제거됩니다.

	GameStart();

	Clear_ConSole();  // 위에 창을 없앰

	while (1)
	{
		printf("1 ~ 100 범위의 플레이어의 값을 넣어주세요.\n"); // 게임 도중에도 적용되게, 범위 밖의 값을 넣을 시 카운트는 제거 되지 않도록
		printf("입력 : ");
		scanf_s("%d", &uservalue);

		if (uservalue < 1 || 100 < uservalue)
		{
			printf("\n");
			printf("잘못된 입력입니다.\n");
		}
		else
		{
			printf("\n");
			break;
		}
	}

	Clear_ConSole();

	int ab; // 남은 기회가 1일때 값을 맞추어도 실패했다고 뜨는 부분을 해결해야함
	for (int ab = 7 ; ab > 0 ; ab--)
	{

		if (uservalue == computervalue) // 함수화1 : gamewin() 게임에서 승리를 구현하는 함수 만들어보세요.
		{
			SetColor(0, 1);
			printf("축하합니다! 게임을 클리어하셨습니다. \n컴퓨터의 값 : %d", computervalue);
			break;
		}
		else
		{
			printf("틀렸습니다. 다시 시도해보세요.\n\n");
			printf("%d번의 기회가 남았습니다\n", ab);

			if (uservalue < computervalue)
			{
				printf("플레이어의 값보다 컴퓨터의 값이 큽니다.\n");
				printf("플레이어의 값을 넣어주세요. 직전값 : %d \n", uservalue);
				printf("입력 : ");
				scanf_s("%d", &uservalue);
				system("cls");

			}
			else if (uservalue > computervalue)
			{
				printf("플레이어의 값보다 컴퓨터의 값이 작습니다.\n");
				printf("플레이어의 값을 넣어주세요. 직전값 : %d \n", uservalue);
				printf("입력 : ");
				scanf_s("%d", &uservalue);
				system("cls");

			}
			if (ab == 1)
			{
				SetColor(0, 4);
				printf("게임종료 ^오^\n");
				printf("컴퓨터의 값은 %d 입니다.\n", computervalue);
			}
			
		}
	}
	return 0;
}