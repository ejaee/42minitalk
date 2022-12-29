/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:06:41 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/29 12:02:00 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_error(char *error_message)
{
	ft_putstr_fd(RED "Error\n" RESET, STANDARD_ERROR);
	ft_putstr_fd(error_message, STANDARD_ERROR);
	exit(1);
}

void	show_pid(char *message)
{
	ft_putstr_fd(BLUE, STANDARD_OUTPUT);
	ft_putstr_fd(message, STANDARD_OUTPUT);
	ft_putnbr_fd(getpid(), STANDARD_OUTPUT);
	ft_putstr_fd("\n" RESET, STANDARD_OUTPUT);
}
