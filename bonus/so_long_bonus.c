/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:24:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 16:39:53 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	suite_images_enemy(t_data *data, int i, int x, int y)
{
	if (data->map[data->i][data->j] == 'A')
	{
		if (i == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_ptr5, x, y);
		if (i == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_ptr6, x, y);
		if (i == 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_ptr7, x, y);
	}
}

void	suite_images(t_data *data, int i, int x, int y)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr, x, y);
	if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr1, x, y);
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr2, x, y);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr3, x, y);
	if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img_ptr4, x, y);
	suite_images_enemy(data, i, x, y);
}

void	construction(int i, t_data *data)
{
	char	*mov_cou;

	data->i = 0;
	data->y = 0;
	data->x = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			suite_images(data, i, data->x, data->y);
			data->enemy_check = i;
			data->j++;
			data->x += 50;
		}
		data->i++;
		data->x = 0;
		data->y += 50;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1, 1, 0xffffff, "move");
	mov_cou = ft_itoa(data->move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 1, 0xffffff, mov_cou);
	free(mov_cou);
}

void	check_xpm(t_data *data)
{
	data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/fog.xpm", &data->f, &data->l);
	data->img_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/yaga.xpm", &data->f, &data->l);
	data->img_ptr2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/app.xpm", &data->f, &data->l);
	data->img_ptr3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/door.xpm", &data->f, &data->l);
	data->img_ptr4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/cuphead.xpm", &data->l, &data->f);
	data->img_ptr5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/anime1.xpm", &data->f, &data->l);
	data->img_ptr6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/anime2.xpm", &data->f, &data->l);
	data->img_ptr7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/anime3.xpm", &data->f, &data->l);
	if (!data->img_ptr || !data->img_ptr1 ||!data->img_ptr2 || !data->img_ptr3
		|| !data->img_ptr4 || !data->img_ptr5
		|| !data->img_ptr6 || !data->img_ptr7)
	{
		write(2, "Error:\nxpm", 11);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	t_data	data;

	if (argc > 2)
		return (ft_putstr("Many Args"), 0);
	data.enemy_check = 0;
	data.map = read_line(argv);
	y = lenstr(data.map);
	x = ft_strrts(data.map[0]) - 1;
	count_collec(data.map, data);
	differnt_caracter(&data);
	fix_map(&data);
	caree(data.map, data.i, data.ben);
	ft_do_it(&data);
	name_map(argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, x * 50, y * 50, "mlx  42");
	check_xpm(&data);
	construction(data.enemy_check, &data);
	mlx_loop_hook(data.mlx_ptr, enemy_a, &data);
	mlx_key_hook(data.win_ptr, ft_move, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
