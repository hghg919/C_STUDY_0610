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

void GameStart();  // 자체제작

void Clear_ConSole();

int getUserInput(); // 자체제작