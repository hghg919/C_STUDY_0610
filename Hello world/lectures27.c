// void에 대한 설명(1) 함수의 반환형 (2) void pointer
// Eum에 대한 설명 (1) Eum이 왜 필요한가

// 무엇을 만들지 정하기 어려운 분 : 별피하기, 콘솔어드밴쳐 [구조체. 파일저장기능]
// 권장하는 부분 여러분이 만들고 싶은 프로젝트를 정하는 것 : 몬스터 데이터 프로그램, 도서관리프로그램, 테트리스, 공룡달리기 게임
// 막히는 부분, 버그가 발생, 조언을 받고 싶은 부분. -> 정리해서 질문

// 함수에서 반환형이 어떤 것인가...
// void : 공허, 비어있다. 함수의 반환형에 사용되면 반한형(Return Type)이 없다.

// swap(int* a, int* b)(int temp; temp. *a, *b) : a의 데이터와 b의 데이터를 교환한다.
// void swap : 인자로 넘겨주는 a와b의 값만 변경해주고 종료된다.
// int compare() : // 같으면 return 0, 틀리면 1을 반환하도록 하여. if문이랑 같이 사용을 했습니다.
// c++, stdbool - true false 변환해서 사용을 하고 있습니다.

#include "lectures.h"

// 반환형 함수이름(인자)
void Add_one(int* a)
{
	*a = *a + 1;
}

// 반환형이 존재하는 이유 : 컴파일러가 이 코드르 보고나서 크기를 미리 결정해주는 기능.
// int num

// void는 메모리 공간에 얼마나 저장되는지 알 수 없어서 void형 변수는 선언할 수 없습니다.
// void* 변수는 메모리 공간에 얼마나 저장됬는지 알 수 있나요?
// void* 불완전한 형식입니다. 왜 불완전하다고 할까요?
// 메모리 공간에 얼마나 차지하는지 크기를 알려줍니다. + 정수, 실수, 구조체

// 정리
// int* : 메모리 공간에 4바이트 확보하고, 4바이트 공간에 int 형식으로 데이터를 읽어와라
// void* : 메모리 공간에 8바이트 확보했는데, 어떤 형식인지 모른다. 쓰임이 있다.
// void 포인터를 사용하는 이유가 무엇일까?
// intSwap, doubleSwap, floatswap 데이터 타입만 다른 버젼의 함수들이 쓰이고 있다.
// 이 함수들을 타입을지정해서 정해주는 함수로 만들면 하나로 표현할 수 있지 않을까?
// ??????

#define TYPEOFINT 1
#define TYPEOFDOUBLE 2
#define TYPEOFFLOAT 3

// defint INT, DOUBLE, FLOAT
// 상수를 한번에 표현하는 방식 : enum 키워드 제공하고 있습니다.

// 열거형 ENUM 사용하는 이유
// 1. 코드의 가독성 증가 : 상수로 표현하는 변수의 이름이 정확히 어떤 내용인지 불완전합니다. enum 상수의 이름들을 정의하는 공간을 만드는 겂니다. TYPE -> 상수 3개 (float, int, double)
// 2. 네임스페이스 공간 제공 : 함수의 인자로 enum type을 사용할 수 있다.
// 3. 유지보수가 쉬워집니다. : 네임스페이스 공간이 따로 지정이 되어있으므로 버그를 찾기도 수월해집니다.
// 4. 타입 안전성이 생깁니다 : 상수의 데이터를 따로 지정할 필요 없이 enum type을 선언하면 된다.

typedef enum TYPE { TYPE_Char, TYPE_INT, TYPE_Double }Type;

void SwapValue(void* ptr1, void* ptr2, Type type)
{
	switch (type)
	{
	    case TYPE_Char:
	    {
			char temp;
			temp = (*(char*)ptr1);
			(*(char*)ptr1) = (*(char*)ptr2);
			(*(char*)ptr2) = temp;
			break;
	    }

		case TYPE_INT:
		{
			int temp;
			temp = (*(int*)ptr1);
			(*(int*)ptr1) = (*(int*)ptr2);
			(*(int*)ptr2) = temp;
			break;
		}

		case TYPE_Double:
		{
			double temp;
			temp = (*(double*)ptr1);
			(*(double*)ptr1) = (*(double*)ptr2);
			(*(double*)ptr2) = temp;
			break;
		}
	}
}

void lectures27()
{
	// void 함수는 이렇게 사용하면 안됩니다.
	int num = 1; // 컴파일러가 미리 메모리 공간에 4바이트 확보를 합니다. 2진수로 작성된 0101 데이터로 부터 정보를 전달.
	// void some; // 컴파일러가 메모리 공간에 얼마나 저장해야하는지 알 수 있나요?
	Add_one(&num);

	void* voidptr; // 포인터 변수는 64비트 시스템일때 8바이트의 크기를 확보합니다.
	printf("void*의 크기 : %d\n", sizeof(voidptr));

	double a = 1.1;
	voidptr = &a;

	// voidptr를 double* 형식으로 type 변환하겠다.

	printf("voidptr가 가르키는 값 : %If\n", (*(double*)voidptr));

	char c1 = 'a';
	char c2 = 'b';
	SwapValue(&c1, &c2, TYPE_Char);
	printf("값 확인 %c %c\n", c1, c2);

	int a1 = 1;
	int a2 = 2;
	SwapValue(&a1, &a2, TYPE_INT);
	printf("값 확인 %d %d\n", a1, a2);

	double d1 = 1.1;
	double d2 = 2.2;
	SwapValue(&d1, &d2, TYPE_Double);
	printf("값 확인 %f %f\n", d1, d2);
}