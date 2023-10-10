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

//함수 이름 : standardWeight
//맴버 변수 : float height
//리턴 값 : float
//공식 : (height - 100) * 0.9

//함수 이름 : GetBMI
//맴버 변수 : float weight, float standardWeight
//리턴 값 : float
//공식 : (weight - standardWeight)  * 100 / standardWeight

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

    printf("\n숫자 하나를 입력하세요:");
    scanf_s("%d", &a);
    printf("\n숫자 하나 더 입력하세요:");
    scanf_s("%d", &b);

    int Sum = 0;

   for(int i = a; i <= b; i++)
    {
        Sum = Sum + i;
    }
        printf("\n%d와 %d사이의 모든 수를 더하면 %d입니다.\n", a, b, Sum);
    */
    /*
    int a = 0;
    int value = 0;
    int per = 0;

    printf("\n소득세를 계산하시겠습니까? 0)No 1)Yes");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n연간 총 소득을 입력하세요(만원 단위) :");
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
        printf("당신의 소득세는 %d 퍼센트 내세요\n", per);
    }
    else
    { 
        return 0;
    }
    */
    int a = 0;
    float weight = 0;
    float height = 0;

    printf("\nBMI를 계산하시겠습니까? 0)No 1)Yes ");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n몸무게를 입력해주세요 : ");
        scanf_s("%f", &weight);
        printf("\n키를 입력해주세요 : ");
        scanf_s("%f", &height);

        float standard = standardWeight(height);
        float BMI = GetBMI(weight, standard);
        if (BMI > 20)
        {
            printf("\n너는 BMI가 비만이야");
        }
        else if (10 < BMI && BMI <= 20)
        {
            printf("\n너는 BMI가 과체중이야");
        }
        else
        {
            printf("\n너는 BMI가 정상이야");
        }
        // printf("\n너는 BMI가 %f 이야 ", GetBMI(weight, standard));
    }
    else
    {
        return 0;
    }


    /*
    bool bRun = true;

    while (bRun)
    {
        printf("BMI를 계산하시겠습니까?  0)No 1)Yes ");
        int input = 0;
        scanf_s("%d", &input);

        switch (input)
        {
        case 0:
            bRun = false;
            break;

        case 1:
            int weight = 0, height = 0, BMI = 0;
            printf("\n몸무게를 입력해주세요 : ");
            scanf_s("%f", &weight);
            printf("\n키를 입력해주세요 : ");
            scanf_s("%f", &height);
            BMI = GetBMI(weight, standardWeight(height));

            if (BMI > 20)
            {
                printf("\n너는 BMI가 비만이야");
            }
            else if (10 < BMI && BMI <= 20)
            {
                printf("\n너는 BMI가 과체중이야");
            }
            else
            {
                printf("\n너는 BMI가 정상이야");
            }
            break;

        default:
            break;
        }
    }
    */

    //float standardWeight(float height)
    //{
    //    return (height - 100) * 0.9;
    //}

    //float GetBMI(float weight, float standardWeight)
    //{
    //    return (weight - standardWeight) * 100 / standardWeight;
    //}


}