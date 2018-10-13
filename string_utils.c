/*
 *Author(s): Collin Sipple, Victor Nguyen, Tony Ong
 *Date Created: 10/10/2018
 *Date Modified: 10/12/2018
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"string_utils.h"

void replaceChar(char *s, char oldChar, char newChar) {

  if(s == NULL) {
    return;
  }

  for(int i = 0; i < strlen(s); i++) {
    if(s[i] == oldChar) {
      s[i] = newChar;
    }
  }
  return;
}

char * replaceCharCopy(const char *s, char oldChar, char newChar) {
  
  if(s == NULL) {
	return NULL;
  }
  
  char *newString = (char *) malloc(sizeof(char) * (strlen(s) + 1));
  //TODO: Make sure to include space for null terminator
  for(int i = 0; i <= strlen(s); i++) {
	//First copy each element
	newString[i] = s[i];
	//Then check for replacement
	if(newString[i] == oldChar) {
	  newString[i] = newChar;
	}
  }
  return newString;
}

void removeChar(char *s, char c) {
  if(s == NULL) {
	return;
  }

  for(int i = 0; i < strlen(s); i++) {
	if(s[i] == c) {
	  for(int j = i; j < strlen(s); j++) {
		s[j] = s[j + 1];
	  }
      //Make sure that repeating characters are also removed	
      while(s[i] == c) {
		for(int j = i; j < strlen(s); j++) {
		  s[j] = s[j + 1];
	    }
	  }
	} else if(s[i] == '\0') {
	  for(int j = i; j < strlen(s); j++) {
		s[j] = '\0';
	  }
	}
  }
  return;
}

char * removeCharCopy(const char *s, char c) {
  if(s == NULL) {
	return NULL;
  }
  //Create a copy of a copy to save memory
  char *ptrString = replaceCharCopy(s, 'a', 'a');
  removeChar(ptrString, c);
  char *stringActual = replaceCharCopy(ptrString, 'a', 'a');
  free(ptrString);
  return stringActual;
}

char **lengthSplit(const char *s, int n) {
  if(s == NULL) {
	return NULL;
  }
  if(n == 0) {
	return NULL;
  }
  //First determine the number of strings(height of array)
  int strHeight = 1;
  int heightCounter = 0;
  for(int i = 0; i < strlen(s); i++) {
	heightCounter++;
	if(heightCounter >= n) {
	  heightCounter = 0;
	  strHeight++;
	}
  }
  char **strArray = (char **) malloc(sizeof(char *) * strHeight);
  for(int i = 0; i < strHeight; i++) {
	strArray[i] = (char *) malloc(sizeof(char) * (n + 1));
  }
  //Assign each character into each string
  int stringCounter = 0;
  for(int i = 0; i < strHeight; i++) {
	for(int j = 0; j <= n; j++) {
	  //Make a null terminator for each string
	  if(j == n) {
		strArray[i][j] = '\0';
	  } else if(stringCounter > strlen(s)) {
		strArray[i][j] = '\0';
	  } else {
	    strArray[i][j] = s[stringCounter];
	    stringCounter++;
	  }
	}
  }
  return strArray;
}