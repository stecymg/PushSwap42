/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:01:39 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:13:58 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_to_one(int *tab, int size)
{
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = 1;
		i++;
	}
	return (tab);
}

int	*list_value(t_list *list, int *tab)
{
	int	*tab_lis;
	int	i;
	int	biggest_lis;

	i = 0;
	biggest_lis = 0;
	while (i < ft_list_size(list))
	{
		if (tab[i] > biggest_lis)
			biggest_lis = tab[i];
		i++;
	}
	tab_lis = malloc(sizeof(int) * biggest_lis);
	while (biggest_lis > 0)
	{
		i--;
		if (tab[i] == biggest_lis)
		{
			biggest_lis--;
			tab_lis[biggest_lis] = list->tab[i];
		}
	}
	free(tab);
	return (tab_lis);
}

int	*find_list(t_list *list, t_list **stack_a)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	tab = NULL;
	tab = init_to_one(tab, ft_list_size(list));
	if (!tab)
		return (0);
	while (i < ft_list_size(list))
	{
		j = 0;
		while (j < i)
		{
			if (list->tab[j] < list->tab[i] && tab[j] + 1 > tab[i])
				tab[i] = tab[j] + 1;
			j++;
		}
		i++;
	}
	(*stack_a)->size_lis = tab[find_index_biggest_number(i, tab)];
	return (list_value(list, tab));
}

//fonction qui tri les liste > 5 nbr
//initialister la listte, trouver list et envoyer les valeurs
//qui ne sont pas dans la stack b et j'envoie les valeurs de B vers A
void	sort_all(int ac, char **av)
{
	int		value;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_init_list_input(ac - 1, av);
	stack_b = NULL;
	value = 0;
	check_sort(&stack_a);
	if (ac == 6 || ac == 5)
		sort_five(stack_a, stack_b, ac);
	else
	{
		if (init_tab(ac, av, &stack_a) != 0)
		{
			stack_a->tab_lis = find_list(stack_a, &stack_a);
			if (stack_a->tab_lis != 0)
			{
				value = stack_a->value;
				send_to_b(&stack_a, &stack_b, stack_a->tab_lis,
					stack_a->size_lis);
				send_to_a(&stack_a, &stack_b);
			}
		}
		free_list(stack_a, value, 1);
	}
}
