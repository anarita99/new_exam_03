#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_set(int *set, int size)
{
	int	i = 0;
	while(i < size)
	{
		printf(" ");
		if(i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void find_set(int size, int soma, int *nums, int *set, int index, int set_index, int target)
{
	int next_soma = 0;
	int i = index;
	while (i < size)
	{
		next_soma = nums[i] + soma;
		set[set_index] = nums[i];
		if(next_soma == target)
			print_set(set, set_index + 1);
		find_set(size, next_soma, nums, set, i + 1, set_index + 1, target);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac < 3)
		return 1;
	int size = ac - 2;
	int soma = 0;
	int *nums = malloc(sizeof(int) * size);
	int *set = malloc(sizeof(int) * size);
	int i = 0;
	int target = atoi(av[1]);
	while(i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if (target == 0)
		printf("\n");
	find_set(size, soma, nums, set, 0, 0, target);
	free(set);
	free(nums);
	return(0);
}