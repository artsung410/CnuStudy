#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void Foo(int *p)
{
	p += 1;
	*p = 20;
}

int main(void)
{
	int a = 10;
	int* p = &a;

	p -= 1;
	*p = 5;
	Foo(p);
}