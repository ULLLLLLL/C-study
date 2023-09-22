#include<stdio.h>

// 함수형
// unsigned int : 반환 자료형 <-Output
// CalculatorSum : 함수이름
//(int x, int y) : 매개 변수(파라메타) <-Input

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

void CallFunction()
{
	//return;
	printf("함수 호출됐다!");
}

int main()
{
	//unsigned int nResult = 0;
	//double nResultt = 0;
	printf("함수 실행 결과 = %d\n", CalculatorSum(10, 1));
	printf("함수 실행 결과 = %d\n", CalculatorMinus(3, 1));
	// nResult = CalculatorMultiply(4, 2);
	printf("함수 실행 결과 = %d\n", CalculatorMultiply(4, 2));
	//nResultt = CalculatorDivide(9, 4);
	printf("함수 실행 결과 = %lf\n", CalculatorDivide(9, 4));
	printf("함수 실행 결과 = %d\n", CalculatorRemain(7, 2));
}