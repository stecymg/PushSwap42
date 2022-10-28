/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:03:08 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 12:19:41 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//je check si jai que jai digit dans mon char je retourne 0 sinon 1
int	ft_digit(int ac, char **av)
{
	int		i;
	int		val;

	while (--ac)
	{
		val = 0;
		i = 0;
		while (av[ac][i] == ' ')
			i++;
		if (av[ac][i] == '-')
			i++;
		while ((av[ac][i] >= '0' && av[ac][i] <= '9'))
		{
			val = 1;
			i++;
		}	
		while (av[ac][i])
			if (av[ac][i++] != ' ')
				return (0);
		if (val == 0)
			return (0);
	}
	return (1);
}

/*calcule de la distance entre le haut et le bas de la valeur dans
la stack_b et son leader
ensuite j'additione si le résultat est plus petit que le
précédent 
i = est devenu ce résultat et la valeur est devenue la valeur de stack_b
je le fais tant que j'ai pas fini */
int	search_value(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*temp;
	t_list	*temp2;
	int		value;

	temp = *stack_a;
	temp2 = *stack_b;
	value = temp2->value;
	while (temp2)
	{
		while (temp)
		{
			if (temp2->leader == temp->value)
			{
				if (i >= temp2->cost_move + temp->cost_move)
				{
					i = temp2->cost_move + temp->cost_move;
					value = temp2->value;
				}
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
		temp = *stack_a;
	}
	return (value);
}

// renvoie le nombre d'élément de ma liste
int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

//creation de nouveau élément ds ma liste et initialiser la valeur ds mn élém
t_list	*ft_create_element(int value)
{
	t_list	*pwd;

	pwd = malloc(sizeof(t_list) * 2);
	if (!pwd)
		return (0);
	pwd -> next = NULL;
	pwd -> value = value;
	return (pwd);
}
