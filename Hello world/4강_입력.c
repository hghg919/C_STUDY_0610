// �Է�
// Scanf �Լ��� �ǽ�
// ���� �̸� ���� (�Է��� �޾Ƽ� ������ ������ �̸� ����)
// �⺻ ���� : Scanf("%d", &������ �̸�);     //shift +7 : &
// Scanf_s("%d, &num);

#include <stdio.h>

int main(void)
{
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
	printf("�� ���� ���� : %d\n", FirstNum1 * FirstNum2);

	// ���� 2. " 3���� ������ �Է� �޾Ƽ�, SecondNum1 * SecondNum2 + SecondNum3 ����ϴ� �ڵ带 �ۼ��غ�����.
	printf("����2\n");
	int SecondNum1, SecondNum2, SecondNum3;
	printf("ù��° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum1);
	printf("�ι�° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum2);
	printf("����° ������ �Է����ּ��� :");
	scanf_s(" %d", &SecondNum3);

	printf("%d x %d + %d �� : %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

	// ���� 3. " �� ���� ������ �Է¹޾Ƽ� ��� �������� ����ϴ� �ڵ带 �ۼ��غ�����.
	// ���� ���ϴ� ��� : a / b(���� ������ ���� �κ��� ��)
	// a % b =  a�� b�� ���� ������ ��
	return 0;
}