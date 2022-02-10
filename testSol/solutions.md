# Test Solutions

1.- Indicates what types the variables var1, var2 and var3 must have for the following snippet is correct:

``` 
var1 = 5.5;
var2 = & varl;
var3 = & var2;
* var2 = var1 + ** var3;
```

> Var1 is assigned a real value, so its type must be either float or double. We will assume that it is float.
var2 receives the address where varl is stored, so var2 is a pointer. Since var1 is float, var2 will have the type float
The line var3 = & var2 means that the value pointed to by var2 is assigned to var3. That is, the value pointed to by var3 is of the same type as var2. Therefore var3 is a pointer to a floating pointer: float
The last line confirms our three assumptions.

```
float var1;
float * var2;
float ** var3;
```

2.- Is there a problem with the following code?

```
long data = 0;
long * ptrData;
ptrData = data;
```
> The code compiles, as there is no syntactic or semantic error (at the type level). However, running errors may occur, because we try to
store data in the memory address pointed by ptrData. But ptrData has not been initialized, so it may be pointing to any place, surely to a place
where we cannot (or should not) write.

3.- What problems are there in the following code?

```
#include <stdlib.h>

void main (void){
  int * ptr1, ptr2;
  int dat1 = 5, dat2 = 4;

  *ptr1 = 4;
  free (ptr1);
  ptr1 = malloc (1);

  ptr1 = 5;
  *(ptr2 + 1) = 3;
  ptr1 = 5;

  return 0;
}
```

> The C standard requires the main function to return an integer. If a specific compiler supports that the main function does not return anything, it is a license that is taken, to "facilitate" the programmer's work. Being purists, we should make main would return an integer. In any case, if we left it as void, the last line (return 0) would be wrong, because we would be saying that it is a procedure and then we would return a value.

> The name of the variable ptr2 declared in the first line seems to indicate that we want it to be of type pointer. However, the * only affects the first variable, not the second. It will not compile because of that

> The C standard only allows to initialize the last line of a declaration. Therefore, the initialization of dat1 in its declaration is incorrect by standard (although some compilers allow it).

> The line * ptr1 = 4 suffers the same problem as in the previous exercise. We should ask for memory for ptr1 before using it (using malloc). Thus, in addition,
we get that the free (ptr1) line does not try to free a memory not controlled by the dynamic memory manager.

> The line ptr1 = malloc (1) asks for memory for a byte, not for the number of bytes that an integer occupies. Therefore, the following line will write to memory that does not
we own. The solution is to ask for enough memory.

> The line *(ptr2 + 1) = 3 suffers the same problem as *ptrl = 4. The difference is that now we have to request memory for two integers in ptr2, because with
the increment of the pointer we are accessing the integer following the one pointed by ptr2.

> The assignment ptr1 = 5 will print a warning, as there are type discrepancies.

> Finally, it would be necessary to free all the memory that has been requested.

> A possible way to fix all the problems would be with the following code:

```
#include <stdlib.h>

int main (void){
  int * ptr1, * ptr2;
  int dat1, dat2 = 4;


  dat1 = 5;
  ptr1 = malloc (sizeof (int));
  if (ptr1 == NULL)
     return -1;
  *ptr1 = 4;
  
  ptr2 = malloc (2 * sizeof (int));
  if (ptr2 == NULL)
     return 1;
  *(ptr2 + 1) = 3;
  *ptr1 = 5;
  
  free (ptr1);
  free (ptr2);
  
  return 0;
  }
```

4.- Build a dynamic array to store an alphabet soup of dimensions read by keyboard.

````
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  char **alphabetSoup;

  unsigned int high ;
  unsigned int width ;
  char letter = 'a';

  puts ("Enter high");
  scanf ("%d", &high);
  puts ("Enter width");
  scanf ("%d", &width);
  
  alphabetSoup = malloc (width * sizeof (char *));
  if (alphabetSoup == NULL)
    return -1;

  for (int i = 0; i < high; i++)
    {
      alphabetSoup[i] = malloc (high * sizeof (char));
      if (alphabetSoup[i] == NULL)
	    return -1;
	    for (int j = 0; j < width; j++){
            alphabetSoup[i][j] = letter++;
        }
      
      
    }
   
    
    for (int i = 0; i < high; i++){
        for (int j = 0; j < width; j++){
            printf("%c ",alphabetSoup[i][j]);
        }
        printf("\n");
    }
   
}
````

5.- Given the following program fragment:

```
float a = 0.001;
float * b;
float * c;

b = & a;
b = c;
a = *c + *b;
```
Which of the following statements is true?


a)  Variables b and c are stored in the same memory address.

b) The statement * c = 4; would modify the content of variable a.

c) a will take an indeterminate value.

d) c stores the address of variable b.

> Both b and c are pointers that we get to point to a. They both point to the same memory address, but each is stored in a different one. At the end of execution, a will contain the value 0.002. Therefore, the only correct option is the second.

6.- Given the following definitions of variables:
```
int x;
int * p1;
int ** p2;
```
Which of the following statements allows x to take the value 4 correctly?


a) `pl = &p2; *p2 = &x; * p1 = 4;`

b) `p2 = &x; *p2 = 4;`

c) `p2 = pl; pl = &x; * p2 = 4;`

d) `p2 = &p1; pl = &x; **p2 = 4;`


> Due to type discrepancy, none of the first three alternatives compile. The last one does. Its execution ends by making p2 points to pl, and the last at x. therefore it is the correct option, since the execution, therefore, of ** p2 = 4 causes the value of x to be modified.

7.- Which of the following expressions allows you to reserve memory for a vector of 10 elements of type float?


* `(float) malloc (10);`
* `(float *) malloc (10);`
* `(float *) malloc (10 * sizeof (float));`
* `(float *) malloc (10 * sizeof (float *));`


> The type convertion in the first line causes it to not compile. 
The second line asks for memory for 10 bytes, not for 10 variables of type float. 
The third asks for memory for and array of 10 elements of type float, so it is correct. 
The latter asks for enough space to hold 10 elements of type float *, which will not necessarily be the same size as 10 float variables, so it is incorrect.

8.- After executing the following code snippet:

```
float nl = 10;
float n2 = 5;
float * p, * q;

p = &n1;
q = &n2;

q = *p + *p;
```

Which of the following statements is correct?

a) `n1 = 10 and n2 = 5`

b) `n1 = 10 and n2 = 10`

c) `the sentence *p + *p is illegal`

d) `n1 = 10 and n2 = 20`

> The program compiles correctly. The first two assignments make p point to nl, and q to n2. The right part of the last assignment sums the content of * p against itself; Since p points to n1, the result of the sum will be 20. This value is assigned to the value indicated by q, which turns out to be 5. Therefore, after execution n1 is not modified, but n2 does (through q), and becomes 20. The valid option is therefore the last one.
