#include <stdio.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/**
*@brief function find first min index of the array
*@param array - pointer to the array
*@param size - size of the array
*@return j - min index
*/
size_t findMinIndex(int* const array, size_t const size);

/**
*@brief function find first max index of the array
*@param array - pointer to the array
*@param size - size of the array
*@return j - max index
*/
size_t findMaxIndex(int* const array, size_t const size);

/**
*@brief funtion checks if left border is less than right(if it false --> abort();)
*@param left - left border of domain
*@param right - right border of domain
*/
void checkDomain(int const left, int const right);

/**
*@brief funtion checks if some value belongs to the domain that user chose.
*@param value - some value
*@param left - left border of domain
*@param right - right border of domain
*/
void checkBelongingDomain(int value, int const left, int const right);

/**
*@brief function for random array fill
*@param array - pointer to array
*@param size - size of array
*@return arrayCopy - copy of an original array
*/
int* copy(int* const array, size_t const size);

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
int* getMemory(size_t const size);

/**
*@brief function for filling array with user's input
*@param array - pointer to array
*@param size - size of array
*@param left - left border of domain
*@param right - right border of domain
*/
void keyboadArray(int* const array, const size_t size, int const left, int const right);

/**
*@brief function for random array fill
*@param array - pointer to array
*@param size - size of array
*@param left - left border of domain
*@param right - right border of domain
*/
void randomArray(int* const array, const size_t size, int const left, int const right);

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
*@brief function swaps all values of array to 0 between smallest and biggest numbers
*@param array - pointer to array
*@param size - size of array
*@param minIndex - index of the first min value of an array
*@param maxIndex - index of the first max value of an array
*/
void thirdTask(int* const array, size_t const size, size_t minIndex, size_t maxIndex);

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
    printf_s("input your domain\n");
    int const left = getInt(),
        right = getInt();
    checkDomain(left, right);
    printf_s("1 - keyboard fill; 2 - random fill ");
    int choice = getInt();
    int* array = getMemory(size);
    switch ((enum Choices)choice)
    {
    case RANDOM:
        randomArray(array, size, left, right);
        break;
    case KEYBOARD:
        printf_s("Enter array elements:\n");
        keyboadArray(array, size, left, right);
        break;
    default:
        printf("Make a valid choice!\n");
        return 1;
        break;
    }
    output(array, size);
    // Task 1
    printf_s("\n\nnegative sum of even numbers: %d\n", firstTask(array, size));
    // Task 2
    printf_s("\nindexes, that can be devided by 6: \n");
    secondTask(array, size);
    // Task 3
    printf_s("\n\nmin index %zu; max index %zu \n", findMinIndex(array,size), findMaxIndex(array,size));
    int* arrayCopy = copy(array,size);
    thirdTask(arrayCopy,size,findMinIndex(array,size),findMaxIndex(array,size));
    output(arrayCopy,size);
    freeArray(arrayCopy);
    freeArray(array);
    return 0;
}

void checkDomain(int const left, int const right)
{
    if (left > right)
    {
        printf_s("wrong domain!!!!");
        abort();
    }
}

void checkBelongingDomain(int value, int const left, int const right)
{
    if (value<left || value>right)
    {
        printf_s("value doesn't belong to domain!");
        abort();
    }
}

int* copy(int* const array, size_t size)
{
    int* arrayCopy = (int*)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        arrayCopy[i] = array[i];
    }
    return arrayCopy;
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

int* getMemory(size_t const size)
{
    int* array = (int*)malloc(size * sizeof(int));
    if (NULL == array)
    {
        abort();
    }
    return array;
}

void keyboadArray(int* const array, const size_t size, int const left, int const right)
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = getInt();
        checkBelongingDomain(array[i], left, right);
    }
}

void randomArray(int* const array, const size_t size, int const left, int const right)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % (right - left + 1) + left;
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
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] % 6 == 0)
        {
            printf_s("%zu ", i);
        }
    }
}

void thirdTask(int* const array, size_t const size, size_t minIndex, size_t maxIndex)
{
    if (minIndex > maxIndex)
    {
        for (maxIndex; maxIndex < minIndex-1; maxIndex++)
        {
            array[maxIndex+1] = 0;
        }
    }
    else
    {
        for (minIndex; minIndex < maxIndex-1; minIndex++)
        {
            array[minIndex+1] = 0;
        }
    }
}

size_t findMinIndex(int* const array, size_t const size)
{
    size_t j = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[j] > array[i])
        {
            j = i;
        }
    }
    return j;
}

size_t findMaxIndex(int* const array, size_t const size)
{
    size_t j = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[j] < array[i])
        {
            j = i;
        }
    }
    return j;
}
