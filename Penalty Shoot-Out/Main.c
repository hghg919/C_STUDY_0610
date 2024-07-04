#include <stdio.h>
#include "Function.h"

int main(void)
{
	SetTitle("승부차기 게임");// 게임 타이틀

	// SetConsoleSize(80,25); // 게임 시작화면에 맞는 적절한 크기 찾기 또는 게임 메인 화면에 맞는 적절한 크기 찾기

	GameStart(); // 시작 화면 // 게임 메인 화면(아스키문자) 게임시작(1)\n과 게임종료(0)

}