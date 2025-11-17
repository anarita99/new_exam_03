/*filter:
Allowed functions: read, strlen, malloc, calloc, realloc, free, printf, perror
------------------------------------------------------------------------------

Write a programm that will take one and only one argument s.

Your programm will then read from stdin and write all the content read in stdout
except that every occurence of s must be replaced by '*'.

For example :

./filter bonjour
will behave the same way as:
*/
//sed 's/bonjour/*******/g'

/*
in case of error during read or a malloc you must write "Error: " followed by
the error message in stderr and return 1.

$> echo 'abcdefgaaaabcdefabc' | ./filter abc | cat -e
***defgaaa***def***

If the program is called whitout argument or with an empty argument or with
multiples arguments it must return 1.*/

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char	str[10000000];
	int		read_bytes;
	int		check;
	int		i;
	int		j;

	if (ac != 2)
		return (1);
	check = 1;
	read_bytes = 0;
	while(check > 0)
	{
		check = read(0, &str[read_bytes], 1);
		if (check < 0)
			return(perror("Error: "), 1);
		read_bytes++;
	}
	str[read_bytes] = '\0';
	i = 0;
	while(str)
	{
		j = 0;
		if(str[i + j] == av[1][j])
			while(str[i + j] == av[1][j])
				j++;
		if (av[1][j] == '\0')
		{
			while(j > 0)
			{
				str[i] = '*';
				i++;
				j--;
			}
		}
		else
			i++;
	}
	printf("%s", str);
	return (0);
}