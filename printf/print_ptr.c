/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:50:09 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/24 17:50:11 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	print_ptr(uintptr_t nbr, char *base)
{
	if (nbr > 0)
	{
		print_ptr(nbr / 16, base);
		ft_putchar(base[nbr % 16]);
	}
}

int	count_digit(uintptr_t nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	print_address(unsigned long long nbr)
{
	int		len;

	len = 0;
	if (nbr != 0)
	{
		len = write(1, "0x", 2);
		print_ptr(nbr, "0123456789abcdef");
		len += count_digit(nbr);
	}
	else
		len = ft_putstr("0x0");
	return (len);
}
