/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	int cnt=0,i=0;
	if (str == '\0') return '\0';
	while (str[i] != '\0')
	{
		if (str[i] == ' '){
			i++;
			continue;
		}
		str[cnt] = str[i];
		cnt++;
		i++;
	}
	str[cnt] = '\0';
	return '\0';
}