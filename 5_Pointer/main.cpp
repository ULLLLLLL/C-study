#include<stdio.h>

void BuyItem(int *Money, int price)
{
	// int *Money�� �޸� ������ �Ͼ�� �ʴ´�
	// �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
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
		pPS->iPhoneCnt--;//����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
		break;
	case ePhoneType::Galaxys23:
		pPS->Galaxys23--;//����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
		break;
	case ePhoneType::GalaxyFold:
		pPS->GalaxyFold--;//����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
		break;
	case ePhoneType::GalaxyZ:
		pPS->GalaxyZ--;//����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
		break;
	default:
		break;
	}
}

int main()
{
	int a = 0;//int�� 4Byte
	int b = 0;
	// �����͸� ����ϴ� ����
	// �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	// int* pA : ������ ������ ����(pA�� �� �ִ� �ּҿ� int���� ũ�⸸ŭ �����ϰڴ�.
	// nullptr : ������ ������ �ʱ�ȭ ��(�ּҰ��� �������)
	// �������� NULL�� ����ߴµ� NULL = 0�� �ǹ�. �׷��� 0�̶� �ǹ̰� �����ؼ� ���� �߻�
	// �ּҰ��� ��������̶�� ��Ȯ�� �ǹ̸� ���� nullptr ���
	// �������� ũ��(x32���� 4byte, x64���� 9byte)
	int* pA = nullptr;
	pA = &a; //a�ּҰ��� pA�� �ִ´�.
	// * : ���۷��� �����Ѵ�.(�ּҰ� ����Ű�� �ִ� ���� �����Ѵ�.)
	b = *pA;   // b�� pA�� ����Ű�� �ִ� �ּҿ� ���� �ִ´�.
	*pA = 10;  // pA�� ����Ű�� �ִ� �ּҿ� ���� 10���� �����Ѵ�.
	//pA = &a == *pA = a
	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1; //pNum�� num1�� �ּҰ��� �ִ´�.(pNum�� num1�� ����Ű�� �ִ� ����)
	printf("pNum = %d\n", *pNum); // num1 = 0
	*pNum = 20;   //pNum�� ����Ű�� �ִ� num1�� 20�� �ִ´�
	printf("pNum = %d\n", *pNum); // num1 = 20
	pNum = &num2; //pNum�� num2�� �ּҰ��� �ִ´�.(pNum�� num2�� ����Ű�� �ִ� ����)
	printf("pNum = %d\n", *pNum); // num2 = 0
	*pNum = 30;   //pNum�� ����Ű�� �ִ� num2�� 30�� �ִ´�
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
	//�迭�� ������
	
	int arrlnt[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pInt = nullptr; // pInt�� ���ִ� �ּҿ� int���� ũ�⸸ŭ �����ϰڴ�.
	pInt = arrlnt;
	printf("\npInt=%d\n", *pInt);
	pInt += 1; //���� �迭 �����Ϳ� �ּҸ� ����Ų��.
	printf("pInt=%d\n", *pInt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pInt = (int*)arrS;//(int*)�� ����ؼ� int*�� ������ ����ȯ(ĳ����Cast)�Ѵ�.
	pInt += 1; // pInt�� int*�̹Ƿ� int(4Byte)��ŭ ���� �ּҰ��� �����Ѵ�.
	short* pS = (short*)pInt;//int(4Byte)��ŭ �̵��� �ּҰ�
	printf("pS=%d\n", *pS);

	// x32 ��Ű���� = x86 ��Ű����
	// int32(4Byte) = 0 ~ 4,294295(Byte)

	// �Ʒ� �迭�� ���� ���� ������� ���
	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };

	for (int i = 0; i < 10; i++) // for( ; ; )�ʱ� ���� �����ϸ� �ݺ�, ��ó��
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				int num = arr[i]; // num�� ������� ������ ��!
				arr[i] = arr[j];
				arr[j] = num;
			}
		}
	};

	for (int value : arr)//for each -> for(���ʴ�� �ҷ��� �迭��:�迭), value�� ���� �����ϴ� �̸����� ����Ʈ �ȿ��� �����ϰ�
	{
		printf("%d ", value);
	}

	printf("\nHappy Birthday Dear Minul!\n");

} 