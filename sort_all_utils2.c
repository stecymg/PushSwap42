/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:02:09 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/21 15:02:10 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_elem2(t_list **stack_a, t_list **stack_b, int valu_a, int value_b)
{
	if ((*stack_b)->index > ft_list_size(*stack_b) / 2)
		while ((*stack_b)->value != value_b)
			reverse_rotate(stack_b, 1, 'b');
	else
		while ((*stack_b)->value != value_b)
			rotate(stack_b, 1, 'b');
	if ((*stack_a)->index > ft_list_size(*stack_a) / 2)
		while ((*stack_a)->value != valu_a)
			reverse_rotate(stack_a, 1, 'a');
	else
		while ((*stack_a)->value != valu_a)
			rotate(stack_a, 1, 'a');
}

void	shift_elem(t_list **stack_a, t_list **stack_b, int value_a, int value_b)
{
	if ((*stack_a)->index > ft_list_size(*stack_a) / 2
		&& (*stack_b)->index > ft_list_size(*stack_b) / 2)
	{
		while ((*stack_b)->value != value_b && (*stack_a)->value != value_a)
		{
			reverse_rotate(stack_b, 0, 'r');
			reverse_rotate(stack_a, 1, 'r');
		}
	}
	else if ((*stack_a)->index <= ft_list_size(*stack_a) / 2
		&& (*stack_b)->index <= ft_list_size(*stack_b) / 2)
	{
		while ((*stack_b)->value != value_b && (*stack_a)->value != value_a)
		{
			rotate(stack_a, 0, 'r');
			rotate(stack_b, 1, 'r');
		}
	}
	shift_elem2(stack_a, stack_b, value_a, value_b);
}

void	move_element(t_list **stack_a, t_list **stack_b, int value)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	temp = *stack_a;
	temp2 = *stack_b;
	while (temp2->value != value)
	{
		i++;
		temp2 = temp2->next;
	}
	(*stack_b)->index = i;
	i = 0;
	while (temp->value != temp2->leader)
	{
		i++;
		temp = temp->next;
	}
	(*stack_a)->index = i;
	shift_elem(stack_a, stack_b, temp2->leader, value);
}

//Quand j'envoie toutes les valeurs de la stack b dans a, je rra ou ra
//tant que ma plus petite valeur n'est pas en haut de ma liste
void	sort_end(t_list **stack_a)
{
	int		smallest;
	t_list	*temp;
	int		i;

	i = 0;
	smallest = smallest_value(*stack_a);
	temp = (*stack_a);
	while (temp->value != smallest)
	{
		temp = temp->next;
		i++;
	}
	if (i > ft_list_size(*stack_a) / 2)
		while ((*stack_a)->value != smallest)
			reverse_rotate(stack_a, 1, 'a');
	else
		while ((*stack_a)->value != smallest)
			rotate(stack_a, 1, 'a');
}

void	send_to_a(t_list **stack_a, t_list **stack_b)
{
	int		value;

	while (*stack_b)
	{
		find_leader(stack_a, stack_b);
		cost_move_a(stack_a);
		cost_move_a(stack_b);
		value = search_value(stack_a, stack_b, 2147483647);
		move_element(stack_a, stack_b, value);
		push(stack_a, stack_b, 'a');
	}
	sort_end(stack_a);
}
