#include<stdio.h>

#include"main.h"

int main()
{
	//int num1, num2;
	//printf("���� 2���� �Է��ϼ���(num1 num2):");
	//scanf_s("%d %d", &num1, &num2);
	//printf("�� ���� ���� %d�Դϴ�.", Sum(num1, num2));

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
			printf("�� ���� �������� %d�Դϴ�.", division(num1, num2));
		}
		break;

		case 4:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������ ������ ���� %d�Դϴ�.", remain(num1, num2));
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