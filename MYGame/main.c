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
	printf("☆★☆★☆★☆★☆★☆\n");
	printf("☆★☆★☆★☆★☆★☆\n");
	printf("★☆★게임 시작!★☆★\n");
	printf("☆★☆★☆★☆★☆★☆\n");
	printf("☆★☆★☆★☆★☆★☆\n\n");

	printf("숫자를 입력하면 게임이 시작합니다.\n");
	int start_num;
	scanf_s("%d", &start_num);

	printf("플레이어의 값을 넣어주세요.\n");
	scanf_s("%d", &uservalue);

	printf("컴퓨터의 값은 %d 입니다.\n", computervalue);
	printf("플레이어의 값은 %d 입니다.", uservalue);

	return 0;
}