#include <stdio.h>
#include <iostream>
#include <assert.h>

unsigned int GetstringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i); // 문자별 주소값에 문자 저장

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
	if (size < destLen + sourceLen + 1)// \0 공간 1개가 더 필요
	{
		assert(nullptr);
	}

	wchar_t c = *(_Dest + destLen); // 순차적인 주소값에 문자를 저장

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
		wchar_t c = *(_Dest + i); // 문자별 주소값에 문자 저장

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

	int nLoop = (LeftLen < RightLen) ? LeftLen : RightLen; // 가장 짧은 문자의 길이만큼만 비교한다.

	for (int i = 0; i < nLoop; i++)
	{
		if(_pLeft[i] == _pRight[i])//문자 같으면 크기 비교 결과를 실행하지 않고 다시 for문을 실행
			continue;

		return (_pLeft[i] > _pRight[i]) ? 1 : -1; //크기 비교 결과를 반환
	}

	if (LeftLen != RightLen)
	{
		//left가 길면 1, right가 길면 -1
		return (LeftLen > RightLen) ? 1 : -1;//크기 비교 결과를 반환
	}
	return 0; // 모든 문자가 같고 길이도 같다.
} // 앞에 Left가 길면 1, Right가 길면 -1

int main()
{
	// 문자 처리
	// 아스키 코드 링크 : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C // ctrl 누르고 클릭하면 열린다.
	// multi=byte
	// 127개 아스키 코드 문자 표기, 문자에 따라 가면형으로 크기가 변경됨
	// 국가 간의 호환이 되지 않는 방식으로 다른 시스템으로 보내면 글자를 알아볼 수 없게 깨짐
	// 일본어 텍스트 파일을 한글 윈도우에서 열었을 때 뷁어로 깨지는 현상이 예시
	// 뷀어 : https://namu.wiki/w/%EB%AC%B8%EC%9E%90%20%EA%B9%A8%EC%A7%90/%EB%B7%81%EC%96%B4%20%ED%85%8C%EC%9D%B4%EB%B8%94
	// 철저히 자국어 표기만을 위한 인코딩. 외국어 교재 같이 다른 문자체계가 필요한 경우 불편함
	char c1 = 'a'; //1Byte(0~255) , 한글자일 때는 ''(작은 따옴표) 사용
	printf("c1=%c\n", c1); // 한글자 char 출력시 %c 사용

	setlocale(LC_ALL, "korean"); // multi-byte 언어 설정

	char arrC1[10] = "abc한글"; //영어는 1Byte, 한글은 2Byte 사용, 문자열일 때는 ""(큰따옴표) 사용
	printf("arrC1=%s\n", arrC1); // 문자열 char 출력시 %s 사용

	// 와이드 문자(wide character)
	// multi-byte 문제를 해결하기 위해 나온 유니코드 방식
	// 세계의 거의 모든 문자를 표현할 수 있기 때문에 최근에 많이 사용됨
	// 가장 자주 사용하는 방식은 UTF-8이 있다.
	// 2Byte(0~65535)에서 앞에 검증용 1bit를 제외하면 32,767개 표현 가능 / 2 = 32,767개(한글 문자 하나당 3만개))
	// wchar_t형에 문자를 넣을 때 앞에 L을 붙인다.
	wchar_t wc1 = L'a';
	wprintf(L"wc1=%c\n", wc1); //wchar_t형을 출력할 때는 wprintf를 사용, 출력 문자열 앞에 L을 붙인다

	_wsetlocale(LC_ALL, L"korean"); // 와이드 문자 언어 설정

	wchar_t arrWC1[10] = L"abc한글"; // wchar_t배열에 문자열을 넣을 때 앞에 L을 붙인다.
	wprintf(L"arrWC1=%s\n", arrWC1); // wchar_t형을 출력할 때는 wprintf를 사용, 출력 문자열 앞에 L을 붙인다

	wchar_t szWChar[10] = L"abcdefghi"; // 마지막에 문자에 마지막이라는 표기로 '\0'문자가 들어간다. (10개를 맞추려면 j 하나를 빼줘야 함)
	wprintf(L"aszWChar=%s\n", szWChar);
	
	wchar_t szWCharLen[20] = L"abcdefg"; // 문자열 길이 구하기(iostream 라이브러리 함수)
	int size = wcslen(szWCharLen); // 문자열 길이 구하기
	printf("szWCharLen size=%d\n", size);


	//wcscat_s(szWCharLen, 20, L"hij"); // 문자열 붙이기(iostream 라이브러리 함수)
	stringCar(szWCharLen, 20, L"hij"); // 문자열 붙이기(iostream 라이브러리 함수)
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	wcscpy_s(szWCharLen, L"abcdef"); // 양쪽 문자열의 뒤에 문자열 복사해서 넣는다
	
	int nResult = wcscmp(L"abcdef", L"abidef"); //같으면 0, 앞에 문자순번이 빠르면 1, 뒤에 문자순번이 빠르면 -1
	nResult = stringCmp(L"abcdef", L"abidef");  //같으면 0, 앞에 문자순번이 빠르면 1, 뒤에 문자순번이 빠르면 -1
	printf("nResult=%d\n", nResult); // 앞에 Left가 길면 1, Right가 길면 -1

/*
	wchar_t _Dest[20] = L"abcde"; // 문자열 길이 구하기(iostream 라이브러리 함수)
	int size = wcslen(_Dest); // 문자열 길이 구하기
	printf("_Dest size=%d\n", size);

	wchar_t _pSource[20] = L"fghi"; // 문자열 길이 구하기(iostream 라이브러리 함수)
	size = wcslen(_pSource); // 문자열 길이 구하기
	printf("_pSource size=%d\n", size);

	//stringCar(_Dest, 20, L"fghi"); // 문자열 붙이기(iostream 라이브러리 함수)
	//wprintf(L"_Dest= %s%s\n", _Dest );
*/
} 