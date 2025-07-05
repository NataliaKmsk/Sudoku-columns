/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:56 by emurbane          #+#    #+#             */
/*   Updated: 2025/07/05 18:04:14 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>

int	is_valid(char *input)
{
	int	i;

	i = 0;
	int count_chars = 0;
	
	while ( input[i] != '\0')
	{
		if (!(input[i] == ' ' || (input[i] >= '1' && input[i] <= '4')))
		{
			return (0);
		}
		if (input[i] >= '1' && input[i] <= '4')
			count_chars++;
		i ++;
	}
	if (count_chars == 16 && i == 31)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	**init(char *input)
{
	int		i;
	int		j;
	char	**digits;

	i = 0;
	j = 0;
	digits = malloc(16 * sizeof(char *));
	if (!digits)
		write(1, "Error :couldn't allocate memory", 32);
	while (input[i] != '\0' && j < 16)
	{
		if (input [i] != ' ')
			digits[j++] = &input[i];
		i ++;
	}
	//digits[16] = '\0';
	int k  =0;
	while ( k <16)
	{
		write(1, digits[k], 1);
		k ++;
	}

	write(1, "\n", 1);
	return (digits);
}
char	***assign(char **digits)
{
	char	***table;
	/*char	*coltop;
	char	*colbottom;
	char	*rowleft;
	char	*rowright;*/
	int	i;
	int	j;

	i = 0;
	table = malloc(4 * sizeof(char **));
	/*coltop = (char *)malloc(5);
	colbottom = (char *)malloc(5);
	rowleft = (char *)malloc(5);
	rowright = (char *)malloc(5);*/

	while ( i < 4)
	{
		table[i] = malloc(4 * sizeof(char *));
		j = 0;
		while (j < 4)
		{
			table[i][j] = digits[i * 4 + j];
			j ++;
		}
		i ++;
	}
	int k =0;
	int l =0;
	while(k < 4)
	{
		l = 0;
		while(l < 4)
		{
			write(1, table[k][l],1);
			l ++;
		}
		write(1, table[k], 4);
		k ++;
	}
	return table;

	/*write(1, coltop,4);
	write(1, colbottom, 4);
	write(1, rowleft, 4);
	write(1, rowright, 4);*/
}
void	initialize(char *input)
{
	char	**digits;
	char	***groups;
	
	digits = init(input);
	groups = assign(digits);
	free(digits);
}
