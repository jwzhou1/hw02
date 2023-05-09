# Homework 2 Readme
Name: Jiawei Zhou

Github Account name: jwzhou1

Link to Assignment on Github: (copy and paste the link to your assignment repo here)

https://github.com/jwzhou1/hw02.git

How many hours did it take you to complete this assignment (estimate)? 

20 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed

No.


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource

No.


(Optional) What was your favorite part of the assignment? 

I have learned that I should write function and tests at the same time.

(Optional) How would you improve the assignment? 

I think it is better to have more pictures to show what it looks like when we run the main function.

## Understanding C Questions

1. What is the difference between a variable and a pointer?

A variable is a named storage location that holds a value of a specific data type. For example: An integer variable can store integers. It is usually implemented on a computer as a block of memory space, characterized by an address and a size. A pointer, on the other hand, is a specialized variable that holds the memory address of another variable. In other words, a pointer points to the data that is contained in the memory address of another variable.

2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?
3. What is the difference between the heap and stack when related to memory allocation and management?
In computer memory management, the heap and the stack are two different regions of memory used for allocating and deallocating memory.

The stack is a reserved region of memory that is automatically managed by the operating system. It is used to store local variables, function parameters, and other short-lived data. The stack grows and shrinks dynamically as functions are called and return, meaning that the memory allocated on the stack is typically limited in size.

On the other hand, the heap is a larger pool of memory that is dynamically allocated by the program at runtime. Memory allocated on the heap remains available until explicitly deallocated (freed) by the program. The heap is typically used for dynamically sized data structures such as arrays and linked lists, and can be much larger than the stack.

In summary, the main difference between the heap and the stack is that the stack is mainly used for storing function call-related data structures, while the heap is used for more flexible dynamic memory allocation and management during program execution.

4. When you use `malloc`, where are you storing the information?
5. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?
6. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library)?
7. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 





### Linking to images?
To link an image, you use the following code

```markdown
![alt text](path / link to image)
```
for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

