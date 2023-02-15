/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:16:39 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/13 15:18:39 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(t_data data, char **ptr)
{
	while (ptr[data.i][data.j])
	{
		if (ptr[data.i][data.j] == 'P')
		{
			data.player++;
			data.j++;
		}
		else if (ptr[data.i][data.j] == 'C')
		{
			data.collectible++;
			data.j++;
		}
		else if (ptr[data.i][data.j] == 'E')
		{
			data.exit++;
			data.j++;
		}
		else
			data.j++;
	}
	return (1);
}

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
			if (count(data, ptr))
				return ;
			data.i++;
		}
	}
	if (data.player != 1 && data.collectible < 1 && data.exit != 1)
	{
		ft_putstr("error not work");
		exit(1);
	}
}

void	fix_map(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = maplen2(str);
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1' || str[0][j] != '1')
		{
			printf("erre not wr");
			exit(1);
		}
		j++;
	}
	j = ft_strlen(str[0]);
	i--;
	while (str[i][0] && str[i][j - 1])
	{
		if (str[i][0] != '1' || str[i][j - 1] != '1')
		{
			ft_putstr("erre not wor");
			exit(1);
		}
		i--;
	}
}

void	caree(char **ptr, int i, int jen)
{
	size_t	len;

	jen = maplen2(ptr);
	len = ft_strlen(ptr[0]);
	i = 0;
	while (ptr[i])
	{
		if (i == jen - 1)
		{
			if (len != ft_strlen(ptr[i]) + 1)
			{
				ft_putstr("error not wooork");
				exit(0);
			}
		}
		else
		{
			if (len != ft_strlen(ptr[i]))
			{
				ft_putstr("error not woddoork");
				exit(0);
			}
		}
		i++;
	}
}
