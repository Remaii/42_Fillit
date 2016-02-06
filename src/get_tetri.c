/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 03:25:14 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/06 12:45:55 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			nb_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	while (tetri[i].str != NULL)
		i++;
	return (i);
}

void		set_nb(t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	while (tetri[i].str != NULL)
	{
		j = 0;
		while (tetri[i].str[j] == '.')
			j++;
		tetri[i].nb = j;
		i++;
	}
}

char		*stock(int fd, int i)
{
	int		j;
	int		len;
	char	tmp[20];
	char	*str;

	len = read(fd, tmp, 20);
	j = 0;
	if (len < 20)
		error("Error\n");
	str = (char *)ft_memalloc(sizeof(char) * 17);
	while (j < len)
	{
		if (tmp[j] != '\n' && tmp[j] != '.' && tmp[j] != '#')
			error("Error\n");
		if (tmp[j] == '#')
			str[j - (j / 5)] = i + 'A';
		else if (tmp[j] == '\n' && (j % 5) != 4)
			error("Error\n");
		else
			str[j - (j / 5)] = '.';
		j++;
	}
	str[j - (j / 5)] = '\0';
	check(str);
	return (str);
}

t_tetri		*get_tetri(char *entry, t_tetri *tab)
{
	int		i;
	int		fd;
	char	buf[1];

	fd = open(entry, O_RDONLY);
	i = 1;
	tab[0].str = stock(fd, 0);
	tab[0].last = -1;
	while (read(fd, buf, 1))
	{
		if (*buf != '\n')
			error("Error\n");
		tab[i].str = stock(fd, i);
		tab[i].last = -1;
		i++;
		if (i > 26)
			error("Error\n");
	}
	close(fd);
	check(tab[0].str);
	return (tab);
}
