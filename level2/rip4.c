#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	solve(char *s, char *res, int i, int bal, int lrem, int rrem)
{
	if(s[i] == '\0')
	{
		if(bal == 0 && lrem == 0 && rrem == 0)
			puts(res);
		return ;
	}
	res[i] = s[i];
	if(s[i] == '(')
		solve(s, res, i + 1, bal + 1, lrem, rrem);
	else if(s[i] == ')')
	{
		if (bal > 0)
			solve(s, res, i + 1, bal - 1, lrem, rrem);
	}
	else
		solve(s, res, i + 1, bal, lrem, rrem);
	if(s[i] == '(' && lrem > 0)
	{
		res[i] = ' ';
		solve(s, res, i + 1, bal, lrem - 1, rrem);
	}
	else if(s[i] == ')' && rrem > 0)
	{
		res[i] = ' ';
		solve(s, res, i + 1, bal, lrem, rrem - 1);
	}
}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	int i = 0;
	int bal = 0;
	int lrem = 0;
	int rrem = 0;
	while(av[1][i])
	{
		if(av[1][i] == '(')
			bal++;
		else if (av[1][i] == ')')
		{
			if(bal > 0)
				bal--;
			else
				rrem++;
		}
		i++;
	}
	if(bal > 0)
		lrem = bal;
	char *res = malloc(sizeof(char) * (strlen(av[1]) + 1));
	res[strlen(av[1])] = '\0';
	solve(av[1], res, 0, 0, lrem, rrem);
	free(res);
	return (0);
}

//
//./a.out '(()(()(' | cat -e