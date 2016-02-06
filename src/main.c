/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:25:47 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/06 12:39:57 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int				size_square(int nb)
{
	int			i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

char			get_pos(char *tetri, int x, int y)
{
	if (x >= 4 || y >= 4 || x < 0 || y < 0)
		return ('.');
	else
		return (tetri[x + (y * 4)]);
}

int				error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void			place_dot(t_sort *sort)
{
	int			i;

	i = 0;
	while (i < 200)
	{
		sort->tab[i] = '.';
		i++;
	}
}

int				main(int ac, char **av)
{
	t_tetri		tab[27];
	t_sort		sort;

	if (ac != 2)
		return (error("Usage: .fillit must be use with only one argument\n"));
	else
	{
		ft_bzero(tab, 27 * sizeof(*tab));
		place_dot(&sort);
		get_tetri(av[1], tab);
		sort.size = size_square(nb_tetri(tab) * 4);
		set_nb(tab);
		solve_fillit(&sort, tab, 0);
	}
	error("Error\n");
}
