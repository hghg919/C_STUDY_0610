/*
* �ۼ��� : ������
* �ۼ��� : 2024.06.20
* �н���ǥ : C��� �⺻ �ڷ��� + ���
* 
* question : �ڷ����� �����ΰ���?
* -> ���� (�ڷ���) (�����̸�)
* �ڷ����� ������ ����� ���ؼ� �ʿ��ѰŴ�.
* ���� ������ �ʿ䰡 �ִ�. <����, �Ǽ�>
* ������ ����ϱ�� ���߽��ϴ�. �󸶸�ŭ �����͸� ������ ���ΰ�?
* char �����̸� = 0b00000001; 1����Ʈ
* int �����̸� = 0b 00000000 00000000 00000000 00000001; 4����Ʈ
* long long �����̸� = 0b 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001; 8����Ʈ
* �����Ͱ� ����� �޸��� ũ�⸦ �����ϱ� ���� ����Ѵ�.
* � ������ Ÿ��(����,�Ǽ�) ����� �� ������ �� �� �������� ũ�⸦ ������ Ű���带 data type(�ڷ���)�̶� �Ѵ�.
* "int" : 4����Ʈ ����, ������ ������ ������ ���� -> ���� �̸�.
*/

/*
* �⺻ �ڷ����� ������ �������� ǥ������
* (1)������
* char      : 1����Ʈ(8��Ʈ) 2e8(256) / -2e7 ~ 2e7 -1 (-128 ~ 127 : 256��)
* short     : 2����Ʈ(16��Ʈ) -2e15 ~ 2e15 -1
* int       : 4����Ʈ(32��Ʈ) -2e31 ~ 2e31 -1
* long      : 4����Ʈ(32��Ʈ)
* long long : 8����Ʈ(64��Ʈ) -2e61 ~ 2e61 -1 / 2e62
* 
* ANSI : american national standards instiue
* c����� ǥ���� ���ϴ� ��ȸ. �����̷�. ���. 65 'A'. int = 4����Ʈ ������. int = 6����Ʈ.
* �����Ϸ��� ������ ���� �ּ� ũ�⸦ ���Ѷ�.
* 
* (2)�Ǽ���
* float      : 4����Ʈ. ��ȣ. ������.������ // �Ҽ��� 6�ڸ� ǥ��.
* double     : 8����Ʈ. �Ҽ��� 15�ڸ� ǥ��
* long float : 8����Ʈ. �Ҽ��� 16�ڸ� ǥ��
*/

/*
* 1��ȣ(MSB) 0, 1, ����, ���...
* ��ȣ�� �ʿ� ����. unsigned
* unsigned char (���� �̸�) : 0 ~ 2e8�� ����. ��ȣ ���� ���� ǥ����.
* unsigned int (���� �̸�)  : 0 ~ 2e32�� ����.
*/

/*
* sizeof ������ .. ���� (n)����Ʈ..
* int i_num = sizeof(int); //4
* int i_num = sizeof a;    // sizeof () �Ѵٰ��ؼ� �Լ��� �ƴϴ�.
* int i_num = sizeof(a);   // �Ϲ������� ()�� �Բ� ����Ѵ�.
*/

/*
* ���
* ������ �ʴ� ��.
* ����(���ϴ� ��) - �ڷ���.
* 
* ���� : �̸��� ���� ���, �̸��� ���� �ʴ� ���
* ���ͷ� ��� (literal) ���� �״�� ������ �ʴ� ��.
* double my_double = 3.15;
* my_double = 2.96;
* 
* 
* int my_int = 10;    // int
* char my_char = 5;   // int
* short my_short = 7; // int
* int my_int = 30�� ���� ū��. 21��... 2e31-1 // long long
* 
* ���ͷ� �������
* ������ �⺻ �ڷ����� int�Դϴ�.
* int���� ū ���� �Է��� �Ǹ� �ڵ����� int���� ū ���������� ������ �˴ϴ�.
* 
* int���� ����, char, short�� �� int�� �����Ϸ��� ������ �ϳ���?
* ���� ���� ó���ϴ� Ÿ�� int.
* short -> char // int���� �༮��� ������ �ؾ� �ϴ� ��찡 ����ϴ�.
* ��ǻ�Ͱ� ó���� �� �ִ� ���� ���� ����(int) �����ؼ� ������ Ÿ���� �ٲپ� �ְ� �ִ�. �����Ϸ�, ���.
* 
* �Ǽ��� �⺻ �ڷ����� double�� ����ϰ� �ֽ��ϴ�.
* my_double = 3.15;
* float my_float = 3.15f?;
* 
* my_long = 3.15l;
* ul  : unsigned long
* ll  : long long
* ull : unsigned long long
* 
* f : float
* l : long float
*/

/*
* �̸� �ִ� ��� : �ɺ��� ���.
* �߷��� ũ�� : -9.8f;
* ����        : 3.141592........
* 
* const float gravity = -9.8f;
* const ����� ���ÿ� �ʱ�ȭ�� ����� �մϴ�.
* 
* ��ó���Ⱑ �������ϱ� ���� garavity��� ������ ���� -9.8�� ��ȯ��Ų��.
* #befine gravity = -9.8f;
* 
* ����� �ۼ��� �� �̸� ��� ���.
* �빮�ڷ� �ۼ��� ���ֵ�, ����� "_" ǥ���Ѵ�.
* ����) GET_TIME_PRICPLE
*/

#include "lectures.h"

void lectures9()
{
	printf("�⺻ �ڷ��� ���� ���� \n\n");
	
	// sizeof �����ڸ� ����ؼ� ���������� ����ϱ� .. 
	// char, short int, long, long long, float, double, long float

	//�̷��� ������ ��� �ذ��� �� ���� �����̴ϴ�.
	int sizenum = sizeof(char);
	printf("char ������ ũ�� : %d \n", sizenum);
	
	sizenum = sizeof(short);
	printf("short ������ ũ�� : %d \n", sizenum);
	
	sizenum = sizeof(int);
	printf("int ������ ũ�� : %d \n", sizenum);

	sizenum = sizeof(long);
	printf("long ������ ũ�� : %d \n", sizenum);

	sizenum = sizeof(long long);
	printf("long long ������ ũ�� : %d \n", sizenum);

	sizenum = sizeof(float);
	printf("float ������ ũ�� : %d \n", sizenum);

	sizenum = sizeof(double);
	printf("double ������ ũ�� : %d \n", sizenum);

	sizenum = sizeof(long float);
	printf("long float ������ ũ�� : %d \n\n", sizenum);

	sizenum = sizeof(double);
	double my_double = 2.45;
	printf("double ������ ũ�� : %d \n", sizenum);
	sizenum = sizeof(long double);
	printf("long double ������ ũ�� : %d \n\n", sizenum);

	// ����2. ���ͷ� ����� sizeof �����ڷ� ����غ�����.
	// 3.15, 3.15f, 10, � �����͸� ����ϴ��� �ľ��غ���
	// ���� ��� sizeof(5); � ���� ����ϴ� �Լ��� ǥ���غ���.
	sizenum = sizeof(10);
	printf("������ ���ͷ� ���� ũ�� : %d\n", sizenum);
	sizenum = sizeof(3.14);
	printf("���ͷ� ����� �Ǽ� ǥ���� �⺻ �ڷ��� : %d\n", sizenum);
	sizenum = sizeof('A');
	printf("������ ��� ǥ���� �⺻ ũ�� : %d\n", sizenum);

	sizenum = sizeof(3.15);
	printf("3.15�� �� : %d \n", sizenum); // long float
	sizenum = sizeof(3.15f);
	printf("3.15f�� �� : %d \n", sizenum); // float
	sizenum = sizeof(10);
	printf("10�� �� : %d \n\n", sizenum); // int

	// ����3. ���簢���� ���̸� ���ϴ� ���α׷��� �ۼ��� �غ�����.
	// ù��° ���� : ��ǥ�� �ΰ� �����޾ƾ� �մϴ�. (xpos1,ypos1) (xpos2,ypos2)
	// �ι�° ���� : xpos2�� xpos1���� Ŀ���մϴ�.
	// xpos2 - xpos1 ���̷� �ϴ� ���簢���� ���Ͻø� �˴ϴ�.
	// (4,6) (6,8) 2x2 = 4
	int xpos1, ypos1, xpos2, ypos2, result;
	printf("��ǥ�� ������� �Է��ϼ��� (xpos2,ypos2�� xpos1,ypos1���� Ŀ���մϴ�) : (xpos1,ypos1) (xpos2,ypos2)\n");
	// �ι�° ������ printf�� �ȳ����ּ���. (���� ǥ��) ��ǥ1�� ��ǥ2�� ���� �Է½�Ű�� �� �� ����
	scanf_s("%d %d %d %d", &xpos1, &ypos1, &xpos2, &ypos2);
	result = (xpos2 - xpos1) * (ypos2 - ypos1);
	
	/* chatgpt
	if (xpos1 > xpos2)
	{
		int temp = xpos1;
		xpos1 = xpos2;
		xpos2 = temp;
	}

	if (ypos1 > ypos2)
	{
		int temp = ypos1;
		ypos1 = ypos2;
		ypos2 = temp;
	}
	*/

	printf("���簢���� ���� : %d \n\n", result);

	// �ɺ��� ��� ����1.
	// const Ű���带 ����Ͽ� ���̸� PI�� �����ϰ� �� ���� 3.14�� �Ѵ�.
	// ���� ���̸� ���ϴ� �ڵ带 ����� ����Ͽ� ǥ���ϼ���
	const double PI = 3.14;
	int AREA;
	scanf_s("%d", &AREA);
	scanf_s("%f", &PI); //�ʿ������� ����
	printf("���� ���� : %f", AREA * PI);
}