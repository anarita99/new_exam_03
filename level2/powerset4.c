#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_set(int *set, int size)
{
	int	i = 0;
	while(i < size)
	{
		printf("%d", set[i]);
		if(i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void find_set(int *nums, int *set, int sum, int size, int index, int set_index, int target)
{
	int next_soma;
	int i = index;
	while(i < size)
	{
		next_soma = nums[i] + sum;
		set[set_index] = nums[i];
		if(next_soma == target)
			print_set(set, set_index + 1);
		find_set(nums, set, next_soma, size, i + 1, set_index + 1, target);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac < 3)
		return 1;
	int size = ac - 2;
	int sum = 0;
	int *nums = malloc(sizeof(int) * size);
	int *set = malloc(sizeof(int) * size);
	int i = 0;
	int target = atoi(av[1]);

	while(i < size)
	{
		nums[i] = atoi(av[i + 2]) ;
		i++;
	}
	if(av[1] == 0)
		printf("\n");
	find_set(nums, set, sum, size, 0, 0, target);
	free(nums);
	free(set);
	return 0;
}