#include<stdio.h>

// �Լ���
// unsigned int : ��ȯ �ڷ��� <-Output
// CalculatorSum : �Լ��̸�
//(int x, int y) : �Ű� ����(�Ķ��Ÿ) <-Input

unsigned int CalculatorSum(int x, int y)
{// -> �Լ� ����
	printf("�Լ� �����ߴ�.\n");
	return x + y;// <- ��ȯ �� ����ó��
	printf("�Լ� ������.\n");
}// -> �Լ� ��

unsigned int CalculatorMinus(int x, int y)
{
	return x - y;// <- ��ȯ �� ����ó��
}// -> �Լ� ��

unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}// -> �Լ� ��

double CalculatorDivide(double x, double y)
{
	return x / y;
}// -> �Լ� ��

unsigned int CalculatorRemain(int x, int y)
{
	return x % y;
}// -> �Լ� ��

void CallFunction()
{
	//return;
	printf("�Լ� ȣ��ƴ�!");
}

int main()
{
	//unsigned int nResult = 0;
	//double nResultt = 0;
	printf("�Լ� ���� ��� = %d\n", CalculatorSum(10, 1));
	printf("�Լ� ���� ��� = %d\n", CalculatorMinus(3, 1));
	// nResult = CalculatorMultiply(4, 2);
	printf("�Լ� ���� ��� = %d\n", CalculatorMultiply(4, 2));
	//nResultt = CalculatorDivide(9, 4);
	printf("�Լ� ���� ��� = %lf\n", CalculatorDivide(9, 4));
	printf("�Լ� ���� ��� = %d\n", CalculatorRemain(7, 2));
}