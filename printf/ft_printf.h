/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:49:38 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/24 17:49:39 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>
# include<limits.h>
# include<stdint.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_base(int nbr, char *base);
int		ft_unsigned(unsigned int nb);
char	*ft_uitoa(unsigned int nb);
int		nb_digit(unsigned int nb, int base);
int		ft_printf(const char *str, ...);
int		print_address(unsigned long long nbr);
void	ft_putnbr_hex(unsigned long long nbr, char *base);

#endif
