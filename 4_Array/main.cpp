#include <stdio.h>

// c++ �� ������
// c++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ���� �� �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����

// �������� 4�ܰ�� ����
// 1. ��ó��(Preprocessing) �ܰ� : #include�� #define�� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(0bject file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking) �ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ����  ������ �����ϴ� �ܰ�
// ��ŷ �ܰ迡�� ���������� 2���� ������ ����.

// �޸� ����
// 1. Code ���� : ������ �ڵ尡 ����Ǿ� �ִ� ����
// 2. Data ���� : ��������, static �������� ����, ���μ����� ����� ������ �޸𸮿� ����
// 3. stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
// 4. Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int g_money = 0;//���� ����

static int s_money = 0;

#include "money.h"
#include "calcFunc.h"
/*
struct fruitShop
{
	//����ü ���� ������ ������ ����ü ������� ������ �� �������.
	//c++���� ������ �����ϸ� �� ������ ������ �����ϰ� �ְ� ��� ����Ǿ� �ִ�.-�޸� ����
	int appleA;
	int mangoA;
	int strawberryA;

	//����ü ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�.
	fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
	{

	}

	//����ü�� �Լ� ����
	void SetFruitValue(int apple, int mange, int strawberry)
	{
		int appleB = apple;//SetFruitValue �Լ��� ����Ǹ� �������.-�����Լ�
		appleA = apple;
		mangoA = mange;
		strawberryA = strawberry;
	}

	void printShopValue()
	{
		printf("���ϰ��� ���� ���:%d, ����:%d, ����:%d\n", appleA, mangoA, strawberryA);
	}
};
*/

struct PhoneShop
{
	int iPhoneA;
	int zFlipA;
	int GalaxyS23A;
	int GalaxyFoldA;

	PhoneShop() : iPhoneA(100), zFlipA(90), GalaxyS23A(80), GalaxyFoldA(15)
	{

	}
	void SetPhoneValue(int iPhone, int zFlip, int GalaxyS23, int GalaxyFold)
	{
		iPhoneA = iPhone;
		zFlipA = zFlip;
		GalaxyS23A = GalaxyS23;
		GalaxyFoldA = GalaxyFold;
	}

	void printShopValue()
	{
		printf("�ڵ������� ���� iPhone:%d, zFlip:%d, GalaxyS23:%d, GalaxyFold:%d\n", iPhoneA, zFlipA, GalaxyS23A, GalaxyFoldA);
	}
};


// 1 + 1 =2
int Add(int a, int b)
{
	printf("int�� Add�� ���Ǿ����ϴ�\n");
	return a + b;
}
// 1.2 +1.3 = 1.5
float Add(float a, float b)
{
	printf("float�� Add�� ���Ǿ����ϴ�\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double�� Add�� ���Ǿ����ϴ�\n");
	return a + b;
}


int main()
{
	int t_money = 0; //��������
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);

	printf("main t_money=%d\n", t_money);
	printf("main g_money=%d\n", g_money);
	printf("1=1 Sum=%d\n", Sum(1, 1));

	Add(1, 1);
	Add(1.0f, 1.0f);//f�� ���̰� �Ǽ��� ���� float��
	Add(1.0, 1.0);//f�� ������ �ʰ� �Ǽ��� ���� double��

	//�迭
	//�迭�� ����
	//int arrlnt[10] = { 0 };//�迭 ���� �� ���� 0���� �ʱ�ȭ
	//int arrlnt[10] = { 0, };//�迭 ���� �� ���� 0���� �ʱ�ȭ
	int arrlnt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //�迭 ���� �� ������ �迭�� �ʱⰪ �ִ� ���
	arrlnt[0] = 10;// �迭 0��°�� �� �ֱ�
	arrlnt[4] = 40;// �迭 4��°�� �� �ֱ�
	arrlnt[9] = 90;// 0������ �迭�� ���۵ǹǷ� ������ �迭�� 9��

	//�迭�� ���
	//for��
	for (int i = 0; i < 10; i++)
	{
		printf("%d��° �迭 ���� %d�Դϴ�.\n", i, arrlnt[i]);// 2�� �̻��� �Ķ��Ÿ ���
	}

	//�迭�� ����ϴ� �ٸ� ���
	// ������ �迭 10������ ������ �������� 10��°������ ����Ѵ�.
	// for each�� for(int value:arrlnt)-> for(int value:�迭)
	int number = 0;
	for (int value : arrlnt)
	{
		printf("for each %d��° �迭 ���� %d�Դϴ�.\n", number, value);
		number++; 
	}

	// Struct�� ���
	// fruitShop : ������
	// shop : ������ �̸�
	/*
	fruitShop shop[3];

	// Struct �Լ� ����
	shop[0].appleA = (1000, 2000, 3000); // shop�� appleA������ �� �ֱ�
	shop[1].mangoA = (1100, 2100, 3100); // shop�� mangoA������ �� �ֱ�
	shop[2].strawberryA = (900, 1900, 2900); // shop�� strawberryA������ �� �ֱ�

	for (fruitShop stValue : shop)
	{
		stValue.printShopValue();
	}
	*/

	// PhoneShop[0], PhoneShop[1], PhoneShop[2]�� ������ ���
	PhoneShop shop[3];

	shop[0].SetPhoneValue(100, 90, 80, 150);
	shop[1].SetPhoneValue(110, 100, 90, 160);
	shop[2].SetPhoneValue(90, 80, 70, 140);
	for (PhoneShop Valuee : shop)
	{
		Valuee.printShopValue();
	}


	bool bRun = true;
	while (bRun)
	{
		int nlnput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1:����, 2:���ϱ�, 3: ������, 4:������):");
		scanf_s("%d", &nlnput);
		switch (nlnput)
		{
		case 0:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ���� %d�Դϴ�.", Sum(num1, num2));
		}
		break;

		case 1:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������ %d�Դϴ�.", Minus(num1, num2));
		}
		break;

		case 2:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������ %d�Դϴ�.", Multiply(num1, num2));
		}
		break;

		case 3:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� �������� %.2f�Դϴ�.", Division(num1, num2));
		}
		break;

		case 4:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������ ������ ���� %d�Դϴ�.", Remain(num1, num2));
		}
		break;

		default:
			break;
		}


		printf("���⸦ �����Ͻðڽ��ϱ�?(0:No, 1: Yes):");
		scanf_s("%d", &nlnput);

		switch (nlnput)
		{
		case 0:
			continue;
			break;
		case 1:
			bRun = false;
			break;
		}

	}

	return 0;

	printf("\nHappy Birthday �ο�!\n\n");

}