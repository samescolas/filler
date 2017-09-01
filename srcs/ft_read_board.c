/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:59:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:36:39 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_read_board(char ***board, size_t rows, int first)
{
	char	*input;
	int		i;
	int		seeking;

	seeking = 1;
	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		if (ft_strncmp(input, "Plateau", 7) == 0)
		{
			if (ft_flush_lines(1) < 0 ||
							get_next_line(STDIN_FILENO, &input) < 0)
				return (-1);
		}
		if (seeking && !first && ft_strcmp((*board)[i], &input[4]) != 0)
		{
			seeking = 0;
		}
		(*board)[i] = ft_strdup(&input[4]);
		ft_strdel(&input);
	}
	return (0);
}
