#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char *s, char *res, int i, int lrem, int bal, int rrem)
{
	if(s[i] == '\0')
	{
		if(bal == 0 && lrem == 0 && rrem == 0)
			puts(res);
		return ;
	}
	res[i] = s[i];
	if(s[i] == '(')
		solve(s, res, i + 1, lrem, bal + 1, rrem);
	else if(s[i] == ')')
	{
		if(bal > 0)
			solve(s, res, i + 1, lrem, bal - 1, rrem);
	}
	else
		solve(s, res, i + 1, lrem, bal, rrem);
	if(s[i] == '(' && lrem > 0)
	{
		res[i] = ' ';
		solve(s, res, i + 1, lrem - 1, bal, rrem);
	}
	else if(s[i] == ')' && rrem > 0)
	{
		res[i] = ' ';
		solve(s, res, i + 1, lrem, bal, rrem - 1);
	}
}

int main(int ac, char **av)
{
	int i = 0;
	char *s = av[1];
	if(ac != 2)
		return 0;
	int lrem = 0;
	int rrem = 0;
	int bal = 0;
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
	solve(s, res, 0, lrem, 0, rrem);
	free(res);
	return 0;
}