#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void	ft_putnbr(int n)
{
	char c;
	c = '0' + n;
	ft_putchar(c);
}

void	ft_atoi(char c)
{
	int n;
	n = c - '0';
}

int	fill_matrix(char *str, int *matrix)
{
	int i;
	int row;
	int col;
	int count;
	char temp;

	i = 0;
	row = 0;
	col = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '4')
		{
			matrix[row * 4 + col] = *str - '0';
			col++;
			if (col == 4)
			{
				col = 0;
				row++;
			}
			count++;
		}
		i++;
		str++;
	}
	if (count != 16)
		return (0);
	return (1);	
}

void	write_matrix(int *matrix)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putnbr(matrix[row * 4 + col]);
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	main(int argc, char **argv)
{
	int *matrix;
	
	argv++;
	matrix = malloc(4 * 4 * 4);
	if(!fill_matrix(*argv, matrix))
	{
		ft_putstr("Error\n");
		return (-1);
	}
	write_matrix(matrix);
	return (0);
}
