/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:05:21 by wel-safa          #+#    #+#             */
/*   Updated: 2023/06/30 19:36:35 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//include "ft_putnbr_base.c"

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

int	ft_printstr(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (ft_strlen(s) == 0)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	ft_putptr(void *ptr)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_base(address, "0123456789abcdef");
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = n;
	if (fd < 0)
		return ;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	if (ln / 10 > 0)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	if (ln / 10 == 0)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
}

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	long unsigned int	ln;
	char				c;

	ln = n;
	if (fd < 0)
		return ;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	if (ln / 10 > 0)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	if (ln / 10 == 0)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	strl;
	size_t	i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	strl = ft_strlen(str);
	va_start(args, str);
	while (i < strl)
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				count += ft_putchar('%');
			else if (str[i + 1] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (str[i + 1] == 's')
				count += ft_printstr(va_arg(args, char *));
			else if (str[i + 1] == 'p')
				ft_putptr(va_arg(args, void *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i + 1] == 'u')
				ft_putunsignednbr_fd(va_arg(args, unsigned int), 1);
			else if (str[i + 1] == 'x')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			if (str[i + 1] != '\0')
				i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
/*
int	main(void)
{
	char c = 'Z';
	char *p = &c;
	int d = -2147483648;
	int i = 2147483647;
	unsigned int u = 4294967295;
	unsigned int x = 42949645;
	unsigned int X = 42949645;

	//printf("printf: %% %c %p %s %d %i %u %x %X\n",
	//c, p, "String", d, i, u, x, X);
	//ft_printf("fprint: %% %c %p %s %d %i %u %x %X\n",
	//c, p, "String", d, i, u, x, X);
	//printf("ft_putnbr_base: ");
	int a = 0;
	int b = 0;
	a = printf("printf= |%s|\n", "");
	b = ft_printf("fprint= |%s|\n", "");
	printf("%i %i \n", a, b);

	a = printf("printf= |%c|\n", '0');
	b = ft_printf("fprint= |%c|\n", '0');
	printf("%i %i \n", a, b);
	
	a = printf("printf= NULL %s NULL \n", (char *)NULL);
	b = ft_printf("fprint= NULL %s NULL \n", NULL);
	printf("%i %i \n", a, b);
	return 0;
}*/