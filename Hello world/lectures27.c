// void�� ���� ����(1) �Լ��� ��ȯ�� (2) void pointer
// Eum�� ���� ���� (1) Eum�� �� �ʿ��Ѱ�

// ������ ������ ���ϱ� ����� �� : �����ϱ�, �ܼ־����� [����ü. ����������]
// �����ϴ� �κ� �������� ����� ���� ������Ʈ�� ���ϴ� �� : ���� ������ ���α׷�, �����������α׷�, ��Ʈ����, ����޸��� ����
// ������ �κ�, ���װ� �߻�, ������ �ް� ���� �κ�. -> �����ؼ� ����

// �Լ����� ��ȯ���� � ���ΰ�...
// void : ����, ����ִ�. �Լ��� ��ȯ���� ���Ǹ� ������(Return Type)�� ����.

// swap(int* a, int* b)(int temp; temp. *a, *b) : a�� �����Ϳ� b�� �����͸� ��ȯ�Ѵ�.
// void swap : ���ڷ� �Ѱ��ִ� a��b�� ���� �������ְ� ����ȴ�.
// int compare() : // ������ return 0, Ʋ���� 1�� ��ȯ�ϵ��� �Ͽ�. if���̶� ���� ����� �߽��ϴ�.
// c++, stdbool - true false ��ȯ�ؼ� ����� �ϰ� �ֽ��ϴ�.

#include "lectures.h"

// ��ȯ�� �Լ��̸�(����)
void Add_one(int* a)
{
	*a = *a + 1;
}

// ��ȯ���� �����ϴ� ���� : �����Ϸ��� �� �ڵ帣 ������ ũ�⸦ �̸� �������ִ� ���.
// int num

// void�� �޸� ������ �󸶳� ����Ǵ��� �� �� ��� void�� ������ ������ �� �����ϴ�.
// void* ������ �޸� ������ �󸶳� �������� �� �� �ֳ���?
// void* �ҿ����� �����Դϴ�. �� �ҿ����ϴٰ� �ұ��?
// �޸� ������ �󸶳� �����ϴ��� ũ�⸦ �˷��ݴϴ�. + ����, �Ǽ�, ����ü

// ����
// int* : �޸� ������ 4����Ʈ Ȯ���ϰ�, 4����Ʈ ������ int �������� �����͸� �о�Ͷ�
// void* : �޸� ������ 8����Ʈ Ȯ���ߴµ�, � �������� �𸥴�. ������ �ִ�.
// void �����͸� ����ϴ� ������ �����ϱ�?
// intSwap, doubleSwap, floatswap ������ Ÿ�Ը� �ٸ� ������ �Լ����� ���̰� �ִ�.
// �� �Լ����� Ÿ���������ؼ� �����ִ� �Լ��� ����� �ϳ��� ǥ���� �� ���� ������?
// ??????

#define TYPEOFINT 1
#define TYPEOFDOUBLE 2
#define TYPEOFFLOAT 3

// defint INT, DOUBLE, FLOAT
// ����� �ѹ��� ǥ���ϴ� ��� : enum Ű���� �����ϰ� �ֽ��ϴ�.

// ������ ENUM ����ϴ� ����
// 1. �ڵ��� ������ ���� : ����� ǥ���ϴ� ������ �̸��� ��Ȯ�� � �������� �ҿ����մϴ�. enum ����� �̸����� �����ϴ� ������ ����� ���ϴ�. TYPE -> ��� 3�� (float, int, double)
// 2. ���ӽ����̽� ���� ���� : �Լ��� ���ڷ� enum type�� ����� �� �ִ�.
// 3. ���������� �������ϴ�. : ���ӽ����̽� ������ ���� ������ �Ǿ������Ƿ� ���׸� ã�⵵ ���������ϴ�.
// 4. Ÿ�� �������� ����ϴ� : ����� �����͸� ���� ������ �ʿ� ���� enum type�� �����ϸ� �ȴ�.

typedef enum TYPE { TYPE_Char, TYPE_INT, TYPE_Double }Type;

void SwapValue(void* ptr1, void* ptr2, Type type)
{
	switch (type)
	{
	    case TYPE_Char:
	    {
			char temp;
			temp = (*(char*)ptr1);
			(*(char*)ptr1) = (*(char*)ptr2);
			(*(char*)ptr2) = temp;
			break;
	    }

		case TYPE_INT:
		{
			int temp;
			temp = (*(int*)ptr1);
			(*(int*)ptr1) = (*(int*)ptr2);
			(*(int*)ptr2) = temp;
			break;
		}

		case TYPE_Double:
		{
			double temp;
			temp = (*(double*)ptr1);
			(*(double*)ptr1) = (*(double*)ptr2);
			(*(double*)ptr2) = temp;
			break;
		}
	}
}

void lectures27()
{
	// void �Լ��� �̷��� ����ϸ� �ȵ˴ϴ�.
	int num = 1; // �����Ϸ��� �̸� �޸� ������ 4����Ʈ Ȯ���� �մϴ�. 2������ �ۼ��� 0101 �����ͷ� ���� ������ ����.
	// void some; // �����Ϸ��� �޸� ������ �󸶳� �����ؾ��ϴ��� �� �� �ֳ���?
	Add_one(&num);

	void* voidptr; // ������ ������ 64��Ʈ �ý����϶� 8����Ʈ�� ũ�⸦ Ȯ���մϴ�.
	printf("void*�� ũ�� : %d\n", sizeof(voidptr));

	double a = 1.1;
	voidptr = &a;

	// voidptr�� double* �������� type ��ȯ�ϰڴ�.

	printf("voidptr�� ����Ű�� �� : %If\n", (*(double*)voidptr));

	char c1 = 'a';
	char c2 = 'b';
	SwapValue(&c1, &c2, TYPE_Char);
	printf("�� Ȯ�� %c %c\n", c1, c2);

	int a1 = 1;
	int a2 = 2;
	SwapValue(&a1, &a2, TYPE_INT);
	printf("�� Ȯ�� %d %d\n", a1, a2);

	double d1 = 1.1;
	double d2 = 2.2;
	SwapValue(&d1, &d2, TYPE_Double);
	printf("�� Ȯ�� %f %f\n", d1, d2);
}