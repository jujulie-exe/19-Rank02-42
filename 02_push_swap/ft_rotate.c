/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:45:05 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 10:45:08 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_exe(t_list **head)
{
	if (empty(head) == 0)
		return ;
	if (*head && (*head)->next != *head)
		*head = (*head)->next;
}

void	ra(t_list **head)
{
	ra_exe(head);
	write(1, "ra\n", 3);
}

void	rb(t_list **head)
{
	ra_exe(head);
	write(1, "rb\n", 3);
}

void	rr(t_list **head_a, t_list **head_b)
{
	ra_exe(head_a);
	ra_exe(head_b);
	write(1, "rr\n", 3);
}
