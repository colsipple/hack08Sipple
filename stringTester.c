/*
 *Author(s): Collin Sipple, Victor Nguyen, Tony Ong
 *Date Created: 10/10/2018
 *Date Modified: 10/12/2018
 *Purpose: Test the functions within the string_utils library
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"string_utils.h"
 
int main(int argc, char **argv) {

  //Test for function replaceChar()
  int numCases = 0;
  int casePassed = 0;
  char sampString[] = "Hello my dudes!";
  printf("Your sample string is:\n");
  printf("%s\n", sampString);
  //Test for correct usage
  numCases++;
  replaceChar(sampString, 'd', 'f');
  printf("Your string is now:\n");
  printf("%s\n", sampString);
  if(strcmp(sampString, "Hello my fufes!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected following string:\n", numCases);
	printf("Hello my fufes!\n");
  }
  //Test for NULL error
  numCases++;
  char *nullString = NULL;
  replaceChar(nullString, 'd', 'f');
  if(nullString == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected to return as NULL.\n", numCases);
  }
  //Test for no change
  numCases++;
  printf("Your current string is:\n");
  printf("%s\n", sampString);
  replaceChar(sampString, 'q', 'g');
  printf("Your string is now:\n");
  printf("%s\n", sampString);
  if(strcmp(sampString, "Hello my fufes!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected no change!\n", numCases);
  }
  
  //Test for function replaceCharCopy()
  //Test for correct usage
  numCases++;
  char *newString = replaceCharCopy(sampString, 'H', 'B');
  printf("Your new string reads:\n");
  printf("%s\n", newString);
  if(strcmp(newString, "Bello my fufes!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected following string!\n", numCases);
	printf("%s\n", newString);
  }
  //Test for NULL error
  numCases++;
  char *replaceNullS = replaceCharCopy(NULL, 'H', 'B');
  if(replaceNullS == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected to return NULL!\n", numCases);
  }
  //Test for no change
  numCases++;
  char *newNoChange = replaceCharCopy(sampString, 'q', 'g');
  printf("Your new string reads:\n");
  printf("%s\n", newNoChange);
  if(strcmp(newNoChange, "Hello my fufes!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected no change!\n", numCases);
  }
  
  //Test for function removeChar()
  //Test for correct usage
  numCases++;
  printf("Your string reads:\n");
  printf("%s\n", sampString);
  removeChar(sampString, 'e');
  printf("Your string now reads:\n");
  printf("%s\n", sampString);
  if(strcmp(sampString, "Hllo my fufs!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected following string:\n", numCases);
	printf("Hllo my fufs!\n");
  }
  //Test for NULL error
  char *removeNullS = NULL;
  numCases++;
  removeChar(removeNullS, 'E');
  if(removeNullS == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected to return NULL!\n", numCases);
  }
  //Test for no change
  numCases++;
  removeChar(sampString, 'e');
  printf("Your string now reads:\n");
  printf("%s\n", sampString);
  if(strcmp(sampString, "Hllo my fufs!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected no change!\n", numCases);
  }
  
  //Test for function removeCharCopy()
  //Test for correct usage
  numCases++;
  printf("Your first string says:\n");
  printf("%s\n", sampString);
  char *newRemoveCopy = removeCharCopy(sampString, 'l');
  printf("Your new copy says:\n");
  printf("%s\n", newRemoveCopy);
  if(strcmp(newRemoveCopy, "Ho my fufs!") == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected follwing string:\n", numCases);
	printf("Ho my fufs!\n");
  }
  //Test for NULL error
  numCases++;
  char *nullRemoveCopy = removeCharCopy(NULL, 'a');
  if(nullRemoveCopy == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
    printf("Case %d failed! Expected to return NULL.\n", numCases);
  }
  //Test for no change
  numCases++;
  char *testNoChangeRemove = removeCharCopy(sampString, 'e');
  printf("Your new string says:\n");
  printf("%s\n", testNoChangeRemove);
  if(strcmp(testNoChangeRemove, sampString) == 0) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected no change!\n", numCases);
  }
  
  //Test for function lengthSplit()
  //Test for correct usage
  char **splitArray = lengthSplit(sampString, 4);
  printf("Your string reads:\n");
  printf("%s\n", sampString);
  printf("Your new array looks like:\n");
  for(int i = 0; i < 4; i++) {
	printf("%s\n", splitArray[i]);
  }
  //Test for NULL error
  numCases++;
  char **nullSplitArray = lengthSplit(NULL, 3);
  if(nullSplitArray == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected to return NULL.\n", numCases);
  }
  //Test for n=0
  numCases++;
  char **zeroSplitArray = lengthSplit(sampString, 0);
  if(zeroSplitArray == NULL) {
	printf("Case %d passed!\n", numCases);
	casePassed++;
  } else {
	printf("Case %d failed! Expected to return NULL.\n", numCases);
  }
  printf("You passed %d out of %d cases.\n", casePassed, numCases);
  return 0;
}