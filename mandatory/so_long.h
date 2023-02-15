/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:47:25 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/14 17:55:02 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "so_long.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_utilise
{
	int		player;
	int		collectible;
	int		wall;
	int		empthy;
	int		exit;
	int		enemy;
	int		i;
	int		j;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr1;
	void	*img_ptr;
	void	*img_ptr2;
	void	*img_ptr3;
	void	*img_ptr4;
	int		x;
	int		y;
	int		h;
	int		w;
	char	**map;
	char	**back_map;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		key_exit;
	int		player_x;
	int		player_y;
	int		l;
	int		f;
	int		jen;
}			t_data;

char		**read_line(char **argv);
void		fix_map(char **str);
void		count_collec(char **ptr, t_data data);
char		**read_line(char **argv);
int			ft_strrts(const char *str);
void		construction(t_data *data);
int			lenstr(char **str);
int			maplen(char **av);
void		position_P(char **map, t_data *data);
void		caree(char **ptr, int i, int jen);
int			ft_move(int keycode, void *param);
void		ft_putstr(char *s);
int			maplen2(char **str);
void		exit_eat(t_data *data);
void		ft_putnbr(int n);
int			ft_backtr(t_data *data, int i, int j, char c);
char		**ft_map_copy(t_data *data);
void		ft_check(t_data *data);
void		moveright(t_data *data);
void		moveleft(t_data *data);
void		movedown(t_data *data);
void		moveup(t_data *data);
int			up(t_data *data, int i, int j);
int			right(t_data *data, int i, int j);
int			left(t_data *data, int i, int j);
int			down(t_data *data, int i, int j);
int			count(t_data data, char **ptr);

#endif