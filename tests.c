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
int *create_simple_array(int size)
{
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    return arr;
}

/**
 * One test for a basic swap
*/
int test_swap_one()
{
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5)
    {
        return 1;
    }
    return 0;
}

/**
 * Another test for a basic swap
*/
int test_swap_second()
{
    printf("2. test_swap_second()\n");
    int a = 15;
    int b = 20;
    swap(&a, &b);
    if (a == 20 && b == 15)
    {
        return 1;
    }
    return 0;
}

/**
 * One test for the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib1()
{
    printf("3. test_create_array_of_ints_fib1()\n");
    int *arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] != expected[i])
        {
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
int test_create_array_of_ints_fib2()
{
    printf("4. test_create_array_of_ints_fib2()\n");
    int *arr = create_array_of_ints_fib(6);
    int expected[] = {1, 1, 2, 3, 5, 8};
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] != expected[i])
        {
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
int test_reverse_array1()
{
    printf("5. test_reverse_array1()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    reverse_array(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] != expected[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * Another test for the reverse_array function
*/
int test_reverse_array2()
{
    printf("6. test_reverse_array2()\n");
    int arr[] = {10, 21, 33, 45, 59, 78, 89};
    int expected[] = {89, 78, 59, 45, 33, 21, 10};
    reverse_array(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] != expected[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * One test for the double_array_size function
*/
int test_double_array_size1()
{
    printf("7. test_double_array_size1()\n");
    int size = 5;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    double_array_size(&arr, size);
    int expected[] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    int new_size = 10;
    for (int i = 0; i < new_size; i++)
    {
        if (arr[i] != expected[i])
        {
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
int test_double_array_size2()
{
    printf("8. test_double_array_size2()\n");
    int size = 6;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    double_array_size(&arr, size);
    int expected[] = {1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0, 0};
    int new_size = 12;
    for (int i = 0; i < new_size; i++)
    {
        if (arr[i] != expected[i])
        {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

/**
 * One test for the copy_array_start_end_loop function
 * Here we test normal range, end > start
*/
int test_copy_array_start_end_loop1()
{
    printf("9. test_copy_array_start_end_loop1()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int new_size = 0;
    int *new_arr = copy_array_start_end_loop(arr, size, 1, 3, &new_size);
    if (new_arr == NULL || new_size != 3)
    {
        free(new_arr);
        return 0;
    }
    int expected1[] = {2, 3, 4};
    for (int i = 0; i < new_size; i++)
    {
        if (new_arr[i] != expected1[i])
        {
            free(new_arr);
            return 0;
        }
    }
    free(new_arr);
    return 1;
}

/**
 * Another test for the copy_array_start_end_loop function
 * Here we test normal range, end < start
*/
int test_copy_array_start_end_loop2()
{
    printf("10. test_copy_array_start_end_loop2()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int new_size = 0;
    int *new_arr = copy_array_start_end_loop(arr, size, 3, 1, &new_size);
    if (new_arr == NULL || new_size != 4)
    {
        free(new_arr);
        return 0;
    }
    int expected2[] = {4, 5, 1, 2};
    for (int i = 0; i < new_size; i++)
    {
        if (new_arr[i] != expected2[i])
        {
            free(new_arr);
            return 0;
        }
    }
    free(new_arr);
    return 1;
}

/**
 * Another test for the copy_array_start_end_loop function
 * Here we test invalid start
*/
int test_copy_array_start_end_loop3()
{
    printf("11. test_copy_array_start_end_loop3()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int new_size = 0;
    int *new_arr = copy_array_start_end_loop(arr, size, -10, 2, &new_size);
    if (new_arr != NULL)
    {
        free(new_arr);
        return 0;
    }
    return 1;
}

/**
 * Another test for the copy_array_start_end_loop function
 * Here we test invalid end
*/
int test_copy_array_start_end_loop4()
{
    printf("12. test_copy_array_start_end_loop4()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int new_size = 0;
    int *new_arr = copy_array_start_end_loop(arr, size, 1, 20, &new_size);
    if (new_arr != NULL)
    {
        free(new_arr);
        return 0;
    }
    return 1;
}

/**
 * One test for the create_point function
*/
int test_create_point1()
{
    printf("13. test_create_point1()\n");
    Point *point = create_point(3, 4);
    if (point->x != 3 || point->y != 4)
    {
        return 0;
    }
    free(point);
    return 1;
}

/**
 * Another test for the create_point function
*/
int test_create_point2()
{
    printf("14. test_create_point2()\n");
    Point *point = create_point(1, 6);
    if (point->x != 1 || point->y != 6)
    {
        return 0;
    }
    free(point);
    return 1;
}

/**
 * One test for the create_polygon function
*/
int test_create_polygon1()
{
    printf("15. test_create_polygon1()\n");
    Polygon *poly1 = create_polygon(3);
    if (poly1 == NULL || poly1->size != 3 || poly1->points == NULL)
    {
        return 0;
    }
    for (int i = 0; i < poly1->size; i++)
    {
        if (poly1->points[i] == NULL || poly1->points[i]->x != 0 || poly1->points[i]->y != 0)
        {
            return 0;
        }
    }
    free(poly1);
    return 1;
}

/**
 * Another test for the create_polygon function
*/
int test_create_polygon2()
{
    printf("16. test_create_polygon2()\n");
    Polygon *poly1 = create_polygon(5);
    if (poly1 == NULL || poly1->size != 5 || poly1->points == NULL)
    {
        return 0;
    }
    for (int i = 0; i < poly1->size; i++)
    {
        if (poly1->points[i] == NULL || poly1->points[i]->x != 0 || poly1->points[i]->y != 0)
        {
            return 0;
        }
    }
    free(poly1);
    return 1;
}

/**
 * One test for the free_polygon function
*/
int test_free_polygon1()
{
    printf("17. test_free_polygon1()\n");
    Polygon *p = create_polygon(4);
    for (int i = 0; i < 4; i++)
    {
        p->points[i] = create_point(i, i);
    }
    free_polygon(p);
    if (p == NULL)
    {
        return 0;
    }
    else
    {

        return 1;
    }
}

/**
 * Another test for the free_polygon function
*/
int test_free_polygon2()
{
    printf("18. test_free_polygon2()\n");
    Polygon *p = create_polygon(5);
    for (int i = 0; i < 5; i++)
    {
        p->points[i] = create_point(i, i);
    }
    free_polygon(p);
    if (p == NULL)
    {
        return 0;
    }
    else
    {

        return 1;
    }
}

/**
 * One test for the create_rectangle function
*/
int test_create_rectangle1()
{
    printf("19. test_create_rectangle1()\n");
    Polygon *rec = create_rectangle(4, 3);
    if (rec->size == 4 &&
        rec->points[0]->x == 0 && rec->points[0]->y == 0 &&
        rec->points[1]->x == 4 && rec->points[1]->y == 0 &&
        rec->points[2]->x == 4 && rec->points[2]->y == 3 &&
        rec->points[3]->x == 0 && rec->points[3]->y == 3)
    {
        free_polygon(rec);
        return 1;
    }
    else
    {
        free_polygon(rec);
        return 0;
    }
}

/**
 * Another test for the create_rectangle function
*/
int test_create_rectangle2()
{
    printf("20. test_create_rectangle2()\n");
    Polygon *rec = create_rectangle(5, 10);
    if (rec->size == 4 &&
        rec->points[0]->x == 0 && rec->points[0]->y == 0 &&
        rec->points[1]->x == 5 && rec->points[1]->y == 0 &&
        rec->points[2]->x == 5 && rec->points[2]->y == 10 &&
        rec->points[3]->x == 0 && rec->points[3]->y == 10)
    {
        free_polygon(rec);
        return 1;
    }
    else
    {
        free_polygon(rec);
        return 0;
    }
}

/**
 * One test for the create_triangle function
*/
int test_create_triangle1()
{
    printf("21. test_create_triangle1()\n");
    Polygon *triangle = create_triangle(3, 4);
    if (triangle->size == 3 &&
        triangle->points[0]->x == 0 && triangle->points[0]->y == 0 &&
        triangle->points[1]->x == 3 && triangle->points[1]->y == 0 &&
        triangle->points[2]->x == 3 && triangle->points[2]->y == 4)
    {
        free_polygon(triangle);
        return 1;
    }
    else
    {
        free_polygon(triangle);
        return 0;
    }
}

/**
 * Another test for the create_triangle function
*/
int test_create_triangle2()
{
    printf("22. test_create_triangle2()\n");
    Polygon *triangle = create_triangle(5, 10);
    if (triangle->size == 3 &&
        triangle->points[0]->x == 0 && triangle->points[0]->y == 0 &&
        triangle->points[1]->x == 5 && triangle->points[1]->y == 0 &&
        triangle->points[2]->x == 5 && triangle->points[2]->y == 10)
    {
        free_polygon(triangle);
        return 1;
    }
    else
    {
        free_polygon(triangle);
        return 0;
    }
}

/**
 * One test for the calculate_polygon_area function
 * Here we calculate triangle area
*/
int test_calculate_polygon_area1()
{
    printf("23. test_calculate_polygon_area1()\n");
    Polygon *triangle = create_triangle(5, 10);
    double expected_area = 25.0;
    double calculated_area = calculate_polygon_area(triangle);
    if (calculated_area == expected_area)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Another test for the calculate_polygon_area function
 * Here we calculate rectangle area
*/
int test_calculate_polygon_area2()
{
    printf("24. test_calculate_polygon_area2()\n");
    Polygon *rectangle = create_rectangle(5, 10);
    double expected_area = 50.0;
    double calculated_area = calculate_polygon_area(rectangle);
    if (calculated_area == expected_area)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// this is a list of all the unit tests
int (*unitTests[])() = {
    test_swap_one,
    test_swap_second,
    test_create_array_of_ints_fib1,
    test_create_array_of_ints_fib2,
    test_reverse_array1,
    test_reverse_array2,
    test_double_array_size1,
    test_double_array_size2,
    test_copy_array_start_end_loop1,
    test_copy_array_start_end_loop2,
    test_copy_array_start_end_loop3,
    test_copy_array_start_end_loop4,
    test_create_point1,
    test_create_point2,
    test_create_polygon1,
    test_create_polygon2,
    test_free_polygon1,
    test_free_polygon2,
    test_create_rectangle1,
    test_create_rectangle2,
    test_create_triangle1,
    test_create_triangle2,
    test_calculate_polygon_area1,
    test_calculate_polygon_area2};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++)
    {
        if (unitTests[i]())
        {
            numPassed++;
        }
        else
        {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
