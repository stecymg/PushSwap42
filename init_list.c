/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:22 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:12:08 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initialiser ma list avec les valeurs recu en input 
t_list	*ft_init_list_input(int size, char **strs)
{
	t_list	*element;
	t_list	*last_element;

	last_element = 0;
	while (size)
	{
		size--;
		element = ft_create_element(ft_atoi(strs[size]));
		element->leader = 0;
		element->next = last_element;
		last_element = element;
	}
	last_element = NULL;
	free(last_element);
	return (element);
}

int	init_tab(int ac, char **av, t_list **list)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	(*list)->tab = malloc(sizeof(int) * ac + 1);
	if (!(*list)->tab)
		return (0);
	while (av[j])
		(*list)->tab[i++] = ft_atoi(av[j++]);
	(*list)->tab[i] = '\0';
	return (1);
}

//cherche l'index de la plus grande valeur de ma liste
int	find_index_biggest_number(int ac, int *tab)
{
	int	i;
	int	next_value;

	next_value = 1;
	i = 0;
	while (next_value < ac)
	{
		if (tab[i] < tab[next_value])
			i = next_value;
		next_value++;
	}
	return (i);
}
