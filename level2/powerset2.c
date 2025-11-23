#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_sets(int *set, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d", set[i]);
		if(i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void find_set(int *nums, int size, int soma, int *set, int set_index, int index, int target)
{
	int next_soma = 0;
	int	i = index;
	while(i < size)
	{
		next_soma = soma + nums[i];
		set[set_index] = nums[i];
		if(next_soma == target)
			print_sets(set, set_index + 1);
		find_set(nums, size, next_soma, set, set_index + 1, i + 1, target);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac < 3)
		return 1;
	int size = ac -2;
	int *nums = malloc(sizeof(int) * size);
	int *set = malloc(sizeof(int) * size);
	int soma = 0;
	int i = 0;
	int target = atoi(av[1]);
	while(i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if(target == 0)
		printf("\n");
	find_set(nums, size, soma, set, 0, 0, target);
	free(set);
	free(nums);
	return (0);
}