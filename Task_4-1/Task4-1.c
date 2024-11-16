#include <stdio.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/**
*@brief function for int value
*@return entered_number - value of entered number
*/
int getInt();

/**
*@brief function for size_t value
*@return entered_number - value of entered number
*/
size_t getSize_t();

/**
*@brief function gives memory for array
*@param size - size of array
*@return array - pointer to an empty array
*/
int* getMemory(size_t size);

/**
*@brief function for filling array with user's input
*@param array - pointer to array
*@param size - size of array
*/
void keyboadArray(int* const array, const size_t size);

/**
*@brief function for random array fill
*@param array - pointer to array
*@param size - size of array
*/
void randomArray(int* const array, const size_t size);

/**
*@brief prints values of array
*@param array - pointer to array
*@param size - size of array
*/
void output(int* const array, size_t const size);

/**
*@brief function clears memory used for array
*@param array - pointer to array
*/
void freeArray(int* array);

/**
*@brief function for the sum of all negative even numbers
*@param array - pointer to array
*@param size - size of array
*@return result - sum of all negative even numbers
*/
int firstTask(int* const array, size_t const size);

/**
*@brief function prints all values of the indexes that can be devided by 6
*@param array - pointer to array
*@param size - size of array
*/
void secondTask(int* const array, size_t const size);

/**
*@brief function that swaps values
*@param a - first value
*@param b - second value
*/
void swap(int* const a, int* const b);

/**
*@brief function sorts values of array from smallest number to biggest
*@param array - pointer to array
*@param size - size of array
*/
void arraySort(int* const array, size_t const size);

/**
*@brief function swaps all values of array to 0 between smallest and biggest numbers
*@param array - pointer to array
*@param size - size of array
*/
void thirdTask(int* const array, size_t const size);

/**
*@brief used for choice of a way to fill an array
*@param KEYBOARD - keyboard fill
*@param RANDOM - random fill
*/
enum Choices
{
    KEYBOARD = 1,
    RANDOM = 2,
};

/**
*@brief entry point to the programm
*@return 0 if code works correctly, otherwise 1
*/
int main()
{
    printf_s("Input size of array: ");
    size_t size = getSize_t();
    printf_s("1 - keyboard fill; 2 - random fill ");
    int choice = getInt();
    int* array = getMemory(size);
    switch ((enum Choices)choice)
    {
    case RANDOM:
        randomArray(array, size);
        break;
    case KEYBOARD:
        printf_s("Enter array elements:\n");
        keyboadArray(array, size);
        break;
    default:
        printf("Make a valid choice!\n");
        return 1;
    }
    arraySort(array,size);
    output(array, size);
    printf_s("\nnegative sum of even numbers: %d\n",firstTask(array,size));
    printf_s("indexes, that can be devided by 6: \n");
    secondTask(array,size);
    printf_s("\n new array: \n");
    thirdTask(array, size);
    output(array, size);
    freeArray(array);
    return 0;
}

int getInt()
{
    int entered_number;
    if (scanf_s("%d", &entered_number) != 1)
    {
        errno = EIO;
        perror("Input Error");
        abort();
    }
    return entered_number;
}

size_t getSize_t()
{
    int entered_number = getInt();
    if (entered_number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)entered_number;
}

int* getMemory(size_t size)
{
    int* array = (int*)malloc(size * sizeof(int));
    if (NULL == array)
    {
        abort();
    }
    return array;
}

void keyboadArray(int* const array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = getInt();
    }
}

void randomArray(int* const array, const size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % 2001 - 1000;
    }
}

void output(int* const array, size_t const size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

void freeArray(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
    array = NULL;
}

int firstTask(int* const array, size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0 && array[i] < 0)
        {
            result += array[i];
        }
    }
    return result;
}

void secondTask(int* const array, size_t size)
{
    for (size_t i = 0;i<size;i++)
    {
        if (array[i] % 6 == 0)
        {
            printf_s("%zu ",i);
        }
    }
}

void swap(int* const a,int* const b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arraySort(int* const array, size_t const size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j],&array[j+1]);
            }
        }
    }
}

void thirdTask(int* const array, size_t const size)
{
    for (size_t i = 1; i < size - 1; i++)
    {
        array[i] = 0;
    }
}