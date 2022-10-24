/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:04:23 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 13:04:28 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list, char c)
{
	t_list	*list2;

	list2 = (*list)->next;
	(*list)->next = list2->next;
	list2->next = *list;
	*list = list2;
	ft_printf("s%c\n", c);
}

void	push(t_list **list1, t_list **list2, char c)
{
	t_list	*temp;

	temp = (*list2)->next;
	(*list2)->next = *list1;
	*list1 = *list2;
	*list2 = temp;
	ft_printf("p%c\n", c);
}

void	rotate(t_list **list, int i, char c)
{
	t_list	*temp;

	temp = (*list)->next;
	(*list)->next = NULL;
	*list = ft_list_push_back(&temp, *list);
	if (i > 0)
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **list, int i, char c)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *list;
	temp2 = *list;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	*list = ft_list_push_front(list, temp);
	if (i > 0)
		ft_printf("rr%c\n", c);
}
