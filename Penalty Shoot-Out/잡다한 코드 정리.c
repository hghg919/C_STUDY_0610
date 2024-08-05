#include <stdio.h>

void save_score(const char* filename, int score) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return;
    }
    fprintf(file, "%d\n", score);
    fclose(file);
    printf("스코어가 저장되었습니다: %d\n", score);
}

int main() {
    int score = 12345; // 예를 들어, 이 스코어를 저장한다고 가정합시다
    save_score("score.txt", score);
    return 0;
}

#include <stdio.h>

int load_score(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일 열기에 실패했습니다.\n");
        return -1; // 실패를 나타내는 값
    }
    int score;
    fscanf(file, "%d", &score);
    fclose(file);
    return score;
}

int main() {
    int score = load_score("score.txt");
    if (score != -1) {
        printf("저장된 스코어: %d\n", score);
    }
    return 0;
}

#ifndef FUNCTION_H
#define FUNCTION_H

// 함수 프로토타입
void SetTitle(const char* title);
void SetConsoleSize(int width, int height);
void SetConsoleCursorVisibility(int visibility);
void GameStart(void);
void GameMain(void);

#endif // FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Windows 환경에서 _getch() 함수 사용
#include "Function.h"

void SetTitle(const char* title) {
    printf("%s\n", title); // 간단한 예제, 실제로는 Windows API를 사용하거나 콘솔 명령어를 사용해야 합니다.
}

void SetConsoleSize(int width, int height) {
    // 콘솔 크기를 조정하는 함수 (Windows 전용 코드 예시)
    // SYSTEMINFO 구조체를 사용하거나 Windows API를 사용해야 함
    // 현재는 단순히 화면 크기를 조정하는 코드가 없으므로 예제로만 작성
    printf("콘솔 크기를 %dx%d로 설정합니다.\n", width, height);
}

void SetConsoleCursorVisibility(int visibility) {
    // 커서 가시성을 조정하는 함수 (Windows 전용 코드 예시)
    // 실제로는 Windows API를 사용해야 함
    printf("커서 가시성을 %d로 설정합니다.\n", visibility);
}

void GameStart(void) {
    printf("게임 시작 화면\n");
    printf("1. 게임 시작\n");
    printf("2. 게임 정보\n");
    printf("3. 게임 기록\n");
    printf("4. 게임 종료\n");

    char choice;
    printf("메뉴를 선택하세요: ");
    choice = _getch(); // 입력을 받음

    switch (choice) {
    case '1':
        GameMain(); // 게임을 시작합니다.
        break;
    case '4':
        printf("게임을 종료합니다.\n");
        exit(0); // 프로그램 종료
        break;
    default:
        printf("잘못된 선택입니다.\n");
        break;
    }
}

void GameMain(void) {
    printf("게임 메인 화면\n");
    printf("패널티킥 게임이 진행됩니다.\n");

    // 게임 로직을 추가합니다.
    // 예를 들어, 공을 슈팅하거나 키 입력을 처리하는 로직을 여기에 추가합니다.

    printf("게임 종료를 원하시면 'Q'를 누르세요.\n");

    char input;
    while (1) {
        input = _getch(); // 입력을 받음
        if (input == 'Q' || input == 'q') {
            printf("게임을 종료합니다.\n");
            break;
        }

        // 게임 로직에 따른 동작을 여기에 추가
        printf("다시 시도하려면 다른 키를 누르세요...\n");
    }
}

#include <stdio.h>
#include "Function.h"

int main(void) {
    SetTitle("승부차기 게임"); // 게임 타이틀 설정

    SetConsoleSize(156, 25); // 콘솔 크기 설정

    SetConsoleCursorVisibility(0); // 커서가 보이지 않게 설정

    GameStart(); // 게임 시작 화면 표시

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Windows 환경에서 _getch() 함수 사용

void GameStart() {
    printf("게임을 시작하려면 'S'를 눌러주세요...\n");
    char input = _getch(); // 키보드 입력을 받습니다 (Windows 전용)

    if (input == 'S' || input == 's') {
        printf("게임이 시작됩니다!\n");
        GameMain();
    }
    else {
        printf("잘못된 입력입니다. 게임을 시작할 수 없습니다.\n");
    }
}

void GameMain() {
    printf("게임 메인 루프에 진입했습니다.\n");
    // 여기에 게임 로직을 추가합니다
    printf("게임 로직을 실행 중...\n");

    // 간단한 종료 로직 추가
    printf("게임을 종료하려면 아무 키나 누르세요...\n");
    _getch(); // 사용자 입력 대기
}

void GK1(int x, int y)
{
    GotoXY(x, y);
    printf("  △  \n");
    GotoXY(x, y + 1);
    printf("<^모^>\n");
    GotoXY(x, y + 2);
    printf(" -¶- \n");
    GotoXY(x, y + 3);
    printf("  ||  \n");
}

void PK_kicker()
{
    printf(" ⓚ \n");
    printf("/||\\ \n");
    printf(" /\\ \n");
}

void PK_kicker_kick()
{
    printf(" ⓚ/ \n");
    printf("/||/ \n");
    printf(" /   \n");
}

void displayStage(int stage)  // 스테이지 표시
{
    clearScreen();
    printf("===== STAGE %d =====\n", stage);
    printf("Complete this stage to proceed to the next one.\n");
    // 여기에서 스테이지를 진행하는 로직을 추가하세요
}

int main() {
    int stage = 1;
    char input;

    while (1) {
        displayStage(stage);

        printf("Press 'c' to clear this stage and proceed to the next stage, or 'q' to quit: ");
        scanf(" %c", &input);  // %c 앞에 공백이 있어야 합니다. 공백이 없으면 개행 문자도 읽힐 수 있습니다.

        if (input == 'c') {
            stage++;  // 다음 스테이지로 이동
        }
        else if (input == 'q') {
            break;  // 게임 종료
        }
        else {
            printf("Invalid input. Please press 'c' to continue or 'q' to quit.\n");
        }

        // 잠시 기다리기 (초당 1초)
        sleep(1);
    }

    printf("Game Over!\n");
    return 0;
}

int stage = 1;
printf("STAGE : %d\n\n", stage); //스테이지가 늘어나면 값도 증가
printf("♥♥♥"); // 실축시 ♡로 바뀌며 3개가 되면 게임오버
