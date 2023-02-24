/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilise3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:54:34 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 23:55:19 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(void)
{
	exit(0);
	return (0);
}

void	exit_eat(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 0)
	{
		construction(data);
		exit(1);
	}
}
