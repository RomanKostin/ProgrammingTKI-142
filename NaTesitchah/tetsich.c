#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
/**
* @brief function finds ammount of cycles required for the second part of the task (compare element of sum to an epsilon and then print sum up to this value)
* @param epsilon - value that user chose as an epsilon
* @return epsilonMaxCycle - max value of cycles required for second part of the task
*/
double epsilonCycle(double epsilon);

/**
* @brief function used to get value from user
* @return temp - result of user's input
*/
int input();

/**
* @brief function used to get value as an epsilon from the user
* @return epsilon - result of user's input
*/
double inputEpsilon();

/**
* @brief function checks amount of the cycles. If there is no cycles - abort()
* @param cycle_max - amount of cycles that user chooses
*/
void check(int cycle_max);

/*
* @brief function that summarizes elements of progression. ((k + 1) / (k * (k + 2))) is the difference between "element" and "element + 1"
* @param cycle_max - ammount of cycles
* @temp - value of the first element of progression
*/
double sum(int cycle_max);

/**
* @brief entry point into the programm
* @return 0 if programm works correctly
*/
int main()
{
    printf_s("input ammount of cycles: ");
    int cycle_max = input();
    printf_s("\ninput value for epsilon: ");
    double epsilon = inputEpsilon();
    check(cycle_max);
    printf_s("sum of the first task: %lf\nsum with epsilon: %lf", sum(cycle_max), epsilonCycle(epsilon));
    return 0;
}

int input()
{
    int temp;
    int res = scanf_s("%d", &temp);
    if (res != 1)
    {
        errno = EIO;
        perror("wrong input");
        abort();
    }
    return temp;
}

double inputEpsilon()
{
    double epsilon;
    int res = scanf_s("%lf", &epsilon);
    if (res != 1 || epsilon - 0.5 > -DBL_EPSILON || epsilon < DBL_EPSILON) // 0.5 - is a value of abs(first element of the sum)
    {
        errno = EIO;
        perror("wrong input");
        abort();
    }
    return epsilon;
}

void check(int cycle_max)
{
    if (cycle_max < 1)
    {
        printf_s("error");
        abort();
    }
}

double sum(int cycle_max)
{
    double temp_sum = -0.5, // -0.5 - is a value of abs(first element of the sum)
        temp = -0.5; // -0.5 - is a value of abs(first element of the sum)
    for (int i = 1; i < cycle_max; i += 1)
    {
        double k = i;
        temp *= -(k + 1) / (k * (k + 2));
        temp_sum += temp;
    }
    return temp_sum;
}

double epsilonCycle(double epsilon)
{
    double k = 1,
        sum = 0,
        epsilonValue = -0.5; // 0.5 - is a value of abs(first element of the sum)
    while (fabs(epsilonValue) - epsilon > -DBL_EPSILON)
    {
        sum += epsilonValue;
        epsilonValue *= -(k + 1) / (k * (k + 2));
        k++;
    }
    return sum;
}