/*Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$*/

#include <stdio.h>
#include <stdlib.h>
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
	char *t = calloc(strlen(s) + 1,  sizeof (char));
    int i = 0;
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
    
    if (!s1 || !s2)
        return 0;
    while(s1[i])
    {
        if(s1[i] != s2[i])
            return(s1[i] > s2[i]);
        i++;
    }
    return(0);
}


void sort(char **m)
{
    int i = 0;
    int j = 0;
    while(m[i])
    {
        j = i + 1;
        if (compare(m[i], m[j]))
            swap_s(&m[i], &m[j]);
        i++;
    }
}



void permutations(char **m, char *s, int l, int r)
{
    if(l == r)
    {
        int j = 0;
        while(m[j])
            j++;
        m[j] = ft_strdup(s);
    }
    else
    {
        int i = l;
        while (i <= r)
        {
            printf("charecter 1 (%c)\n", s[l]);
            printf("charecter 1 (%c)\n", s[i]);
            swap((s + l), (s + i));
            permutations(m, s, l + 1, r);
            swap((s + l), (s + i));
            i++;
        }
    }
}


int fac(char *s)
{
    int i = 0;
    int ret = 1;
    
    while(s[i])
    {
        ret *= (i + 1);
        i++;
    }
    return(ret);
}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	char *s = av[1];
    char **m = calloc(fac(s) + 1, sizeof(char *));
    int i = 0;
    permutations(m, s, 0 , strlen(s) - 1);
    sort(m);
    while(m[i])
    {
        printf("%s\n", m[i]);
        i++;
    }
    return 0;
}