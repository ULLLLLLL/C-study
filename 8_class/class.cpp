#include<stdio.h>
#include"MyClass.h"
struct stMyStruct // ������
{
	int a;

	stMyStruct() : a(0)
	{

	}
};

// Class(����, �ڷ���)
// Class�� ����� ���� Type�̶�� �Ѵ�.
// C�� struct�� Ȯ��� ����
// C++�� Ŭ������ ������ �׼���(����) ������(private, protected, public)�� ����
// �׼����� ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ���� �Ǵ� ������ ������ �����.
// �׼��� �����ڸ� ����Ͽ� ������ �� �Լ��� ����� �� 'ĸ��ȭ'��� �Ѵ�.
// class�� �ѱ۷� �����ϸ� '��Ʋ'�̶�� ��, ��� ������ ��ü�� �ƴ�
// ��ü�� �����ϱ� ���� ����� ��Ÿ����.

// ��ü(Object)
// Class�� ����ؼ� ������ ���� ��ü��� �Ѵ�.
// Class�� ������ �������� �����ǰ� �޸𸮿��� ������ ������

// ��ü ���� ���α׷���
// ��ü ���� �׷α׷����� ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� �������� ������ ����
// ��, '��ü'���� �������� ������ ����� �ϴ� �з�����
// ������ ��ü�� �޽����� �ְ�ް�, �����͸� ���������� ó���� �� �ִ�.
class CMyClass // ������
{
	// ���� ������
	// public : ��𼭵� ���� ����
	// protected : ��Ӱ����� �� ������ ����, �̿ܿ��� ���� �Ұ�
	// private : �ܺο��� ���� �Ұ�

	//���� ���� �����ڰ� ������ �⺻������ private
	int b; // Ŭ���� �ȿ� ����� ������ ��� ������� �Ѵ�.(�����ڵ��� ���������� ���������� ���� ǥ���ϱ� ���� m_�� �ٿ���.)

public:
	// ������
	// Ŭ������ ������ �� ȣ��Ǵ� �Լ�
	// ������ ���� �ʾƵ� �⺻ �����ڰ� ����
	// �����ڵ� private�� �ܺο��� ȣ�� �Ұ�, �ݵ�� public���� ��������� �Ѵ�.
	// �����ڵ� �Ķ��Ÿ�� ������ Ÿ�Կ� ���� Overload(������ �Լ��� Ÿ�Ժ��� ����) �� �� �ִ�.
	// (int valueA = 0) �̷� ������� �Ķ��Ÿ�� �־��� �� �ִ�.
	// :a(valueA), b(0), c(0) <- ������ �� �̷� ������� ��������� �ʱⰪ�� ������ �� �ִ�.
	// �Ķ��Ÿ ������ ���°� �Է� ��Ŀ� ���� ������ �Ұ����ϸ� ������ �߻��Ѵ�.
	CMyClass(int valueA = 0):a(valueA), b(0), c(0)
	{
		printf("������A ȣ���\n");
	}

	CMyClass(int valueA, int valueB) :a(valueA), b(valueB), c(0) // value = ���� ��������� �ϴµ� �� ���ָ�
																// A�� B�� ������ ���� ���� �Ѵٴ� ���̱⿡ ������ �ȵȴ�.
	{
		printf("������B ȣ���\n");
	}

	CMyClass(int valueA, int valueB, int valueC) :a(valueA), b(valueB), c(valueC) // value = ���� ��������� �ϴµ� �� ���ָ�
		// A�� B�� ������ ���� ���� �Ѵٴ� ���̱⿡ ������ �ȵȴ�.
	{
		printf("������C ȣ���\n");
	}
	// �ı���
	// Ŭ������ �ı��� �� ȣ��Ǵ� �Լ�
	// ���� ���� �ʾƵ� �⺻ �ı��ڰ� ����
	// �ı��ڵ� public�� �ƴϸ� ȣ���� �Ұ���
	~CMyClass()
	{
		printf("�ı��� ȣ���\n");
	}

	void PrintB()
	{
		printf("B=%d", b);
	}

	void PrintAllValue()
	{
		printf("A=%d, B=%d, C=%d\n", a, b, c);
	}

	void SetC(int num)
	{
		// �Ϲ������� this Ű����� ������
		// this : Ŭ���� �ȿ��� �Լ��� ȣ���� ��� ��ü�� �ǹ��� (�ܺο��� �������� ����)
		this->c = num;
	}

	// ������ �����ε�(Operator Overloading)
	// ���Կ����� (�⺻������ ������)
	// const CMyClass& : �������� ��ȯ�� ������
	// operator = : �����ε� �� ������
	// (const CMyClass& other) : �����ʿ� �Էµ� ����


	//cMy3 = cMy + cMy2
	//cMy3 = CMyClass(a + other.a, b + other.b, c + other.c);
	// cMy�� a, b, c ��ġ�̰�, cMy2�� other.a, other.b, other.c�� ��ġ�� ����.
	// const : ������ �ʴ� ���
	// & : ����(�ּҰ�)
	const CMyClass& operator=(const CMyClass& other)
	{
		a = other.a;
		b = other.b;
		c = other.c;

		return *this;
	}

	const CMyClass& operator+(const CMyClass& other)
	{
		return CMyClass(a + other.a, b + other.b, c + other.c);
	}

public:
	int a;
protected:
private:
	int c;
};

int main()
{
	{
		// ���۷��� ����
		// �޸� ������ ���� �ʰ� ������ �����Ͽ� �޸𸮸� ȿ�������� ����ϱ� ���� ������.
		int num = 100;
		stMyStruct stTest;

		// ������ ������ ������ ������ �ּҰ��� �����Ѵ�.
		// ������ ������ �ּҰ��� �����Ͱ� ����Ű�� �ִ� �ּҰ��� �ٸ���.
		int* pNum = &num; // pNum ������ �������� num�� �ּҰ��� ����. ��, pNum�� num������ ����Ű�� �ִ�.
		stMyStruct* pTest = &stTest;
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));
		pTest->a = 0;

		//���۷��� ������ ���� ����� �ּҰ��� �����ϴ�.
		int& refNum = num;
		stMyStruct& refTest = stTest;
		refTest.a = 0;
		printf("&refNum == &num ? %d\n", (int(&refNum) == int(&num)));
	}
	int a;

	stMyStruct stMy;
	stMy.a = 0;

	CMyClass cMy(100); // <- ���⼭ ������A ȣ���
	CMyClass cMy2(100, 200); // <- ���⼭ ������B ȣ���
	printf("cMy.a=%d\n", cMy.a);
	cMy.a = 0;
	cMy.SetC(0); // Ư�� ������ �����ϱ� ���� �Լ��� �����ؼ� �����ϴ°� �⺻ ��Ģ�̴�.
	// cMy.c = 100; // ���� ������ private�� �Ǿ��ִٸ� �����ڰ� ���� �������� ����� �ǵ��� �ִٴ� ��

	CMyClass aa;

	CMyClass cMy3;
	cMy.a = 1000;
	cMy.PrintAllValue();
	cMy2.PrintAllValue();
	cMy3 = cMy + cMy2;
	cMy3.PrintAllValue();

} // <- ���⼭ �ı��� ȣ���