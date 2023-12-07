#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief function is used to get the value from the user
* @return temp - result of user's input
*/
double input();

/**
* @brief function for solution of the equation.
* @param left - left border of the domain
* @param right - right border of the domain
* @return sqrt(1 - i) - cos(sqrt(1 - i)) if function exists in this point, otherwise undefined
*/
double solution(double left, double right);

/**
* @brief function checks delta x. If delta x is equal or less than 0 -> abort();
* @param delta - delta x
*/
void check_delta(double delta);

/**
* @brief fuction checks if domain exists. If value of left border is more than value of the right -> abort();
* @param left - left border of the domain
* @param right - rigth border of the domain
*/
void check_domain(double left, double right);

/**
* @brief entrance point into the programm
* @return 0 if programm works correctly
*/
int main()
{
	double left, right, delta;
	printf_s("input your domain: ");
	left = input();
	right = input();
	check_domain(left, right);
	printf_s("your domain is [%lf, %lf]\n", left, right);
	delta = input();
	check_delta(delta);
	for (left - delta; left - right < DBL_EPSILON; left += delta)
	{
		if (left - 1 > DBL_EPSILON)
		{
			printf_s("x = %lf ; y = undefined\n",left);
		}
		else
		{
			printf_s("x = %lf ; y = %lf\n", left, solution(left, right));
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

double solution(double left, double right)
{
		{
			return sqrt(1 - left) - cos(sqrt(1 - left));
		}
}

void check_domain(double left, double right)
{
	if (left - right > -DBL_EPSILON)
	{
		printf_s("Wrong domain!");
		abort();
	}
}

void check_delta(double delta)
{
	if (delta < DBL_EPSILON)
	{
		printf_s("wrong delta x!");
		abort();
	}
}