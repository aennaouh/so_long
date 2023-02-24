/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepla.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:10:18 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 23:53:28 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (up(data, i, j))
			return ;
		i++;
	}
}

void	movedown(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (down(data, i, j))
			return ;
		i++;
	}
}

void	moveleft(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (left(data, i, j))
			return ;
		i++;
	}
}

void	moveright(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (right(data, i, j))
			return ;
		i++;
	}
}

int	ft_move(int keycode, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keycode == 126 || keycode == 13)
		moveup(data);
	if (keycode == 125 || keycode == 1)
		movedown(data);
	if (keycode == 123 || keycode == 0)
		moveleft(data);
	if (keycode == 124 || keycode == 2)
		moveright(data);
	if (keycode == 53)
	{	
		exit(1);
	}
	return (0);
}
