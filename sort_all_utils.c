/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:01:58 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:15:41 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_leader_utils(t_list **temp, t_list **temp2, int i)
{
	while (*temp)
	{
		if ((*temp)->value > (*temp2)->value)
		{
			if ((*temp)->value - (*temp2)->value > 0)
			{
				if ((*temp)->value - (*temp2)->value < i)
				{
					(*temp2)->leader = (*temp)->value;
					i = (*temp)->value - (*temp2)->value;
				}
			}
		}
		*temp = (*temp)->next;
	}
}

void	find_leader(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_a;
	temp2 = *stack_b;
	while (temp2)
	{
		temp2->leader = smallest_value(temp);
		find_leader_utils(&temp, &temp2, 2147483647);
		temp2 = temp2->next;
		temp = *stack_a;
	}
}

/*1) chercher dans la stack a stack_a->value == value,
quand j'ai trouve je check le cost_move
2) Si cost_move > size_list/2 je = RRA while(*list->value != value)
3) Sinon RA = while (*list->value != value)
4) Quand la valeur que je veux envoyer est en haut de la stack 
je l'envoie dans ma stack B
*/
void	pb_condition(t_list **stack_a, t_list **stack_b, int value)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp && temp->value != value)
		temp = temp->next;
	if (temp)
	{
		if (temp->cost_move > ft_list_size(temp) / 2)
			while ((*stack_a)->value != value)
				rotate(stack_a, 1, 'a');
		else
			while ((*stack_a)->value != value)
				rotate(stack_a, 1, 'a');
		push(stack_b, stack_a, 'b');
	}
}

/*
chercher la valeur de List pour l'envoyer dans la stack_b
1)checker si la valeur de temp est dans mon tab
2)Si la valeur dans temp est dans mon tab j'attribue un cost_move
à tous les élément de ma liste avant d'appeler pb_condition ou je l'envoie en b
tab = valeur de mon list
size_list = longueur de ma list
 */
void	send_to_b(t_list **st_a, t_list **stack_b, int *tab, int size_lis)
{
	int		j;
	t_list	*temp;

	temp = (*st_a);
	j = 0;
	while (temp)
	{
		while (j < size_lis && tab[j] != temp->value)
			j++;
		if (j >= size_lis)
		{
			cost_move_a(st_a);
			pb_condition(st_a, stack_b, temp->value);
			temp = *st_a;
		}
		else
			temp = temp->next;
		j = 0;
	}
}
