/*
*  �ۼ���  : ������
*  �ۼ���  : 2024-06-25
* �н���ǥ : while �ݺ���
* 
* for �ݺ��� �н��� �߽��ϴ�
* while �ݺ������ε� �ݺ��� ǥ���� �� ���� �ֽ��ϴ�.
* 
* while(���ǽ�) : ���ǽ��� true�̸� ���� ��ü�� �����ϰ�, ���ǽ��� false�̸� ���� �ڵ带 �����϶�.
* {
*     �ڵ� ����; /���� ��ü 
*     ��ȭ��;
* }
* 
* do ~ while
* 
* do
* {
*     �ݺ���ų �ڵ�;
* }while(���ǽ�);
* 
*/
#include "lectures.h"

void lectures12_3()
{
	int i = 0;
	while (i < 10) // i�� 10���� ������ ��� �ݺ��ض�
	{
		i = i + 2; // ��ȭ��
		printf("hello wolrd!\n");
	}
	
	printf("\n");

	int index;
	scanf_s("%d", &index);

	while (index != 3) // while ���ǽĿ� �������� ���Կ����ڸ� ����ϸ� ���� ������ ���� �� �����Ƿ� �����ؾ� �Ѵ�.
	{
		printf("hello world!\n");
		scanf_s("%d", &index);
	}

	// while �ݺ����� ���� : �� �� �ݺ����� �𸣴� �ڵ忡�� ����ϱ� ����.

	printf("\n");

	// do ~ while ����
	// �� ���� �ݵ�� ����ϵ��� ������ �Ǿ� �ִ� �ڵ�.
	int i_donum = 1;
	do 
	{
		printf("�ѹ��� �ݵ�� ����ϴ� do ~ while��.\n");
		i_donum = i_donum * 3;
	} while (i_donum < 10);

	// ���ӿ��� �ѹ��� �ݵ�� �����ؾ� �Ѵ�.
	// do while
}