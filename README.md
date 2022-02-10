# Lab C Pointers 

## Statement 1:

Create a program that declares two integer pointers and a string. 
This program should print the addresses of the pointers and then use malloc and free to allocate space to those pointers and assign them a value.

## Statement 2:

Write a C program that interchanges the values of two numbers. 
You must create a swap function that takes the numbers as arguments by reference.

## Statement 3:

Write a program to use sizeof and strlen. 

Write a program that displays the size in bytes of a 10-element integer vector. 
And declare a string of 12, copy a text of 8 and show its length.


## Statement 4:

Write a C program that allows you to create a dynamic array of integer type whose size is requested by input, as well as its elements. 

Once created, the array should be printed in reverse order.


## Statement 5:

Write a program that calls a function that increments the value of an integer that it receives by reference. 
The function must be of type void.


## Statement 6:

Write a program in C that for a number of students, which is requested by keyboard, asks for each one of them: name and 3 notes (which can have decimals). 
Once the list of students has been entered, it calculates the average of the three grades for each student and displays the name and average grade of the student on the screen.

# Test

1.- Indicates what types the variables var1, var2 and var3 must have for the following snippet is correct:
```
var1 = 5.5;
var2 = &varl;
var3 = &var2;
*var2 = var1 + **var3;
```

2.- Is there a problem with the following code?

```
long dato = 0;
long *ptrDato;
ptrDato = dato;
```


3.- What problems are there in the following code?

```
void main(void)
int *ptrl, ptr2;
int datl = 5, dat2 = 4;

ptrl = 4;
free(ptrl);
ptr1 = malloc(l);

ptrl = 5;
(ptr2 + 1) = 3;
ptr1 = 5;

return 0;
```

4.- Build a dynamic array to store a word search of dimensions read by keyboard.

5.- Given the following program fragment:

```
float a = 0.001;
float *b;
float *c;

b = &a;
b = c;
a = *c + *b;
```

Which of the following statements is true?

* Variables b and c are stored in the same memory address.
* The statement *c = 4; it would modify the content of variable a.
* a will take an indeterminate value.
* c stores the address of variable b.

6.- Given the following variable definitions:
```
int x;
int *p1;
int **p2;
```
Which of the following statements allows x to take the value 4 correctly?
```
pl = &p2; *p2 = &x; *p1 = 4;

p2 = &x; *p2 = 4;

p2 = pl; pl = &x; *p2 = 4;

p2 = &p1; pl = &x; **p2 = 4;
```

7.- Which of the following expressions allows you to reserve memory for a vector of 10 elements of type float?
```
(float) malloc(10);
(float *) malloc(10);
(float *) malloc(10 * sizeof(float))
(float *) malloc(10 * sizeof(float*));
```

8.- After executing the following code snippet:
```
float nl = 10;
float n2 = 5;
float *p, *q;

p = &n1;
q = &n2;

q=*p+*p;
```
Which of the following statements is correct?

* `n1 = 10 y n2 = 5`

* `n1 = 10 y n2 = 10`

* `the statement *p == *p is illegal`

* `n1 = 10 y n2 = 20`

