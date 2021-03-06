/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:39:21 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/08/25 19:45:39 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
t_possible *rank_moves(t_possible *head, t_filler filler);

void		add_move(t_possible **head, int x, int y, int fitness)
{
	t_possible *tmp;

	if (!(*head))
	{
		*head = (t_possible *)malloc(sizeof(t_possible));
		(*head)->x = x;
		(*head)->y = y;
		(*head)->fitness = fitness;
		(*head)->next = NULL;
		return ;
	}
	tmp = (t_possible *)malloc(sizeof(t_possible));
	tmp->x = x;
	tmp->y = y;
	tmp->fitness = fitness;
	tmp->next = *head;
	*head = tmp;
}

void		free_map(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	ptr ? free(ptr) : 0;
}

void		free_filler(t_possible **head, t_filler filler)
{
	t_possible *tmp;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	free_map(filler.map);
	free_map(filler.piece);
}

int		valid_move(int y, int x, t_filler *filler)
{
	int yi;
	int xi;
	int res;

	res = 0;
	yi = 0;
	if ((y + (*filler).y_piece > (*filler).y_map) ||
	    (x + (*filler).x_piece > (*filler).x_map))
		return (2);
	while ((yi < (*filler).y_piece) && res < 2)
	{
		xi = 0;
		while ((xi < (*filler).x_piece) && res < 2)
		{
			if ((*filler).map[yi + y][xi + x]
			    != '.')
			{
				if ((*filler).piece[yi][xi] == '*')
				{
					if ((*filler).map[yi + y][xi + x] ==
					    (*filler).player)
						res += 1;
					else
						res += 2;
				}
			}
			xi++;
		}
		yi++;
	}
	return (res);
}

void		collect_possible_moves(t_filler *filler, t_possible **moves)
{
	int y;
	int x;

	y = -1;
	while (++y < (*filler).y_map)
	{
		x = -1;
		while (++x < (*filler).x_map)
		{
			if (valid_move(y, x, filler) == 1)
				add_move(moves, x, y, 0);
		}
	}
}

void		print_moves(t_possible *moves, t_filler f)
{
	if (moves)
	{
		moves = rank_moves(moves, f);
		ft_putnbr(moves->y);
		ft_putchar(' ');
		ft_putnbr(moves->x);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	(void)f;
}

int		main(void)
{
	t_filler	filler;
	t_possible	*moves;

	ft_bzero(&filler, sizeof(t_filler));
	if (get_player(&filler))
	{
		while (1)
		{
			moves = NULL;
			if (get_map_size(&filler) < 0)
				break ;
			get_map(&filler);
			if (get_piece_size(&filler) < 0)
				break ;
			get_piece(&filler);
			collect_possible_moves(&filler, &moves);
			print_moves(moves, filler);
			free_filler(&moves, filler);
		}
	}
	return (0);
}
