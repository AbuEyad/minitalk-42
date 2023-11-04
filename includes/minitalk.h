/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:20:10 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/02 20:05:05 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_pointer(unsigned long ptr);
int	ft_hexlower(unsigned int nb);
int	ft_hexupper(unsigned int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_atoi(const char	*str);
int	ft_isdigit(int c);

#endif
