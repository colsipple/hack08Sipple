/*
 *Author(s): Collin Sipple, Victor Nguyen
 *Date Created: 10/10/2018
 *Date Modified: 10/11/2018
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
	} else if(s[i] == '\0') {
	  for(int j = i; j < strlen(s); j++) {
		s[j] = '\0';
	  }
	}
  }
  
  return;
}

char * removeCharCopy(const char *s, char c);

char **lengthSplit(const char *s, int n);