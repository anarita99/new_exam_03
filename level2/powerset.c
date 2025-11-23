/*Assignment name  : powerset
Expected files   : *.c *.h
Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write
--------------------------------------------------------------------------------

Write a program that will take as argument an integer n followed by a set s of
distinct integers.
Your program should display all the subsets of s whose sum of elements is n.

The order of the lines is not important, but the order of the elements in a subset is:
it must match the order in the initial set s.
This way, you should not have any duplicates (eg: '1 2' and '2 1').
For example, using the command ./powerset 5 1 2 3 4 5
this output is valid:
1 4
2 3
5
this one is also valid:
2 3
5
1 4
but not this one:
4 1
3 2
5


In case of a malloc error your program will exit with the code 1.

We will not test with invalid sets (for example '1 1 2').

Hint: the empty subset is a valid subset of any set. It will be displayed as an empty line.

For example this should work:
$> ./powerset 3 1 0 2 4 5 3 | cat -e
3$
0 3$
1 2$
1 0 2$
$> ./powerset 12 5 2 1 8 4 3 7 11 | cat -e
8 4$
1 11$
1 4 7$
1 8 3$
2 3 7$
5 7$
5 4 3$
5 2 1 4$
$> ./powerset 0 1 -1 | cat -e
$
1 -1$
$> ./powerset 7 3 8 2 | cat -e

// Other tests:
$> ./powerset 100 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 | cat -e
...
$> ./powerset -1 1 2 3 4 5 -10 | cat -e
...
$> ./powerset 0 -1 1 2 3 -2 | cat -e
...
$> ./powerset 13 65 23 3 4 6 7 1 2 | cat -e
...
$> ./powerset 10 0 1 2 3 4 5 6 7 8 9 | cat -e
...
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_set (int *set, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d", set[i]);
		if (i < size - 1)
		{
			printf(" ");
		}
		i++;
	}
	printf("\n");
}

void	find_sets(int size, int *nums, int soma, int *set, int set_index, int index, int target)
{
	int i = index;

	while (i < size)
	{
		int next_soma = soma + nums[i];
		set[set_index] = nums[i];
		if (next_soma == target)
			print_set(set, set_index + 1);
		find_sets(size, nums, next_soma, set, set_index + 1, i + 1, target);
		i++;
	}
}

int main (int ac, char **av)
{
	int n = ac - 2;
	int soma = 0;
	int *nums = malloc (sizeof (int) * n);
	int *set = malloc (sizeof(int) * n);
	int i = 0;
	int target = atoi(av[1]);

	if (ac < 3)
		return 1;
	while (i < n)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if (target == 0)
		printf("\n");
	find_sets(n, nums, soma, set, 0, 0, target);
	free (set);
	free (nums);
	return 0;
}

