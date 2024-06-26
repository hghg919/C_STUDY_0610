#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// printf 함수와 scanf 함수를 사용해서 게임의 느낌을 만들어 보도록 합시다.

	// 플레이어를 ★☆ 환영하는 텍스트를 출력해주세요  ★☆

	// printf ( 숫자를 입력하면 게임이 시작합니다. ) [press start any key]
	// scanf -> 입력을 받는다.. 커서가 멈춘 상태로 대기하고 있다.

	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고,
	// 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요.

	srand(time(NULL));	
	int computervalue = rand() % 100 + 1; // 1 ~ 100의 랜덤한 숫자가 cumputervalue에 입력이 됩니다.
	int uservalue;

	// 컴퓨터의 밸류는 ~ 값입니다.
	
	// 플레이어의 값은 ~ 입니다.
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★★☆★숫자 게임!★☆★★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n");
	printf("| ☆★☆★☆★☆★☆★☆★☆★☆ |\n\n");

	printf("1을 입력하면 게임을 시작합니다.\n");  // 정해진 숫자만 입력하게 <0 : 게임종료> <1 : 게임시작> 그외 숫자는 숫자를 다시 입력하게
	printf("0을 입력하면 게임을 종료합니다.\n");

	while (1)
	{
		int start_num;
		scanf_s("%d", &start_num);

		if (start_num == 0) // 종료가 안됨 수정이 필요
		{
			printf("게임을 종료합니다.\n\n");
			break;
		}
		else if(start_num == 1)
		{
			printf("게임 시작!\n\n");
			break;
		}
		else
		{
			printf("잘못된 입력입니다. 0 또는 1을 입력해주세요.\n");
		}
	}

	printf("1 ~ 100 범위의 플레이어의 값을 넣어주세요.\n"); // 1 ~ 100 이외의 숫자는 다시 입력하게
	
	while (1)
	{
		scanf_s("%d", &uservalue);

		if (uservalue < 1 || 100 < uservalue)
		{
			printf("잘못된 값입니다.\n");
			printf("1 ~ 100 범위의 플레이어의 값을 넣어주세요.\n\n");
		}
		else
		{
			break;
		}
	}
	printf("\n");

	//printf("컴퓨터의 값은 %d 입니다.\n", computervalue);
	//printf("플레이어의 값은 %d 입니다.\n\n", uservalue);

	//플레이어의 값과 컴퓨터의 값이 같으면 축하합니다. 게임을 클리어하셨습니다.

	//플레이어의 값과 컴퓨터의 값이 다르면 틀렸습니다. 다시 시도해보세요.

	//다시 시도를 하려면 어떻 해야 할까? 
	
	int ab;
	for (int ab = 7 ; ab > 0 ; ab--)
	{

		if (uservalue == computervalue)
		{
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
				scanf_s("%d", &uservalue);

				printf("\n");
			}
			else if (uservalue > computervalue)
			{
				printf("플레이어의 값보다 컴퓨터의 값이 작습니다.\n");
				printf("플레이어의 값을 넣어주세요. 직전값 : %d \n", uservalue);
				scanf_s("%d", &uservalue);

				printf("\n");
			}
			if (ab == 1)
			{
				printf("게임종료 ^모^\n");
				printf("컴퓨터의 값은 %d 입니다.\n", computervalue);
			}
			
		}
	}

	/*
	* 숫자 맞추기 게임 도전사항
      전제 사항  : 조건문과 반복문으로 답 맞추기 구현
      도전 과제1 : 플레이어의 값이 컴퓨터값과 다르면 작으면 작다. 크면 크다라고 출력 되도록 작성
      도전 과제2 : 플레이어가 숫자를 맞출 수 있는 기회를 제공해서. 틀릴 때 마다 기회를 줄이는 코드.
	*/

	return 0;
}