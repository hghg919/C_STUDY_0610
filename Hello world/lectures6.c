/* 
  �ۼ���  : ������
* �ۼ���   : 2024-06-17
* �н���ǥ : �����
* 
*  �����
*  - ������� �ؾ� �ϴ� ����
*  - ���α׷����� �ϸ鼭 �ۼ��� ������ ������ �ذ��ϱ� ���ؼ�
*  - ������ �ǽɰ��� �κп� �ڵ��� �ߴ����� �����ϰ� ������ ��ǻ���� ������� ������ Ȯ���� �� �ִ�.
*  - ������ �ذ� �ϱ� ���� ����̴�(With Computer Debuging System)
*  ����Ű
*/

// Operator ������
// ����, ��� ������
// '=', -, +, x, / , % 
// "=" : A = B ����.(�� ������ - ����)	(���� ������);
// int num = 30;   // Left Value = Right Value; ������ ���� ���� ������ �־��ִ� ���
// ���� ������ (a <- b ) �������ִ�.

/*���� ���� ������
* ���� :  a = a + b;	   a += b;
*        a = a - b;    a -= b;
*        a = a * b;    a *= b;
*        a = a >> b;   a >>= b;
*        a = a & b;    a &= b;
*        a = a | b;    a |= b;
*/

/* ����, ���� ������
*  num++;
* ++num;
* num--;
* --num;
*  ++ : ���� +=1�� ���� ��.
*  -- : ���� -=1�� ���� ��.
*
*  ���� ����(����) : ������ 1�� ���� �� ���� ��, ������ ������ �����Ѵ�.
*  ���� ����(����) : ������ ������ ���� ���� �� ������ ���� ��ȭ ��Ų��.
*
*/



/* ���� ������
*  �� ������. �� ���� ���� ���Ͽ� �� ���踦 ǥ���ϴ� ������.
*  a ,  b , result ;
*  a = 10, b = 12
*  ��� ���� True(��), False(����)���� ���ɴϴ�.
*  True : 1,  False : 0
*  result = (a > b);
*  result�� ���� true�� 1��, false�� 0�� ����.
*/

/* �� ������
*  AND, OR, NOT
*  AND : && (shift + 7)	       ->  A�� B�� ��� ���̸� ����� ���� ����� ��ȯ�Ѵ�. "1"
*  OR  : || (Shift + \(�޷�))  ->  A�� B�� �ϳ��� ���̸� 1�� ����� ��ȯ�Ѵ�.
*  NOT : !���� 	               -> A�� True�̸� False ��ȯ, False�̸� True ��ȯ�Ѵ�.
*/

// ���� ���� ����
// int A = (a == 10 && b == 12);
// int B = (a < 12 || b > 12);
// int C = !a; 

#include "lectures.h"

void lectures6()
{
	printf("����� ���� ����\n");
	char a, b, c;
	a = 100;
	b = 300;
	c = a + b;
	printf("%d + %d = %d\n\n", a, b, c);

	printf("������ ���� ����\n\n");

	// 9 + 2 = 11, 9 - 2 = 7; �ڵ� ȣ�⽺��

	int num1, num2, num3, result;
	result = 0;
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("��� ���(l-value) = %d x %d + %d = %d\n", num1, num2, num3, num1 * num2 + num3);
	printf("���մ��� ������(��� = %d += %d)\n\n", result, num1);

	printf("����, ���� ������ ���� ����\n");
	int plusa = 10;
	int plusb = (plusa++) + 2;
	printf("plusb�� ���� ������ ���� ���? : %d \n", plusb);
	printf("plusa�� ���� �󸶳� ���� ���? : %d \n\n", plusa);

	printf("��� �� = %d \n\n", num1 < num3);

	printf("������ �켱 ���� ������ ����\n");

	//���� : ���� a�� ���� 3 + 4 X 5 �̸�, ���� b�� ���� 7 / 3 % 2 �̴�.
	//���� a�� b�� ���� ���� ���� result ������ �����Ͽ� ����Ͽ� ������.

	int variablea; // 3 + 4 X 5;
	int variableb; // 7 / 3 % 2;
	int final; // variablea�� variableb�� ���迬���ڸ� ����Ͽ� final �����غ�����.

	// scanf �۾� �������� �Ҵ�

	int cal1, cal2, cal3;
	scanf_s("%d %d %d\n", &cal1, &cal2, &cal3);
	variablea = cal1 + cal2 * cal3;
	printf("variablea�� �� : %d \n", variablea);
	variableb = 7 / 3 % 2;
	final = (variablea < variableb);

	printf("variablea�� variableb ���� �۳���? ture�̸� 1�� ��� false�̸� 0�� ����մϴ� : %d\n", final);
}