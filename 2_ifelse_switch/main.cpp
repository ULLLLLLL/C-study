#include <iostream>
#include <stdio.h>
//
int main()
{
    //    {
            //int a = 0;
            //std::cin >> a;
            //std::cout << a << "를 입력하셨습니다.";
            // %d : 부호 있는 10진수 정수
            // %I64d : 부호 있는 10진수 정수(8Byte)
            // %u : 부호 없는 10진수 정수
            // %I64u : 부호 없는 10진수 정수(8Byte)
            // %f : 부호 있는 실수(12.3456789) ;
            // %e, %E : 부호 있는 실수(1.23456789e+005)
            // %i : 부호 있는 10진수 정수(10진수/8진수/16진수 입력 가능)
            // %x : 부호 없는 16진수 정수(123456789abcdef)
            // %X : 부호 없는 16진수 정수(123456789ABCDEF)
            // %o : 부호 없는 8진수
            // %p : 포인터 값을 16진수로 표기
            // %c : 단일 문자 출력

            /*int a = 0, b = 0;
            scanf_s("%d %d", &a, &b);
            printf("a더하기 b는? %d", a + b);
        }
    */
    //bool bReulst = true;

    //if (bReulst)
    //{
    //    printf("참이다.");
    //}
    //else
    //{
    //    printf("거짓이다.");
    //}

    /*int score = 0;
    printf("Score를 입력해주세요 : ");
    scanf_s("%d", &score);

        if (score >= 90)
        {
            printf("A학점");
        }
        else if (score >= 80)
        {
            printf("B학점");
        }
        else if (score >= 70)
        {
            printf("C학점");
        }
        else if (score >= 60)
        {
            printf("D학점");
        }
        else if (score >= 50)
        {
            printf("E학점");
        }
        else
        {
            printf("F학점");
        }*/

        /*
        int backNumber = 0;
            scanf_s("%d", &backNumber);

            switch (backNumber)
            {
                case 10:
                    //break;
                case 11:
                {
                    // 11일 때는 실행
                    printf("포수");
                }
                break;

                case 8:
                case 9:
                {
                    // 8, 9일 때는 실행
                    printf("투수");
                }
                break;

                default:
                {
                    // 위에 case가 모두 아니면 실행
                    printf("후보");
                }
                 break;
             }


        return 0;
        */

    /*
    int light = 0;
    // scanf_s로 light 값을 입력
    // light가 true(1)이면 "파랑" 출력
    // light가 false(0)이면 "빨강" 출력
    scanf_s("%d", &light);
    switch (light)
    {
        case 1 :
       {
            printf("파랑");
       }
        break;
        case 0 :
        {
            printf("빨강");
        }
        break;
    }
    */
/*  
    위 문제의 다른 해결 방법
    if(light==true) //괄호 안이 부울
    {
    print("파랑"):
    }
    else
    {
    print("빨강"):
    }
*/


    /*
    int nlnput = 0;
    //nlnput 값이 100보다 크면 "100보다 크다" 출력(printf)
    //nlnput 값이 100보다 작으면 "100보다 작다" 출력(printf)
    scanf_s("%d", &nlnput);
    {
        if (nlnput > 100)
        {
            printf("100보다 크다");
        }
        else if (nlnput == 100)
        {
            printf("100이다");
        }
        else
        {
            printf("100보다 작다");
        }
    }
    */
    
/*
    int myscore = 0, Otherscore = 0;
    // scanf_s로 ,myscore, otherscore 값을 입력
    // myscore가 otherscore 크면 "3점"
    // myscore가 otherscore 같으면 "1점"
    // myscore가 otherscore 작으면 "0점"
    scanf_s("%d %d", &myscore, &Otherscore);
    {
        if (myscore > Otherscore)
        {
            printf("3점");
        }
        else if (myscore == Otherscore)
        {
            printf("1점");
        }
        else
        {
            printf("0점");
        }
    }
*/

    // nCode가 1이나 3이면 "남자" 출력
    // nCode가 2이나 4이면 "여자" 출력
/*
    int ncode = 0;
    scanf_s("%d", &ncode);
    switch (ncode)
        {
        case 1 :
        case 3 :
        {
            printf("남자");
        }
        break;
        case 2 :
        case 4 :
        {
            printf("여자");
        }
        break;
        default :
        {
            printf("잘못 입력");
        }
        break;
    }
  */

    int nCode2 = 0;
    // scanf_s로 nCode2 값을 입력
    // nCode2가 1이나 2이면 "2000년 미만 출생" 출력
    // nCode2가 3이나 4이면 "2000년 이후 출생" 출력
    scanf_s("%d", &nCode2);
    switch (nCode2)
        {
        case 1:
        case 2:
        {
            printf("2000년 미만 출생");
        }
        break;
        case 3:
        case 4:
        {
            printf("2000년 이후 출생");
        }
        break;
        default :
        {
            printf("잘못 입력");
        }
        break;
        }
}