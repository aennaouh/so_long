/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilis2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:36 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/23 14:37:07 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplen2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	map_len(char **av)
{
	int		fd;
	t_data	data;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\ninvalide file\n", 21);
		exit(1);
	}
	data.tab = get_next_line(fd);
	if (data.tab == 0)
	{
		write(2, "Error\nfile eempty\n", 19);
		exit(1);
	}
	free(data.tab);
	data.i = 0;
	while (data.tab)
	{
		data.tab = get_next_line(fd);
		data.i++;
		free(data.tab);
	}
	close(fd);
	return (data.i);
}

char	**read_line(char **argv)
{
	int		fd;
	t_data	data;

	data.j = 0;
	data.i = map_len(argv);
	data.arg = malloc((data.i + 1) * sizeof(char *));
	if (!data.arg)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\ninvalide file\n", 21);
		exit(0);
	}
	while (data.j < data.i)
	{
		data.arg[data.j] = get_next_line(fd);
		data.j++;
	}
	data.arg[data.i] = NULL;
	return (data.arg);
}

int	lenstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strrts(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
