#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief function used to get value from user
* @return temp - result of user's input
*/
int input();

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
double sum(int cycle_max, double temp);

/**
* @brief entry point into the programm
* @return 0 if programm works correctly
*/
int main()
{
    double temp = 0.5; // 0.5 --- is the value of the first element
    int cycle_max;
    cycle_max = input();
    check(cycle_max);
    printf_s("%lf", sum(cycle_max, temp));
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

void check(int cycle_max)
{
    if (cycle_max < 1)
    {
        printf_s("error");
        abort();
    }
}

double sum(int cycle_max, double temp)
{
    double temp_sum = 0;
    for (int i = 1; i < cycle_max; i += 1)
    {
        double k = i;
        temp = ((k + 1) / (k * (k + 2))) * temp;
        temp_sum += temp;
    }
    temp_sum += 0.5; // 0.5 --- is the value of the first element
    return temp_sum;
}