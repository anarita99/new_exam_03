#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_results(char **grid)
{
	int i = 0;
	int j = 0;
	while(grid[i])
	{
		j = 0;
		while(grid[i][j])
		{
			if(grid[i][j] == '1')
				printf("%d", j);
			j++;
		}
		if(grid[i][j] == '\0')
			printf(" ");
		i++;
	}
	printf("\n");
}

int check_d(char **grid, int x, int y, int add_x)
{
	int new_y = y - 1;
	int new_x = x + add_x;
	if(new_x < 0 || new_y < 0)
		return 1;
	if(grid[new_y][new_x] == '\0')
		return 1;
	if(grid[new_y][new_x] == '1')
		return 0;
	return (check_d(grid, new_x, new_y, add_x));
}

int is_valid(char **grid, int y, int x)
{
	int i = y - 1;
	while(i >= 0)
	{
		if(grid[i][x] == '1')
			return 0;
		i--;
	}
	return(check_d(grid, x, y, -1) && check_d(grid, x, y, 1));
}

void	n_queens(char **grid, int y)
{
	int x = 0;
	if(grid[y] == NULL)
		print_results(grid);
	else
	{
		while(grid[y][x])
		{
			if(is_valid(grid, y, x))
			{
				grid[y][x] = '1';
				n_queens(grid, y + 1);
				grid[y][x] = '0';
			}
			x++;
		}
	}
}

void free_grid(char **grid)
{
	int i = 0;
	while(grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	int grid_size = atoi(av[1]);
	char **grid = calloc(grid_size + 1, sizeof(char *));
	int i = 0;
	int j = 0;
	while(i < grid_size)
	{
		grid[i] = calloc(grid_size + 1, sizeof(char));
		if(!grid)
			return(free_grid(grid), 1);
		j = 0;
		while(j < grid_size)
		{
			grid[i][j] = '0';
			j++;
		}
		i++;
	}
	grid[grid_size] = NULL;
	n_queens(grid, 0);
	free(grid);
	return (0);
}