#pragma once

#include <stdio.h>
#define filename "Test\\people.txt"

// ~~~.h : �Լ��� ������ �����մϴ�.
// (������ Ÿ��) 1. void  2. (��ȯ�� ��������) <- int, double, char, char*, int*, double*, struct people 
// int �Լ��̸�(); :: ��ȯ���� int�̰� �Լ��̸��� �ش��ϴ� �༮�� �����մϴ�. �����Ϸ�����.

// ����ü ��� ���Ͽ� ������ ��. ����ü�� ���� ������ �ۼ��� ���ص� �ɱ��? �ȵȴ�. ����ü�� ���빰�� ���� �ۼ�������Ѵ�.

typedef struct Person {
	char name[30];
	int age;
}Person;

void WriteFile();
void ReadFile();
void WriteFileByStruct();
void ReadFileByStruct();