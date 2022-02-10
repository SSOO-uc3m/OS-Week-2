#ifndef WEEK_02_H    /* This is an "include guard" */
#define WEEK_02_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/




/*Problem 1:
Create a program that declares two integer pointers and a string. This program should print the addresses of the pointers and then use malloc and free to allocate space to those pointers and assign them a value..*/
int problem_01();

/*
Problem 2:
Write a C program that interchanges the values of two numbers. You must create a swap function that takes the numbers as arguments by reference.*/
void problem_02();

/*Problem 3:
Write a program to use sizeof and strlen.

Write a program that displays the size in bytes of a 10-element integer vector. And declare a string of 12, copy a text of 8 and show its length.*/
void problem_03();

/*Problem 4:
Write a C program that allows you to create a dynamic array of integer type whose size is requested by input, as well as its elements.

Once created, the array should be printed in reverse order.*/
void problem_04 ();

/*Problem 5:
Write a program that calls a function that increments the value of an integer that it receives by reference. The function must be of type void.*/
void problem_05 ();

/*Problem 6:
Write a program in C that for a number of students, which is requested by keyboard, asks for each one of them: name and 3 notes (which can have decimals). Once the list of students has been entered, it calculates the average of the three grades for each student and displays the name and average grade of the student on the screen.*/
void problem_06() ;


#endif /* WEEK_01_H */