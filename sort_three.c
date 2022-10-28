/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:02:47 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/21 15:02:48 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_case(t_list **list)
{
	int	value1;
	int	value2;

	value1 = (*list)->value - (*list)->next->next->value;
	value2 = (*list)->value - (*list)->next->value;
	if (value1 < 0)
		swap(list, 'a');
	else if (value1 > value2)
	{
		swap(list, 'a');
		reverse_rotate(list, 1, 'a');
	}
	else if (value1 < value2)
		rotate(list, 1, 'a');
}

void	other_case(t_list **list)
{
	int	value;

	value = (*list)->value - (*list)->next->next->value;
	if (value < 0)
	{
		swap(list, 'a');
		rotate(list, 1, 'a');
	}
	else
	{
		reverse_rotate(list, 1, 'a');
	}
}

void	three_value(t_list **list)
{
	t_list	*temp;

	temp = (*list);
	check_sort(list);
	if (temp->value > temp->next->value)
	{
		first_case(list);
	}	
	else
	{
		other_case(list);
	}
}
