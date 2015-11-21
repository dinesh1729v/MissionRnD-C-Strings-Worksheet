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
int noWords(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	if (str[i] != ' ')return 0;
	return 1;
}
int length(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
int compare(char *a, char *b,int i , int j, int k, int l)
{
	int iter;
	for (iter = 0; iter <= (j - i);iter++)
	if (a[iter + i] != b[iter + k])return 0;
	return 1;
}

int noOfWords(char *s)
{
	int i, cnt = 0;
	for (i = 0; s[i] != '\0'; i++)
	if (s[i] == ' ')
		cnt++;
	cnt++;
	return cnt;
}
void copy(char *s1, char *s2,int i,int j)
{
	int iter;
	for (iter = 0; iter <= (j - i); iter++)
		s1[iter] = s2[iter + i];
}
char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)return NULL;
	int len1, len2, i, j, k, l, nw1, nw2;
	if (noWords(str1) || noWords(str2))return NULL;
	len1 = length(str1);
	len2 = length(str2);
	nw1 = noOfWords(str1);
	int *a = (int *)calloc(nw1+1, sizeof(int));
	nw2 = noOfWords(str2);
	int *b = (int *)calloc(nw2+1, sizeof(int));
	a[nw1] = len1 + 1; b[nw2] = len2 + 1;
	j = 1;
	for (i = 0; i < len1; i++)if (str1[i] == ' ')a[j++] = i + 1;
	j = 1;
	for (i = 0; i < len2; i++)if (str2[i] == ' ')b[j++] = i + 1;
	char **common = (char **)calloc(10, sizeof(char *));
	for (i = 0; i < 10; i++)
		common[i] = (char *)calloc(SIZE, sizeof(char));
	for (i = 0,k=0; i < nw1; i++)
	{
		for (j = 0; j < nw2; j++)
		{
			if ((a[i + 1] - a[i]) == (b[j+1]-b[j]))
			if (compare(str1, str2, a[i], (a[i + 1] - 2), b[j], (b[j + 1] - 2)))
			{
				copy(common[k], str2, b[j], (b[j + 1] - 2));
				k++;
			}
		}
	}
	if (k == 0)return NULL;
	return common;
}
	/*char *str1,*str2;
	if (s1 == NULL || s2 == NULL)return NULL;
	int len1, len2, i, j, nw1=5, nw2=2, k;
	if (noWords(s1) || noWords(s2))return NULL;
	len1 = length(s1);
	len2 = length(s2);
	str1 = (char *)calloc(len1, sizeof(char));
	str2 = (char *)calloc(len2, sizeof(char));
	copy(str1, s1); copy(str2, s2);
	nw1 = noOfWords(str1);
	int *a = (int *)calloc(nw1, sizeof(int));
	nw2 = noOfWords(str2);
	int *b = (int *)calloc(nw2, sizeof(int));
	/*j = 1;
	for (i = 0; i < len1; i++)if (str1[i] == '\0')a[j++] = i + 1;
	j = 1;
	for (i = 0; i < len2; i++)if (str2[i] == '\0')b[j++] = i + 1;
	char **common = (char **)calloc(10,sizeof(char *));
	for (i = 0; i < 10; i++)
	common[i] = (char *)calloc(SIZE, sizeof(char));
	k = 0;
	for (i = 0; i < nw1; i++)
	{
		for (j = 0; j < nw2; j++)
		{
			if (compare(&str1[a[i]], &str2[b[j]]) == 1)
			{
				//common[k] = (char *)calloc(SIZE+1, sizeof(char));
				common[k] = &str2[b[j]];
				k++;
				break;
			}
		}
		if (k == nw1 || k == nw2)break;
	}
	if (k == 0)return NULL;
	return common;*/

/*
int compare(char *a, char *b,int i , int j, int k, int l)
{

	int i = 0, len1 = length(a), len2 = length(b);
	if (len1 != len2)return 0;
	for (i = 0; i < len1; i++)
	if (a[i] != b[i])return 0;
	return 1;
}
*/

/*
void copy(char *s1, char *s2,int i,int j)
{
	int i = 0;
	while (s2[i]!='\0')
	{
		s1[i] = s2[i];
		i++;
	}
}

*/