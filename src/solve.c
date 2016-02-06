/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 05:01:42 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/06 12:24:24 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			find_coord(t_sort *sort, t_tetri *tetri, int i)
{
	return (((i % 4) - (tetri->nb % 4)) + (((i / 4) - (tetri->nb / 4))
			* sort->size) + tetri->last);
}

char		get_value(t_sort *sort, t_tetri *tetri, int i)
{
	int		x;

	x = find_coord(sort, tetri, i);
	if (x >= (sort->size * sort->size))
		return ('#');
	if ((x % sort->size) > (find_coord(sort, tetri, tetri->nb) % sort->size))
	{
		if (i % 4 < tetri->nb % 4)
			return ('#');
	}
	else if (i % 4 > tetri->nb % 4)
		return ('#');
	return (sort->tab[find_coord(sort, tetri, i)]);
}


int			good_tetri(t_sort *sort, t_tetri *tetri)
{
	int		i;

	i = tetri->nb;
	while (i < 16)
	{
		if (tetri->str[i] != '.')
			if (get_value(sort, tetri, i) != '.')
				return (0);
		i++;
	}
	return (1);
}

int			can_put_tetri(t_sort *sort, t_tetri *tetri)
{
	tetri->last++;
	if (tetri->last < (sort->size * sort->size))
	{
		if (good_tetri(sort, tetri))
		{
			put_tetri(sort, tetri);
			return (1);
		}
		else
			return (can_put_tetri(sort, tetri));
	}
	else
	{
		tetri->last = -1;
		return (0);
	}
}

void		solve_fillit(t_sort *sort, t_tetri *tetri, int i)
{
	if (tetri[i].str == NULL)
	{
		ft_print(sort);
		exit(0);
	}
	else
	{
		while (can_put_tetri(sort, &tetri[i]))
		{
			solve_fillit(sort, tetri, i + 1);
			remove_tetri(sort, tetri[i]);
		}
		tetri[i].last = -1;
		if (i == 0)
		{
			sort->size++;
			solve_fillit(sort, tetri, i);
		}
	}
}
