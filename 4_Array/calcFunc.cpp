#include"calcFunc.h"
#include<stdio.h>

static int a = 0;

extern int b;


int Sum(int a, int b)
{
	return a + b;
}
int Minus(int a, int b)
{
	return a - b;
}
int Multiply(int a, int b)
{
	return a * b;
}

float Division(float a, float b)
{
	return a / b;
}

int Remain(int a, int b)
{
	return a % b;
}
