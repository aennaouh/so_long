/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:47:25 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 00:03:27 by aennaouh         ###   ########.fr       */
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
	void	*img_ptr5;
	void	*img_ptr6;
	void	*img_ptr7;
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
	int		ben;
	int		l;
	int		f;
	char	**arg;
	int		enemy_check;
	int		frame;
	int		move;
	char	*tab;
}			t_data;

char		**read_line(char **argv);
void		fix_map(t_data *data);
void		count_collec(char **ptr, t_data data);
char		**read_line(char **argv);
int			ft_strrts(const char *str);
void		construction(int i, t_data *data);
int			lenstr(char **str);
int			map_len(char **av);
int			ft_move(int keycode, void *param);
void		ft_putstr(char *s);
int			maplen2(char **str);
void		exit_eat(t_data *data);
void		ft_putnbr(int n);
int			enemy_a(t_data *data);
void		enemyleft(t_data *data);
void		enemyright(t_data *data);
void		enemydown(t_data *data);
void		enemyup(t_data *data);
char		**ft_map_copy(t_data *data);
void		moveright(t_data *data);
void		moveleft(t_data *data);
void		movedown(t_data *data);
void		moveup(t_data *data);
int			up(t_data *data, int i, int j);
int			right(t_data *data, int i, int j);
int			left(t_data *data, int i, int j);
int			down(t_data *data, int i, int j);
int			enemy_mo(t_data *data);
int			ft_destroy(void);
void		ft_do_it(t_data *data);
char		**ft_map_copy(t_data *data);
char		*ft_strd(const char *s1);
void		name_map(char *ar);
char		*ft_itoa(int n);
void		move_up_1(t_data *data, int i, int j);
void		move_right_1(t_data *data, int i, int j);
void		move_down_1(t_data *data, int i, int j);
void		move_left_1(t_data *data, int i, int j);
void		caree(char **ptr, int i, int jen);
void		suit_count_collect(char **ptr, t_data *data);
void		differnt_caracter(t_data *data );
char		*ft_strchr_str(const char *str, int c);
#endif