#include<stdio.h>

// 함수형
// unsigned int : 반환 자료형 <-Output
// CalculatorSum : 함수이름
//(int x, int y) : 매개 변수(파라메타) <-Input
//return은 숫자 변수가 있을 시에 무조건 사용해야 한다. 그래야 계산 후 문자에 숫자를 입력 즉, 반환을 할 수가 있다.

unsigned int CalculatorSum(int x, int y)
{// -> 함수 시작
	printf("함수 시작했다.\n");
	return x + y;// <- 반환 및 종료처리
	printf("함수 끝났다.\n");
}// -> 함수 끝

unsigned int CalculatorMinus(int x, int y)
{
	return x - y;// <- 반환 및 종료처리
}// -> 함수 끝

unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}// -> 함수 끝

double CalculatorDivide(double x, double y)
{
	return x / y;
}// -> 함수 끝

unsigned int CalculatorRemain(int x, int y)
{
	return x % y;
}// -> 함수 끝


//Factorial 함수
int Factorial (int num) 
{
	int Facresult = 1;
	for (int i = num; i > 0; i--)
	{
		Facresult *= i;
	}

	return Facresult;
}

//Factorial2  함수
int Factorial2(int Num)
{
	int FacResult = 1;
	for (int i = 1; i <= Num; i++)	
	{	
		FacResult *= i;	
	}	
	return FacResult;	
}


int ReFactorial(int Num) // Num부터 1까지 곱하는 함수
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1); 
	// ReFactorial Num 3 / Return (3)
	// ReFactorial Num 3-1=2 / Return (2) ->(이 전 리팩토리얼에 반환) ReFactorial Num 3 / Return (3*2)
	// ReFactorial Num 2-1=1 / Return(1) ->(이 전 리팩토리얼에 반환) ReFactorial Num 2 / Return (3*2*1)
}

int SumToN(int Num) //1부터 Num까지 더하는 함수
{
	if (Num == 1)
	{
		return 1;
	}
	return Num + SumToN(Num - 1);
}

int AAA()
{
	while (1)
	{
		printf("1st while! Start\n");
		break;
		printf("1st while! End\n");
	}
	while (1)
	{
		printf("2nd while! Start\n");
		return 0;
		printf("2nd while! End\n");
	}
	while (1)
	{
		printf("3rd while! Start\n");
		break;
		printf("3rd while! End\n");
	}
	return 0;
}


int main()
{
	//unsigned int nResult = 0;
	//double nResultt = 0;
	//printf("더하기 함수 실행 결과 = %d\n", CalculatorSum(10, 1));
	//printf("빼기 함수 실행 결과 = %d\n", CalculatorMinus(3, 1)); 	
	//printf("곱하기 함수 실행 결과 = %d\n", CalculatorMultiply(4, 2));// nResult = CalculatorMultiply(4, 2);
	//printf("나누기 함수 실행 결과 = %lf\n", CalculatorDivide(9, 4));  	//nResultt = CalculatorDivide(9, 4);
	//printf("나머지 함수 실행 결과 = %d\n", CalculatorRemain(7, 2)); 
// 이건 계산이 아니라 호출됐다는 말을 출력하기 위해, 그리고 반환 및 종료를 위해
		// 위에 print 주석 처리하면 내용이 가려지고, 있어도 상관 없으면 주석 처리 안 해도 된다. 단 int main 안에서 처리해야 함!

	//// 반복문
	//// for문
	//for (/*초기 설정*/ int i = 0;/*반복 조건 체크*/i < 10;/*반복 후 처리*/++i)
	//{// <- 반복 처리할 코드 시작
	//
	//	printf("%d Hello\n", i);
	//}// <- 반복 처리할 코드 끝

	////for (int i = 0;i < 10;++i)
	////{
	////	printf("Hello\n");
	////} // 코멘트 빼면 이런 형식

	//int a = 0;
	//for (; a < 5; ++a) // for 전에 int로 함수값을 설정해주면 '초기설정'값 자리를 비워둬도 괜찮다.
	//{
	//	printf("HelloA\n");
	//}

	//for (int b = 0;b < 10;b+=a)
	//{
	//	printf("HelloB\n");
	//}

	//for (int c = 1110; c < 1113; ++c)
	//{
	//	printf("%d Happy birthday\n", c);
	//}

	//1. int i = 0;
	//2. i = 0이고, i < 10 체크 결과는 true(1)
	//3. 반복 처리할 코드 실행
	//4. 반복 후 처리 ++i(i를 1 증가 시킨다.) i=1;
	//~~~~~반복
	//1. int i = 9;
	//2. i = 9이고 i<10 체크 결과는 true(1)
	//3. 반복 처리할 코드 실행
	//4. 반복 후 처리 ++i(i를 1 증가 시킨다.) i = 10
	//1. int 1 = 10;
	//2. i=10이고 i<10 체크 결과는 false(0)

	// Factorial
	// 5 Factorial 구해라
	// 5 * 4 * 3 * 2 * 1 = 120;

	//int FacResult = 1;
/*
	for (int i = 1; i <= 10; i++) // 1에서 10까지 1씩 더해진 값을 모두 곱한 값
	{
		FacResult *= i;
	}

	int FacNum = 4; // 4부터 1씩 작아진 양수를 모두 곱한 값
	for (int i = FacNum; i > 0; i--)
	{
		FacResult *= i;
	}

	int FacResult = 0; //0부터 n까지 더한 값
 
	for (int i = 1; i < 1113; i++)
	{
		FacResult += i;
	}

	printf("FacResult = %d", FacResult);
*/

	//printf("FacResult = %d\n", Factorial(5)) ; // (-> n부터 1까지 곱하는 방법. -1씩 하다가 i>0에서 False일 때 멈춘다)37번째 줄에서 만든 도구(함수)를 사용한 식
	//printf("FacResult = %d\n", Factorial(8)); // (1부터 n까지 곱하는 방법. i+1씩 하다가 i<Num에서 False일 때 멈춘다)49번째 줄에서 만든 도구(함수)를 사용한 식
	//printf("ReFactorial FacResult = %d\n", ReFactorial(5)); // (n부터 1까지 곱하는 방법)
	//printf("SumToN FacResult = %d\n", SumToN(4));// 1~n까지 합 구하는 함수


	//int nResult = 1;
	//int i = 1;
	////(i <= 10) : <- 이 조건식이 true면 아래 괄호{} 안에 코드를 실행한다
	////(i <= 10) : <- 이 조건식이 false면 while문을 종료하고 다음 코드 실행

	////while문
	////조건식이 true면 아래 괄호 안에 코드를 실행한다.
	////조건식이 false면 while문을 종료하고 다음 코드 실행
	//while (i <= 10/*조건식*/)
	//{// <- 반복 처리할 코드 시작
	//	nResult *= i;
	//	i++;
	//}// <- 반복 처리할 코드 종료
	//printf("while Factorial = %d\n", nResult);
	//
	//while (true) //<-true면 무한히 반복돼서 쭈루룩 계속 나온다. 이럴 때 브레이크를 써야 함.
	//{// <- 반복 처리할 코드 시작
	//	printf("i=%d\n", i);
	//	i++;
	//	printf("break 실행 전\n");
	//	break; // 이 명령어를 만나면 while 즉시 종료한다. 아래 코드 실행 안됨.
	//	printf("break 실행 후\n");
	//}// <- 반복 처리할 코드 종료

	
	//0부터 Num 짝수만 더하기 1번 방법(while문)
	// != 0 나머지가 0이 아닌 경우 nResult로 못 넘어가! continue 위로 올라가서 계속 반복해!
	// 나머지가 0인 경우 nResult로 갔다가 위로 가서 반복해!
	int i = 0, Num = 10;
	int nResult = 0;
	while (i <= Num)
	{
		i++;
		if (i % 2 != 0)
			continue; // 다음 코드를 실행하지 않고 위로 올라가서 while 코드를 계속 실행
		nResult += i;
	}
	printf("0~Num EvenSum=%d\n", nResult);

	//0부터 Num 짝수만 더하기 2번 방법 (for문)
	// == 0 나머지가 0인 경우만 모아서 nResult로 보내고 반복해!
	nResult = 0; //리셋하고 쓰기, Num은 위에서 10으로 지정해줌.
	for (int i = 0; i <= Num; i++)
	{
		if (i % 2 == 0)
		{
			nResult += i;
		}
	}
	printf("nResult= %d\n", nResult);

	AAA();

}

	

void CallFunction()
{
	//return;
	printf("함수 호출됐다!");
}