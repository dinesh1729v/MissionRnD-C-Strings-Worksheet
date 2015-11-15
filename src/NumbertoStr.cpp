/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

long long int Mypow(int n)
{
	int i,pow=1;
	for (i = 0; i < n; i++)pow *= 10;
	return pow;
}
int reverse(int n)
{
	int rev = 0;
	while (n>0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}
void number_to_str(float number, char *str, int afterdecimal){

	int num_before, i=0;
	if (number < 0)
	{
		number *= -1.0f;
		str[0] = '-';
		i = 1;
	}
	int  num_after;
	num_before = (int)number;
	num_after = ((number - float(num_before))*Mypow(afterdecimal));
	num_before=reverse(num_before);
	num_after=reverse(num_after);
	while (num_before > 0)
	{
		str[i] = (num_before % 10) + 48;
		num_before /= 10;
		i++;
	}
	if (afterdecimal > 0)
	{
		str[i] = '.';
		i++;
		while (num_after > 0)
		{
			str[i] = (num_after % 10) + 48;
			num_after /= 10;
			i++;
		}
		str[i] = '\0';
	}
}
