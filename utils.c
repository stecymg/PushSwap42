/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:02:57 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:18:19 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *list)
{
	t_list	*temp;
	int		value;

	temp = list;
	value = temp->value;
	while (temp)
	{
		if (value > temp->value)
			value = temp->value;
		temp = temp->next;
	}
	return (value);
}

// quand value != 0 ca signifie que je dois free mon tab
//flag = 1 signifie que je veux free
void	free_list(t_list *list, int value, int flag)
{
	t_list	*list2;

	list2 = list->next;
	while (list2)
	{
		if (list->value == value && flag == 1)
			free(list->tab_lis);
		if (list->value == value && flag == 1)
			free(list->tab);
		free(list);
		list = list2;
		list2 = list2->next;
	}
	free(list);
}

//creation de ma liste avec ft push front
t_list	*ft_list_push_back(t_list **begin_list, t_list *list)
{
	t_list	*lis;

	lis = *begin_list;
	if (!lis)
	{
		*begin_list = list;
		return (*begin_list);
	}
	else
	{
		while (lis->next != NULL)
		{
			lis = lis->next;
		}
		lis->next = list;
	}
	return (*begin_list);
}

//initialisation de toute la liste avc un ft_sort_in_tab
t_list	*ft_list_push_front(t_list **begin_list, t_list *list)
{
	t_list	*lis;

	lis = NULL;
	if (!(begin_list))
		*begin_list = list;
	else
	{
		lis = list;
		lis->next = *begin_list;
		*begin_list = lis;
	}
	return (*begin_list);
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
