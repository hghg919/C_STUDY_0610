#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// printf �Լ��� scanf �Լ��� ����ؼ� ������ ������ ����� ������ �սô�.

	// �÷��̾ �ڡ� ȯ���ϴ� �ؽ�Ʈ�� ������ּ���  �ڡ�

	// printf ( ���ڸ� �Է��ϸ� ������ �����մϴ�. ) [press start any key]
	// scanf -> �Է��� �޴´�.. Ŀ���� ���� ���·� ����ϰ� �ִ�.

	// ���� �Ǵ� �Ǽ� �����͸� ���� ��ǻ�Ͱ� �����ϴ� ����� ����ϰ�,
	// ���� �����ϴ� ����� ���� ����ϴ� ���α׷��� ����� ������.

	srand(time(NULL));	
	int cumputervalue = rand() % 100 + 1; // 1 ~ 100�� ������ ���ڰ� cumputervalue�� �Է��� �˴ϴ�.
	int uservalue;

	// ��ǻ���� ����� ~ ���Դϴ�.
	
	// �÷��̾��� ���� ~ �Դϴ�.
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("�ڡ١ڰ��� ����!�ڡ١�\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ�\n");
	printf("�١ڡ١ڡ١ڡ١ڡ١ڡ�\n\n");

	printf("���ڸ� �Է��ϸ� ������ �����մϴ�.\n");
	int start_num;
	scanf_s("%d", &start_num);

	printf("�÷��̾��� ���� �־��ּ���!");

	return 0;
}