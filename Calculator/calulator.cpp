#include <stdio.h>
#include <iostream>
/*
int cSum(int a, int b) {
    return a + b;
}

int cMinus(int a, int b) {
    return a - b;
}

int cMulti(int a, int b) {
    return a * b;
}

float cDivide(float a, float b) {
    return a / b;
}

enum InputType
{
    Quit = 0,
    Sum,
    Minus,
    Multi,
    Divide
};
*/

float standardWeight(float height)
{
    return (height - 100) * 0.9;
}

float GetBMI(float weight, float standardWeight)
{
    return (weight - standardWeight) * 100/ standardWeight;
}


int main()
{
    /*
    int a = 0;
    int b = 0;

    printf("\n���� �ϳ��� �Է��ϼ���:");
    scanf_s("%d", &a);
    printf("\n���� �ϳ� �� �Է��ϼ���:");
    scanf_s("%d", &b);

    int Sum = 0;

   for(int i = a; i <= b; i++)
    {
        Sum = Sum + i;
    }
        printf("\n%d�� %d������ ��� ���� ���ϸ� %d�Դϴ�.\n", a, b, Sum);
    */
    /*
    int a = 0;
    int value = 0;
    int per = 0;

    printf("\n�ҵ漼�� ����Ͻðڽ��ϱ�? 0)No 1)Yes");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n���� �� �ҵ��� �Է��ϼ���(���� ����) :");
        scanf_s("%d", &value);

        if (value > 100000)
        {
            per = 45;
        }
        else if (50000 < value)
        {
            per = 42;
        }
        else if (30000 < value)
        {
            per = 40;
        }
        else if (15000 < value)
        {
            per = 38;
        }
        else if (8800 < value)
        {
            per = 35;
        }
        else if (4600 < value)
        {
            per = 24;
        }
        else if (1200 < value)
        {
            per = 15;
        }
        else
        {
            per = 6;
        }
        printf("����� �ҵ漼�� %d �ۼ�Ʈ ������\n", per);
    }
    else
    { 
        return 0;
    }
    */

    int a = 0;
    float weight = 0;
    float height = 0;

    printf("\nBMI�� ����Ͻðڽ��ϱ�? 0)No 1)Yes ");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n�����Ը� �Է����ּ��� : ");
        scanf_s("%f", &weight);
        printf("\nŰ�� �Է����ּ��� : ");
        scanf_s("%f", &height);

        float standard = standardWeight(height);
        float BMI = GetBMI(weight, standard);
        if (BMI > 20)
        {
            printf("\n�ʴ� BMI�� ���̾�");
        }
        else if (10 < BMI)
        {
            printf("\n�ʴ� BMI�� ��ü���̾�");
        }
        else
        {
            printf("\n�ʴ� BMI�� �����̾�");
        }
        // printf("\n�ʴ� BMI�� %f �̾� ", GetBMI(weight, standard));
    }
    else
    {
        return 0;
    }

    //float standardWeight(float height)
    //{
    //    return (height - 100) * 0.9;
    //}

    //float GetBMI(float weight, float standardWeight)
    //{
    //    return (weight - standardWeight) * 100 / standardWeight;
    //}


}