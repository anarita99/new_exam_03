#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_set(int *set, int size)
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

void find_set(int *nums, int *set, int size, int soma, int index, int set_index, int target)
{
	int next_soma;
	int i = index;
	while(i < size)
	{
		next_soma = soma + nums[i];
		set[set_index] = nums[i];
		if(next_soma == target)
			print_set(set, set_index + 1);
		find_set(nums, set, size, next_soma, i + 1, set_index + 1, target);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac < 3)
		return 0;
	int target = atoi(av[1]);
	int size = ac - 2;
	int *nums = malloc(sizeof(int) * size);
	int *set = malloc(sizeof(int) * size);
	int i = 0;
	while(i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if(target == 0)
		printf("\n");
	find_set(nums, set, size, 0, 0, 0, target);
	free(nums);
	return 0;
}