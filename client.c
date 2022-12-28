/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:05:25 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/28 20:44:46 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shift(char c, int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c & POINT_TO_ONE_BIT)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		usleep(500);
	}	
}

void	set_message(char *message, int pid)
{
	int	i;

	i = -1;
	while (message[++i])
		shift(message[i], pid);
	shift('\0', pid);
}

void	send_client_pid(int pid)
{
	set_message("\n[client pid] ", pid);
	set_message(ft_itoa(getpid()), pid);
	set_message("\n", pid);
}

void	send_client_message(char **argv, int pid)
{
	int	i;

	i = 1;
	while (argv[++i])
	{
		set_message(argv[i], pid);
		if (argv[i])
			shift(' ', pid);
	}
}



int main(int argc, char **argv)
{
    int	pid;

    if (argc < 3 || argv[2][0] == '\0')
        exit_error("invalid argc\n");
    pid = ft_atoi(argv[1]);
    if (pid < 101 || 99999 < pid)
        exit_error("invalid server pid\n");
    show_pid("[client pid] ");
    send_client_pid(pid);
	send_client_message(argv, pid);
	exit(0);
}
