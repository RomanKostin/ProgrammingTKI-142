#include <stdio.h>
#include <float.h>
#include <errno.h>
#include <stdbool.h>

/**
* @brief function checks if there is any positive combination. If sum of any of them is more than DBL_EPSILON it prints positive, otherwise no positive
* @param a user's input
* @param b user's input
* @param c user's input
* @return 0 if False; 1 if True
*/
bool find_positive(double a, double b, double c);

/**
* @brief function used to get value from user
* @return temp - result of user's input
*/
double input();

/**
* @brief entrance point into the programm
* @return 0 if programm works correctly
*/
int main()
{
	double a, b, c;
	printf_s("input a, b ,c ");
	a = input();
	b = input();
	c = input();
	find_positive(a, b, c);
	return 0;
}
bool find_positive(double a, double b, double c)
{
	if (a + b > DBL_EPSILON || a + c > DBL_EPSILON || b + c > DBL_EPSILON)
	{
		printf_s("positive");
		return true;
	}
	else
	{
		printf_s("no positive");
		return false;
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
