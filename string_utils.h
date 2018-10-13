/*
 *Author(s): Collin Sipple, Victor Nguyen, Tony Ong
 *Date Created: 10/10/2018
 *Date Modified: 10/12/2018
 *Purpose: Provide functions that copies, modifies, and produces strings from
 *given arrays (namely strings)
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Replaces a given character in a string with another one.
void replaceChar(char *s, char oldChar, char newChar);

//Deep copies a string, but replaces a certain character with another.
char * replaceCharCopy(const char *s, char oldChar, char newChar);

//Removes characters from a string, making all char shift down
void removeChar(char *s, char c);

//Deep copies a string, but performs removeChar() on the copy
//Returns a shortened copy of a copy of the original string using removeChar()
char * removeCharCopy(const char *s, char c);

//Returns an array of strings(where each row is its own string) where
//Each string length is determined by n, with some stragglers
char **lengthSplit(const char *s, int n);