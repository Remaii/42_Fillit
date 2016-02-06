/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 01:04:06 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/03 05:53:14 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../include/libft.h"
# include <fcntl.h>
# define READ_BUFFER 676

// struture de sortie //
typedef struct	s_sort
{
	int			size;
	char		tab[200];
}				t_sort;

// structure de stockage des piece //
typedef struct	s_tetri
{
	int			nb;
	int			last;
	char		*str;
}				t_tetri;

// Main.c //
int				error(char *str);
void			place_dot(t_sort *sort);
char			get_pos(char *tetri, int x, int y);

// get_tetri.c //
t_tetri			*get_tetri(char *entry, t_tetri *tab);
char			*stock(int fd, int i);

// check.c //
int				check(char *tetri);
int				nbhash(char *tetri);
int				check_form(char *tetri, int x, int y, int skip);

// count.c //
int				nb_tetri(t_tetri *tetri);
void			set_nb(t_tetri *tetri);

// solve .c //
void			solve_fillit(t_sort *sort, t_tetri *tetri, int i);
int				can_put_tetri(t_sort *sort, t_tetri *tetri);
int				good_tetri(t_sort *sort, t_tetri *tetri);
int				find_coord(t_sort *sort, t_tetri *tetri, int i);

// output.c //
void			put_tetri(t_sort *sort, t_tetri *tetri);
void			ft_print(t_sort *sort);
void			remove_tetri(t_sort *sort, t_tetri tetri);

#endif
