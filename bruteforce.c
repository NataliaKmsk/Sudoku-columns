//Kopiowanie znakow z tablicy z src do dest
void	copy_row(char *dest, char *src)
{
	int i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

//Macierz 4x4 / Sprawdzanie unikalnosci liczb
int	is_column_unique(char grid[4][4])
{
	int col = 0;
	while (col < 4)
	{
		int row = 0;
		while (row < 4)
		{
			int check = row + 1;
			while (check < 4)
			{
				if (grid[row][col] == grid[check][col])
					return (0);
				check++;
			}
			row++;
		}
		col++;
	}
	return (1);
}
void	solve(char *clues)
{
	char *perms[24] = {
		"1234", "1243", "1324", "1342", "1423", "1432",
		"2134", "2143", "2314", "2341", "2413", "2431",
		"3124", "3142", "3214", "3241", "3412", "3421",
		"4123", "4132", "4213", "4231", "4312", "4321"
	};
	char grid[4][4];
	int i = 0;
	while (i < 24)
	{
		int j = 0;
		while (j < 24)
		{
			int k = 0;
			while (k < 24)
			{
				int l = 0;
				while (l < 24)
				{
					copy_row(grid[0], perms[i]);
					copy_row(grid[1], perms[j]);
					copy_row(grid[2], perms[k]);
					copy_row(grid[3], perms[l]);

					if (is_column_unique(grid) && check_clues(grid, clues))
					{
						print_grid(grid);
						return ;
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	write(1, "Error", 6);
}
