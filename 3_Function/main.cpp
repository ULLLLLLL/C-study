#include<stdio.h>

// �Լ���
// unsigned int : ��ȯ �ڷ��� <-Output
// CalculatorSum : �Լ��̸�
//(int x, int y) : �Ű� ����(�Ķ��Ÿ) <-Input
//return�� ���� ������ ���� �ÿ� ������ ����ؾ� �Ѵ�. �׷��� ��� �� ���ڿ� ���ڸ� �Է� ��, ��ȯ�� �� ���� �ִ�.

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


//Factorial �Լ�
int Factorial (int num) 
{
	int Facresult = 1;
	for (int i = num; i > 0; i--)
	{
		Facresult *= i;
	}

	return Facresult;
}

//Factorial2  �Լ�
int Factorial2(int Num)
{
	int FacResult = 1;
	for (int i = 1; i <= Num; i++)	
	{	
		FacResult *= i;	
	}	
	return FacResult;	
}


int ReFactorial(int Num) // Num���� 1���� ���ϴ� �Լ�
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1); 
	// ReFactorial Num 3 / Return (3)
	// ReFactorial Num 3-1=2 / Return (2) ->(�� �� �����丮�� ��ȯ) ReFactorial Num 3 / Return (3*2)
	// ReFactorial Num 2-1=1 / Return(1) ->(�� �� �����丮�� ��ȯ) ReFactorial Num 2 / Return (3*2*1)
}

int SumToN(int Num) //1���� Num���� ���ϴ� �Լ�
{
	if (Num == 1)
	{
		return 1;
	}
	return Num + SumToN(Num - 1);
}

int main()
{
	//unsigned int nResult = 0;
	//double nResultt = 0;
	//printf("���ϱ� �Լ� ���� ��� = %d\n", CalculatorSum(10, 1));
	//printf("���� �Լ� ���� ��� = %d\n", CalculatorMinus(3, 1)); 	
	//printf("���ϱ� �Լ� ���� ��� = %d\n", CalculatorMultiply(4, 2));// nResult = CalculatorMultiply(4, 2);
	//printf("������ �Լ� ���� ��� = %lf\n", CalculatorDivide(9, 4));  	//nResultt = CalculatorDivide(9, 4);
	//printf("������ �Լ� ���� ��� = %d\n", CalculatorRemain(7, 2)); 
// �̰� ����� �ƴ϶� ȣ��ƴٴ� ���� ����ϱ� ����, �׸��� ��ȯ �� ���Ḧ ����
		// ���� print �ּ� ó���ϸ� ������ ��������, �־ ��� ������ �ּ� ó�� �� �ص� �ȴ�. �� int main �ȿ��� ó���ؾ� ��!

	//// �ݺ���
	//// for��
	//for (/*�ʱ� ����*/ int i = 0;/*�ݺ� ���� üũ*/i < 10;/*�ݺ� �� ó��*/++i)
	//{// <- �ݺ� ó���� �ڵ� ����
	//
	//	printf("%d Hello\n", i);
	//}// <- �ݺ� ó���� �ڵ� ��

	////for (int i = 0;i < 10;++i)
	////{
	////	printf("Hello\n");
	////} // �ڸ�Ʈ ���� �̷� ����

	//int a = 0;
	//for (; a < 5; ++a) // for ���� int�� �Լ����� �������ָ� '�ʱ⼳��'�� �ڸ��� ����ֵ� ������.
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
	//2. i = 0�̰�, i < 10 üũ ����� true(1)
	//3. �ݺ� ó���� �ڵ� ����
	//4. �ݺ� �� ó�� ++i(i�� 1 ���� ��Ų��.) i=1;
	//~~~~~�ݺ�
	//1. int i = 9;
	//2. i = 9�̰� i<10 üũ ����� true(1)
	//3. �ݺ� ó���� �ڵ� ����
	//4. �ݺ� �� ó�� ++i(i�� 1 ���� ��Ų��.) i = 10
	//1. int 1 = 10;
	//2. i=10�̰� i<10 üũ ����� false(0)

	// Factorial
	// 5 Factorial ���ض�
	// 5 * 4 * 3 * 2 * 1 = 120;

	int FacResult = 1;
/*
	for (int i = 1; i <= 10; i++) // 1���� 10���� 1�� ������ ���� ��� ���� ��
	{
		FacResult *= i;
	}

	int FacNum = 4; // 4���� 1�� �۾��� ����� ��� ���� ��
	for (int i = FacNum; i > 0; i--)
	{
		FacResult *= i;
	}

	int FacResult = 0; //0���� n���� ���� ��
 
	for (int i = 1; i < 1113; i++)
	{
		FacResult += i;
	}

	printf("FacResult = %d", FacResult);
*/

	printf("FacResult = %d", Factorial(5)); // (-> n���� 1���� ���ϴ� ���. -1�� �ϴٰ� i>0���� False�� �� �����)37��° �ٿ��� ���� ����(�Լ�)�� ����� ��
	printf("FacResult = %d", Factorial(8)); // (1���� n���� ���ϴ� ���. i+1�� �ϴٰ� i<Num���� False�� �� �����)49��° �ٿ��� ���� ����(�Լ�)�� ����� ��
	printf("ReFactorial FacResult = %d\n", ReFactorial(5)); // (n���� 1���� ���ϴ� ���)
	printf("SumToN FacResult = %d\n", SumToN(4));// 1~n���� �� ���ϴ� �Լ�
}



void CallFunction()
{
	//return;
	printf("�Լ� ȣ��ƴ�!");
}