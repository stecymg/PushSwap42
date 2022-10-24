/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:47 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/21 15:00:49 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strs(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
}

void	ft_error(char **strs, int size)
{
	if (strs)
		free_strs(strs, size);
	ft_printf("Error\n");
	exit(1);
}

int	ft_strlen_tab(char **strs)
{
	int	i;

	i = 0;
	while (ft_strlen(strs[i]))
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	long			i;
	int				signe;
	long long int	nbr;

	nbr = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			signe = signe * 1;
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * signe;
	return (nbr);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**strs;
	int		size;

	strs = check_digit(ac, av);
	size = ft_strlen_tab(strs) + 1;
	if (check_args(size, strs) == 0 || !strs)
		ft_error(strs, size);
	if (size == 4 || size == 3)
	{
		stack_a = ft_init_list_input(size - 1, strs);
		if (size == 3)
		{
			if (check_sort(&stack_a) == 0)
				swap(&stack_a, 'a');
		}
		else
			three_value(&stack_a);
		free_list(stack_a, 0, 0);
	}
	else if (size >= 5)
		sort_all(size, strs);
	free_strs(strs, size);
	return (1);
}
