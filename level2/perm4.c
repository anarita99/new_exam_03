#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void swap_s(char **a, char **b)
{
	char *tmp = *a;
	*a = *b;
	*b = tmp; 
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

char *ft_strdup(char *s)
{
	int i = 0;
	char *t = calloc(strlen(s) + 1, sizeof(char));
	if(!t)
		return NULL;
	while(s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return(t);
}

int compare(char *s1, char *s2)
{
	int i = 0;
	if(!s1 || !s2)
		return 0;
	while(s1[i] && s2[i])
	{
		if(s1[i] != s2[i])
			return (s1[i] > s2[i]);
		i++;
	}
	return (s1[i] > s2[i]);
}

void sort(char **m)
{
	int i = 0;
	int j;
	while(m[i])
	{
		j = 0;
		while(m[j] && m[j + 1])
		{
			if(compare(m[j], m[j + 1]))
				swap_s(&m[j], &m[j + 1]);
			j++;
		}
		i++;
	}
}

void permutations(char **m, char *s, int l, int r)
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
			swap((i + l), (s + i));
			permutations(m, s, i + 1, r);
			swap((i + l), (s + i));
			i++;
		}
	}
}

int fac(char *s)
{
	int i = 0;
	int res = 0;
	while(s[i])
	{
		res *= (i + 1);
		i++;
	}
	return (res);
}

int main(int ac, char **av)
{
	if(ac != 2)
		return NULL;
	char *s = av[1];
	char **m = calloc(fac(s) + 1, sizeof(char *));
	if(!m)
		return 1;
	int i = 0;
	permutations(m, s, 0, strlen(s) - 1);
	sort(m);
	while(m[i])
	{
		printf("%s\n", m[i]);
		free(m[i]);
		i++;
	}
	free(m);
	return 0;
}