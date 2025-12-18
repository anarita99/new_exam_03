#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void swap_s(char **a, char **b)
{
	char *temp = *a;
	*a = *b;
	*b = temp;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

char *ft_strdup(char *s)
{
	char *t = malloc((strlen(s) + 1) * sizeof(char));
	int i = 0;
	while(s[i] != '\0')
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

int ft_strcmp(char *s1, char *s2)
{
	if(!s1 || !s2)
		return 0;
	int i = 0;
	while(s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void sort(char **m)
{
	int n = 0;
	while(m[n])
		n++;
	int gap = n;
	int trocas = 1;
	int i;
	while(gap > 1 || trocas == 1)
	{
		gap = (gap * 10) / 13;
		if(gap < 1)
			gap = 1;
		trocas = 0;
		i = 0;
		while(m[i + gap])
		{
			if(ft_strcmp(m[i], m[i + gap]) > 0)
			{
				swap_s(&m[i], &m[i + gap]);
				trocas = 1;
			}
			i++;
		}
	}
}

void perm(char **m, char *s, int l, int r)
{
	if(l == r)
	{
		int i = 0;
		while(m[i])
			i++;
		m[i] = ft_strdup(s);
	}
	else
	{
		int i = l;
		while(i <= r)
		{
			swap((s + l), (s + i));
			perm(m, s, l + 1, r);
			swap((s + l), (s + i));
			i++;
		}
	}
}

int fac(char *s)
{
	int i = 0;
	int res = 1;
	while(s[i])
	{
		res *= (i + 1);
		i++;
	}
	return res;
}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	int l = 0;
	char *s = av[1];
	int r = strlen(s) - 1;
	char **m = malloc((fac(s) + 1) * sizeof(char *));
	if (!m)
		return 1;
	perm(m, s, l, r);
	sort(m);
	int i = 0;
	while(m[i])
	{
		puts(m[i]);
		free(m[i]);
		i++;
	}
	free(m);
	return(0);
}