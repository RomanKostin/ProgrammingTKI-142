#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/**
*@brief function that finds answer to the equation. If a*x is less than 1 it solves a^x - log10(a*x) otherwise a^x + log10(a*x);
*@param a user's input
*@param x user's input
*@return answer to the equation
*/
double function(double a, double x);
/**
*@brief function for user's input
*@param input user's input
*/
void input(double *input);
int main()
{
	double a, x;
	printf_s("Input a = ");
	input(&a);
	printf_s("Input x = ");
	input(&x);
	printf_s("the answer is %lf ",function(a,x));
	return 0;
}
void input(double* input)
{
	scanf_s("%lf", input);
}
double function(double a, double x)
{
	if (a*x - 1 < DBL_EPSILON)
	{
		return pow(a, x) - log10(a * x);
	}
	else
	{
		return pow(a, x) + log10(a*x);
	}
}