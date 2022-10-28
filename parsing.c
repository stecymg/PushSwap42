/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:01:01 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:05:52 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n_of_words(char *s, char sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

//checker si jai des chiffres dans ma string et je copie tout 
//dans mon char **sa
char	**check_digit(int ac, char **av)
{
	char	**sa;
	char	*s;
	int		i;

	if (!ft_digit(ac, av))
		ft_error(NULL, 0);
	s = malloc(sizeof(char));
	if (!s)
		ft_error(NULL, 0);
	s[0] = '\0';
	i = 0;
	while (++i < ac)
	{
		if (!av[i])
			break ;
		s = ft_strjoin(s, av[i]);
		if (!s)
			return (NULL);
	}
	sa = ft_split(s, ' ');
	free(s);
	if (!sa)
		return (NULL);
	return (sa);
}

int	check_order(char **strs)
{
	int	i;
	int	counter;

	i = 1;
	counter = 1;
	if (!strs[0])
		return (0);
	while (strs && strs[i + 1])
	{
		if (ft_atoi(strs[i - 1]) < ft_atoi(strs[i]))
			counter++;
		i++;
	}
	if (counter == i)
		return (1);
	return (0);
}

//checker les arguments que je recois
int	check_args(int ac, char **av)
{
	int				i;
	long long int	value;
	int				j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		value = ft_atoi(av[i]);
		if (ft_strlen(av[i]) > 11)
			return (0);
		if ((value > 2147483647) || (value < -2147483648))
			return (0);
		while (j < ac - 1)
		{
			if (value == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
