#include <stdio.h>
#include "Function.h"

int main(void)
{
	SetTitle("승부차기 게임"); // 게임 타이틀

	SetConsoleSize(156,25); // 게임 시작화면에 맞는 적절한 크기 찾기 또는 게임 메인 화면에 맞는 적절한 크기 찾기

	SetConsoleCursorVisibility(0); // 커서가 보이지 않게

	GameStart(); // 시작 화면 // 게임 메인 화면(아스키문자) 게임시작과 게임종료 // 게임정보(키 및 기타정보 소개) 추가?

	// 게임 메인 화면 // 패널티킥 게임 골키퍼, 골대, 공, 키커, 라인(흰색) // 골대9분할 난이도는 ~7까지 // 성공, 실패 화면

}