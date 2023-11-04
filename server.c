/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:25:51 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/03 16:47:46 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_and_exit(char *error_msg)
{
	ft_printf("Error\n%s\n", error_msg);
	exit(1);
}

void	sig_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	word;
	static int	pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
		error_and_exit("Message interrupted.");
	if (sig == SIGUSR1)
		word += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write (1, &word, 1);
		if (word == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			pid = 0;
		}
		word = 0;
		bit = 0;
	}
}

static void	setup_sig_handler(struct sigaction *act, int sig)
{
	if (sig == SIGUSR1)
		sigaddset(&act->sa_mask, SIGUSR2);
	else if (sig == SIGUSR2)
		sigaddset(&act->sa_mask, SIGUSR1);
	else
		error_and_exit("Incorrect SIGUSR provided.");
	act->sa_sigaction = sig_to_char;
	act->sa_flags = SA_SIGINFO;
	sigaction(sig, act, NULL);
}

int	main(int argc, char **argv)
{
	struct sigaction	act0;
	struct sigaction	act1;

	(void)argv;
	if (argc != 1)
	{
		printf("ERROR, No arguments needed!\n");
		return (1);
	}
	ft_printf("PID : %d\n", getpid());
	setup_sig_handler(&act0, SIGUSR1);
	setup_sig_handler(&act1, SIGUSR2);
	while (1)
	{
		pause();
	}
	return (0);
}
