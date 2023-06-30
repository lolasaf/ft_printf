/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:58 by wel-safa          #+#    #+#             */
/*   Updated: 2023/06/30 19:31:51 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *s);
int		ft_printstr(char *s);
int		ft_putchar(char c);
int		ft_strlen_valid(char *str);
void	ft_putnbr_base(unsigned long long nb, char *base);
void	ft_putptr(void *ptr);
void	ft_putunsignednbr_fd(unsigned int n, int fd);

#endif
