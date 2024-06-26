/*
* if ~ else if ~ else �ڵ带 �����ϴ� ����� ������ϴ�.
* 
* �Ǵٸ� ���ǹ� switch ~ break;
* 
* switch (����)
* {
*     case ������ �� :
*     ����Ǵ� �ڵ�
*     break;
*     ...
*     ...
*     ...
*     default :
*     break;
* }
* 
* ������ ������, ó���ؾ� �� ������ �پ��� �� ����ϴ� ���ǹ� �Դϴ�.
*/

#include "lectures.h"

void lectures13_switch()
{
	int num;
	scanf_s("%d", &num);

	switch (num)
	{
	case 0:
		printf("num�� 0�Դϴ�. \n");
		break;
	case 1:
		printf("num�� 1�Դϴ�. \n");
		break;
	case 2:
		printf("num�� 2�Դϴ�. \n");
		break;
	default:
		printf("num�� 0~2 �̿��� ���Դϴ�. \n");
		break;
	}

	//if (num == 0)
	//	printf("num�� 0�Դϴ�. \n");
	//else if (num == 1)
	//	printf("num�� 1�Դϴ�. \n");
	//else if (num == 2)
	//	printf("num�� 2�Դϴ�. \n");
	//else
	//	printf("num�� 0~2 �̿��� ���Դϴ�. \n");

	// switch���� �⺻ ������ ���� �н��Ͽ����ϴ�.
	// break�� ������ ��� �ɱ��?

	switch (num)
	{
	case 0:
	case 1:
		printf("0,1�� ���� ���� Ȯ�� : \n");
		break;
	case 2:
	case 3:
	case 4:
		printf("2,3,4�� ���� ���� Ȯ�� : \n");
	default:
		printf("num�� 0~2 �̿��� ���Դϴ�. \n");
	}


	// switch( ) // int ������ �Է��߽��ϴ�.
	// ( ) �ȿ� �� �� �ִ� ������ Ÿ���� ������!
	// flaot, double �Ǽ��� ������ Ÿ���� ���� ������ ������ �߻��մϴ�.

	char d_num = 1;
	switch (d_num)  // case ( ) : case�� �����ݷ�(;) ���̿� ���� ����. ������ �ƴϰ�, ������ ������ ��ȯ�Ǵ� ���̿��� ����� ����.
	{               // ������ ������, switch ~ case���� ����ϴ� ������ �������� ���ؼ� ����� �մϴ�.
	case 2+3+3+2+3:
		break;
	case 65:
		break;
	}
}