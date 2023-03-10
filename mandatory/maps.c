/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:16:39 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 16:52:06 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collec(char **ptr, t_data data)
{
	data.i = 0;
	data.collectible = 0;
	data.player = 0;
	data.exit = 0;
	while (ptr[data.i])
	{
		data.j = 0;
		while (ptr[data.i][data.j])
		{
			if (ptr[data.i][data.j] == 'P')
			data.player++;
			else if (ptr[data.i][data.j] == 'C')
			data.collectible++;
			else if (ptr[data.i][data.j] == 'E')
			data.exit++;
		data.j++;
		}
		data.i++;
	}
	if (data.player != 1 || data.collectible < 1 || data.exit != 1)
	{
		write(2, "Error\nerr not work \n", 21);
		exit(1);
	}
}

void	fix_map_up(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[i])
		i++;
	while (data->map[i - 1][j] && data->map[i - 1][j] != '\n')
	{
		if (data->map[i - 1][j] != '1')
		{
			write(2, "Error\ninvlide map_down\n", 24);
			exit(1);
		}
		j++;
	}
}

void	fix_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][i] && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1')
		{
			write(2, "Error\ninvalide map_up\n", 23);
			exit(1);
		}
		i++;
	}
	while (data->map[j])
	{
		if (data->map[j][i - 1] != '1' || data->map[j][0] != '1')
		{
			write(2, "Error\ninvalide_right_left\n", 27);
			exit(1);
		}
		j++;
	}
	fix_map_up(data);
}

void	caree(char **ptr, int i, int ben)
{
	size_t	len;

	ben = maplen2(ptr);
	len = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[i])
	{
		if (i == ben - 1)
		{
			if (len != ft_strlen(ptr[i]) + 1)
			{
				write(2, "Error\ninvalid caree1\n", 22);
				exit(0);
			}
		}
		else
		{
			if (len != ft_strlen(ptr[i]))
			{
				write(2, "Error\ninvalid caree2\n", 22);
				exit(0);
			}
		}
		i++;
	}
}

void	differnt_caracter(t_data *data )
{
	int	i ;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (!ft_strchr_str("01PCE", data->map[i][j]))
			{
				write(2, "Error:\n invlaide caracter", 26);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
