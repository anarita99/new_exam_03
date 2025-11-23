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

#define _GNU_SOURCE
#include <stdio.h>      // For printf, fprintf, stdout, stderr, perror
#include <stdlib.h>     // For malloc, calloc, realloc, free
#include <string.h>     // For strlen, memmem, memmove
#include <unistd.h>        // read

int	main(int argc, char **argv)
{
	char	str[1000000];
	int		read_result = 1;
	size_t		i = 0;

	if (argc != 2 || argv[1] == NULL)
		return (1);
	while (read_result > 0)
	{
		read_result = read(0, &str[i], 1);
		if (read_result == -1)
		{
 			perror("Error: ");
			return (1);
		}
		i++;
	}
	str[i]= '\0';
	char *find = "";
	while (find != NULL)
	{
		i = 0;
		find = memmem(str, strlen(str), argv[1], strlen(argv[1]));
		if(find != NULL)
		{
			 while (i < strlen(argv[1]))
			{
				find[i] = '*';
				i++;
			}
		}
	}
	return (printf("\nstr =%s", str) ,0);
}