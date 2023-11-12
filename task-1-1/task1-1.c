#include <stdio.h>
#include <math.h>
/**
*@brief function gives solution for the equation "a"
*@param a some constant
*@param b some constant
*@param c some constant
*@return solution for the equation "a"
*/
double solve_1(double a, double b, double c);
/**
*@brief function gives solution for the equation "b"
*@param a some constant
*@param b some constant
*@param c some constant
*@return solution for the equation "b"
*/
double solve_2(double a, double b, double c);
//@brief entry point into the programm
int main()
{
	double a = 0.5, b = 0.05, c = 0.7;
	printf_s("%lf\n%lf\n", solve_1(a, b, c), solve_2(a, b, c));
	return 0;
}
double solve_1(double a, double b, double c)
{
	double result = (pow(a, 2) * (a + 1)) / (b - pow(sin(a + c), 2));
	return result;
}
double solve_2(double a, double b, double c)
{
	double result = sqrt((a * b) / c) + pow((cos(pow((a + b), 2))), 2);
	return result;
}