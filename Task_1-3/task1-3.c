#include <stdio.h>
#include <float.h>
#include <errno.h>

/**
* @brief function used to get value from user
* @return result - result of user's input
*/
double input();

/**
* @brief function checks if inputs are right
* @param Length - length of the wire
* @param Cross_sectional_area - cross sectional area of the wire
* @param Resistivity - resistivity of the metal which is used in the wire
*/
void check_input(double Length, double Cross_sectional_area, double Resistivity);

/**
*@brief function for finding resistivity of the wire (length * resistivity of the metal) divided by cross sectional area, which is turned in meters
*@param Length - length of the wire
*@param Cross_sectional_area - cross sectional area of the wire
*@param Resistivity - resistivity of the metal which is used in the wire
*@return resistivity of the wire
*/
double find_resistance(double Length, double Cross_sectional_area, double Resistivity);

/**
* @brief entry point into the program
* @return 0 if program works correctly
*/
int main()
{
	printf_s("input length (meters), cross sectional area (milimeters^2) and resistivity of any metal (aluminium is 0.028) ");
	double Length = input(),
	Cross_sectional_area = input(),
	Resistivity = input();
	check_input(Length, Cross_sectional_area, Resistivity);
	printf_s("Resistance of the wire %lf", find_resistance(Length, Cross_sectional_area, Resistivity));
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

void check_input(double Length, double Cross_sectional_area, double Resistivity)
{
	if (Length <= DBL_EPSILON || Cross_sectional_area <= DBL_EPSILON || Resistivity <= DBL_EPSILON)
	{
		printf_s("Wrong inputs!");
		abort();
	}
}

double find_resistance(double Length, double Cross_sectional_area, double Resistivity)
{
	double const convert = 0.000001;
	return (Length * Resistivity) / (Cross_sectional_area * convert);
}
