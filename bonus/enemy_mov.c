/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:58:32 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/14 19:23:25 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_movement_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{
				if (data->map[i][j + 1] == '0')
				{
					data->map[i][j + 1] = 'A';
					data->map[i][j] = '0';
				}
				else
				{
					data->frame = 0;
				}
				construction(data->enemy_frame, data);
			}
			j++;
		}
		i++;
	}
}

void	enemy_movement_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{
				if (data->map[i][j - 1] == 'P')
				{
					exit(1);
					ft_putstr("you lose");
				}
				if (data->map[i][j - 1] == '0')
				{
					data->map[i][j - 1] = 'A';
					data->map[i][j] = '0';
				}
				else
				{
					data->frame = 1;
				}
				construction(data->enemy_frame, data);
			}
			j++;
		}
		i++;
	}
}

int	enemy_mo(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'A')
			{
				enemy_movement_left(data);
			}
			if (data->frame == 1)
			{
				enemy_movement_right(data);
			}
			j++;
		}
		i++;
	}
	return (1);
}
