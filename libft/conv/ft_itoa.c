/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:35 by agaussel          #+#    #+#             */
/*   Updated: 2025/11/04 11:08:36 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	whereami(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	reviter(char *str, long l, int i)
{
	if (l == 0)
	{
		str[0] = '0';
		return ;
	}
	if (l < 0)
	{
		str[0] = '-';
		l *= -1;
	}
	while (l > 0)
	{
		str[i] = l % 10 + '0';
		i--;
		l /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long		l;

	l = n;
	i = whereami(l);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if ((!str))
		return (NULL);
	str[i] = '\0';
	i--;
	reviter(str, l, i);
	return (str);
}
