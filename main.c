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

int	ft_strlen_tab(char **strs)
{
	int	i;

	i = 0;
	while (ft_strlen(strs[i]))
		i++;
	return (i);
}

void	free_strs(char **strs, int size)
{
	int	i;

	i = 0;
	size = ft_strlen_tab(strs) + 1;
	if (strs && size)
	{
		while (i < size && strs[i])
			free(strs[i++]);
		free(strs);
	}
	strs = NULL;
}

void	ft_error(char **strs, int size)
{
	if (strs)
		free_strs(strs, size);
	ft_printf("Error\n");
	exit(1);
}

void	check_errors(int size, char **strs)
{
	if (check_args(size, strs) == 0 || !strs)
		ft_error(strs, size);
	if (check_order(strs))
	{
		free_strs(strs, size);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**strs;
	int		size;

	if (ac == 1)
		return (1);
	strs = check_digit(ac, av);
	size = ft_strlen_tab(strs) + 1;
	check_errors(size, strs);
	if (size == 4 || size == 3)
	{
		stack_a = ft_init_list_input(size - 1, strs);
		check_sort(&stack_a);
		if (size == 3)
		{
			check_sort(&stack_a);
			swap(&stack_a, 'a');
		}
		else
			three_value(&stack_a);
		free_list(stack_a, 0, 0);
	}
	else if (size >= 5)
		sort_all(size, strs);
	return (free_strs(strs, size), 0);
}
