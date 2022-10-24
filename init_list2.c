/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:35 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:01:37 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trouver la plus petite valeur
int	smallest_value(t_list *list)
{
	int	value;

	value = list->value;
	while (list)
	{
		if (list->value < value)
			value = list->value;
		list = list->next;
	}
	return (value);
}

// calcule du cout pour envoyer ma valeur
int	cost_move_a(t_list **stack_a)
{
	int		i;
	int		size;
	t_list	*temp;

	temp = *stack_a;
	i = 0;
	size = ft_list_size(temp);
	while (i < size)
	{
		if (i >= size / 2)
			temp->cost_move = (size - i);
		else
			temp->cost_move = i;
		temp->index = i;
		i++;
		temp = temp->next;
	}
	return (1);
}
