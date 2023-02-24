/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:22:52 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 14:53:15 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(t_data *data)
{
	int		i;
	char	**str;

	i = 0;
	while (data->map[i])
		i++;
	str = malloc((i + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		str[i] = ft_strd(data->map[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_check_pat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->back_map[i])
	{
		j = 0;
		while (data->back_map[i][j])
		{
			if (data->back_map[i][j] == '0' || data->back_map[i][j] == 'C')
			{
				if (data->back_map[i][j - 1] == 'P' ||
					data->back_map[i][j + 1] == 'P' ||
					data->back_map[i - 1][j] == 'P' ||
					data->back_map[i + 1][j] == 'P')
				{
					data->back_map[i][j] = 'P';
					ft_check_pat(data);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_exit(t_data *data)
{
	data->i = 0;
	while (data->back_map[data->i])
	{
		data->j = 0;
		while (data->back_map[data->i][data->j])
		{
			if (data->back_map[data->i][data->j] == 'E')
			{
				if (data->back_map[data->i][data->j - 1] == 'P' ||
				data->back_map[data->i][data->j + 1] == 'P' ||
					data->back_map[data->i - 1][data->j] == 'P' ||
					data->back_map[data->i + 1][data->j] == 'P')
				{
					return ;
				}
				else
				{
					write(2, "Error:\ninvalide pat", 20);
					exit(1);
				}
			}
			data->j++;
		}
		data->i++;
	}
}

void	check_col(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->back_map[i])
	{
		j = 0;
		while (data->back_map[i][j])
		{
			if (data->back_map[i][j] == 'C')
			{
				write(2, "Error:\ninvlide Collec", 22);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_do_it(t_data *data)
{
	data->back_map = ft_map_copy(data);
	ft_check_pat(data);
	check_exit(data);
	check_col(data);
}
