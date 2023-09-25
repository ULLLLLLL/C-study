#include"money.h"
#include<stdio.h>


// int yoominul = 0; 전역변수
static int s_money = 0; // 정적변수
extern int g_money; // 정적전역변수 -> 다른 곳에 쓸 때는 int g_mone로 쓰면 된다.

int addMoney(int money)
{
	int t_money = 0; //지역변수
	t_money += money;
	g_money += money;

	printf("t_money=%d\n", t_money);
	printf("g_money=%d\n", g_money);
	return 0;
}

int useMoney(int money)
{
	return 0;
}