#include <stdio.h>



// student structure
//struct Student...
struct Student {
  char first[30];
  char last[30];
  int age;
  int studentID;
};


void printStudent(struct Student* student)
{
  printf("--- Student ---\n");
  printf("First Name: %s\n", student->first);
  printf("Last Name: %s\n", student->last);
  printf("Age: %d\n", student->age);
  printf("ID: %d\n", student->studentID);
}


void printAllStudents(struct Student students[], int num)
{
  for (int i = 0; i < num; i++) 
  {
    printStudent(&students[i]); 
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student studentInfo[100];
  char input[256];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(studentInfo, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First Name: \n");
      fgets(input, 256, stdin);
      if (sscanf(input, "%s", studentInfo[numStudents].first) != 1) continue;
      printf("Last Name: \n");
      fgets(input, 256, stdin);
      if (sscanf(input, "%s", studentInfo[numStudents].last) != 1) continue;
      printf("Age: \n");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &studentInfo[numStudents].age) != 1) continue;
      printf("Student ID: \n");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &studentInfo[numStudents].studentID) != 1) continue;
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
