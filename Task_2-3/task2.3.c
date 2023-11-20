#include <stdio.h>
#include <float.h>
/**
*@brief function checks if there is any positive combination. If sum of any of them is more than DBL_EPSILON it prints positive, otherwise no positive
*@param a user's input
*@param b user's input
*@param c user's input
*/
void find_positive(double a, double b, double c);
/**
*@brief function to get user's input
*@param input user's input
*/
void input(double *input);
int main()
{
	double a, b, c;
	printf_s("input a, b ,c ");
	input(&a);
	input(&b);
	input(&c);
	find_positive(a, b, c);
	return 0;
}
void find_positive(double a, double b, double c)
{
	if (a + b > DBL_EPSILON || a + c > DBL_EPSILON || b + c > DBL_EPSILON)
	{
		printf_s("positive");
	}
	else
	{
		printf_s("no positive");
	}
}
void input(double* input)
{
	scanf_s("%lf", input);
}