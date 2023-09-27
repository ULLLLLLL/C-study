#include <stdio.h> //c
#include <iostream> //c++라이브러리

using namespace std;
//"abcdef\0"
void minul(wchar_t* _pString)
{
	int num = wcslen(_pString);//총 길이를 구함
	for (int i = 0; i < num / 2; i++)//나누기 2는 돌릴 때 절반만 앞뒤로 바꿔주면 되기 때문
	{
		wchar_t c = *(_pString + i); // 첫번째를 구하는 방법
		wchar_t r = *(_pString + num-1-i);// 마지막에 \n이 있으므로 하나 빼야지 마지막 알파벳!
		*(_pString + num - 1 -i) = c;//첫번째 문자의 자리인 c에 마지막 알파벳인 f를 넣는다.
		*(_pString + i) = r;//마지막 문자의 자리인 f에 첫번째 알파벳인 a를 넣는다.
	}
	wprintf(L"%s\n", _pString);
}

void Anum(wchar_t* _pString)
{
	int num = wcslen(_pString);
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		wchar_t c = *(_pString + i); // *(_pString) : 받아온 문자열의 첫 번째 칸
		if (c == 97) count++; //97 자리에 'a'를 넣어도 된다. //아스키코드에서 a가 97이다. 
		// //https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
	}
	printf("%d",count);
}

int main()
{
	//2의 배수 출력하기 (0~100)
	//0 2 4 6 8 ~ 96 98 100
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", i);
		}
	}

	//n은 숫자 하나를 입력 받기
	//n의 배수 출력하기(0~100)

	int num = 0;
	printf("배수를 구하고 싶은 값을 입력하세요");
	scanf_s("%d", &num);
	for (int i = 0; i <= 100; i++)
	{
		if (i % num == 0)
		{
			printf("%d\n", i);
		}
	}
		return 0;
		

	//(0~100) 2의 배수의 개수 출력 .
	int count = 0;
	for (int i = 0; i <= 100; i++)
	{	
		if (i % 2 == 0)	
		{	
			count++;
		}	
	}		
	printf("\n%d\n", count);

	//abcdef를 역으로 출력하기 fedcba
	wchar_t szWChar[20] = L"abcdef";
	minul(szWChar);

	// wchar_t 형으로 문자 입력 받기
	// "szWChar Input"이름을 가진
	// "wchar_t" 변수형을
	// [20]의 크기로 생성하고
	// L"" 값을 초기값으로 넣는다.
	wchar_t szWCharInput[20] = L"";
	// wscanf_s는 입력을 받는 기능을 사용하겠다.
	// L"%ls" 변수형태로 입력을 받겠다
	// "szWChar Input"변수에 입력한 값을 넣어주겠다
	// "(unsigned)_countof(szWCharInput)"는 값을 넣을 변수에 크기
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	// wprintf는 출력을 하는 기능. 사용하겠다.
	// L"szWCharInput=%s" 문자 형태로 출력하겠다.
	// %s위치에 szWCharInput 값을 출력하겠다.
	wprintf(L"szWCharInput=%s", szWCharInput);
	
	//입력 받은 문자열에서 'a'문자 개수 출력
	Anum(szWCharInput);

}