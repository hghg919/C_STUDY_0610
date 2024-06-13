/*기본 환경 설정
 main함수 시작과 끝을 알리는 핵심 함수이다. 반드시 1개만 존재해야 한다. 이름 대소문자 반드시 지켜줘야한다.
 main 이름의 함수가 2이상 존재하면 에러가 발생한다.
 소스파일 - 우클릭 - 설정 - 빌드에서 제외 기능으로 원하는 파일만 빌드할 수 있다.

 작성자   : 정현준
 작성일자 : 2024-06-12
 학습주제 : 변수(variable)

 컴퓨터 한테 명령을 하고, 그 명령한 내용을 저장하기 위해서 변수을 사용해야 한다.

 선언(declare) : 변수를 어떻게 컴퓨터한테 알려주나요.
 컴파일러에게 변수가 무엇을 저장하고, 얼만큼 저장해야 하는지 알려주는 것
 int   : 무엇을(정수)
 float : 무엇을(실수)

 선언방법
 데이터 형태 작성(int, float) 변수 이름(a)
 예시 int a;

 할당(assignment) -> =
 선언한 변수에 데이터를 넣는 것
 a이름의 변수에 정수 형태의 데이터를 넣을 수 있게 된다.
 예시 int a = 10;

 초기화(initialize)
 변수에 처음으로 데이터를 할당하는 것*/

#include <stdio.h>

int main()
{
	int a = 5 + 3;
	a = 4 + 7;
	printf("%d \n", a);

	float b = 3.2f + 4.7f;
	printf("%f \n", b);

	//문제1-1
	//변수의 이름 width=12, height=10, length=8 정수를 담을 수 있는 변수 선언

	int width = 12;
	int	height = 10;
	int length = 8;

	//문제1-2, 세 변을 곱한 값(부피) volume 변수에 저장하세요.

	int volume = width * height * length;

	//문제1-3, 부피 / 165로 나누어 원하는 계산 값을 구한다. prinrtf 함수로 출력하세요.

	volume = (volume + 164) / 165;

	float volume_f = width * height * length;
	volume_f = volume_f / 165;

	printf("문제 1-3.1의 답은 %d \n", volume);
	printf("문제 1-3.2의 답은 %f \n", volume_f);

	//문제4 섭씨, 화씨
	//화씨 = 9/5 * 섭씨 + 32
	//화씨가 실수로 표현할 수 있도록 변수를 선언해주세요.
	//9/5의 값이 1이 아닌 1.8이 나와야 합니다.
	//섭씨1, 화씨 33.8

	float celsius = 1;                             //섭씨
	float fahrenheit = 9.0f / 5.0f * celsius + 32; //화씨  

	printf("섭씨 to 화씨 : %.2f", fahrenheit);

	return 0;
}