/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:44:25 by agaussel          #+#    #+#             */
/*   Updated: 2025/11/06 11:44:26 by agaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	isc;

	isc = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			isc = 1;
		}
		if (s[i] != c && isc == 1)
		{
			count++;
			isc = 0;
		}
		i++;
	}
	return (count);
}

static size_t	nextsep(const char *s, size_t current, char c)
{
	size_t	count;

	count = 0;
	while (s[current] && s[current] != c)
	{
		current++;
		count++;
	}
	return (count);
}

static void	ft_free_split(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	*ft_strdupp(const char *s, size_t i, const char c)
{
	size_t	count;
	size_t	siz;
	char	*dest;

	count = 0;
	siz = nextsep(s, i, c);
	dest = malloc(siz + 1);
	if (!dest)
		return (NULL);
	while (count < siz)
	{
		dest[count] = s[i];
		i++;
		count++;
	}
	dest[count] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**csplit;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	csplit = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!csplit)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			csplit[j++] = ft_strdupp(s, i, c);
			if (!csplit[j - 1])
				return (ft_free_split(csplit, j - 1), NULL);
			i += nextsep(s, i, c);
		}
	}
	csplit[j] = NULL;
	return (csplit);
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
    char	**tab;
    int		i;

    if (ac == 3)
    {
        tab = ft_split(av[1], av[2][0]);
        if (!tab)
            return (1);
        i = 0;
        while (tab[i])
        {
            printf("mot %d: %s\n", i, tab[i]);
            i++;
        }
    }
    return (0);
}*/