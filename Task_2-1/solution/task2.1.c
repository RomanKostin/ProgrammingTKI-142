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
	printf_s("%s", "choose formula 1) N; 2) 2N; 3) 3N ");
	int choice = input();
	printf_s("input A = ");
	double a = input();
	printf_s("input N = ");
	double n = input();
	enum formula equation = (enum formula)(choice);
	switch (equation)
	{
	case N:
	{
		printf_s("the answer is %lf", a * n);
		break;
	}
	case DBL_N:
	{
		printf_s("the answer is %lf", a * n * 2);
		break;
	}
	case TPL_N:
	{
		printf_s("the answer is %lf", a * n * 3);
		break;
	}
	default:
	{
		errno = EIO;
		perror("Input error!");
		return 1;
		break;
	}
	}
	return 0;
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
