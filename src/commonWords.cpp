/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
int length(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)return NULL;
	int len1, len2, max = 0, i, j, k, p;
	char * result = (char *)calloc(1000, sizeof(char));
	len1 = length(str1);
	len2 = length(str2);
	for (i = 0; i < len1;i++)
	if (str1[i] == ' ')str1[i] = '\0';
	for (i = 0; i < len2; i++)
	if (str2[i] == ' ')str2[i] = '\0';
	int **match = (int **)calloc(len1, sizeof(int *));
	for (i = 0; i<len1; i++)
		match[i] = (int *)calloc(len2, sizeof(int));
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)match[i][j] = 1;
				else
				{
					match[i][j] = match[i - 1][j - 1] + 1;
				}
				if (match[i][j]>max)
				{
					max = match[i][j]; p = 0;
					for (k = i - max + 1; k <i + 1; k++)
					{
						result[p] = str1[k];
						p++;
					}
					result[p] = '\0';
				}
			}
			else match[i][j] = 0;
		}
	}
	if (p==0)return NULL;
	char **common=(char**)malloc(sizeof(char *));
	int index = 0; k = 0;
	for (i = 0; i < p; i++)
	{
		if (result[i]=='\0')
		{
			common = (char **)realloc(common, p+2);
			common[k] = (char*)malloc(length(&result[index])*sizeof(char));
			common[k] = &result[index];
			index = i + 1;
			k++;
		}
	}
	return common;
}