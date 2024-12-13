/*
*  �ۼ��� : 2024-07-15
*  �ۼ��� : �赿��
* �н� ��ǥ : �迭�� �������� ���� => "���" ������
*/

// 1. �迭�� �������� ����
// (1) sizeof(�迭) , sizeof(�����ͺ���) ������ ���� �ٸ��� ���Դ�.
// (2) �迭�� ��� �����ʹ�.

// 2. �����Ϳ� ���
// (1) ����� ����Ű�� ������ pointer to constant
// (2) ������ �� ��ü�� ��� constant pointer
// (3) ����� ����Ű�� �� ��ü�� ����� ���� constant pointer to constant


#include "lectures.h"

void ShowData(const int* ptr)	// const int* arr�� �ǹ̸� �ѹ� �����غ��ð�.
{
    const int* rPtr = ptr;
	printf("%d \n", *rPtr);
	//*rPtr = 20;
}

void ShowAllData(int* const arr, int len)
{
	// for �ݺ������� arr�� ���� ��ŭ �迭��Ҹ� printf �Լ��� ����� ���ð�.

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

}

void lecture19()
{
	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_arr[4] = { 1,2,3,4 };
	int* s_arrPtr = s_arr;

	ShowAllData(s_arrPtr, 3);  // sizeof(arr) -> 4 *sizeof(int)/sizeof(int)

	// (1) sizeof ������
	int arr[3] = { 1};  // 100
	int* arrPtr = arr; // &arr[0] ǥ���� �� �ִ�.

	printf("�迭�� ũ�� : %d \n", sizeof(arr));	    //   siezof(int) x 100 = 400(����Ʈ)
	printf("�������� ũ�� : %d ", sizeof(arrPtr));	//   16����. 32��Ʈ, 64��Ʈ	   8 x 4��Ʈ (32) , 16 x 4��Ʈ (64)			 

	// �����ͷ� �ڵ带 �ۼ��ϴ� ��. �Ǽ��� ������ ���ɼ� ��������, �����ϱ⵵ �����ϴ�.
	// 4000����Ʈ 8����Ʈ ǥ���� �� �� �ִ�.
	// ������ ���� ������� �ʴ� ���.

	// Constant (���)
	// Pi = 3.14; 
	// �ڵ��� �������� �����ִ� ������. �ڿ� ����Ǵ� ������ �ٲ� �� ����.
	//const int Pi = 3.14;
	//pi = 3.5;

	//(1) ����� ����Ű�� ������ pointer to constant
	// num�� ���� �������� ���ϰ� �����ش�.
	// const int* ������ ������ �� ���� �������� ���Ѵ�.  ������ �����ڷ� ���� ���ٲ۴�.
	const int num = 10;
	//num = 15;
	const int* numPtr = &num;  // int const* numPtr = &num;
	//*numPtr = 15;

	// (2) ������ �� ��ü�� ��� constant pointer
	
	int num1 = 20;
	int num2 = 30;
	int* const numCptr = &num1;	 // ��� �������� ����. �迭�� ��� ������.
	*numCptr = 40;
	//numCptr = &num2;             // ��� ������. �ּҸ� �������� ���Ѵ�.
	                               // �迭�� ��� ������. �迭�� ���� �� �� �迭�� �ּҸ� ������ �� ����.

	// (3) ����� ����Ű�� �� ��ü�� ����� ���� constant pointer to constant
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCptr2 = &num3;
	//*numCptr2 = 50;
	//numCptr2 = &num4;


	// ����
	// ������. ����.
	// ���� - ��, �ּ�(&)
	// ������ - �ּ�, ��(*)

	// ������ ����
	// + Const
	// �� const, �ּ� const
	// �� const - ��� ������             costant pointer								    
	// �ּ� const - ����� ����Ű�� ������ pointer to constant
	// Const �����Ϳ� ����ϴ� ����?
	// ������ ������ ����� ������� �ʱ⸦ �����Ϸ� �ܰ迡�� �����ϱ� ���ؼ� (�������� �����ϱ� ���ؼ�)

}