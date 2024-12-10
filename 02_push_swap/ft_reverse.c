/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:44:36 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 10:44:37 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_exe(t_list **head)
{
	if (empty(head) == 0)
		return ;
	if (*head && (*head)->next != *head)
		*head = (*head)->prev;
}

void	rra(t_list **head)
{
	rra_exe(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head)
{
	rra_exe(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra_exe(head_a);
	rra_exe(head_b);
	write(1, "rrr\n", 4);
}
