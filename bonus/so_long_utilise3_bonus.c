/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilise3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:47:36 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 00:07:39 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		construction(data->enemy_check, data);
		exit(1);
	}
}

int	ft_destroy(void)
{
	exit(0);
	return (0);
}

void	name_map(char *ar)
{
	int	i;
	int	fd;

	i = ft_strlen(ar);
	if (ar[i - 1] == 'r' && ar[i - 2] == 'e' && \
		ar[i - 3] == 'b' && ar[i - 4] == '.')
	{
		fd = open(ar, O_RDONLY);
		if (fd == -1)
		{
			write(2, "Error\ninvalide name_map\n", 25);
		}
		else
			close(fd);
	}
	else
	{
		write(2, "Error ber:\n", 12);
		exit(1);
	}
}

char	*ft_strchr_str(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if ((char)c == *ptr)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
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
			if (!ft_strchr_str("01PCEA", data->map[i][j]))
			{
				write(2, "Error:\n invlaide caracter", 26);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
