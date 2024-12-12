/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:47:05 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/11 21:10:49 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		current_bit = 0;
	static char		current_char = 0;
	static pid_t	client_pid;

	if (info->si_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		current_char &= ~(1 << current_bit);
	else if (sig == SIGUSR2)
		current_char |= (1 << current_bit);
	current_bit++;
	if (current_bit == CHAR_BIT)
	{
		current_bit = 0;
		if (current_char == '\0')
		{
			write(1, "\n<<Received transmission>>\n", 27);
			kill(client_pid, SIGUSR1);
			current_char = 0;
			return ;
		}
		write(1, &current_char, 1);
		current_char = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	print_pid();
	ft_siganl(SIGUSR1, handle_signal, true);
	ft_siganl(SIGUSR2, handle_signal, true);
	while (1)
		pause();
	return (0);
}
