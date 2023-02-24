/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_suite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:35:18 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 14:46:46 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left_1(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i][j - 1] = 'P';
	construction(data->enemy_check, data);
		data->move++;
}

void	move_down_1(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i + 1][j] = 'P';
	construction(data->enemy_check, data);
	data->move++;
}

void	move_right_1(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i][j + 1] = 'P';
	construction(data->enemy_check, data);
	data->move++;
}

void	move_up_1(t_data *data, int i, int j)
{
	data->map[i][j] = '0';
	data->map[i - 1][j] = 'P';
	construction(data->enemy_check, data);
	data->move++;
}
