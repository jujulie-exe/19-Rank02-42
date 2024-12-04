/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:08:39 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/04 14:08:52 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_stack_init(t_list **head_a, char **argv)
{
	int	i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return ;
		if (*head_a == NULL)
			*head_a = lstnew((int)(n));
		else
			lstadd(head_a, (int)n);
		i++;

	}
	// mettere if per la verifica della stringa isdigit
	// mettere il controllo di ripetizione
	// mettere il free per argv
	
}

void init(t_list **head_a, t_list **head_b)
{
	set_index(head_a);
	set_index(head_b);
	set_target(head_a, head_b);
	set_price(head_a, head_b);
	set_cheapest(head_b);
}


