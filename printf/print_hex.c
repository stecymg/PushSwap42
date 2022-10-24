/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:49:59 by smontgen          #+#    #+#             */
/*   Updated: 2022/10/24 17:50:00 by smontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long long nbr, char *base)
{
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb > 0)
	{
		ft_putnbr_hex(nb / 16, base);
		nb = nb % 16;
		ft_putchar(base[nb]);
	}
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr != 0)
		ft_putnbr_hex(nbr, base);
	else
		ft_putchar(0 + '0');
	len = nb_digit(nbr, 16);
	return (len);
}
