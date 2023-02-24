/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:24:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 16:47:04 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	suit_construction(t_data *data, int x, int y)
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
			data->img_ptr1, x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr4, x, y);
	}
}

void	construction(t_data *data)
{
	int	y;
	int	x;

	data->i = 0;
	y = 0;
	x = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			suit_construction(data, x, y);
		data->j++;
		x += 50;
		}
		data->i++;
		x = 0;
		y += 50;
	}
}

void	check_xpm(t_data *data)
{
	int	f;
	int	l;

	data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/tiran.xpm", &f, &l);
	data->img_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/empty.xpm", &f, &l);
	data->img_ptr2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/app.xpm", &f, &l);
	data->img_ptr3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/door.xpm", &f, &l);
	data->img_ptr4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"../textures/cuphead.xpm", &f, &l);
	if (!data->img_ptr || !data->img_ptr1 \
		|| !data->img_ptr2 || !data->img_ptr3 \
		|| !data->img_ptr4)
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
	data.map = read_line(argv);
	y = lenstr(data.map);
	x = ft_strrts(data.map[2]) - 1;
	count_collec(data.map, data);
	differnt_caracter(&data);
	fix_map(&data);
	caree(data.map, data.i, data.jen);
	ft_do_it(&data);
	name_map(argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, x * 50, y * 50, "mlx  42");
	check_xpm(&data);
	construction(&data);
	mlx_key_hook(data.win_ptr, ft_move, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
