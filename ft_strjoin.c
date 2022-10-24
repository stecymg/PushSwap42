/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:49:02 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/24 17:49:04 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (s1 && s2)
	{
		str = malloc(sizeof(char) * i + 2);
		if (!str)
			return (0);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str[i] = ' ';
		str[i + 1] = '\0';
		free(s1);
		return (str);
	}
	else
		return (0);
}
