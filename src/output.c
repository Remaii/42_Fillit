/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 05:35:49 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/03 05:55:37 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void		ft_print(t_sort *sort)
{
	int		i;

	i = 0;
	while (i < sort->size)
	{
		write(1, sort->tab + (i * sort->size), sort->size);
		ft_putchar('\n');
		i++;
	}
}

void		remove_tetri(t_sort *sort, t_tetri tetri)
{
	int		i;

	i = 0;
	while (i < (sort->size * sort->size))
	{
		if (sort->tab[i] == tetri.str[tetri.nb])
			sort->tab[i] = '.';
		i++;
	}
}

void		put_tetri(t_sort *sort, t_tetri *tetri)
{
	int		i;

	i = tetri->nb;
	while (i < 16)
	{
		if (tetri->str[i] != '.')
			sort->tab[find_coord(sort, tetri, i)] = tetri->str[i];
		i++;
	}
}
