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
}