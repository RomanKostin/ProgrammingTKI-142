#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief enum type used to choose formula
*/
enum formula { N = 1, DBL_N, TPL_N };

/**
* @brief function used to get value from user
* @return temp - result of user's input
*/
double input();

/*
* @brief entry point into the programm
* @return 0 if programm works correctly
*/
int main()
{
	double a, n;
	int choice;
	printf_s("%s", "choose formula 1) N; 2) 2N; 3) 3N ");
	choice = input();
	printf_s("input A = ");
	a = input();
	printf_s("input N = ");
	n = input();
	enum formula equation = (enum formula)(choice);
	switch (equation)
	{
	case N:
	{
		printf_s("the answer is %lf", a * n);
		return 0;
	}
	case DBL_N:
	{
		printf_s("the answer is %lf", a * n * 2);
		return 0;
	}
	case TPL_N:
	{
		printf_s("the answer is %lf", a * n * 3);
		return 0;
	}
	default:
	{
		errno = EIO;
		perror("Input error!");
		return 0;
	}
	}
}

double input()
{
	double temp;
	int res = scanf_s("%lf", &temp);
	if (res != 1)
	{
		errno = EIO;
		perror("wrong input");
		abort();
	}
	return temp;
}
