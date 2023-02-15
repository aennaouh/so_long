/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:12:13 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/14 21:56:39 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(t_data *data)
{
	int		i;
	char	**str;

	i = maplen(data->map);
	str = malloc(i * sizeof(char) + 1);
	while (str[i])
	{
		str[i] = ft_strdup(data->map[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_backtr(t_data *data, int i, int j, char c)
{
	if (data->back_map[i][j] == 'P')
		return (1);
	if (data->back_map[i][j] == '1' || (c != 'E'
			&& data->back_map[i][j] == 'E'))
		return (0);
	data->back_map[i][j] = '1';
	if (ft_backtr(data, i - 1, j, c))
		return (1);
	if (ft_backtr(data, i, j - 1, c))
		return (1);
	if (ft_backtr(data, i + 1, j, c))
		return (1);
	if (ft_backtr(data, i, j + 1, c))
		return (1);
	return (0);
}

void	ft_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->back_map = ft_map_copy(data);
	while (data->back_map[i])
	{
		j = 0;
		while (data->back_map[i][j])
		{
			if (data->back_map[i][j] == 'E' || (data->back_map[i][j] == 'C'))
			{
				if (!ft_backtr(data, i, j, data->back_map[i][j]))
				{
					exit(1);
				}
				data->back_map = ft_map_copy(data);
			}
			j++;
		}
		i++;
	}
}
