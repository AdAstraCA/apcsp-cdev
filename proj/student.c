//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt/encrypt.h"

const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  Student* st = (Student*)malloc(sizeof(Student));
  st->firstName = (char*)malloc((strlen(fname)+1) * sizeof(char*));
  strcpy(st->firstName, fname);
  st->lastName = (char*)malloc((strlen(lname)+1) * sizeof(char*));
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;
  students[numStudents] = st;
  numStudents++;
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
}


void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student);
  // free the memory associated with a student including the strings
}


void deleteStudents()
{
  while (numStudents >= 0)
  {
    deleteStudent(students[numStudents]);
    students[numStudents] = 0;
    numStudents--;
  }
  numStudents = 0;
  // iterate over the students array deleting every student and setting the pointer
  // values to 0 and adjusting the numStudents to 0
}


void saveStudents(int key)
{
  FILE* fp;
  fp = fopen("studentdata.txt", "w");
  char buff[256];
  if (fp)
  {
    for (int i = 0; i < numStudents; i++)
    {
      Student* st = students[i];
      sprintf(buff, "%s %s %d %ld\n", st->firstName, st->lastName, st->age, st->id);
      if (key != 0)
      {
        caesarEncrypt(buff, key);
      }
      fprintf(fp, "%s\n", buff);
      printf("Saving: %s", buff);
    }
    fclose(fp);
  }
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  // the best way to do this is to convert the student data to a string using sprintf and then
  // (optionally) encrypt the whole string before writing it to disk (see cdemo/fileio3.c)
  printf("Save Successful!\n");
}


void loadStudents(int key)
{
  if (numStudents != 0)
  {
    deleteStudents();
  }
  FILE* fr;
  fr = fopen("studentdata.txt", "r");
  if (fr)
  {
    while (1) 
    {
      char r1[256];
      char r2[256];
      char r3[256];
      char r4[256];
      int loadAge;
      long loadID;
      int match = fscanf(fr, "%s %s %s %s", r1, r2, r3, r4);
      if (match == 4)
      {
        if (key != 0)
        {
          caesarDecrypt(r1, key);
          caesarDecrypt(r2, key);
          caesarDecrypt(r3, key);
          caesarDecrypt(r4, key);
        }
        sscanf(r3, "%d", &loadAge);
        sscanf(r4, "%ld", &loadID);
        createStudent(r1, r2, loadAge, loadID);
      } else {
        break;
      }
    }
  }
  printf("Load Successful!\n");
  // load the students from the data file overwriting all exisiting students in memory
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}

void printStudents()
{
  for (int i = 0; i < numStudents; i++)
  {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




