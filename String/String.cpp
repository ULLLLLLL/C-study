#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

// 네임스페이스는 내부 식별자로 여러개의 라이브러리를 사용할 때 이름 간의 충돌을 방지하기 위해서 사용
using namespace std; // std 이름의 공간을 가져오겠다. std 라이브러리 함수 앞에 std를 붙이지 않아도 된다.

int main()
{
	/*
	* String 이란?
	* - C++ STL에서 제공하는 클래스로, 문자열을 다루는 클래스
	* C에서는 char* 또는 char[]의 형태로 문자열을 다루었다면, C++에서는 문자열을 하나의 변수 type처럼 사용
	* 문자열을 다양하고 쉽게 다룰 수 있게 해준다.
	* char*, char[]과 다르게 문자열의 끝에 '\0' 문자가 들어가지 않으면 문자열의 길이를 동적으로 변경 가능하다.
	*/

	wchar_t chars[20] = L"abcdef";
	int result = wcscmp(chars, L"abcdef");
	wcscpy_s(chars, 20, L"ghijkl");

	// 변수명 : std::string
	// 변수 이름 : strA
	// 기본값 : ("abcdef")
	std::string strA("abcdef");
	printf("strA = %s\n", strA.c_str()); // 문자열 출력은 c_str()을 사용하여 출력
	size_t size = strA.size(); // 문자열 크기 구하기 (물리적인 크기, 차지하고 있는 공간)
	size_t len = strA.length(); // 문자열 길이 구하기 (문자의 개수)

	std::string A("12");
	std::string B("34");
	A += B; // A에다가 B를 붙인다.
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	A = B; // A에 B를 대입한다.
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());

	//if (A == "A") // string 비교시에 문자열 ""로 비교
	if (A == B) // 문자열 비교 연산자 가능
	{
		printf("A와 B는 같다.\n");
	}

	std::wstring wstr; // wchar_t형 string
	// auto : 대입한 값의 형태에 따라 자동으로 변수형이 설정된다.
	// literals : https://learn.microsoft.com/ko-kr/cpp/cpp/string-and-character-literals-cpp?view=msvc-170
	auto stringS = "abcdef"s; // string 문자형을 표기

	double d = 3.14;
	string strD = to_string(d); // 숫자 -> 문자로 변환
	printf("strD = %s\n", strD.c_str());

	string toParse = " 123USD";
	size_t index = 0;
	// stoi(int), stof(flort), stod(double), stol(long)
	int nResult = stoi(toParse, &index); // 문자 -> 숫자로 변환
	printf("stoi result=%d\n", nResult); // nResult : 변환된 숫자
	printf("toParse index Character = %c\n", toParse[index]); // index Parse가 불가능한 첫번째 시작 포인트를 출력

	string findStr = "123SABC456SORRY";
	int nPointL = findStr.find('S'); // 왼쪽에서부터 문자 찾기
	printf("Find Point[%d] Character = %c\n", nPointL, findStr[nPointL]); // nPoint 찾은 문자열의 위치 ( 0번째, 1번째, 2번째, 3번째... 이기 때문에 왼쪽부터 시작된 S는 3번째에 있다.)
	int nPointR = findStr.rfind('S'); // 오른쪽에서부터 문자 찾기
	printf("rFind Point[%d] Character = %c\n", nPointR, findStr[nPointR]); // nPoint 찾은 문자열의 위치

	string strleft = findStr.substr(0, nPointL); // 문자열 잘라오기. 0부터 nPointL 길이 만큼(첫번째 S 전까지).
												 // 괄호의 의미: (몇번째 문자열부터, 몇개의 문자열을 셀 것인지)
	string strcenter = findStr.substr(nPointL, nPointR - nPointL); // nPointR 전까지(두번째 S 전까지).
																   // 괄호 : (nPointL부터-3번째 문자열부터,  nPointR - nPointL(7개)를 셀 것이다->SABC456
	string strright = findStr.substr(nPointR, findStr.length() - nPointR); // nPointR(두번째 s)를 전체 문자열에서 뺀다.
	printf("strleft=%s\nstrcenter=%s\nstrright=%s\n", strleft.c_str(), strcenter.c_str(), strright.c_str());


	string testStr = " 1, 2, 3, 4, 5, 6, 7, 8, 9";

	stringstream ssTest(testStr); // string 문자열을 stringstream 변수 형태로 만든다
	string line; // 읽어온 string 담아둘 변수

	// ssTest을 왼쪽부터 ','를 기준으로 문자를 잘라서 line에 넣는다.
	// getline 결과가 false(더이상 문자열이 없으면)면 좋료.

	while (getline(ssTest, line, ','))
	{
		printf("line=%s\n", line.c_str());
	}

	// 스트링에서 특정 문자 제거
	testStr.erase(remove(testStr.begin(), testStr.end(), ','), testStr.end());
	printf("testStr=%s\n", testStr.c_str());

}