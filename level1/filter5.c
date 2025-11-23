#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int read_ret = 1;
	char str[1000000];
	size_t i = 0;
	char *find = "";

	if(ac != 2 || av[1] == NULL)
	{
		printf("erro");
		return 1;
	}
		
	while(read_ret > 0)
	{
		read_ret = read(0, &str[i], 1);
		if(read_ret == -1)
		{
			perror("Error: ");
			return 1;
		}
		i++;
	}
	str[i] = '\0';

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
	}
	return (printf("\nstr =%s", str) ,0);
}