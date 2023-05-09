/**
 * Student Name: Jiawei Zhou
 * Semester: Summer 2023
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * One test for a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Another test for a basic swap
*/
int test_swap_second() {
    printf("2. test_swap_second()\n");
    int a = 15;
    int b = 20;
    swap(&a, &b);
    if (a == 20 && b == 15) {
        return 1;
    }
    return 0;
}

/**
 * One test for printing array
*/
int test_print_array1() {
   printf("3. test_print_array1()\n");
    int arr[] = {1, 3, 2, 4, 5};
    int size = 5;
    print_array(arr, size);
    int expected[] = {1, 3, 2, 4, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Another test for printing array
*/
int test_print_array2() {
    printf("4. test_print_array2()\n");
    int arr[] = {1, 3, 2, 4, 5, 6};
    int size = 6;
    print_array(arr, size);
    int expected[] = {1, 3, 2, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * One test for the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib1() {
    printf("5. test_create_array_of_ints_fib1()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

/**
 * Another test for the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib2() {
    printf("6. test_create_array_of_ints_fib2()\n");
    int* arr = create_array_of_ints_fib(6);
    int expected[] = {1, 1, 2, 3, 5, 8};
    for (int i = 0; i < 6; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

/**
 * One test for the reverse_array function
*/
int test_reverse_array1() {
    printf("7. test_reverse_array1()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    reverse_array(arr, 5);
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Another test for the reverse_array function
*/
int test_reverse_array2() {
    printf("8. test_reverse_array2()\n");
    int arr[] = {10, 21, 33, 45, 59, 78, 89};
    int expected[] = {89, 78, 59, 45, 33, 21, 10};
    reverse_array(arr, 7);
    for (int i = 0; i < 7; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * One test for the double_array_size function
*/
int test_double_array_size1() {
    printf("9. test_double_array_size1()\n");
    int size = 5;
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    double_array_size(&arr, size);
    int expected[] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    int new_size = 10;
    for (int i = 0; i < new_size; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

/**
 * Another test for the double_array_size function
*/
int test_double_array_size2() {
    printf("10. test_double_array_size2()\n");
    int size = 6;
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    double_array_size(&arr, size);
    int expected[] = {1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0, 0};
    int new_size = 12;
    for (int i = 0; i < new_size; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}


// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_swap_second,
        test_print_array1,
        test_print_array2,
        test_create_array_of_ints_fib1,
        test_create_array_of_ints_fib2,
        test_reverse_array1,
        test_reverse_array2,
        test_double_array_size1,
        test_double_array_size2
        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
