//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  int shiftMod = shift % CHARS_LEN;
  int found = 0;
  int cycle = 0;

  while (found == 0)
  {
    if (c == CHARS[cycle])
    {
      found = 1;
    }
    cycle++;
  }
  cycle--;
  if (direction == 1) {
    if (cycle + shiftMod > 61) {
      shiftMod = 62 - shiftMod;
      c = CHARS[cycle - shiftMod];
    } else {
      c = CHARS[cycle + shiftMod];
    }
  } else if (cycle - shiftMod < 0) {
    shiftMod = 62 - shiftMod;
    c = CHARS[cycle + shiftMod];
  } else {
    c = CHARS[cycle - shiftMod];
  }
  return c;
// implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


