#include "MyClass.h"
#include <stdio.h>

CMyClass2::CMyClass2(int valueA) :a(valueA), b(0), c(0)
{
	printf("������ ȣ���\n");
}

CMyClass2::CMyClass2(int valueA, int valueB) :a(valueA), b(valueB), c(0)
{
	printf("������ ȣ���\n");
}

CMyClass2::~CMyClass2()
{
	printf("�ı��� ȣ���\n");
}

void CMyClass2::PrintB()
{
	printf("B=%d", b);
}

void CMyClass2::SetC(int num)
{
	c = num;
}