//HW 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int a[], int size) {
  printf("---------- Problem 1 ----------\n");
  //use pointer arithmetic
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", *(a+i));
  }
  printf("\n");
}

void upperCaseSecondA(void) {
  printf("Type something in all lower-case: ");
  char s[100];
  fgets(s, 100, stdin);
  char a = 'a';
  char *search = strchr(s, a);
  if (search == NULL){
    printf("There are no a's in: %s\n", s);
  }
  else {
    // pointer arithmetic to move past the 'a' that's been found
    (search)++;
    char *secA = strchr(search, a);
    if (secA == NULL){
      printf("There's only 1 a in: %s\n", s);
    }
    else {//now change second 'a' to 'A'
      *secA = 'A';
      printf("Result: %s \n",s);
    }
  }
}

//count how many of each letter (ignoring case) and punctiation occur
#define SPACE 26
#define PERIOD 27
#define EXCLA 28
#define QUES 29
#define APOS 30
#define COMMA 31
#define ELSE 32

void textData(void){
  printf("Type in a bunch of text (no more than 1000 characters total): ");
  char s[1000];
  fgets(s, 1000, stdin);
  int i;
  // int count[33] = {0}; // Missing values are intialized to 0
  static int count[33]; // objects with static storage initialize to 0
  for(i = 0; i < strlen(s) + 1; i++){
    //ASCII: 32, 33, 39, 44, 46, 65-90 (+32 for lower-case)
    if(s[i] >=65 && s[i] <= 90)
      count[s[i] - 65]++;
    else if (s[i] >= 97 && s[i] <= 122)
      count[s[i] - 97]++;
    else if (s[i] == 32)
      count[SPACE]++;
    else if (s[i] == 33)
      count[EXCLA]++;
    else if (s[i] == 39)
      count[APOS]++;
    else if (s[i] == 44)
      count[COMMA]++;
    else if (s[i] == 46)
      count[PERIOD]++;
    else if (s[i] == 63)
      count[QUES]++;
    else
      count[ELSE]++;
  }

  for(i = 0; i < 33; i++){
    if (i <= 25)
      printf("%c: %d\n", i+97, count[i]);
    else if (i == SPACE)
      printf("%c: %d\n", 32, count[i]);
    else if (i == EXCLA)
      printf("%c: %d\n", 33, count[i]);
    else if (i == APOS)
      printf("%c: %d\n", 39, count[i]);
    else if (i == COMMA)
      printf("%c: %d\n", 44, count[i]);
    else if (i == PERIOD)
      printf("%c: %d\n", 46, count[i]);
    else if (i == QUES)
      printf("%c: %d\n", 63, count[i]);
    else if (i == ELSE)
      printf("Other characters: %d\n", count[i]);
  }
}


int main(void) {
  int a[] = {10,4,5,-2};
  printArray(a, 4);
  upperCaseSecondA();
  textData();

  return 0;
}
