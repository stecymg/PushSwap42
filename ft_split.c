/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:48:52 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/24 17:48:54 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length_word(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

int	nb_word(char *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

char	**writing(char **tab, char *s, char c, int word)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < word)
	{
		while (*s == c)
			s++;
		tab[i] = malloc(sizeof(char) * (length_word(s, c) + 1));
		if (!tab[i])
			return (0);
		j = 0;
		while (*s && *s != c)
		{
			tab[i][j] = *s;
			j++;
			s++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int			word;
	char		**tab;

	if (!s)
		return (0);
	word = nb_word(s, c);
	tab = malloc(sizeof (char *) * (word + 1));
	if (!tab)
		return (0);
	tab = writing(tab, s, c, word);
	return (tab);
}
