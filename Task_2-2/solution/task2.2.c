#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>

/**
*@brief function that finds answer to the equation. If a*x is less than 1 it solves a^x - log10(a*x) otherwise a^x + log10(a*x);
*@param a user's input
*@param x user's input
*@return answer to the equation
*/
double function(double a, double x);

/**
* @brief function used to get value from user
* @return result - result of user's input
*/
double input();

/**
* @brief entrance point into the programm
* @return 0 if programm works correctly
*/
int main()
{
	double a, x;
	printf_s("Input a = ");
	a = input();
	printf_s("Input x = ");
	x = input();
	printf_s("the answer is %lf ", function(a, x));
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

double function(double a, double x)
{
	if (a * x < -DBL_EPSILON)
	{
		errno = EIO;
		perror("wrong input");
		abort();
	}
	if (a * x - 1 < DBL_EPSILON)
	{
		return pow(a, x) - log10(a * x);
	}
	else
	{
		return pow(a, x) + log10(a * x);
	}
}
