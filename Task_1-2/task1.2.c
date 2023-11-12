#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>
/**
*@brief function used to get value from user
*@param *input user's input
*/
void input(double *input);
/**
*@brief function checks if triangle exist
*@param side_a length of the first side
*@param side_b length of the second side
*@param angle_ab angle between two sides of a triangle
*/
void check_for_existance(double side_a, double side_b, double angle_ab);
/**
*@brief formula for finding the third side of a triangle
*@param side_a length of the first side
*@param side_b length of the second side
*@param angle_ab angle between two sides of a triangle (in degrees)
*@return length of the third side
*/
double find_side(double side_a, double side_b, double angle_ab);
/**
*@brief formula for finding the area of a triangle
*@param side_a length of the first side
*@param side_b length of the second side
*@param angle_ab angle between two sides of a triangle (in degrees)
*@return area of the triangle
*/
double find_area(double side_a, double side_b, double angle_ab);
/**
*@brief formula for finding the circumscribed circle radius of a triangle
*@param side_a length of the first side
*@param side_b length of the second side
*@param angle_ab angle between two sides of a triangle (in degrees)
*@return circumscribed circle radius
*/
double find_radius(double side_a, double side_b, double angle_ab);
int main()
{
	double side_a, side_b, angle_ab;
	printf_s("%s", "input two sides of a triangle and an angle between them: ");
	input(&side_a);
	input(&side_b);
	input(&angle_ab);
	check_for_existance(side_a, side_b, angle_ab);
	printf_s("%lf\n%lf\n%lf\n", find_side(side_a,side_b,angle_ab), find_area(side_a, side_b, angle_ab), find_radius(side_a, side_b, angle_ab));
	return 0;
}
double find_side(double side_a, double side_b, double angle_ab)
{
	return sqrt(pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b * cos((angle_ab * M_PI) / 180)));
}
double find_area(double side_a, double side_b, double angle_ab)
{
	return 0.5 * side_a * side_b * sin((angle_ab * M_PI) / 180);
}
double find_radius(double side_a, double side_b, double angle_ab)
{
	return (side_a * side_b * (sqrt(pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b * cos((angle_ab * M_PI) / 180))))) / (4 * 0.5 * side_a * side_b * sin((angle_ab * M_PI) / 180));
}
void input(double *input)
{
	scanf_s("%lf", input);
}
void check_for_existance(double side_a, double side_b, double angle_ab)
{
	if (side_a <= DBL_EPSILON || side_b <= DBL_EPSILON || cos(((angle_ab)*M_PI) / 180) == DBL_EPSILON)
	{
		printf_s("Triangle doesn't exist");
		abort();
	}
}