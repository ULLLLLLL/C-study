#include <stdio.h> //c
#include <iostream> //c++���̺귯��

using namespace std;
//"abcdef\0"
void minul(wchar_t* _pString)
{
	int num = wcslen(_pString);//�� ���̸� ����
	for (int i = 0; i < num / 2; i++)//������ 2�� ���� �� ���ݸ� �յڷ� �ٲ��ָ� �Ǳ� ����
	{
		wchar_t c = *(_pString + i); // ù��°�� ���ϴ� ���
		wchar_t r = *(_pString + num-1-i);// �������� \n�� �����Ƿ� �ϳ� ������ ������ ���ĺ�!
		*(_pString + num - 1 -i) = c;//ù��° ������ �ڸ��� c�� ������ ���ĺ��� f�� �ִ´�.
		*(_pString + i) = r;//������ ������ �ڸ��� f�� ù��° ���ĺ��� a�� �ִ´�.
	}
	wprintf(L"%s\n", _pString);
}

void Anum(wchar_t* _pString)
{
	int num = wcslen(_pString);
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		wchar_t c = *(_pString + i); // *(_pString) : �޾ƿ� ���ڿ��� ù ��° ĭ
		if (c == 97) count++; //97 �ڸ��� 'a'�� �־ �ȴ�. //�ƽ�Ű�ڵ忡�� a�� 97�̴�. 
		// //https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
	}
	printf("%d",count);
}

int main()
{
	//2�� ��� ����ϱ� (0~100)
	//0 2 4 6 8 ~ 96 98 100
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", i);
		}
	}

	//n�� ���� �ϳ��� �Է� �ޱ�
	//n�� ��� ����ϱ�(0~100)

	int num = 0;
	printf("����� ���ϰ� ���� ���� �Է��ϼ���");
	scanf_s("%d", &num);
	for (int i = 0; i <= 100; i++)
	{
		if (i % num == 0)
		{
			printf("%d\n", i);
		}
	}
		return 0;
		

	//(0~100) 2�� ����� ���� ��� .
	int count = 0;
	for (int i = 0; i <= 100; i++)
	{	
		if (i % 2 == 0)	
		{	
			count++;
		}	
	}		
	printf("\n%d\n", count);

	//abcdef�� ������ ����ϱ� fedcba
	wchar_t szWChar[20] = L"abcdef";
	minul(szWChar);

	// wchar_t ������ ���� �Է� �ޱ�
	// "szWChar Input"�̸��� ����
	// "wchar_t" ��������
	// [20]�� ũ��� �����ϰ�
	// L"" ���� �ʱⰪ���� �ִ´�.
	wchar_t szWCharInput[20] = L"";
	// wscanf_s�� �Է��� �޴� ����� ����ϰڴ�.
	// L"%ls" �������·� �Է��� �ްڴ�
	// "szWChar Input"������ �Է��� ���� �־��ְڴ�
	// "(unsigned)_countof(szWCharInput)"�� ���� ���� ������ ũ��
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	// wprintf�� ����� �ϴ� ���. ����ϰڴ�.
	// L"szWCharInput=%s" ���� ���·� ����ϰڴ�.
	// %s��ġ�� szWCharInput ���� ����ϰڴ�.
	wprintf(L"szWCharInput=%s", szWCharInput);
	
	//�Է� ���� ���ڿ����� 'a'���� ���� ���
	Anum(szWCharInput);

}