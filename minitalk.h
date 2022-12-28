/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:20:35 by ejachoi           #+#    #+#             */
/*   Updated: 2022/12/28 20:23:15 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "color.h"
# include "libft/libft.h"

# define INITIALIZE_EACH_BIT 0xFF
# define POINT_TO_ONE_BIT 0x80

# define STANDARD_OUTPUT 1
# define STANDARD_ERROR 2

void	exit_error(char *error_message);
void	error_handler(int error_flag);
void	show_pid(char *message);

#endif