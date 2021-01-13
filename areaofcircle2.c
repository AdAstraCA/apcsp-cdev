#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, float* b)
{  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%f", b);
}
}// add your areaOfCircle function here - it must NOT printf, instead it must// return the result to be printed in main
float areaOfCircle(float rad)
{
  float area = rad * rad * M_PI; 
  return area;
}
int main(int argc, char* argv[]) 
{  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  char input[256];
  float start;
  float end;
  
  printf("Input lower:\n");
  while (1)
  {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &start) == 1) break;
    printf("Not a valid input - try again!\n");
  }
  printf("Input upper:\n");
  while (1)
  {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &end) == 1) break;
    printf("Not a valid input - try again!\n");
  }
  // for testing only - do not change
  getTestInput(argc, argv, &start, &end);

  // add your code below to call areaOfCircle function with values between
  // start and end
  printf("Start: %f, End: %f\n", start, end);
  for (float i = start; i <= end; i++)
  {
    float eachArea = areaOfCircle(i);
    printf("The area of the circle with a radius of %f is %f\n", i, eachArea);
  }
}
