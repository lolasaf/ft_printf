/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:07 by wel-safa          #+#    #+#             */
/*   Updated: 2023/07/03 13:57:33 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			return (-1);
		if (!(str[i] > ' ' && str[i] <= '~'))
			return (-1);
		while (str[j])
		{
			if (j != i && str[j] == str[i])
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(unsigned long long nb, char *base, int count)
{
	if (!(ft_strlen_valid(base) > 1))
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb *= -1;
	}
	if (nb / ft_strlen_valid(base) == 0)
	{
		ft_putchar(base[nb % ft_strlen_valid(base)]);
		count++;
	}
	else
	{
		count = ft_putnbr_base(nb / ft_strlen_valid(base), base, count);
		count = ft_putnbr_base(nb % ft_strlen_valid(base), base, count);
	}
	return (count);
}
