/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_en_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:38:49 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 01:16:32 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_a(t_data *data)
{
	static int	i;

	if (i == 29)
		enemy_mo(data);
	if (i < 10)
		construction(0, data);
	if (i < 20)
		construction(1, data);
	if (i < 30)
		construction(2, data);
	if (i > 30)
	{
		i = 0;
		construction(0, data);
	}
	i++;
	return (0);
}

void	enemyleft(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				if (data->map[i][j - 1] == 'A')
				{
					data->map[i][j] = 'A';
					data->map[i][j - 1] = 'P';
					construction(data->enemy_check, data);
					ft_putstr("you lose");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	enemyright(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				if (data->map[i][j + 1] == 'A')
				{
					data->map[i][j] = 'A';
					data->map[i][j + 1] = 'P';
					construction(data->enemy_check, data);
					ft_putstr("you lose");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	enemydown(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				if (data->map[i + 1][j] == 'A')
				{
					data->map[i][j] = 'A';
					data->map[i + 1][j] = 'P';
					construction(data->enemy_check, data);
					ft_putstr("you lose");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	enemyup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				if (data->map[i - 1][j] == 'A')
				{
					data->map[i][j] = 'A';
					data->map[i - 1][j] = 'P';
					construction(data->enemy_check, data);
					ft_putstr("you lose");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
