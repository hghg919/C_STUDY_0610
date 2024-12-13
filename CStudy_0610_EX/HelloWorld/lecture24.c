/*
*  �ۼ���   : 2024-07-23
*  �ۼ���   : �赿��
*  �н���ǥ : ����ü
*/

#include "lectures.h"
#include "stdbool.h"

// ����ü�� ��� ������ �ʱ�ȭ�ϴ� ��.

// ����ü�� ������
typedef struct Item {
	int itemX;
	int itemY;
	int* itemPtr;
}Item;

// typedef Ű���带 ����Ͽ� ����ü �����ϱ�
typedef struct Player2 {
	int playerX;
	int playerY;
	bool isPlayerDead;
}Player2;

typedef struct Monster {
	char* monsterName;  // Goblin, orc...
	char* monsterGrade; // Common, Elite, Named, Boss
}Monster;


void ChangePlayerInfoByStruct(Player2* p2, int addValue)
{
	// ����ü �����ͷ� ����� �ٲٴ� ��� -> ������ ����ϸ� �ȴ�.
	p2->playerX += addValue; // *playerX += addValue;
	p2->playerY += addValue; // *playerY += addValue;
	// playerX �ּ��� �������� �� ���� addValue ���ض�
	p2->isPlayerDead = !(p2->isPlayerDead);	 // *isPlayerDead = !(*isPlayerDead);  // !(*(isPlayerDead : �ּҸ� ��� �ִ� ����) : ����Ű�� �� false) => True
		
}

void ChangeItemInfoByStruct(Item* item1, int addValue)
{
	item1->itemX += addValue;
	item1->itemY += addValue;
}

void ChangePlayerInfo(int* playerX, int* playerY, bool* isPlayerDead, int addValue)	// X,Y�� ��ǥ�� AddValue��ġ��ŭ �������Ѻ�����
{
	*playerX += addValue;
	*playerY += addValue;
	*isPlayerDead = !(*isPlayerDead);  // !(*(isPlayerDead : �ּҸ� ��� �ִ� ����) : ����Ű�� �� false) => True
}

void lecture24()
{
	// �÷��̾��� ��ġ�� ����ϴ� �Լ�
	// playerX, playerY, isPlayerDead :: �÷��̾��� ��ǥ(x,y), �÷��̾��� ���� ����
	// Call-by-Reference. ��, �ּҸ� �Ѱ��ִ� �Լ�
	int playerX = 5, playerY = 5;
	bool isPlayerDead = false;
	// structure �ڷᱸ��
	struct Player {
		int playerX;
		int playerY;
		bool isPlayerDead;
	};


	// Item�̶�� �̸����� ����ü�� �ϳ� �����ð�.	itemX, itemY

	// ����ü �ȿ��� �ʱ�ȭ�� �� �� ����.



	struct Player p1;
	Player2 p2;
	Item item1;	 // item1.itemX, itemY 
	item1.itemX, item1.itemY = 0;
	int some = 1;
	item1.itemPtr = &some;
	printf("some�� �� : %d\n", some);
	*item1.itemPtr = 10;
	printf("some�� �� : %d\n", some);

	// Item ����ü ������ ����Ű�� �ּҸ� �����ϴ� ����(������) �����غ���.
	Item* itemPtr = &item1;

	// ����ü�� �ּҸ� �̿��ؼ� ����ü ������ �����ϱ�
	(*itemPtr).itemX = 20; // item1.itemX = 20; �ִ� �Ͱ� ������ �����̴�.
	//*itemPtr.itemX // �ǹ̴� itemPtr������ itemX�� �������϶� 
	printf("item1�� itemX �� ��� : %d \n", item1.itemX);

	// (*�����ͺ���).�������; vs *�����ͺ���.��������� ������
	// *������������ : �켱������ ������ ���� �����̱� ������ *�����ͺ���.��������� ������ ��������� �������� �ǹ̸� ���´�.
	// (*�����ͺ���).������� ����� �ϸ�, (������ ������ ����Ű�� ��).��������� �����ϰ� �ȴ�.

	// ����ü �����͸� �̿��ؼ� ��� ������ �����ϱ� ���ؼ���
	// (*������ �����̸�)�� ���·� �ݵ�� ����ؾ� �Ѵ�.

	// ȭ��ǥ �����ڰ� ����!! : ����ü �����Ϳ��� ����ϴ� ������
	itemPtr->itemX = 10; // (*itemPtr).itemX = 10;

	// �� ����
	// ����ü�� ���� ����
	// typedef struct �̸� {int a;, int b, int* ptr;} �̸�;
	// ����ü�� �����ϰ� �� ����ü�� ������ �����ϴ� ������ (.) 
	// ����ü ������ : ����ü�� �ּҸ� ����Ű�� ����
	// ����üŸ��* �������̸� = &����üŸ�Ժ���;	   
	// ���� �Ҵ�. malloc << ���� ��������� �ҰԿ�.
	// ����ü �����͸� �̿��ؼ� ���� �����ϱ� ���� -> ȭ��ǥ �����ڸ� ���.


	// ����ü�� ��������� ����ϴ� ��� : (.)������
	p1.playerX = 5;
	p1.playerY = 5;
	p1.isPlayerDead = true;

	printf("player����ü�� ��� ��� playerX : %d, playerY : %d, playerDead : %d\n", p1.playerX, p1.playerY, p1.isPlayerDead);

	p2.playerX = 5;
	p2.playerY = 5;
	p2.isPlayerDead = true;

	printf("player2����ü�� ��� ��� playerX : %d, playerY : %d, playerDead : %d\n", p2.playerX, p2.playerY, p2.isPlayerDead);

	// item1 ����ü�� ����մ� ��� ������ ����غ�����.
	item1.itemX = 10;
	item1.itemY = 10;
	printf("item����ü�� ��� ��� itemX : %d, itemY : %d\n", item1.itemX, item1.itemY);


	ChangePlayerInfo(&playerX,&playerY,&isPlayerDead, 10);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", playerX, playerY, (bool)isPlayerDead);

	ChangePlayerInfoByStruct(&p1, 5);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", p1.playerX, p1.playerY, (bool)p1.isPlayerDead);

	// �÷��̾ ���� ���� �Ӽ��� �ϳ��� ��� ǥ���� �� ������?
	// �ּ�. ������ Ÿ��(4����Ʈ) n��
	// ���� �ٸ� ������ Ÿ���� ����� �� �ִ� �ϳ��� Ÿ���� ���� �� �ִ� ���.=> ����ü

	// Item�� ���� Item ����ü �����͸� ����ؼ� �����ϴ� �Լ��� ��������.
	ChangeItemInfoByStruct(&item1 , 5); // �Լ��� �ϼ� ��Ű�� printf ����غ�����!
	printf("item1 : %d, item1 : %d\n", item1.itemX, item1.itemY);

	Monster monster;

	monster.monsterGrade = "�Ϲ�";
	monster.monsterName = "���";

	printf("������ �̸� : %s ������ ��� : %s", monster.monsterGrade, monster.monsterName);

}

