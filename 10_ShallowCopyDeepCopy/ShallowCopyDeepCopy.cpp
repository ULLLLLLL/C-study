#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName(const wchar_t* name):szName(nullptr), len(0) // ������ / const wchar_t* name = �Ķ��Ÿ. �̰� ����� ������ "�ο�"���� ����� ����
	{
		// szName = name; �̷��� ���ڳ��� ���� ������ ����. ���ڴ� ����� ���������� �ʱ� ������ �� ���� ����.(���̰� �� ���ϴϱ�)
		len = wcslen(name) + 1; // +1�� 1-5���� ���ڰ� ������ ���� �� 12345\0 �̷� ������ ���� \0���� �Լ��� �����ٴ� ��ȣ�� �ش�.
								// ���� +1�� \0�� ��������� ��ü ���̸� �� �� �ִ�.
		szName = new wchar_t[len]; // ��ü ������ len�� �����༭ �Լ��� ������ �����Ѵ�.
		wcscpy_s(szName, len, name);
	}

	// ���� ������ �� �����Ҵ� ������(C++)
	// �Ķ��Ÿ�� (const CName& Other)�� ���� �ڻ��� Ŭ���� Ÿ���� ���۷����� ������ ���� ������
	CName(const CName& Other) :szName(nullptr), len(0) 
	{
		if (szName != nullptr)
		{
			delete[] szName;
		}
		
		// Other.szName�� �����ؼ� szName�� �ִ´� (���� ����)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);\
	}

	~CName() // �ı���.
	{
		delete[] szName; // delete[]�� �Ἥ �ı��ȴٴ� ���� �ݵ�� �˷��� ��.
	}

	wchar_t* GetName()
	{
		return szName;
	}

	const CName& operator=(const CName& Other)
	{
		//szName = Other.szName; // Other.szName�� ����Ű�� �ִ� ���� szName�� ����Ű�� �ϰڴ�.(���� ����)
		// len = Other.len;
		
		if (szName != nullptr)
		{
			delete[] szName;
		}

		//Other.szName�� �����ؼ� szName�� �ִ´�.(���� ����)

		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
		return *this;
	}

	wchar_t* szName;
	size_t len;
};

int main() // ���⼭ ������ �۵�
{
	_wsetlocale(LC_ALL, L"korean");

	CName name1(L"�ο�");
	CName name2(L"����");

	name1 = name2; // ���Կ����� ó��

	CName name3 = name1;

	wprintf(L"name1=%s", name1.GetName());	//%s�� ���ڿ�
} // ���� �� �� ���� �� ���뵵 ���� - �ı��� �۵�