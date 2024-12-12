/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:33:15 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/11 21:15:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

volatile sig_atomic_t	g_server_reponse = BUSY;

void	end_message(void)
{
	write(1, "OK!\n", 4);
	exit (0);
}

void	ready_or_not(void)
{
	g_server_reponse = READY;
}

void	send_message(pid_t server_pid, char message)
{
	int	bit;
	int	bit_value;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		bit_value = (message >> bit) & 1;
		if (bit_value == 0)
			ft_kill_check(server_pid, SIGUSR1);
		else
			ft_kill_check(server_pid, SIGUSR2);
		bit++;
		while (g_server_reponse == BUSY)
			usleep(100);
		g_server_reponse = BUSY;
	}
}

int	main(int argc, char **argv)
{
	const char	*message;
	pid_t		server_pid;

	if (argc != 3)
	{
		write(1, "./client PID_SERVER STRING_TO_PASS\n", 35);
		return (1);
	}
	server_pid = ft_atol(argv[1]);
	message = argv[2];
	ft_siganl(SIGUSR2, ready_or_not, false);
	ft_siganl(SIGUSR1, end_message, false);
	while (*message)
		send_message(server_pid, *message++);
	send_message(server_pid, '\0');
	return (0);
}
