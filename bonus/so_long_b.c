/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:24:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/14 22:03:10 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	construction(int i, t_data *data)
{
	int	y;
	int	x;

	data->i = 0;
	y = 0;
	x = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_ptr, x, y);
			if (data->map[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_ptr1, x, y);
			if (data->map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_ptr2, x, y);
			if (data->map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_ptr3, x, y);
			if (data->map[data->i][data->j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img_ptr4, x, y);
			}
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
			data->enemy_frame = i;
			data->j++;
			x += 50;
		}
		data->i++;
		x = 0;
		y += 50;
	}
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	int		l;
	int		f;
	t_data	data;

	argc = 0;
	data.enemy_frame = 0;
	data.map = read_line(argv);
	y = lenstr(data.map);
	x = ft_strrts(data.map[2]) - 1;
	count_collec(data.map, data);
	fix_map(data.map);
	caree(data.map, data.i, data.jen);
	//ft_check(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, x * 50, y * 50, "mlx  42");
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "../textures/fog.xpm",
			&f, &l);
	data.img_ptr1 = mlx_xpm_file_to_image(data.mlx_ptr, "../textures/yaga.xpm",
			&f, &l);
	data.img_ptr2 = mlx_xpm_file_to_image(data.mlx_ptr, "../textures/app.xpm",
			&f, &l);
	data.img_ptr3 = mlx_xpm_file_to_image(data.mlx_ptr, "../textures/door.xpm",
			&f, &l);
	data.img_ptr4 = mlx_xpm_file_to_image(data.mlx_ptr,
		"../textures/cuphead.xpm",&l ,&f);
	data.img_ptr5 = mlx_xpm_file_to_image(data.mlx_ptr,
		"../textures/anime1.xpm", &f, &l);
	data.img_ptr6 = mlx_xpm_file_to_image(data.mlx_ptr,
		"../textures/anime2.xpm", &f, &l);
	data.img_ptr7 = mlx_xpm_file_to_image(data.mlx_ptr,
		"../textures/anime3.xpm", &f, &l);
	data.frame = 0;
	construction(data.enemy_frame, &data);
	mlx_loop_hook(data.mlx_ptr, enemy_p, &data);
	mlx_key_hook(data.win_ptr, ft_move, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
