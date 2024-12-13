#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "CountNumFunc.h";

int InputNumber(); // 함수를 미리 선언해두는 방식.
                   // 사용 이유 : 컴파일러는 코드를 위에서 부터 읽기 때문에 미리 선언되어 있지 않은 함수를 호출할 수 없습니다.
				   // C언어에서 이 함수를 나중에 사용한다.

int main(void)
{
	system("cls");

	// printf 함수와 scanf 함수를 사용해서 게임의 느낌을 만들어 보도록 합시다.
	
	// 플레이어를 ★☆ 환영하는 텍스트를 출력해주세요 ☆★
	// printf( 숫자를 입력하면 게임이 시작합니다.) 
	// scanf -> 입력을 받는다.. 커서가 멈춘상태로 대기하고 있다.
	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고,
	// 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요.

	// 0 ~ 15에 해당하는 색을 이용해서 콘솔창을 꾸며보기

	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1 ~ 100 랜덤한 숫자가 computerValue에 입력이 됩니다.
	int userValue;

	int playerHP = SetPlayerHP();   // 지역 변수로 사용되면 그 값이 사라지기 때문에
	                                // 함수의 리턴과 동시에 변수에 할당해줘야 한다.
	printf("★☆ 환영합니다. ☆★\n");
	printf("숫자를 입력하면 게임이 시작합니다.\n");

	printf("게임 시작!\n");
	SetColor(0, 15);
	printf("플레이어의 값을 입력해주세요.");
	
	userValue = InputNumber();

	//scanf_s("%d", &userValue);
	// 컴퓨터의 벨류는 ~ 값입니다.
	printf("컴퓨터의 값은 %d 입니다.", computerValue);
	// 플레이어의 값은 ~ 입니다.

	printf("플레이어의 값은 %d 입니다.", userValue);
	
	while (1) // 무한 반복.. break 빠져 나올 수 있다. -> 게임 승리, 게임 패배
	{
		if (computerValue == userValue) {
			// 함수화_1 : GameWin() 게임에서 승리를 구현하는 함수를 만들어보세요.
			GameWin();			
			break;
		}
		else 
		{
			// 만약 플레이어의 현재 체력이 0보다 작거나 같으면 게임을 종료시켜라.
			if (playerHP <= 0) 
			{
				printf("게임 종료\n");
				break;
			}

			// 함수화_2 : 플레이어의 체력을 감소 시키고 숫자를 다시 맞출 기회를 주는 코드를 함수화 시켜 볼겁니다.

			// 플레이어의 체력을 감소시킨다.
			playerHP--; // playerHP = playerHP - 1; 같은 코드
            // 다시 플레이어가 숫자를 맞출 기회를 준다.
			printf("플레이어의 값을 입력해주세요.");
			scanf_s("%d", &userValue);
		}
	}

	// 플레이어의 값과 컴퓨터의 값이 다르면 틀렸습니다. 다시 시도해보세요.
	// 다시 시도를 하려면 어떻게 해야 할까? -> 내일 강의

	return 0;
}
