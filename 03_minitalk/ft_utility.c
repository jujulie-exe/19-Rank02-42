/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utili_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:33:15 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/11 21:15:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	out_char(int c)
{
	return (write(1, &c, 1));
}

void	ft_kill_check(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}

int	out_digit(int n)
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
		count += out_digit(n / 10);
		count += out_char(n % 10 + '0');
	}
	return (count);
}

void	ft_siganl(int sign, void *handler, bool use)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	if (use)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sign, &sa, NULL) < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	print_pid(void)
{
	int	n;

	n = getpid();
	write(1, "Server PID ", 11);
	out_digit(n);
	write(1, "\n\n", 2);
	write(1, "Hold position\n", 14);
}
