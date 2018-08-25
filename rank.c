/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 19:27:22 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/08/25 20:37:05 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <stdlib.h>

int	distance(char **map, int x, int y, char opponent)
{
	int yi;
	int xi;
	int d;

	d = 0;
	yi = -1;
	while (map[++yi] && !d)
	{
		xi = -1;
		while (map[++xi] && !d)
		{
			if (map[yi][xi] == opponent && (map[yi][xi - 1] !=
							opponent
							|| map[yi][xi + 1] !=
							opponent))
				d = 1;
		}
	}
	d = abs(yi - y) + abs(xi - x);
	if (y < yi)
		d = d - y;
	//d = abs((y < yi ? yi - y : y - yi) - (x < xi ? xi - x : x - xi));
	return (d);
}

t_possible *rank_moves(t_possible *head, t_filler filler)
{
	t_possible *tmp;
	t_possible *best;

	tmp = head;
	while (tmp)
	{
		tmp->fitness = distance(filler.map, tmp->x, tmp->y,
					(filler.player == 'O') ? 'X' : 'O');
		tmp = tmp->next;
	}
	tmp = head;
	best = tmp;
	while (tmp)
	{
		if (tmp->fitness < best->fitness)
			best = tmp;
		tmp = tmp->next;
	}
	return (best);
}
