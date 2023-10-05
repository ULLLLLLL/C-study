#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"

// �Լ��̸� : Sum
// �Ű� ����(�Ķ��Ÿ) : int a, int b
// ��ȯ �� : int
// a�� b�� ���� ����� ��ȯ�Ͻÿ�

// �Լ��̸� : Minus
// �Ű� ����(�Ķ��Ÿ) : int a, int b
// ��ȯ �� : int
// a�� b�� ������ ����� ��ȯ�Ͻÿ�

// �Լ��̸� : Multi
// �Ű� ����(�Ķ��Ÿ) : int a, int b
// ��ȯ �� : int
// a�� b�� ���ϱ��� ����� ��ȯ�Ͻÿ�

// �Լ��̸� : Divide
// �Ű� ����(�Ķ��Ÿ) : float a, float b
// ��ȯ �� : float
// a�� b�� �������� ����� ��ȯ�Ͻÿ�

// �Լ��̸� Average
// �Ķ��Ÿ int &Sum, int a, int b, int c
// ��ȯ�� ����
// ���۷��� ���� Sum���� a, b, c�� ��� ���� ��ȯ

void Average(int &Sum, int a, int b, int c)
{
	Sum = (a+b+c)/3;
}

// �Լ��̸� ArraySum
// �Ķ��Ÿ int* arr, int length
// ��ȯ �� : int
// �迭 "arr"�� �迭�� ���� "length"�� �Ķ��Ÿ�� �޾Ƽ� ��� �迭�� ���� ��ȯ

int ArraySum(int* arr, int length)
{
	int Sum = 0;
	for (int i = 0; i < length ; i++)
	{
		Sum = Sum + arr[i];
	}
	return Sum;
}

// Ŭ���� �̸� : CShop
// �ɹ� ���� : m_value(�⺻��:0)
// �ɹ� �Լ� �߰� : printValue
// printValue �Լ� ��� : "Value=%d"�� m_value ���
class CShop // ������
{
	int m_value = 0;
public:
	void printValue()
	{
		printf("Value=%d", m_value);
	}
};
// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
// ������ �Ķ��Ÿ : int PhoneCnt ( m_PhoneCnt�� �� ���� )
// ������ �Ķ��Ÿ : int PhonePrice ( m_PhonePrice�� �� ���� )
// �ɹ� ���� : m_PhoneCnt
// �ɹ� ���� : m_PhonePrice
// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���
class CPhoneShop : public CShop
{
public:
	CPhoneShop(int PhoneCnt, int PhonePrice):m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{
	}
void printValue()
{
	printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
}

public:
	int m_PhoneCnt;
	int m_PhonePrice;
};

// CPhoneShop(10, 100) ���� �� ��ü�� printValue ���

// Ŭ���� �̸� : CFruitShop
// ������ �Ķ��Ÿ : int FruitCnt ( m_FruitCnt�� �� ���� )
// ������ �Ķ��Ÿ : int FruitPrice ( m_FruitPrice�� �� ���� )
// �θ� Ŭ���� : CShop
// �ɹ� ���� : m_FruitCnt
// �ɹ� ���� : m_FruitPrice
// printValue �Լ� ��� : "Value=%d"�� m_FruitCnt * m_FruitPrice���

class CFruitShop : public CShop
{
public:
	CFruitShop(int FruitCnt, int FruitPrice):m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{
	}
	void printValue()
	{
		printf("Value=%d\n", m_FruitCnt * m_FruitPrice);
	}

public:
	int m_FruitCnt;
	int m_FruitPrice;
};

// CFruitShop(10, 100) ���� �� ��ü�� printValue ���

int main()
{
	// printf�� "Sum=%d\n"���� Sum�Լ� ��� ���
	// printf�� "Minus=%d\n"���� Minus�Լ� ��� ���
	// printf�� "Multi=%d\n"���� Multi�Լ� ��� ���
	// printf�� "Divide=%d\n"���� Divide�Լ� ��� ���

	printf("Sum=%d\n", Sum(1, 2));
	printf("Minus=%d\n", Minus(5, 2));
	printf("Multi=%d\n", Multi(1, 3));
	printf("Divide=%f\n", Divide(9, 3));
	int Sum; 
	Average(Sum, 3, 6, 9);
	printf("Average=%d\n", Sum);
	int arr[] = { 0, 1, 2, 3, 4, 5};
	int length = 6;
	printf("ArraySum=%d\n", ArraySum(arr, length));


	// CPhoneShop(10, 100) ���� �� ��ü�� printValue ���
	CPhoneShop PS(10, 100);
	PS.printValue();

	// CFruitShop(10, 100) ���� �� ��ü�� printValue ���
	CFruitShop FS(10, 100);
	FS.printValue();
}