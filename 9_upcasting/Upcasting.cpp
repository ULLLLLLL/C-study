#include <stdio.h>

// ���
// ���� Ŭ������ ����� �߰��ϰų� �������Ͽ� ���ο� Ŭ������ �����ϴ� ���
// ���� - �⺻ �ֻ��� Ŭ������� ����
// ���� : ���� + �����δٴ� ����� �߰�
// ������ ������ ����� ��� ����
// ������ :  ���� + �����̸� �Ѵٴ� ����� �߰�
// �������� ������ ����� ��� ����
// ��� : ������ + ���� �ɷ� ����� �߰�
// ����� �������� ����� ��� ����

class CBase
{
public:
	CBase(int x = 1, int y = 2):m_X(x), m_Y(y)
	{
		printf("�θ� Ŭ����(CBase) ����\n");
	}
	~CBase()
	{
		printf("�θ� Ŭ����(CBase) �ı�\n");
	}

	// ���� �Լ� (virtual tunction)
	// �ڽ� Ŭ�������� ������ �� ������ ����ϴ� ����Լ�
	// �Լ� �տ� virtual Ű���带 ���δ�.
	/*
	virtual	void printValue()
	{
		printf("m_X=%d\n", m_X);
	}
	*/

public:
	int m_X;
	int m_Y;
};

// ��� ��� : ": public CBase"�� ���� Ŭ���� �ڿ� ����� �θ� Ŭ������ ����
class CChild : public CBase
{
public:
	// ":"�� �ڿ� �θ�Ŭ����(CBase)�� �־ �θ�Ŭ������ ������ ȣ��
	// �θ� Ŭ������ �����ڰ� ���� ȣ�� �� �ڽ� �����ڰ� ȣ���.
	CChild(int x = 1, int y = 2, int z = 3):m_Z(z), CBase(x, y)
	{
		printf("�ڽ� Ŭ����(CChild) ����\n");
	}

	// �ڽ� �ı��� ���� ȣ�� �� �θ� �ı��� ȣ���
	~CChild()
	{
		printf("�ڽ� Ŭ����(CChild) �ı�\n");
	}

	/*
	virtual	void printValue() override
	{
		printf("m_X=%d, m_Y=%d\n", m_X, m_Z); // �Ʒ��� ������ �����Ӱ� �ٲ� �� �ִ�. (��� ����)

		CBase::printValue(); // �θ𿡼��� ó���� ȣ�� - �θ��� Ŭ�������� ������ �������� �Լ� ȣ��
	}
	*/

public:
	int m_Z;
};

// Upcasting(��ĳ����)
// �ڽ� -> �θ�� ȣ�� �� ���� ���ٸ� ������ ���� �ڵ����� ĳ����(�о�����) �Ǵ� ���
void printObject(CBase** pBase, int n) // ��ĳ���� �Ǹ� CBase�� ũ���� �׳� �߶������. 
{
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%d, ypos=%d\n", pBase[i]->m_X, pBase[i]->m_Y);
	}
}

int main()
{
	/*
	CBase base(10);
	base.m_X = 100;
	base.printValue();

	CChild child(10, 20);
	child.m_X = 200; // ��� ���� �θ��� ����� �״�� ��� ����
	child.printValue();
	*/
	/*
	//pArrChild - �迭
	CChild* pArrChild = new CChild[10];
	printObject(pArrChild, 10); // �ڽ� �ʿ��� �θ� �θ� �ǵ� (�� void printObject(CBase...) �κ�) �̷� ���� ��ĳ�����̶�� ��. (������ ���� ����)
	delete[] pArrChild;
	*/

	CBase** pArrBase = new CBase * [10]; // ���������ͷ� �ް� �� void printObject printf���� ->�� �������ָ� ��� ���ڰ� �����ϰ� ���´�.
	for (int i = 0; i < 10; i++)
	{
		pArrBase[i] = new CChild;
	}
	printObject(pArrBase, 10);
	for(int i =0; i<10; i++)
	{
		delete pArrBase[i];
	}
	delete[]pArrBase;
}