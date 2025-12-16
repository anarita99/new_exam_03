#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac != 2 || av[1] == NULL)
		return 1;
	char str[1000000];
	size_t i = 0;
	int read_res = 1;
	while(read_res > 0)
	{
		read_res = read(0, &str[i], 1);
		if(read_res == - 1)
		{
			perror("Error: ");
			return 0;
		}
		i++;
	}
	str[i] = '\0';
	char *find = "";
	while(find != NULL)
	{
		i = 0;
		find = memmem(str, strlen(str), av[1], strlen(av[1]));
		if(find != NULL)
		{
			while(i < strlen(av[1]))
			{
				find[i] = '*';
				i++;
			}
		}
		i++;
	}
	printf("%s", str);
	return 0;
}


//cc -Wall -Wextra -Werror filter6.c
//echo 'abcdefgaaaabcdefabc' | ./a.out abc | cat -e