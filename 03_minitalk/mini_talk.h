/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:15:28 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/11 21:07:06 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

# define BUSY 0
# define READY 1
void	print_pid(void);
void	ft_kill_check(pid_t pid, int sig);
void handle_signal(int sig, siginfo_t *info, void *context);
void	ft_siganl(int sign, void *handler, bool use);

/*typedef struct 	s_server {
	pid_t	client_pid;
	int	received_bits;
	bool	pid_received;
} t_server;*/

#endif
