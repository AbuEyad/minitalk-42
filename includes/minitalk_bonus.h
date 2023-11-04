/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:14:09 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/04 11:14:33 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
