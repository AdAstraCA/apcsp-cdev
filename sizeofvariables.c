#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b[] = "g";

  // print value and size of an int variable
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));

  float c = 4.2;

  // print value and size of an int variable
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  double d  = 10.783;

  // print value and size of an int variable
  printf("double d value: %lf and size: %lu bytes\n", d, sizeof(d));

  long int e = 712;

  // print value and size of an int variable
  printf("long int e value: %d and size: %lu bytes\n", e, sizeof(e));

  short int f = 9;
  // print value and size of an int variable
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

