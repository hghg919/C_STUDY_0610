/*
* �ۼ���   : ������
* �ۼ���   : 2024-06-26
* �н���ǥ : break, continue;
*/

/*
* for �ݺ���, while �ݺ���
* �ݺ����� ������ �����ϰ� ǥ��.
* break, continue.. (�ݺ���, ���ǹ� - ���) �������ִ� ���
* for, while, do while, switch ����� �մϴ�.
*/

/*
* break    : �����帧���� ����� ���� ����մϴ�. break ����Ǹ� �ش� ������� ���� ���ɴϴ�.
* continue : �����帧�� ������ ���·� �ش� �ڵ��� ���ุ �ǳ� �ٴ� ����� �մϴ�.
*/

#include "lectures.h"

void lectures13()
{
	// printf 10�� �ݺ��ϴ� �ڵ带 for �ݺ���.
	// 0�� ���� ~ Ư�� ���ڱ��� �Ʒ��� �ڵ带 �����ϴµ�,
	// ���� ���ϴ� ��ǥ���� �����ϸ�
	for (int i = 0; i < 10; i++)
	{
		printf("Hi &d\n", i);

		if (i == 7)
		{
			printf("i�� 7�� �� ��µ�\n");
			break;
		}
	}
	int index = 0;
	for (;;) // ���� �ݺ��� ctrl + c
	{
		index++;
		printf("Hi &d\n", index);
		if (index == 7)
		{
			printf("7�� ��µǾ����ϴ�. \n");
			break;
		}
	}

	printf("\n");

	//
	int targetnumber; // �������� ����ϰ��� �ϴ� ��ǥ ����(scanf_s)
	//int counter = 0;  // �ݺ������� targetnumber�� ã�� ���� ����
	//scanf_s("%d", &targetnumber);

	//for (;;)
	//{
	//	counter++;
	//	if (targetnumber == counter)
	//	{
	//		printf("���ϴ� ��� ���� ��µǾ����ϴ�. %d\n", targetnumber);
	//		break;
	//	}
	//}

	// while �ݺ���
	//scanf_s("%d", &targetnumber);
	//int w_counter = 0;
	//while (1) // ���� �ݺ���
	//{
	//	w_counter++;
	//	if (targetnumber == w_counter)
	//	{
	//		printf("���ϴ� ��� ���� ��µǾ����ϴ�. %d\n", targetnumber);
	//		break;
	//	}
	//	// for �ݺ������� Ÿ�� �ѹ��� ã�� �ڵ�� ���� ������ �����غ�����.
	//	// break�� ����� �ϼž� �մϴ�.
	//}
	//
	//printf("\n");
	//
	//// continue ��� ����
	//int w_num = 0;
	//while (w_num < 10)
	//{
	//	w_num++;
	//	if (w_num % 2 == 0) // 2�� �������� �������� 0�� �� : ¦��, Ȧ��
	//	{
	//		printf("%d�� �н��Ǿ����ϴ�. \n", w_num);
	//		continue;
	//	}
	//	printf("w_num�� �� : %d\n", w_num);
	//}

	printf("\n");

	// �ֻ����� �����ſ���. �ֻ������� 12���� ���� �ֽ��ϴ�. scanf_s �������� �ֻ����� ���� �����ϼ���.
	// ���࿡ �ֻ����� ¦���� ���´ٸ�, ���� �������� ���� �ִ� ���� �������� 2�谡 �ǰ�, (�б� ���� �Ϸ�)
	// ���࿡ Ȧ���� ���´ٸ�, �������� ���� �ִ� �������� 0���� �Ǵ� �ڵ带 �ۼ��غ�����. 
	// ���࿡ �������� 0���� �ȴٸ� ���α׷��� ����� ����.

	printf("�ֻ��� �������� ����! \n\n");

	// 0 ~ 12���ڸ� scanf_s ���
	printf("�������� ���� Ÿ¥���� �ֻ��� ���ڸ� ����ּ���(0~12) : ");
	int dicenum, game_money;

	// ���� �ڵ带 ������ 12 ���� ū����, 0���� ���� ���ڸ� �Է��ϸ� �� ���ڰ� dicenum�� ����� �˴ϴ�. �̰��� �����ϴ� �ڵ�
	scanf_s("%d", &dicenum);
	game_money = 1000; //�⺻������ 1000��

	while (1) // while Ż�� ���ǵ�
	{
		if (dicenum < 1 || dicenum > 12)
		{
			printf("�߸��� �ֻ����� ũ�⸦ �Է��޽��ϴ�. \n�ֻ��� ũ�⸦ �ٽ� �Է����ּ��� : \n");
			scanf_s("%d", &dicenum);
			printf("\n");
		}
		else
		{
			// ¦������ Ȧ������ �Ǻ��ϴ� �ڵ带 �ۼ��ؾ� �Ѵ�. 1 ~ 12
			if (dicenum % 2 == 0) // ¦��
			{
				game_money = game_money * 2;

				if (game_money > 5000) // ���� �¸� ����
				{
					printf("���ӿ��� �¸��߽��ϴ�. ���� �ݾ��� : %d �Դϴ�. \n", game_money);
					break;
				}
				else
				{
					printf("���� ���� ���� �ݾ� : %d \n", game_money);
					scanf_s("%d", &dicenum);
				}
			}
			else // Ȧ��
			{
				game_money = 0;
				printf("����� ���ӿ��� �����ϴ�. ���� �ݾ��� : %d \n", game_money);
				break;
			}
		}
	}
}