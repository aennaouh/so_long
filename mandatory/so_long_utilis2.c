/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilis2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:36 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/14 19:40:39 by aennaouh         ###   ########.fr       */
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

int	maplen(char **av)
{
	int		fd;
	char	*tab;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("invalid file");
		exit(1);
	}
	tab = get_next_line(fd);
	i = 0;
	while (tab)
	{
		tab = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_line(char **argv)
{
	int		fd;
	char	**arg;
	int		i;
	int		j;

	j = 0;
	i = maplen(argv);
	arg = malloc(i * sizeof(char *) + 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("invalide file");
		exit(0);
	}
	while (j < i)
	{
		arg[j] = get_next_line(fd);
		j++;
	}
	arg[i] = 0;
	return (arg);
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
