#include<stdio.h>

#include"main.h"

int main()
{
	//int num1, num2;
	//printf("숫자 2개를 입력하세요(num1 num2):");
	//scanf_s("%d %d", &num1, &num2);
	//printf("두 수의 합은 %d입니다.", Sum(num1, num2));

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
			printf("두 수의 나눗셈은 %d입니다.", division(num1, num2));
		}
		break;

		case 4:
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 나눗셈 나머지 값은 %d입니다.", remain(num1, num2));
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