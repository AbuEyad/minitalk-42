/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:17:39 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/04 11:20:37 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_and_exit(char *error_msg)
{
	ft_printf("Error\n%s\n", error_msg);
	exit(1);
}

static void	server_check(int sig)
{
	(void)sig;
	write(1, "Message Received Successfully\n", 30);
}

static void	char_to_sig(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
			if (!ft_isdigit(argv[1][i++]))
				error_and_exit("Wrong Server PID.");
		pid = ft_atoi(argv[1]);
		if (pid == 0 || kill(pid, 0) == -1)
			error_and_exit("Wrong Server PID.");
		i = 0;
		while (argv[2][i] != '\0')
			char_to_sig(pid, argv[2][i++]);
		signal(SIGUSR2, server_check);
		char_to_sig(pid, '\n');
		char_to_sig(pid, '\0');
	}
	else
		error_and_exit("Wrong number of arguments.");
	return (0);
}
