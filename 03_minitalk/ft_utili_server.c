/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utili_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:33:15 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 16:55:56 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signal_hander(int sig, siginfo_t *info, void *context)
{
	t_server	*server;

	server = (t_server *)info->si_value.sival_ptr;
	server->client_pid<<=1;
	if (sig == SIGUSR2)
		server->client_pid |= 1;
	else if (sig == SIGUSR1)
		server->client_pid &= -1;
	server->received_bits++;
	if (server->received_bits == PID_BITS)
		server->pid_received = true;

}

void	set_signal_handlers(t_server *server)
{
	struct sigaction sa;

	sa.sa_flags = 0;
	sa.sa_handler = (void (*)(int))signal_hander;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		exit (1);
	}
}

pid_t	receive_pid(t_server *server)
{
	server->client_pid = 0;
	server->received_bits = 0;
	server->pid_received = false;

	while (!server->pid_received)
		pause();
	return server->client_pid;
}

int	out_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n == INT_MAX)
		return (write(1, "2147483647", 10));
	if (n < 0)
	{
		count += out_char('-');
		n = -n;
	}
	if (n < 10)
	{
		count += out_char(n + '0');
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += out_char(n % 10 + '0');
	}
	return (count);
}

void	print_pid()
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr((int)pid);
}

int	main()
{
	t_server	server;
	pid_t		pid;
	print_pid();
	set_signal_handlers(&server);
	while (1)
	{
		pid_t	client_pid = receive_pid(&server);
	}
}

