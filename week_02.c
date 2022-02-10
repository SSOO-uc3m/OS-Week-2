#include "week_02.h"   
#include "student.h"  
#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h> // for strcpy                 

int problem_01(){
    int *x  = NULL;
    int *y  = NULL ;
   
    char* string ;
    
    printf ("Address of the not initialized x variable  %p\n", x); 
     
    printf ("xMalloc of x variable \n");
    
    x = (int*) malloc (sizeof(int));    
    if(x==NULL) {
        perror("Error allocating memory");
        return -1;
        }
    
    printf ("Address of x variable %p\n", x);    
    *x = 4;
    printf ("Content of x variable %d\n", *x);
    
    free(x);
    
    y = (int*) malloc (sizeof(int));    
    if( y == NULL ) {
        perror("Error allocating memory");
        return -1;
        }
        
    printf ("Address of y variable %p\n",y);
    
    printf ("Content of y variable after malloc %d\n",*y);
    
    *y = 5;
    
    printf ("Content of y variable %d\n",*y);
    
    free(y);

    string = (char*) malloc (sizeof(char)*12);   
 
    if(string==NULL) {
        perror("Error allocating memory");
        return -1;
        }
    printf ("Address of string variable %p\n",string);
    


    strcpy(string, "test string");
    
    
    printf ("Content of string %s\n",string);
    
    free(string);

    return 0;

}

  void swap (int *x, int *y) {
  int r;
  r=*x;
  *x=*y;
  *y=r;
}

  void XorSwap(int *x, int *y) {
  if (x != y)
  {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
  }

void problem_02(){
  int a=3, b=5;
  printf ("a = %d, b = %d\n", a, b );  //Has to print: a = 3, b = 5
  swap (&a,&b);
  printf ("swapped a = %d, b = %d\n", a, b );  //Has to print: swapped a = 5, b = 3
    
}

void problem_03(){
  int arraySize = 10;
  int stringSize = 12;

  int v[arraySize];
  char string[stringSize];

  printf ("size of the array: %lu bytes, number of elements of the array = %lu\n",
         sizeof(v), sizeof(v)/sizeof(int));
  printf ("size of the string:%lu bytes, number of elements of the array=%lu\n",
         sizeof(string),sizeof(string)/sizeof(char));
  printf ("length of the string: %lu\n",strlen(string));
  strcpy (string,"Hello Alice");
  printf ("Copy. New size of string: %lu bytes, number of elements of the array=%lu\n",
         sizeof(string),sizeof(string)/sizeof(char));
  printf ("length of the string:%lu\n",strlen(string));


    
}

int *readArray( int *numE){
  int i, *v;
  printf("How many items do you want to enter:");
  if(!scanf ("%d",numE)){
    printf("error reading number of items");
    return NULL;
  }
  v=(int *) malloc (*numE * sizeof(int) );
  for (i=0; i<*numE; i++){
    printf ("Enter item position %d : ",i);
    /*  This is the alternative way to read with with pointer arithmetic : scanf ("%d",(v+i)); */
    if(!scanf ("%d",&v[i])){
      printf("error reading item");
     return NULL;
  }
  }
  return v;
}

void reverseList (int *v, int nume){
  int i;
  for (i=nume-1; i>= 0; i--)
    /* This is the alternative way to read with with pointer arithmetic :
       printf ("posicion %d, valor=%d\n", i, *(v+i)); */
    printf ("position %d, value=%d\n", i, v[i]);
}
  
void problem_04 () {

  int numElements;
  int *v;
  
  v= readArray(&numElements);
  reverseList(v, numElements);

}

void incrementByReference(int* integer, int value)
{
    *integer = *integer + value;
    //value is added to the content of the memory position of integer
}

void problem_05() {

  int number = 10;

    printf ("Number value before= %d \n", number);

    incrementByReference(&number, 10);
    // The memory address is sent and the function resolves the reference
    
    printf ("Number value after= %d \n", number);
}


void problem_06(){
    tStudent classroom[NUM_STUDENTS];
  float *average;
  int numStudents;

  printf("Number of students (max 10) = "); 
  if(!scanf("%d",&numStudents)){
    printf("error reading number of students");
  }
  getchar();  
  printf("Number of students in the group = %d\n", numStudents); 

  getNames (classroom, numStudents);
  getMarks (classroom, numStudents);
  average=calculateAverage (classroom, numStudents);
  getAverage(average, numStudents);
}


