#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
*@brief function changes max value to it negative
*@param array - pointer to the array
*@param maxIndex - index of the max value in array
*/
void firstTask(int* array, const size_t maxIndex);

/**
*@brief function finds size of new array. if value from the array contain one, new size gets + 1. that rule applies to full array.
*@param array - pointer to the array
*@param size - size of original array
*@param maxIndex - index of the max value in array
*@return new size of the array
*/
size_t newSize(int* const array, size_t const size, const size_t maxIndex);

/**
*@brief function checks if value contain one
*@param value - some value
*@return true - value has one; false - value do not have one
*/
bool containOne(int value);

/**
*@brief function fills the copy of array and puts max value after each element of array that has one in it.
*@param array - pointer to array
*@param arrayCopy - empty array with new size
*@param size - size of original array
*@param maxIndex - index of the max value from original array
*/
void secondTask(int* const array, int* arrayCopy, size_t const size, size_t maxIndex);

/**
*@brief function changes values of array with the rule that the first N elements of array changes: 1) if even A = A + index; 2) if odd A = A - index
*@param array - pointer to the array
*@param size - size of the array
*@param rule - ammount of times that the rule applies
*/
void thirdTask(int* const array, const size_t size, const int rule);

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
void randomArray(int* array, const size_t size, int const left, int const right);

/**
*@brief prints values of array
*@param array - pointer to array
*@param size - size of array
*/
void output(const int* const array, size_t const size);

/**
*@brief function clears memory used for array
*@param array - pointer to array
*/
void freeArray(int** array);

/**
*@brief used for choice of a way to fill an array
*@brief KEYBOARD - keyboard fill
*@brief RANDOM - random fill
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
    printf_s("%d - keyboard fill; %d - random fill ",(int)KEYBOARD, (int)RANDOM);
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
    }
    output(array, size);
    size_t maxIndex = findMaxIndex(array, size);
    //Task 1
    int* arrayFirstCopy = copy(array, size);
    firstTask(arrayFirstCopy, maxIndex);
    printf_s("\narray for the first task: \n");
    output(arrayFirstCopy, size);
    freeArray(&arrayFirstCopy);
    //Task 2
    size_t sizeForSecondArray = newSize(array, size, maxIndex);
    int* secondArray = getMemory(sizeForSecondArray);
    secondTask(array, secondArray, size, maxIndex);
    printf_s("\narray for the second task:\n");
    output(secondArray, sizeForSecondArray);
    freeArray(&secondArray);
    //Task 3
    int* arraySecondCopy = copy(array, size);
    printf_s("\ninput ammount of times that you want rule to work: ");
    int rule = getInt();
    thirdTask(arraySecondCopy, size, rule);
    printf_s("\narray for the third task:\n");
    output(arraySecondCopy, size);
    freeArray(&arraySecondCopy);
    freeArray(&array);
    return 0;
}

void firstTask(int* array, const size_t maxIndex)
{
    array[maxIndex] = -1 * array[maxIndex];
}

size_t newSize(int* const array, size_t const size, const size_t maxIndex)
{
    size_t temp = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (containOne(array[i]))
        {
            temp += 1;
        }
    }
    return temp + size;
}

bool containOne(int value)
{
    value = abs(value);
    while (value > 0)
    {
        if (value % 10 == 1)
        {
            return true;
        }
        value /= 10;
    }

    return false;
}

void secondTask(int* const array, int* arrayCopy, size_t const size, size_t maxIndex)
{
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (containOne(array[i]))
        {
            arrayCopy[j] = array[i];
            j++;
            arrayCopy[j] = array[maxIndex];
        }
        else
        {
            arrayCopy[j] = array[i];
        }
        j++;
    }
}

void thirdTask(int* const array, const size_t size, int rule)
{
    if (rule > 0)
    {
        if (rule > size)
        {
            rule = size;
        }
        for (size_t i = 0; i < rule; i++)
        {
            if (i % 2 == 0)
            {
                array[i] += i;
            }
            else
            {
                array[i] -= i;
            }
        }
    }
}

void checkDomain(int const left, int const right)
{
    if (left > right)
    {
        perror("wrong domain!!!!");
        abort();
    }
}

void checkBelongingDomain(int value, int const left, int const right)
{
    if (value<left || value>right)
    {
        perror("value doesn't belong to domain!");
        abort();
    }
}

int* copy(int* const array, size_t size)
{
    int* arrayCopy = getMemory(size);
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
        perror("Error");
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

void randomArray(int* array, const size_t size, int const left, int const right)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % (right - left + 1) + left;
    }
}

void output(const int* const array, size_t const size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

void freeArray(int** array)
{
    free(*array);
    *array = NULL;
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
