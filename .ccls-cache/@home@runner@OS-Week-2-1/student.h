#ifndef __STUDENT_H__
#define __STUDENT_H__

#define NUM_STUDENTS 10
#define NUM_MARKS 3

// Definition of a Date data type
struct Student {
  char name[20];
  float marks[NUM_MARKS]; };

typedef struct Student tStudent;

void getMarks(tStudent c[], int num);

void getNames(tStudent c[], int num);

float * calculateAverage(tStudent c[], int num);

void getAverage(float average[], int num);

#endif // __STUDENT_H__
