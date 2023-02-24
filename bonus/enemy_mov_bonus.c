/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:58:32 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 00:56:42 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose_right(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] == 'P')
	{
		ft_putstr("you lose");
		exit(1);
	}
}

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
				construction(data->enemy_check, data);
				lose_right(data, i, j);
			}
			j++;
		}
		i++;
	}
}

void	lose_left(t_data *data, int i, int j)
{
	if (data->map[i][j - 1] == 'P')
	{
		ft_putstr("you lose");
		exit(1);
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
				if (data->map[i][j - 1] == '0')
				{
					data->map[i][j - 1] = 'A';
					data->map[i][j] = '0';
				}
				construction(data->enemy_check, data);
				lose_left(data, i, j);
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
				if (rand() % 2 == 0)
					enemy_movement_left(data);
				else if (rand() % 2 == 1)
					enemy_movement_right(data);
			}
			j++;
		}
		i++;
	}
	return (1);
}
