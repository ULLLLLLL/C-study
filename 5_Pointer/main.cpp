#include<stdio.h>

void BuyItem(int *Money, int price)
{
	// int *Money는 메모리 복제가 일어나지 않는다
	// 메모리에 효율적인 관리, 데이터 참조가 편리하다.
	Money -= price;
}

enum ePhoneType
{
	iPhone = 0,
	Galaxys23,
	GalaxyFold,
	GalaxyZ
};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;
	
	void printPhoneCnt()
	{
		printf("iPhone=%d, Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d",
			iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};

void BuyiPhone(ePhoneType phoneType, stPhoneShop* pPS)
{
	switch (phoneType)
	{
	case ePhoneType::iPhone:
		pPS->iPhoneCnt--;//포인트로 참조하는 구조체의 변수는 "->" 키워드로 참조한다.
		break;
	case ePhoneType::Galaxys23:
		pPS->Galaxys23--;//포인트로 참조하는 구조체의 변수는 "->" 키워드로 참조한다.
		break;
	case ePhoneType::GalaxyFold:
		pPS->GalaxyFold--;//포인트로 참조하는 구조체의 변수는 "->" 키워드로 참조한다.
		break;
	case ePhoneType::GalaxyZ:
		pPS->GalaxyZ--;//포인트로 참조하는 구조체의 변수는 "->" 키워드로 참조한다.
		break;
	default:
		break;
	}
}

//Number 받아서 화면에 출력한다.
void printNumber(const int* number)
{
	// number = nullptr; // 포인터 주소 값을 변경할 수 있다.
	//*number = 2;
	printf("print number = %d\n", *number);
}

void printNumber2(const int& number)
{
	// number = nullptr;
	// number = 4;
	printf("print number=%d\n", number);
}

void printPhoneS(const stPhoneShop* ps)
{
	printf("print IPhoneCnt=%d\n", ps->iPhoneCnt);
} // ps뒤에 ->(화살표)를 쓴다.

void printPhoneS(const stPhoneShop& ps) // 얘는 레퍼런스 참조하는 방법 복습
{
	printf("print IPhoneCnt=%d\n", ps.iPhoneCnt);
} // 레퍼런스 참조이기 때문에 ps 뒤에 화살표가 아니라 .(점)으로 쓴다.
int main()
{
	int a = 0;//int는 4Byte
	int b = 0;
	// 포인터를 사용하는 이유
	// 메모리에 효율적인 관리, 데이터 참조가 편리하다.
	// int* pA : 포인터 변수의 선언(pA에 들어가 있는 주소에 int형의 크기만큼 참조하겠다.
	// nullptr : 포인터 변수의 초기화 값(주소값이 비어있음)
	// 이전에는 NULL을 사용했는데 NULL = 0을 의미. 그래서 0이랑 의미가 동일해서 문제 발생
	// 주소값이 비어있음이라는 명확한 의미를 가진 nullptr 사용
	// 포인터의 크기(x32에는 4byte, x64에는 9byte)
	int* pA = nullptr;
	pA = &a; //a주소값을 pA에 넣는다.
	// * : 레퍼런스 참조한다.(주소가 가리키고 있는 값을 참조한다.)
	b = *pA;   // b에 pA가 가리키고 있는 주소에 값을 넣는다.
	*pA = 10;  // pA가 가리키고 있는 주소에 값을 10으로 변경한다.
	//pA = &a == *pA = a
	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1; //pNum에 num1에 주소값을 넣는다.(pNum은 num1을 가리키고 있는 상태)
	printf("pNum = %d\n", *pNum); // num1 = 0
	*pNum = 20;   //pNum이 가리키고 있는 num1에 20을 넣는다
	printf("pNum = %d\n", *pNum); // num1 = 20
	pNum = &num2; //pNum에 num2에 주소값을 넣는다.(pNum은 num2을 가리키고 있는 상태)
	printf("pNum = %d\n", *pNum); // num2 = 0
	*pNum = 30;   //pNum이 가리키고 있는 num2에 30을 넣는다
	printf("pNum = %d\n", *pNum); // num2 = 30
	printf("num1=%d num2=%d\n", num1, num2);// num1 num2 = 20 30

	//----------------------------------------------------------------
	int Money = 10000;

	BuyItem(&Money, 1000);
	printf("MyMoney=%d\n", Money);

	stPhoneShop stPS;
	stPS.iPhoneCnt = 100;
	stPS.Galaxys23 = 100;
	stPS.GalaxyFold = 100;
	stPS.GalaxyZ = 100;
	
	BuyiPhone(ePhoneType::iPhone, & stPS);
	stPS.printPhoneCnt();

	//----------------------------------------------------------------------------------------------------------------------
	//배열과 포인터
	
	int arrlnt[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pInt = nullptr; // pInt에 들어가있는 주소에 int형의 크기만큼 참조하겠다.
	pInt = arrlnt;
	printf("\npInt=%d\n", *pInt);
	pInt += 1; //다음 배열 포인터에 주소를 가리킨다.
	printf("pInt=%d\n", *pInt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pInt = (int*)arrS;//(int*)를 사용해서 int*로 강제로 형변환(캐스팅Cast)한다.
	pInt += 1; // pInt가 int*이므로 int(4Byte)만큼 다음 주소값을 참조한다.
	short* pS = (short*)pInt;//int(4Byte)만큼 이동한 주소값
	printf("pS=%d\n", *pS);

	// x32 아키텍쳐 = x86 아키텍쳐
	// int32(4Byte) = 0 ~ 4,294295(Byte)

	// 아래 배열을 낮은 숫자 순서대로 출력
	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };

	for (int i = 0; i < 10; i++) // for( ; ; )초기 설정 만족하면 반복, 후처리
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				int num = arr[i]; // num도 마음대로 설정한 거!
				arr[i] = arr[j];
				arr[j] = num;
			}
		}
	};

	for (int value : arr)//for each -> for(차례대로 불러올 배열값:배열), value는 내가 설정하는 이름으로 프린트 안에도 동일하게
	{
		printf("%d ", value);
	}

	printf("\nHappy Birthday Dear 민울!\n");

	// const 상수화
	// 실수를 줄일 수 있어서 디버깅 횟수를 줄일 수 있다.(디버깅 : 버그를 찾거나 수정하는 모든 행위)
	const int cint = 100; //상수

	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	// const int* pValue = &value; // 포인터가 가리키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	// int const* pValue = &value; // 포인터가 가리키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
		// * 별표 왼쪽으로 const가 붙어 있으면 포인터가 가리키는 내용 수정 불가!
		// * 별표 오른쪽으로 const가 붙어 있으면 포인터 값 수정 불가!
	// int* const pValue = &value; // 포인터가 가리키는 내용 수정 가능, 포인터 값 수정 불가, 참조 가능
	// const int* const pValue = &value; // 포인터가 가리키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
	// int const* const pValue = &value; // 포인터가 가리키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
		// * 별표 왼쪽, 오른쪽으로 const가 붙어 있으면 포인터가 가리키는 내용, 포인터 값 둘다 수정 불가!

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);

	printNumber(&value);
	printNumber2(value);
} 