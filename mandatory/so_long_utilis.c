/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:21:39 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/22 23:55:09 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}

char	*ft_strd(const char *s1)
{
	size_t	i;
	size_t	lent;
	char	*str;

	i = 0;
	lent = ft_strlen(s1);
	str = malloc ((lent + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < lent)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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
