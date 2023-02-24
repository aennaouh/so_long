/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:24 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/21 15:41:17 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == 'P')
		{
			if (data->map[i - 1][j] == '0')
			{
				move_up_1(data, i, j);
				return (1);
			}
			if (data->map[i - 1][j] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i - 1][j] = 'P';
				data->map[i][j] = '0';
				construction(data->enemy_check, data);
				data->move++;
			}
			else if (data->map[i - 1][j] == 'E')
				exit_eat(data);
		}
		j++;
	}
	return (0);
}

int	down(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == 'P')
		{
			if (data->map[i + 1][j] == '0')
			{
				move_down_1(data, i, j);
				return (1);
			}
			else if (data->map[i + 1][j] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i + 1][j] = 'P';
				data->map[i][j] = '0';
				construction(data->enemy_check, data);
				data->move++;
			}
			else if (data->map[i + 1][j] == 'E')
				exit_eat(data);
		}
		j++;
	}
	return (0);
}

int	left(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == 'P')
		{
			if (data->map[i][j - 1] == '0')
			{
				move_left_1(data, i, j);
				return (1);
			}
			else if (data->map[i][j - 1] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i][j - 1] = 'P';
				data->map[i][j] = '0';
				construction(data->enemy_check, data);
				data->move++;
			}
			else if (data->map[i][j - 1] == 'E')
				exit_eat(data);
		}
		j++;
	}
	return (0);
}

int	right(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == 'P')
		{
			if (data->map[i][j + 1] == '0')
			{
				move_right_1(data, i, j);
				return (1);
			}
			else if (data->map[i][j + 1] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i][j + 1] = 'P';
				data->map[i][j] = '0';
				construction(data->enemy_check, data);
				data->move++;
			}
			else if (data->map[i][j + 1] == 'E')
				exit_eat(data);
		}
		j++;
	}
	return (0);
}
