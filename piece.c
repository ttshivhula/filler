/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:36:21 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/08/25 15:45:03 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_filler *filler)
{
	char	*line;
	int	i;

	if (get_next_line(0, &line))
	{
		i = 0;
		ft_putendl_fd(line, 3);
		while (line[i])
		{
			if (line[i] == 'p' && ft_isdigit(line[i + 1]))
			{
				(*filler).player = (line[i + 1] == '1') ? 'O' :
					'X';
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int		get_piece_size(t_filler *filler)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line))
	{
		ft_putendl_fd(line, 3);
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			tmp = ft_strchr(line, ' ') + 1;
			(*filler).y_piece = ft_atoi(tmp);
			tmp = ft_strchr(tmp, ' ') + 1;
			(*filler).x_piece = ft_atoi(tmp);
			return (1);
		}
	}
	else
		return  (-1);
	return (0);
}

int		get_map_size(t_filler *filler)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line))
	{
		ft_putendl_fd(line, 3);
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			tmp = ft_strchr(line, ' ') + 1;
			(*filler).y_map = ft_atoi(tmp);
			tmp = ft_strchr(tmp, ' ') + 1;
			(*filler).x_map = ft_atoi(tmp);
			return (1);
		}
	}
	else
		return (-1);
	return (0);
}

void		get_piece(t_filler *filler)
{
	int	i;
	char	*line;

	(*filler).piece = (char **)malloc(sizeof(char *) * ((*filler).y_piece +
							    1));
	i = -1;
	while (get_next_line(0, &line) && (++i < (*filler).y_piece))
	{
		ft_putendl_fd(line, 3);
		(*filler).piece[i] = (char *)malloc(sizeof(char) * (*filler).x_piece + 1);
		ft_strcpy((*filler).piece[i], line);
		if (i == (*filler).y_piece - 1)
			break ;
	}
	(*filler).piece[++i] = NULL;
}

void		get_map(t_filler *filler)
{
	int	i;
	char	*line;
	char	*tmp;

	(*filler).map = (char **)malloc(sizeof(char *) * (*filler).y_map + 1);
	i = -2;
	while (get_next_line(0, &line) && (++i < (*filler).y_map))
	{
		ft_putendl_fd(line, 3);
		if (i > -1)
		{
			tmp = ft_strchr(line, ' ') + 1;
			(*filler).map[i] = (char *)malloc(sizeof(char) *
							  (*filler).x_map + 1);
			ft_strcpy((*filler).map[i], tmp);
		}
		if (i + 1 >= (*filler).y_map)
			break ;
	}
	(*filler).map[++i] = NULL;
}
