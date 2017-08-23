#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_coord
{
	size_t		x;
	size_t		y;
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
	t_coord		dim;
	char		**board;
	t_piece		*piece;
}				t_game;

#endif
