/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:25:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 20:36:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_read_piece(char ***piece, size_t rows)
{
	char	*input;
	int		i;

	i = -1;
	while (++i < rows)
	{
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (-1);
		(*piece)[i] = input;
	}
	return (0);
}

static int	ft_get_piece_dims(t_coord *dims)
{
	char	*input;

	if (get_next_line(STDIN_FILENO, &input) < 0)
		return (-1);
	if (ft_strlen(input) > 6 && ft_isdigit(input[6]))
		dims->r = ft_atoi(&input[6]);
	else
		return (-1);
	if ((input = ft_strchr(&input[6], ' ')) && ft_isdigit(*(input + 1)))
	{
		dims->c = ft_atoi(input);
		return (0);
	}
	return (-1);
}

int			ft_get_piece(t_piece *piece)
{
	char	*input;

	if (ft_get_piece_dims(&piece->dim) < 0)
		return (-1);
	if (!(piece->str = (char **)malloc(piece->dim.r * sizeof(char *))))
		return (-1);
	if (ft_read_piece(&piece->str, piece->dim.r) < 0)
		return (-1);
	return (0);
}
