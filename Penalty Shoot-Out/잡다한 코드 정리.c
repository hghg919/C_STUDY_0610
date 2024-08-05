#include <stdio.h>

void save_score(const char* filename, int score) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("���� ���⿡ �����߽��ϴ�.\n");
        return;
    }
    fprintf(file, "%d\n", score);
    fclose(file);
    printf("���ھ ����Ǿ����ϴ�: %d\n", score);
}

int main() {
    int score = 12345; // ���� ���, �� ���ھ �����Ѵٰ� �����սô�
    save_score("score.txt", score);
    return 0;
}

#include <stdio.h>

int load_score(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("���� ���⿡ �����߽��ϴ�.\n");
        return -1; // ���и� ��Ÿ���� ��
    }
    int score;
    fscanf(file, "%d", &score);
    fclose(file);
    return score;
}

int main() {
    int score = load_score("score.txt");
    if (score != -1) {
        printf("����� ���ھ�: %d\n", score);
    }
    return 0;
}

#ifndef FUNCTION_H
#define FUNCTION_H

// �Լ� ������Ÿ��
void SetTitle(const char* title);
void SetConsoleSize(int width, int height);
void SetConsoleCursorVisibility(int visibility);
void GameStart(void);
void GameMain(void);

#endif // FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Windows ȯ�濡�� _getch() �Լ� ���
#include "Function.h"

void SetTitle(const char* title) {
    printf("%s\n", title); // ������ ����, �����δ� Windows API�� ����ϰų� �ܼ� ��ɾ ����ؾ� �մϴ�.
}

void SetConsoleSize(int width, int height) {
    // �ܼ� ũ�⸦ �����ϴ� �Լ� (Windows ���� �ڵ� ����)
    // SYSTEMINFO ����ü�� ����ϰų� Windows API�� ����ؾ� ��
    // ����� �ܼ��� ȭ�� ũ�⸦ �����ϴ� �ڵ尡 �����Ƿ� �����θ� �ۼ�
    printf("�ܼ� ũ�⸦ %dx%d�� �����մϴ�.\n", width, height);
}

void SetConsoleCursorVisibility(int visibility) {
    // Ŀ�� ���ü��� �����ϴ� �Լ� (Windows ���� �ڵ� ����)
    // �����δ� Windows API�� ����ؾ� ��
    printf("Ŀ�� ���ü��� %d�� �����մϴ�.\n", visibility);
}

void GameStart(void) {
    printf("���� ���� ȭ��\n");
    printf("1. ���� ����\n");
    printf("2. ���� ����\n");
    printf("3. ���� ���\n");
    printf("4. ���� ����\n");

    char choice;
    printf("�޴��� �����ϼ���: ");
    choice = _getch(); // �Է��� ����

    switch (choice) {
    case '1':
        GameMain(); // ������ �����մϴ�.
        break;
    case '4':
        printf("������ �����մϴ�.\n");
        exit(0); // ���α׷� ����
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
        break;
    }
}

void GameMain(void) {
    printf("���� ���� ȭ��\n");
    printf("�г�Ƽű ������ ����˴ϴ�.\n");

    // ���� ������ �߰��մϴ�.
    // ���� ���, ���� �����ϰų� Ű �Է��� ó���ϴ� ������ ���⿡ �߰��մϴ�.

    printf("���� ���Ḧ ���Ͻø� 'Q'�� ��������.\n");

    char input;
    while (1) {
        input = _getch(); // �Է��� ����
        if (input == 'Q' || input == 'q') {
            printf("������ �����մϴ�.\n");
            break;
        }

        // ���� ������ ���� ������ ���⿡ �߰�
        printf("�ٽ� �õ��Ϸ��� �ٸ� Ű�� ��������...\n");
    }
}

#include <stdio.h>
#include "Function.h"

int main(void) {
    SetTitle("�º����� ����"); // ���� Ÿ��Ʋ ����

    SetConsoleSize(156, 25); // �ܼ� ũ�� ����

    SetConsoleCursorVisibility(0); // Ŀ���� ������ �ʰ� ����

    GameStart(); // ���� ���� ȭ�� ǥ��

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Windows ȯ�濡�� _getch() �Լ� ���

void GameStart() {
    printf("������ �����Ϸ��� 'S'�� �����ּ���...\n");
    char input = _getch(); // Ű���� �Է��� �޽��ϴ� (Windows ����)

    if (input == 'S' || input == 's') {
        printf("������ ���۵˴ϴ�!\n");
        GameMain();
    }
    else {
        printf("�߸��� �Է��Դϴ�. ������ ������ �� �����ϴ�.\n");
    }
}

void GameMain() {
    printf("���� ���� ������ �����߽��ϴ�.\n");
    // ���⿡ ���� ������ �߰��մϴ�
    printf("���� ������ ���� ��...\n");

    // ������ ���� ���� �߰�
    printf("������ �����Ϸ��� �ƹ� Ű�� ��������...\n");
    _getch(); // ����� �Է� ���
}

void GK1(int x, int y)
{
    GotoXY(x, y);
    printf("  ��  \n");
    GotoXY(x, y + 1);
    printf("<^��^>\n");
    GotoXY(x, y + 2);
    printf(" -��- \n");
    GotoXY(x, y + 3);
    printf("  ||  \n");
}

void PK_kicker()
{
    printf(" �� \n");
    printf("/||\\ \n");
    printf(" /\\ \n");
}

void PK_kicker_kick()
{
    printf(" ��/ \n");
    printf("/||/ \n");
    printf(" /   \n");
}

void displayStage(int stage)  // �������� ǥ��
{
    clearScreen();
    printf("===== STAGE %d =====\n", stage);
    printf("Complete this stage to proceed to the next one.\n");
    // ���⿡�� ���������� �����ϴ� ������ �߰��ϼ���
}

int main() {
    int stage = 1;
    char input;

    while (1) {
        displayStage(stage);

        printf("Press 'c' to clear this stage and proceed to the next stage, or 'q' to quit: ");
        scanf(" %c", &input);  // %c �տ� ������ �־�� �մϴ�. ������ ������ ���� ���ڵ� ���� �� �ֽ��ϴ�.

        if (input == 'c') {
            stage++;  // ���� ���������� �̵�
        }
        else if (input == 'q') {
            break;  // ���� ����
        }
        else {
            printf("Invalid input. Please press 'c' to continue or 'q' to quit.\n");
        }

        // ��� ��ٸ��� (�ʴ� 1��)
        sleep(1);
    }

    printf("Game Over!\n");
    return 0;
}

int stage = 1;
printf("STAGE : %d\n\n", stage); //���������� �þ�� ���� ����
printf("������"); // ����� ���� �ٲ�� 3���� �Ǹ� ���ӿ���
