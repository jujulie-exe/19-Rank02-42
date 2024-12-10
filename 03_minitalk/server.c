/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:07:19 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 14:32:49 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	received_signal()
{
}


void	recived_pid(int pid)
{
}

int	main()
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid(void);
	ft_itoa(pid, pid_str);

	write(1, , len_pid);

}
