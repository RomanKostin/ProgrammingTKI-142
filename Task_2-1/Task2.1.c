#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
*@brief enum type used to choose formula
*/
enum formula {N=1,DBL_N,TPL_N};
/**
*@brief used to get user's input
*@param input - user's input
*/
void input(double *input);
/**
*@brief function that lets user to choose formula
*@param choice - user's choice
*@return choice
*/
int choose_formula(int *choice);
int main()
{
	int choice;
	double A, D;
	choose_formula(&choice);
	printf_s("input A = ");
	input(&A);
	printf_s("input N = ");
	input(&D);
	enum formula equation = (enum formula)(choice);
	switch (equation)
	{
		case N:
		{
			printf_s("the answer is %lf",A*D);
			return 0;
		}
		case DBL_N:
		{
			printf_s("the answer is %lf",A*D*2);
			return 0;
		}
		case TPL_N:
		{
			printf_s("the answer is %lf",A*D*3);
			return 0;
		}
		default:
		{
			errno = EIO;
			perror("Input error!");
			return 1;
		}
	}
}
void input(double *input)
{
	scanf_s("%lf", input);
}
int choose_formula(int *choice)
{
	printf_s("%s","choose formula 1) N; 2) 2N; 3) 3N ");
	scanf_s("%d", choice);
	return choice;
}