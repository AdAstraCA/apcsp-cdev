#include <stdio.h>
#include <string.h>


int main()
{
  char string1[27];
  for (int i = 0; i < 26; i++)
  {
    string1[i] = 'a' + i;
  }
  string1[26] = '\0';
  char string2[] = "abcdefghijklmnopqrstuvwxyz";
  if (strcmp(string1, string2) == 0) {
    printf("The strings are identical\n");
  } else {
    printf("The strings are different\n");
  }
  for (int i = 0; i < 26; i++)
  {
    string1[i] -= 32;
  }
  if (strcmp(string1, string2) == 0) {
    printf("The strings are identical\n");
  } else {
    printf("The strings are different\n");
  }
  char string3[54];
  strcpy(string3, string1);
  strcat(string3, string2);
  printf("%s + %s = %s\n", string1, string2, string3);
}
