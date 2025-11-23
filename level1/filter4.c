#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char	str[10000];
	int		read_ret = 1;
	int		i = 0;
	size_t	j;
	char	*find = "";

	if (ac != 2 || av[1] == NULL)
		return 1;
	while (read_ret > 0)
	{
		read_ret = read(0, &str[i], 1);
		if (read_ret == -1)
		{
			perror("Error: ");
			return 1;
		}
		i++;
	}
	str[i] = '\0';
	while(find != NULL)
	{
		j = 0;
		find = memmem(str, strlen(str), av[1], strlen(av[1]));
		if(find != NULL)
		{
			while(j < strlen(av[1]))
			{
				find[j] = '*';
				j++;
			}
		}
		j++;
	}
	return(printf("%s", str), 0);
}