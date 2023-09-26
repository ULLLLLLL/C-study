#include <stdio.h>

// c++ 의 컴파일
// c++에서 사람이 작성한 소스코드를 컴퓨터가 읽을 수 있는 코드로 변환하여 실행할 수 있는 파일로 변환하는 과정

// 컴파일은 4단계로 정리
// 1. 전처리(Preprocessing) 단계 : #include와 #define과 같은 전처리기 매크로들을 처리하는 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(0bject file)로 변환하는 단계
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행  파일을 생성하는 단계
// 링킹 단계에서 전역변수가 2개면 오류가 난다.

// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어 있는 영역
// 2. Data 영역 : 전역변수, static 변수들이 저장, 프로세스가 종료될 때까지 메모리에 저장
// 3. stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자로 할당, free() 또는 delete 연산자로 해제

int g_money = 0;//전역 변수

static int s_money = 0;

#include "money.h"
#include "calcFunc.h"
/*
struct fruitShop
{
	//구조체 내부 선언한 변수는 구조체 사라지지 않으면 안 사라진다.
	//c++에서 변수를 선언하면 그 변수는 공간을 차지하고 있고 계속 선언되어 있다.-메모리 차지
	int appleA;
	int mangoA;
	int strawberryA;

	//구조체 생성자 ":"이 구문 오른쪽에 변수에 초기값을 세팅한다.
	fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
	{

	}

	//구조체에 함수 생성
	void SetFruitValue(int apple, int mange, int strawberry)
	{
		int appleB = apple;//SetFruitValue 함수가 종료되면 사라진다.-지역함수
		appleA = apple;
		mangoA = mange;
		strawberryA = strawberry;
	}

	void printShopValue()
	{
		printf("과일가게 가격 사과:%d, 망고:%d, 딸기:%d\n", appleA, mangoA, strawberryA);
	}
};
*/

struct PhoneShop
{
	int iPhoneA;
	int zFlipA;
	int GalaxyS23A;
	int GalaxyFoldA;

	PhoneShop() : iPhoneA(100), zFlipA(90), GalaxyS23A(80), GalaxyFoldA(15)
	{

	}
	void SetPhoneValue(int iPhone, int zFlip, int GalaxyS23, int GalaxyFold)
	{
		iPhoneA = iPhone;
		zFlipA = zFlip;
		GalaxyS23A = GalaxyS23;
		GalaxyFoldA = GalaxyFold;
	}

	void printShopValue()
	{
		printf("핸드폰가게 가격 iPhone:%d, zFlip:%d, GalaxyS23:%d, GalaxyFold:%d\n", iPhoneA, zFlipA, GalaxyS23A, GalaxyFoldA);
	}
};


// 1 + 1 =2
int Add(int a, int b)
{
	printf("int형 Add가 사용되었습니다\n");
	return a + b;
}
// 1.2 +1.3 = 1.5
float Add(float a, float b)
{
	printf("float형 Add가 사용되었습니다\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double형 Add가 사용되었습니다\n");
	return a + b;
}


int main()
{
	int t_money = 0; //지역변수
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);

	printf("main t_money=%d\n", t_money);
	printf("main g_money=%d\n", g_money);
	printf("1=1 Sum=%d\n", Sum(1, 1));

	Add(1, 1);
	Add(1.0f, 1.0f);//f를 붙이고 실수를 쓰면 float형
	Add(1.0, 1.0);//f를 붙이지 않고 실수를 쓰면 double형

	//배열
	//배열을 설정
	//int arrlnt[10] = { 0 };//배열 생성 및 전부 0으로 초기화
	//int arrlnt[10] = { 0, };//배열 생성 및 전부 0으로 초기화
	int arrlnt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //배열 생성 및 각각에 배열에 초기값 넣는 방법
	arrlnt[0] = 10;// 배열 0번째에 값 넣기
	arrlnt[4] = 40;// 배열 4번째에 값 넣기
	arrlnt[9] = 90;// 0번부터 배열이 시작되므로 마지막 배열은 9번

	//배열을 출력
	//for문
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 배열 값은 %d입니다.\n", i, arrlnt[i]);// 2개 이상의 파라메타 출력
	}

	//배열을 출력하는 다른 방법
	// 위에서 배열 10까지로 설정을 해줬으니 10번째까지만 출력한다.
	// for each문 for(int value:arrlnt)-> for(int value:배열)
	int number = 0;
	for (int value : arrlnt)
	{
		printf("for each %d번째 배열 값은 %d입니다.\n", number, value);
		number++; 
	}

	// Struct에 사용
	// fruitShop : 변수형
	// shop : 변수의 이름
	/*
	fruitShop shop[3];

	// Struct 함수 사용법
	shop[0].appleA = (1000, 2000, 3000); // shop에 appleA변수에 값 넣기
	shop[1].mangoA = (1100, 2100, 3100); // shop에 mangoA변수에 값 넣기
	shop[2].strawberryA = (900, 1900, 2900); // shop에 strawberryA변수에 값 넣기

	for (fruitShop stValue : shop)
	{
		stValue.printShopValue();
	}
	*/

	// PhoneShop[0], PhoneShop[1], PhoneShop[2]에 가격을 출력
	PhoneShop shop[3];

	shop[0].SetPhoneValue(100, 90, 80, 150);
	shop[1].SetPhoneValue(110, 100, 90, 160);
	shop[2].SetPhoneValue(90, 80, 70, 140);
	for (PhoneShop Valuee : shop)
	{
		Valuee.printShopValue();
	}


	bool bRun = true;
	while (bRun)
	{
		int nlnput = 0;
		int num1, num2;

		printf("어떤 연산을 하시겠습니까?(0:더하기, 1:빼기, 2:곱하기, 3: 나누기, 4:나머지):");
		scanf_s("%d", &nlnput);
		switch (nlnput)
		{
		case 0:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 합은 %d입니다.", Sum(num1, num2));
		}
		break;

		case 1:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 뺄셈은 %d입니다.", Minus(num1, num2));
		}
		break;

		case 2:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 곱셈은 %d입니다.", Multiply(num1, num2));
		}
		break;

		case 3:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 나눗셈은 %.2f입니다.", Division(num1, num2));
		}
		break;

		case 4:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 나눗셈 나머지 값은 %d입니다.", Remain(num1, num2));
		}
		break;

		default:
			break;
		}


		printf("계산기를 종료하시겠습니까?(0:No, 1: Yes):");
		scanf_s("%d", &nlnput);

		switch (nlnput)
		{
		case 0:
			continue;
			break;
		case 1:
			bRun = false;
			break;
		}

	}

	return 0;

	printf("\nHappy Birthday 민울!\n\n");

}