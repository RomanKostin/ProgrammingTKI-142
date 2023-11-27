#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
/**
* @brief function for domain
* @param left - left border
* @param right - right border
*/
void get_domain(double *left, double *right);
/**
* @brief function for delta
* @param delta - delta x
*/
void get_delta_x(double *delta);
/**
* @brief function for solution. if left border == right border it gives position of "x" and value "y"(if solution exists). when domain consists of more than one number function goes for the cycle, it gives solution for "y" (if it exist) in point "x", after that "delta x is added to "x" and function gives new solution "y". That rule is cycled until value of "x" is more than right border
* @param left - left border of the domain
* @param right - right border of the domain
* @param delta - delta x
*/
void solution(double left, double right, double delta);
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
int main()
{
	double left, right, delta;
	get_domain(&left, &right);
	check_domain(left, right);
	printf_s("your domain is [%lf, %lf]\n",left,right);
	get_delta_x(&delta);
	check_delta(delta);
	solution(left,right,delta);
	return 0;
}
void get_domain(double *left, double *right)
{
	printf_s("input non-strict domain of the function ");
	scanf_s("%lf%lf",left,right);
}
void get_delta_x(double* delta)
{
	printf_s("input a value between x: ");
	scanf_s("%lf",delta);
}
void solution(double left, double right, double delta)
{
	double i = left;
	if (left == right)
	{
		if (left - 1 > DBL_EPSILON)
		{
			printf_s("x = %lf, y = undefined\n", i);
		}
		else
		{
			printf_s("x = %lf, y = %lf\n", left, sqrt(1 - i) - cos(sqrt(1 - i)));
		}
	}
	for (i - delta; i - right < -DBL_EPSILON; i += delta)
	{
		if (i - 1 > DBL_EPSILON)
		{
			printf_s("x = %lf, y = undefined\n", i);
		}
		else
		{
			printf_s("x = %lf, y = %lf\n",i,sqrt(1-i)-cos(sqrt(1-i)));
		}
	}
}
void check_domain(double left,double right)
{
	if (left - right > DBL_EPSILON)
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