/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:06:58 by emurbane          #+#    #+#             */
/*   Updated: 2025/07/05 15:14:52 by emurbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#include <stdlib.h>

void	initialize(char *input);

int	is_valid(char *input);

int	main(int argc, char **argv)
{
	char	*input;

	input = argv[1];
	if (argc != 2)
	{
		write(1, "invalid input", 13);
		return (1);
	}
	if (is_valid(input))
	{
		initialize(input);
	}
	else
	{
		write(1, "Error", 5);
		return 1;
	}
	return (0);
}
