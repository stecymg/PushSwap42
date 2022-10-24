/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:01:27 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/22 11:51:25 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	int				value;
	int				leader;
	int				distance;
	int				cost_move;
	char			**strs;
	int				*tab;
	int				*tab_list;
	int				size_list;
	int				index;
}	t_list;

char		**check_digit(int ac, char **av);
void		init_list(t_list **list, int ac, char **av);
void		print_list(t_list *beta);
void		free_list(t_list *list, int value, int flag);
t_list		*ft_create_element(int value);
t_list		*ft_init_list_input(int size, char **strs);
t_list		*ft_list_push_back(t_list **begin_list, t_list *list);
t_list		*ft_list_push_front(t_list **begin_list, t_list *list);
int			check_args(int ac, char **av);
void		swap(t_list **list, char c);
void		push(t_list **list1, t_list **list2, char c);
void		rotate(t_list **list, int i, char c);
void		reverse_rotate(t_list **list, int i, char c);
int			ft_list_size(t_list *begin_list);
int			check_sort(t_list **list);
int			init_tab(int ac, char **av, t_list **list);
int			find_index_biggest_number(int ac, int *tab);
int			cost_move_a(t_list **list);
void		three_value(t_list **list);
void		sort_all(int ac, char **av);
void		send_to_b(t_list **st_a, t_list **stack_b, int *tab, int size_list);
int			smallest_value(t_list *list);
void		send_to_a(t_list **stack_a, t_list **stack_b);
int			search_value(t_list **stack_a, t_list **stack_b, int i);
void		find_leader(t_list **stack_a, t_list **stack_b);
long long	ft_atoi(const char *str);
char		**ft_split(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
int			check_n_of_words(char *s, char sep);
int			ft_digit(int ac, char **av);
int			ft_strlen(char *str);
void		ft_error(char **strs, int size);
void		sort_five(t_list *stack_a, t_list *stack_b, int size);

#endif
