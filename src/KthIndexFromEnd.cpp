/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<stdlib.h>
char KthIndexFromEnd(char *str, int K) {
	if (str == NULL||K<0)return NULL;
	if ((str[K] == '\0' || str[K-1] == '\0')&&K>0)return '\0';
	for (int i = 0;;i++)
	if (str[i + K + 1] == '\0')return str[i];
}