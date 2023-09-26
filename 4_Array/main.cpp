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
}