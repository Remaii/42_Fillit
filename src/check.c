/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 04:09:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/06 12:39:19 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			nbhash(char *tetri)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < 16)
	{
		if (tetri[i] != '.')
			nb++;
		i++;
	}
	return (nb);
}

int			check_form(char *tetri, int x, int y, int skip)
{
	if (get_pos(tetri, x, y) != '.')
	{
		if (skip == 0)
			return (1 + check_form(tetri, x + 1, y, 1)
					+ check_form(tetri, x - 1, y, -1)
					+ check_form(tetri, x, y + 1, 0));
		else if (skip == 1)
			return (1 + check_form(tetri, x + 1, y, 1) 
					+ check_form(tetri, x, y + 1, 0));
		else if (skip == -1)
			return (1 + check_form(tetri, x - 1, y, -1)
					+ check_form(tetri, x, y + 1, 0));
	}
	return (0);
}

int			check(char *tetri)
{
	int		x;
	int		y;

	if (nbhash(tetri) != 4)
		error("Error\n");
	x = 0;
	y = 0;
	while (get_pos(tetri, x, y) == '.')
	{
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
	if (check_form(tetri, x, y, 1) < 4)
		error("Error\n");
	return (0);
}
