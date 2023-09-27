#include <stdio.h>
#include <iostream>
#include <assert.h>

unsigned int GetstringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i); // ���ں� �ּҰ��� ���� ����

		//if (c == 0)
		if (c == '\0')

		{
			break;
		}

		++i;
	}

	return i;
}

//_Dest : "abcde"
// _pSource : "fghi"
void stringCar(wchar_t* _Dest, unsigned int size, const wchar_t* _pSource)
{
	int destLen = GetstringLength(_Dest);
	int sourceLen = GetstringLength(_pSource);
	if (size < destLen + sourceLen + 1)// \0 ���� 1���� �� �ʿ�
	{
		assert(nullptr);
	}

	wchar_t c = *(_Dest + destLen); // �������� �ּҰ��� ���ڸ� ����

	for (int i = 0; i < sourceLen + 1; i++)
	{
		*(_Dest + destLen + i) = *(_pSource + i);
		//_Dest[destLen + i] = _pSource[i];
	}
	//*(_Dest + destLen + 0) = *(_pSource + 0); //f
	//*(_Dest + destLen + 1) = *(_pSource + 1); //g
	//*(_Dest + destLen + 2) = *(_pSource + 2); //h
	//*(_Dest + destLen + 3) = *(_pSource + 3); //i


	/*
	int i = 0;
	int j = 0;
	while (1)
	{
		wchar_t c = *(_Dest + i); // ���ں� �ּҰ��� ���� ����

		//if (c == 0)
		if (c == '\0')
		{
			break;
		}
		++i;
	}

	while (1)
	{
		wchar_t q = *(_pSource + j);
		//if (c == 0)
		if (q == '\0')
		{
			break;
		}
		++j;
	}
	*/
}

int stringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	int LeftLen = GetstringLength(_pLeft);
	int RightLen = GetstringLength(_pRight);

	int nLoop = (LeftLen < RightLen) ? LeftLen : RightLen; // ���� ª�� ������ ���̸�ŭ�� ���Ѵ�.

	for (int i = 0; i < nLoop; i++)
	{
		if(_pLeft[i] == _pRight[i])//���� ������ ũ�� �� ����� �������� �ʰ� �ٽ� for���� ����
			continue;

		return (_pLeft[i] > _pRight[i]) ? 1 : -1; //ũ�� �� ����� ��ȯ
	}

	if (LeftLen != RightLen)
	{
		//left�� ��� 1, right�� ��� -1
		return (LeftLen > RightLen) ? 1 : -1;//ũ�� �� ����� ��ȯ
	}
	return 0; // ��� ���ڰ� ���� ���̵� ����.
} // �տ� Left�� ��� 1, Right�� ��� -1

int main()
{
	// ���� ó��
	// �ƽ�Ű �ڵ� ��ũ : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C // ctrl ������ Ŭ���ϸ� ������.
	// multi=byte
	// 127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
	// ���� ���� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
	// �Ϻ��� �ؽ�Ʈ ������ �ѱ� �����쿡�� ������ �� ���� ������ ������ ����
	// ��� : https://namu.wiki/w/%EB%AC%B8%EC%9E%90%20%EA%B9%A8%EC%A7%90/%EB%B7%81%EC%96%B4%20%ED%85%8C%EC%9D%B4%EB%B8%94
	// ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�. �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ������
	char c1 = 'a'; //1Byte(0~255) , �ѱ����� ���� ''(���� ����ǥ) ���
	printf("c1=%c\n", c1); // �ѱ��� char ��½� %c ���

	setlocale(LC_ALL, "korean"); // multi-byte ��� ����

	char arrC1[10] = "abc�ѱ�"; //����� 1Byte, �ѱ��� 2Byte ���, ���ڿ��� ���� ""(ū����ǥ) ���
	printf("arrC1=%s\n", arrC1); // ���ڿ� char ��½� %s ���

	// ���̵� ����(wide character)
	// multi-byte ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	// ������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	// ���� ���� ����ϴ� ����� UTF-8�� �ִ�.
	// 2Byte(0~65535)���� �տ� ������ 1bit�� �����ϸ� 32,767�� ǥ�� ���� / 2 = 32,767��(�ѱ� ���� �ϳ��� 3����))
	// wchar_t���� ���ڸ� ���� �� �տ� L�� ���δ�.
	wchar_t wc1 = L'a';
	wprintf(L"wc1=%c\n", wc1); //wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�

	_wsetlocale(LC_ALL, L"korean"); // ���̵� ���� ��� ����

	wchar_t arrWC1[10] = L"abc�ѱ�"; // wchar_t�迭�� ���ڿ��� ���� �� �տ� L�� ���δ�.
	wprintf(L"arrWC1=%s\n", arrWC1); // wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�

	wchar_t szWChar[10] = L"abcdefghi"; // �������� ���ڿ� �������̶�� ǥ��� '\0'���ڰ� ����. (10���� ���߷��� j �ϳ��� ����� ��)
	wprintf(L"aszWChar=%s\n", szWChar);
	
	wchar_t szWCharLen[20] = L"abcdefg"; // ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	int size = wcslen(szWCharLen); // ���ڿ� ���� ���ϱ�
	printf("szWCharLen size=%d\n", size);


	//wcscat_s(szWCharLen, 20, L"hij"); // ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	stringCar(szWCharLen, 20, L"hij"); // ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	wcscpy_s(szWCharLen, L"abcdef"); // ���� ���ڿ��� �ڿ� ���ڿ� �����ؼ� �ִ´�
	
	int nResult = wcscmp(L"abcdef", L"abidef"); //������ 0, �տ� ���ڼ����� ������ 1, �ڿ� ���ڼ����� ������ -1
	nResult = stringCmp(L"abcdef", L"abidef");  //������ 0, �տ� ���ڼ����� ������ 1, �ڿ� ���ڼ����� ������ -1
	printf("nResult=%d\n", nResult); // �տ� Left�� ��� 1, Right�� ��� -1

/*
	wchar_t _Dest[20] = L"abcde"; // ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	int size = wcslen(_Dest); // ���ڿ� ���� ���ϱ�
	printf("_Dest size=%d\n", size);

	wchar_t _pSource[20] = L"fghi"; // ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	size = wcslen(_pSource); // ���ڿ� ���� ���ϱ�
	printf("_pSource size=%d\n", size);

	//stringCar(_Dest, 20, L"fghi"); // ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	//wprintf(L"_Dest= %s%s\n", _Dest );
*/
} 