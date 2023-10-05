#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"

// 함수이름 : Sum
// 매개 변수(파라메타) : int a, int b
// 반환 값 : int
// a와 b를 합한 결과를 반환하시오

// 함수이름 : Minus
// 매개 변수(파라메타) : int a, int b
// 반환 값 : int
// a와 b를 빼기한 결과를 반환하시오

// 함수이름 : Multi
// 매개 변수(파라메타) : int a, int b
// 반환 값 : int
// a와 b를 곱하기한 결과를 반환하시오

// 함수이름 : Divide
// 매개 변수(파라메타) : float a, float b
// 반환 값 : float
// a와 b를 나누기한 결과를 반환하시오

// 함수이름 Average
// 파라메타 int &Sum, int a, int b, int c
// 반환값 없음
// 레퍼런스 변수 Sum으로 a, b, c의 평균 값을 반환

void Average(int &Sum, int a, int b, int c)
{
	Sum = (a+b+c)/3;
}

// 함수이름 ArraySum
// 파라메타 int* arr, int length
// 반환 값 : int
// 배열 "arr"와 배열의 길이 "length"를 파라메타로 받아서 모든 배열의 합을 반환

int ArraySum(int* arr, int length)
{
	int Sum = 0;
	for (int i = 0; i < length ; i++)
	{
		Sum = Sum + arr[i];
	}
	return Sum;
}

// 클래스 이름 : CShop
// 맴버 변수 : m_value(기본값:0)
// 맴버 함수 추가 : printValue
// printValue 함수 결과 : "Value=%d"로 m_value 출력
class CShop // 변수형
{
	int m_value = 0;
public:
	void printValue()
	{
		printf("Value=%d", m_value);
	}
};
// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
// 생성자 파라메타 : int PhoneCnt ( m_PhoneCnt에 값 적용 )
// 생성자 파라메타 : int PhonePrice ( m_PhonePrice에 값 적용 )
// 맴버 변수 : m_PhoneCnt
// 맴버 변수 : m_PhonePrice
// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력
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

// CPhoneShop(10, 100) 생성 후 객체에 printValue 출력

// 클래스 이름 : CFruitShop
// 생성자 파라메타 : int FruitCnt ( m_FruitCnt에 값 적용 )
// 생성자 파라메타 : int FruitPrice ( m_FruitPrice에 값 적용 )
// 부모 클래스 : CShop
// 맴버 변수 : m_FruitCnt
// 맴버 변수 : m_FruitPrice
// printValue 함수 결과 : "Value=%d"로 m_FruitCnt * m_FruitPrice출력

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

// CFruitShop(10, 100) 생성 후 객체에 printValue 출력

int main()
{
	// printf로 "Sum=%d\n"으로 Sum함수 결과 출력
	// printf로 "Minus=%d\n"으로 Minus함수 결과 출력
	// printf로 "Multi=%d\n"으로 Multi함수 결과 출력
	// printf로 "Divide=%d\n"으로 Divide함수 결과 출력

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


	// CPhoneShop(10, 100) 생성 후 객체에 printValue 출력
	CPhoneShop PS(10, 100);
	PS.printValue();

	// CFruitShop(10, 100) 생성 후 객체에 printValue 출력
	CFruitShop FS(10, 100);
	FS.printValue();
}