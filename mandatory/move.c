/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:24 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 00:54:59 by aennaouh         ###   ########.fr       */
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
				suit_up(data, i, j);
				return (1);
			}
			if (data->map[i - 1][j] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i - 1][j] = 'P';
				data->map[i][j] = '0';
				construction(data);
				ft_putnbr(data->move++);
				ft_putstr("\n");
				return (1);
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
				suit_down(data, i, j);
				return (1);
			}
			else if (data->map[i + 1][j] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i + 1][j] = 'P';
				data->map[i][j] = '0';
				construction(data);
				ft_putnbr(data->move++);
				ft_putstr("\n");
				return (1);
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
				suit_left(data, i, j);
				return (1);
			}
			else if (data->map[i][j - 1] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i][j - 1] = 'P';
				data->map[i][j] = '0';
				construction(data);
				ft_putnbr(data->move++);
				ft_putstr("\n");
				return (1);
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
				suit_right(data, i, j);
				return (1);
			}
			else if (data->map[i][j + 1] == 'C')
			{
				data->map[i][j] = 'C';
				data->map[i][j + 1] = 'P';
				data->map[i][j] = '0';
				construction(data);
				ft_putnbr(data->move++);
				ft_putstr("\n");
				return (1);
			}
			else if (data->map[i][j + 1] == 'E')
				exit_eat(data);
		}
		j++;
	}
	return (0);
}
