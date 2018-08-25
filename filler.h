/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:42:29 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/08/25 16:22:41 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <get_next_line.h>

typedef	struct	s_filler
{
	char	player;
	int	x_map;
	int	y_map;
	int	x_piece;
	int	y_piece;
	char	**map;
	char	**piece;
}		t_filler;

typedef struct	s_possible
{
	int	x;
	int	y;
	int	fitness;
	struct s_possible *next;
}		t_possible;

int		get_player(t_filler *filler);
int		get_piece_size(t_filler *filler);
int		get_map_size(t_filler *filler);
void		get_piece(t_filler *filler);
void		get_map(t_filler *filler);

#endif
