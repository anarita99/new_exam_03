#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

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
	char *t = calloc((strlen(s) + 1),sizeof(char));
	if(!t)
		return NULL;
	int i = 0;
	while(s[i] != '\0')
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return t;
}

int ft_strcmp(char *s1, char *s2)
{
	if(!s1 || !s2)
		return 0;
	int i = 0;
	while(s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void sort(char **m)
{
    int n = 0;
    while(m[n]) 
		n++; // 1. Descobrir o tamanho total da lista

    int gap = n;     // O "gap" é o tamanho dos dentes do pente
    int trocas = 1;  // Para saber se mexemos em alguma coisa
    int i;

    // MUDANÇA 1: O loop principal muda.
    // Em vez de i++, fazemos enquanto o pente não for fino (gap > 1) 
    // OU enquanto houver trocas para fazer.
    while (gap > 1 || trocas == 1)
    {
        // MUDANÇA 2: Diminuir o pente.
        gap = (gap * 10) / 13;
        if (gap < 1) 
			gap = 1; // O pente mínimo é 1 (vizinho com vizinho)
        trocas = 0; // Reset
        i = 0;
        
        // MUDANÇA 3: O loop interno compara com o GAP, não com +1
        while (m[i + gap]) 
        {
            // O teu compare original funciona, mas o strcmp é melhor.
            // Se usares o teu compare, garante que retorna a diferença.
            if (ft_strcmp(m[i], m[i + gap]) > 0) 
            {
                swap_s(&m[i], &m[i + gap]);
                trocas = 1; // Marcamos que fizemos uma troca
            }
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

int main(int ac, char **av)
{
	if(ac != 2)
		return 0;
	char *s = av[1];
	char **m = calloc((fac(s) + 1), sizeof(char*));
	if(!m)
		return 1;
	perm(m, s, 0, strlen(s) - 1);
	sort(m);
	int i = 0;
	while(m[i])
	{
		puts(m[i]);
		free(m[i]);
		i++;
	}
	free(m);
	return 0;

}

// cc -Wall -Wextra -Werror perm6.c