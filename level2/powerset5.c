#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

void	find_set(int *nums, int *set, int sum, int size, int index, int set_index, int target)
{
	int i = index;
	int next_sum = 0;
	while(i < size)
	{
		next_sum = sum + nums[i];
		set[set_index] = nums[i];
		if(next_sum == target)
			print_set(set, set_index + 1);
		find_set(nums, set, next_sum, size, i + 1, set_index + 1, target);
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
	while(i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	find_set(nums, set, 0, size, 0, 0, target);
	return (0);
}

//./a.out 12 5 2 1 8 4 3 7 11 | cat -e