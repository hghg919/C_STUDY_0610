/*
	4��. �̽������� ����
	�ۼ���   : ������
	�ۼ���   : 2024-06-13
	�н���ǥ : �̽������� ���� ���
*/

#include <stdio.h>

void lectures4()
{
	int num6 = 500;
	printf("���� ������ �ݾ� : 450�� \n");
	printf("\"���� ������ �ݾ� : %d��\" \n", num6);

	// ��ӵ� ��Ģ���� ���� ����� �� �� ���� ���ڵ��� �ִ�.
	// �̷��� ���ڵ��� ����ϰ� ���� �� �̽������� : "\"
	// \ + (��ӵ� ����) : ���ο� ����� ������ �� �ִ�.
	// ���� : \n , \a ,  \t, \b, \r , \\, \? , \", \'

	/*
	   \n :	�� ���� ����ش�. ����. new line
	   \a :	alarm. ������ ������� ����Ѵ�.
	   \t :	tab ���� ���ڻ����� ������ ����(tab) ���.
	   \b : backSpace, �ܼ� Ŀ���� �� ĭ �ڷ� �̵���Ų��.
	   \r :	ĳ���� ����(return), ���콺 Ŀ���� �ش� ���� �� ó������ �̵���Ų��.
	   \\, \?, \", \' :	�ý��� ��� �� �⺻�� ����� �� ���� ���ڸ� ����ϰ� ���ش�.
	*/

	printf("���� ������ �ݾ� : %d�� \n", num6);
	printf("\a");
	printf("hello\b\bhi\n");
	printf("�ǳ��ϼ���\r�ȳ�\n");
	printf("�ݰ�\t���ϴ�. \n");
	printf("\\ \' \" \? ������ �߻� �ϳ���? \n");

	// ������ �̿��� �������� ����.
	// ������ �����ϴ� �پ��� ���
	// (1) ������ ����, ���� �Ҵ�
	int num1;
	num1 = 10;
	// (2) ���� �ʱ�ȭ. (����� �Ҵ�)
	int num2 = 20;
	// (3) ������ ���ÿ� ����, �� ������ ���� ���� �͸�!
	int num3, num4, num5;
	num3 = 10, num4 = 20, num5 = 30;
	printf("%d %d %d\n\n", num3, num4, num5);
	// (4) ������ ���ÿ� ����� �Բ� �Ҵ�;

	// ���� �̸� �ۼ� �� ���� ����(���� ����)

	// ������ ù ���ڿ� ���ڰ� ���� �ȵȴ�.
	//int 776num;
	// #,$ Ư�� ��ȣ�� �̸��� ����� �� ����.
	//int #num;
	// ���� �̸� ���̿� ����(���� ����)�� �� �� ����.
	//int your function;
	// Ű���嵵 �̸����� ����� �� ����.
	// auto, enum, break, return, void, float, short, while
	//int union;

	// ������ �̸��� �� ���� ���� ������ �ؾ��մϴ�.

	//int abc = 10;
	int playerHP = 100;

// �Է�
// Scanf �Լ��� �ǽ�
// ���� �̸� ���� (�Է��� �޾Ƽ� ������ ������ �̸� ����)
// �⺻ ���� : Scanf("%d", &������ �̸�);     //shift +7 : &
// Scanf_s("%d, &num);

	int width = 24, height = 12, length = 8;

	int num;
	// �ּ��� ���� �Լ��� ��� Scanf_s
	// ������ �Է��� ���ڸ� "num�� �� ���� : n" ���·� ����ϴ� ���α׷����Դϴ�.
	printf("����\n");
	printf("���ڸ� �Է����ּ���\n");
	scanf_s("%d", &num);
	printf("num�� �� ���� : %d\n", num);

	// ������ �̸� FirstNum1, FirstNum2, FirstNum3
	// ���� 1. " �� ���� ������ �Է� �޾Ƽ� �� ���� ������ ������ ����� ����غ�����"
	// int FirstNum1, FirstNum2;   
	// �� ���� ���� : ���   
	// �� ���� ���� : ���
	printf("����1\n");
	int FirstNum1, FirstNum2;
	printf("ù��° ������ �Է����ּ��� :");
	scanf_s(" %d", &FirstNum1);
	printf("�ι�° ������ �Է����ּ��� :");
	scanf_s(" %d", &FirstNum2);
	printf("�� ���� ���� : %d\n", FirstNum1 - FirstNum2);
	printf("�� ���� ���� : %d\n\n", FirstNum1 * FirstNum2);

	// ���� 2. " 3���� ������ �Է� �޾Ƽ�, SecondNum1 * SecondNum2 + SecondNum3 ����ϴ� �ڵ带 �ۼ��غ�����.
	printf("����2\n");
	int SecondNum1, SecondNum2, SecondNum3;
	printf("ù��° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum1);
	printf("�ι�° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum2);
	printf("����° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum3);

	printf("%d x %d + %d �� : %d\n\n", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

	// ���� 3. " �� ���� ������ �Է¹޾Ƽ� ��� �������� ����ϴ� �ڵ带 �ۼ��غ�����.
	// ���� ���ϴ� ��� : a / b(���� ������ ���� �κ��� ��)
	// a % b =  a�� b�� ���� ������ ��
	printf("����3\n");
	int a, b;
	printf("ù��° ������ �Է����ּ��� :");
	scanf_s(" %d", &a);
	printf("�ι�° ������ �Է����ּ��� :");
	scanf_s(" %d", &b);

	printf("�� ���� �� : %d \n", a / b);
	printf("�� ���� ������ �� : %d \n\n", a % b);

	//����4. " �ϳ��� ������ �޾Ƽ� ������ ����ϴ� �ڵ� �ۼ� "

	printf("����4\n");
	int c;
	printf("�ϳ��� ������ �Է����ּ��� :");
	scanf_s(" %d", &c);

	printf("%d�� ���� : %d \n\n", c, c * c);
	
	//����5. �� ���� ������ �Է��� �޾Ƽ�, {fifthnum1 - fifthnum2} x { fifthnum2 + fifthnum3 } x { fifthnum3 * fifthnum1} �� ����� ����ϴ� �ڵ带 �ۼ��غ�����.
	printf("����5\n");
	int fifthnum1, fifthnum2, fifthnum3;
	printf("ù��° ������ �Է����ּ��� :");
	scanf_s(" %d", &fifthnum1);
	printf("�ι�° ������ �Է����ּ��� :");
	scanf_s(" %d", &fifthnum2);
	printf("����° ������ �Է����ּ��� :");
	scanf_s(" %d", &fifthnum3);

	printf("�� ������ �� : %d \n\n", fifthnum1 - fifthnum2 * fifthnum2 + fifthnum3 * fifthnum3 * fifthnum1);
}