#pragma once
class CMyClass2
{
	int b; 

public:
	CMyClass2(int valueA = 0);

	CMyClass2(int valueA, int valueB);

	~CMyClass2();

	void PrintB();

	void SetC(int num);

public:
	int a;
protected:
private:
	int c;
};