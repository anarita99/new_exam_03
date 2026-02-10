#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void solve(char *res, char *s, int i, int lrem, int rrem, int bal)
{
	if(s[i] == '\0')
	{
		if(bal == 0 && lrem == 0 && rrem == 0)
			puts(res);
		return ;
	}
	res[i] = s[i];
	if(s[i] == '(')
		solve(res, s, i + 1, lrem, rrem, bal + 1);
	else if(s[i] == ')')
	{
		if(bal > 0)
			solve(res, s, i + 1, lrem, rrem, bal - 1);
	}
	else
		solve(res, s, i + 1, lrem, rrem, bal);
	if(s[i] == '(' && lrem > 0)
	{
		res[i] = ' ';
		solve(res, s, i + 1, lrem - 1, rrem, bal);
	}
	else if(s[i] == ')' && rrem > 0)
	{
		res[i] = ' ';
		solve(res, s, i + 1, lrem, rrem - 1, bal);
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
		else if(av[1][i] == ')')
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
	char *res = malloc((strlen(av[1]) + 1) * sizeof(char));
	res[strlen(av[1])] = '\0';
	solve(res, av[1], 0, lrem, rrem, 0);
	return 0;
}

//cc -Wall -Wextra -Werror rip4.c
//./a.out '(()(()(' | cat -e