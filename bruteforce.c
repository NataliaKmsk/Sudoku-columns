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

//Sprawdzanie kombinacji
int try_combinations(char **perms, char *clues)
{
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
						return (1);  // znaleziono rozwiązanie
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (0); // Brak rozwiazania
}
// Możliwości
void solve(char *clues)
{
	char *perms[24] = {
		"1234", "1243", "1324", "1342", "1423", "1432",
		"2134", "2143", "2314", "2341", "2413", "2431",
		"3124", "3142", "3214", "3241", "3412", "3421",
		"4123", "4132", "4213", "4231", "4312", "4321"
	};

	if (!try_combinations(perms, clues))
		write(1, "Error", 5);
}
//Funkcja pomocnicza
int count_visible(char *line)
{
	int max_height = 0;
	int visible = 0;
	int i = 0;

	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible++;
		}
		i++;
	}
	return visible;
}
// Sprawdzanie widocznosci
int check_clues(char grid[4][4], char *clues)
{
	int i;
	char line[4];

	// Sprawdzamy wskazówki z góry i dołu (kolumny)
	i = 0;
	while (i < 4)
	{
		// Z góry
		line[0] = grid[0][i];
		line[1] = grid[1][i];
		line[2] = grid[2][i];
		line[3] = grid[3][i];
		if (clues[i] != '0' && count_visible(line) != (clues[i] - '0'))
			return 0;

		// Z dołu (odwrócone)
		line[0] = grid[3][i];
		line[1] = grid[2][i];
		line[2] = grid[1][i];
		line[3] = grid[0][i];
		if (clues[i + 4] != '0' && count_visible(line) != (clues[i + 4] - '0'))
			return 0;

		i++;
	}

	// Sprawdzamy wskazówki z lewej i prawej (wiersze)
	i = 0;
	while (i < 4)
	{
		// Z lewej
		line[0] = grid[i][0];
		line[1] = grid[i][1];
		line[2] = grid[i][2];
		line[3] = grid[i][3];
		if (clues[i + 8] != '0' && count_visible(line) != (clues[i + 8] - '0'))
			return 0;

		// Z prawej (odwrócone)
		line[0] = grid[i][3];
		line[1] = grid[i][2];
		line[2] = grid[i][1];
		line[3] = grid[i][0];
		if (clues[i + 12] != '0' && count_visible(line) != (clues[i + 12] - '0'))
			return 0;

		i++;
	}
	return 1;
}
