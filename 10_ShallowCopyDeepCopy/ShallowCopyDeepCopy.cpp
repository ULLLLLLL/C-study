#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName(const wchar_t* name):szName(nullptr), len(0) // 생성자 / const wchar_t* name = 파라메타. 이걸 써줬기 때문에 "민울"문자 출력이 가능
	{
		// szName = name; 이렇게 문자끼리 쓰면 오류가 난다. 문자는 사이즈가 정해져있지 않기 때문에 쓸 수가 없다.(길이가 막 변하니까)
		len = wcslen(name) + 1; // +1은 1-5까지 숫자가 있으면 끝날 때 12345\0 이런 식으로 쓰고 \0으로 함수가 끝났다는 신호를 준다.
								// 따라서 +1로 \0을 포함해줘야 전체 길이를 알 수 있다.
		szName = new wchar_t[len]; // 전체 길이인 len을 더해줘서 함수가 공간을 생성한다.
		wcscpy_s(szName, len, name);
	}

	// 복사 생성자 및 복사할당 연산자(C++)
	// 파라메타로 (const CName& Other)와 같이 자산의 클래스 타입을 레퍼런스로 받으면 복사 생성자
	CName(const CName& Other) :szName(nullptr), len(0) 
	{
		if (szName != nullptr)
		{
			delete[] szName;
		}
		
		// Other.szName을 복사해서 szName에 넣는다 (깊은 복사)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);\
	}

	~CName() // 파괴자.
	{
		delete[] szName; // delete[]를 써서 파괴된다는 것을 반드시 알려야 함.
	}

	wchar_t* GetName()
	{
		return szName;
	}

	const CName& operator=(const CName& Other)
	{
		//szName = Other.szName; // Other.szName이 가리키고 있는 곳을 szName도 가리키게 하겠다.(얕은 복사)
		// len = Other.len;
		
		if (szName != nullptr)
		{
			delete[] szName;
		}

		//Other.szName을 복사해서 szName에 넣는다.(깊은 복사)

		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
		return *this;
	}

	wchar_t* szName;
	size_t len;
};

int main() // 여기서 생성자 작동
{
	_wsetlocale(LC_ALL, L"korean");

	CName name1(L"민울");
	CName name2(L"기혁");

	name1 = name2; // 대입연산자 처리

	CName name3 = name1;

	wprintf(L"name1=%s", name1.GetName());	//%s는 문자열
} // 종료 시 위 메인 안 내용도 제거 - 파괴자 작동