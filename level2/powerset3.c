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

void find_sets(int *nums, int *set, int sum, int size, int index, int set_index, int target)
{
	int next_soma;
	int i = index ;

	while(i < size)
	{
		next_soma = nums[i] + sum;
		set[set_index] = nums[i];
		if(next_soma == target)
			print_sets(set, set_index + 1);
		find_sets(nums, set, next_soma, size, i + 1, set_index + 1, target);
		i++;
	}
}

int main(int ac, char **av)
{
	
	if(ac < 3)
		return 1;
	int size = ac - 2;
	int *nums = malloc(sizeof(int) * size);
	int *set = malloc(sizeof(int) * size);
	int target = atoi(av[1]);
	int i = 0;
	int soma = 0;

	while(i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if(target == 0)
		printf("\n");
	find_sets(nums, set, soma, size, 0, 0, target);
	free(set);
	free(nums);
	return 0;
}
