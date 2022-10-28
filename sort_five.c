/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:02:19 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/21 15:02:20 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checker si ma liste a été triée
void	check_sort(t_list **list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (*list);
	temp2 = temp->next;
	while (temp->next)
	{
		if (temp2 == NULL)
		{
			temp = temp->next;
			temp2 = temp->next;
		}
		if (temp2)
		{
			if (temp->value > temp2->value)
				return ;
			temp2 = temp2->next;
		}
	}
	(*list)->tab_lis = NULL;
	(*list)->tab = NULL;
	free_list(*list, 0, 1);
	exit(EXIT_FAILURE);
}

/*
Tri quand il y a 4 ou 5 nbr a trier
conditions (size == 6) pck dans cette taille j'ai l'exec.
Donc si jai 5 numéros + 1 exec ; la taille = 6
 */
void	sort_five(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 6)
	{
		push(&stack_b, &stack_a, 'b');
		push(&stack_b, &stack_a, 'b');
	}
	if (size == 5)
		push(&stack_b, &stack_a, 'b');
	three_value(&stack_a);
	send_to_a(&stack_a, &stack_b);
	free_list(stack_a, 0, 0);
}
