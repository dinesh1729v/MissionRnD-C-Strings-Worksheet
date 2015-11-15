/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void myRev(char *s, int i, int j)
{
	char temp;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++; j--;
	}
}
void str_words_in_rev(char *input, int len){
	int i,index=0;
	for (i = 0; i <= len; i++)
	{
		if (input[i] == ' ' || input[i] == '\0')
		{
			myRev(input, index, i-1);
			index = i + 1;
		}
	}
	myRev(input, 0, len - 1);
}
