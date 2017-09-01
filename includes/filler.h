/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 21:33:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/31 21:34:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

enum			e_max
{
	top,
	bottom,
	left,
	right
};

typedef struct	s_coord
{
	size_t		r;
	size_t		c;
}				t_coord;

typedef struct	s_piece
{
	t_coord		dim;
	t_coord		pos;
	char		**str;
}				t_piece;

typedef struct	s_game
{
	char		player;
	char		marker;
	char		opponent;
	t_coord		dim;
	char		**board;
	t_piece		*piece;
	int			first_turn:1;
	t_coord		bullseye;
}				t_game;

int				ft_place_smother(t_game *game);
int				ft_place_move(t_coord pos);
void			ft_get_bullseye(t_game *game);
int				ft_place_tl(t_game game);
int				ft_place_tr(t_game game);
int				ft_place_bl(t_game game);
int				ft_place_br(t_game game);
int				ft_new_game(t_game *game, t_piece *piece);
int				ft_get_piece(t_piece *piece);
int				ft_read_board(char ***board, size_t rows, int first);
int				ft_flush_lines(size_t lines);
int				ft_place_piece(t_game *game);
int				ft_valid_placement(t_game game, t_coord pos);
void			ft_set_bounds(t_game *game);

#endif
