#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int InputNumber();

void StartGameSetting(); // = void GameStart(); 

int SetPlayerHP();

void inputPlayerValue();

void GameWin();

int Fail(int playerHP);

void SetColor(unsigned char BGColor, unsigned char TextColor);

void GameStart();  // ��ü����

void Clear_ConSole();

int getUserInput(); // ��ü����