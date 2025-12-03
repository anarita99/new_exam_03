/*Assignment name  : rip
Expected files   : *.c *.h
Allowed functions: puts, write
--------------------------------------------------------------------------------

Write a program that will take as argument a string containing only parenthesis.
if the parenthesis are unbalanced (for example "())")
your program shall remove the minimum number of parentheses for the expression to be balanced.
By removing we mean replacing by spaces.
You will then print all the solutions (can be more than one).

The order of the solutions is not important.

For example this should work:
$> ./rip '(()' | cat -e
 ()$
( )$
$> ./rip '((()()())())' | cat -e
((()()())())$
$> ./rip '()())()'| cat -e
()() ()$
()( )()$
( ())()$
$> ./rip '(()(()(' | cat -e
(()  ) $
( )( ) $
( ) () $
 ()( ) $*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A função recursiva
// s: string original
// res: string que estamos a construir com espaços
// i: índice atual
// bal: balanço atual ( ( = +1, ) = -1 )
// l_rem: quantos '(' ainda precisamos remover
// r_rem: quantos ')' ainda precisamos remover
void	solve(char *s, char *res, int i, int bal, int l_rem, int r_rem)
{
	// CASO BASE: Chegámos ao fim da string
	if (s[i] == '\0')
	{
		// Só imprimimos se o balanço for 0 (equilibrado)
		// E se já removemos tudo o que era suposto remover
		if (bal == 0 && l_rem == 0 && r_rem == 0)
			puts(res);
		return;
	}

	// --- OPÇÃO A: Tentar MANTER o caracter atual ---
	// Copiamos o char original para o resultado
	res[i] = s[i];

	if (s[i] == '(')
		solve(s, res, i + 1, bal + 1, l_rem, r_rem); // Balanço sobe
	else if (s[i] == ')')
	{
		// Só podemos manter um ')' se o balanço for positivo (houver um '(' antes)
		if (bal > 0)
			solve(s, res, i + 1, bal - 1, l_rem, r_rem); // Balanço desce
	}
	else
		solve(s, res, i + 1, bal, l_rem, r_rem); // Outros chars (se existissem)

	// --- OPÇÃO B: Tentar REMOVER (transformar em ESPAÇO) ---
	// Só entramos aqui se ainda tivermos stock de parênteses para remover

	if (s[i] == '(' && l_rem > 0)
	{
		res[i] = ' '; // Vira espaço
		solve(s, res, i + 1, bal, l_rem - 1, r_rem); // Decrementa l_rem
	}
	else if (s[i] == ')' && r_rem > 0)
	{
		res[i] = ' '; // Vira espaço
		solve(s, res, i + 1, bal, l_rem, r_rem - 1); // Decrementa r_rem
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	// Variáveis para a Fase 1 (Contagem)
	int l_rem = 0;
	int r_rem = 0;
	int balance = 0;
	int i = 0;

	// FASE 1: Calcular quantos estão a mais
	while (av[1][i])
	{
		if (av[1][i] == '(')
			balance++;
		else if (av[1][i] == ')')
		{
			if (balance > 0)
				balance--; // Este ')' casou com um '(' anterior
			else
				r_rem++;   // Este ')' está a mais (não tem par)
		}
		i++;
	}
	// No fim, se o balance for positivo, sobraram '(' sem par
	l_rem = balance;

	// Preparar o buffer de resultado (mesmo tamanho da original)
	char *res = malloc(sizeof(char) * (strlen(av[1]) + 1));
	res[strlen(av[1])] = '\0';

	// FASE 2: Recursão
	solve(av[1], res, 0, 0, l_rem, r_rem);

	free(res);
	return (0);
}