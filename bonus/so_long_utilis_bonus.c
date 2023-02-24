/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilis_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:21:39 by aennaouh          #+#    #+#             */
/*   Updated: 2023/02/21 15:38:19 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lent;
	long	nb;

	nb = n;
	lent = count(nb);
	str = (char *)malloc(lent * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[lent--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	else if (nb == 0)
		str[lent] = '0';
	while (nb > 0)
	{
		str[lent] = nb % 10 + 48;
		nb = nb / 10;
		lent--;
	}
	return (str);
}
