/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:10:17 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 14:28:11 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	suit_right(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i][j + 1] = 'P';
	construction(data);
	ft_putnbr(data->move++);
	ft_putstr("\n");
}

void	suit_left(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i][j - 1] = 'P';
	construction(data);
	ft_putnbr(data->move++);
	ft_putstr("\n");
}

void	suit_down(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i + 1][j] = 'P';
	construction(data);
	ft_putnbr(data->move++);
	ft_putstr("\n");
}

void	suit_up(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i - 1][j] = 'P';
	construction(data);
	ft_putnbr(data->move++);
	ft_putstr("\n");
}

void	name_map(char *ar)
{
	int	i;
	int	fd;

	i = ft_strlen(ar);
	if (ar[i - 1] == 'r' && ar[i - 2] == 'e' && \
		ar[i - 3] == 'b' && ar[i - 4] == '.')
	{
		fd = open(ar, O_RDONLY);
		if (fd == -1)
		{
			write(2, "Error\ninvalid file_map1\n", 25);
		}
		else
			close(fd);
	}
	else
	{
		write(2, "Error\ninvalid name_map2\n", 25);
		exit(1);
	}
}
