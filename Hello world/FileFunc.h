// ___.h : �Լ��� ������ �����մϴ�.
// (������ Ÿ��) 1.void 2.(��ȯ�� ��������) <- int, duoble, char, int* .......
// int �����̸�(); :: ��ȯ���� int�̰� �Լ��̸�

// ����ü ��� ���Ͽ� ������ ��. ����ü�� ����������  �ۼ��� ���ص� �ɱ��? �ƴϿ�. ����ü�� ���빰�� ���� �ۼ������ �Ѵ�.

#include <stdio.h>
#define filename "C:\\Users\\Jung\\Documents\\GitHub\\people.txt"

typedef struct Person
{
	char name[30];
	int age;
}Person;

void WriteFile();

void Readfile();

void WriteFileByStruct();

void ReadFileByStruct();