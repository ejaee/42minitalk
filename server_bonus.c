/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:33:40 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/28 20:34:39 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handshake(char *status_message)
{
	ft_putstr_fd(GREEN "status :" RESET, STANDARD_OUTPUT);
	ft_putstr_fd(status_message , STANDARD_OUTPUT);
}

void	receive_message(char char_buffer)
{
	ft_putstr_fd(YELLOW, STANDARD_OUTPUT);
	ft_putchar_fd(char_buffer, STANDARD_OUTPUT);
	ft_putstr_fd(RESET, STANDARD_OUTPUT);
}

void	get_message(int sig_num, struct __siginfo *info, void *vo)
{
	static char	char_buffer = INITIALIZE_EACH_BIT;
	static int	bit = 0;
	static int	pid = 0;

	(void)*vo;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		char_buffer = INITIALIZE_EACH_BIT;
	}
	if (sig_num == SIGUSR1)
		char_buffer |= POINT_TO_ONE_BIT >> bit;
	else
		char_buffer ^= POINT_TO_ONE_BIT >> bit;
	if (++bit == 8)
	{
        if (!char_buffer)
			kill(pid, SIGUSR2);
		receive_message(char_buffer);
		bit = 0;
		char_buffer = INITIALIZE_EACH_BIT;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 1 || argv[1] != NULL)
		exit_error("invalid argc\n");
	act.sa_sigaction = get_message;
	act.sa_flags = SA_SIGINFO;
	handshake("create socket!\n");
	show_pid("[server pid] ");
	handshake("waiting\n");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
