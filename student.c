#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for malloc and free
#include "student.h"

void getNames(tStudent c[], int num){
  int i;

  printf("\n");
  
  for (i=0;i<num; i++) {
      printf ("Give the student's name %d:",i);
      if(fgets (c[i].name,20,stdin)){
        c[i].name[strlen(c[i].name)-1]='\0';  //I remove the new line
      }
      else {
        printf("Error reading student name");
      }
    }
}
void getMarks(tStudent c[], int num){
  int i,j;
  
  printf("\n");
  for (i=0;i<num; i++)
    for (j=0; j<NUM_MARKS;j++) {
      printf ("Give the mark %d of the student %s(decimals with .):",j,c[i].name );
      if(!scanf ("%f", &(c[i].marks[j]))) {
        printf("Error reading mark");
      }
    }
}
float * calculateAverage(tStudent c[], int num){
  int i,j;
  float add,*average;
  
  average=(float *)malloc(NUM_STUDENTS*sizeof(float));
  for (i=0;i<num; i++) {
    add=0;
    for (j=0; j<NUM_MARKS;j++) 
      add=add+c[i].marks[j];
    average[i]=add/NUM_MARKS;
  }  
  return average;
}
void getAverage(float average[], int num){
    
  printf("\n");
  for (int i=0;i<num; i++)
    printf ("Average student grade %d=%f\n",i,average[i]);
}