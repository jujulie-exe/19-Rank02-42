#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

typedef	struct s_list
{
	int		value;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

void	rra(t_list **head);
void	rrb(t_list **head);
void	rrr(t_list **head_a, t_list **head_b);

void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);

void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_b, t_list **head_a);

void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **head_a, t_list **head_b);

t_list	*lstnew(int value);
void	lstadd(t_list **head, int value);
void	lstadd_head(t_list **head, int value);
void	lstdelone(t_list **head, t_list *node);
void	lstclear(t_list **head);
int	ft_lenstck(t_list *head);
void	ft_stack_a(t_list **head_a, char **argv);

int	atoi(const char	*str);
char	**ft_split(char const *s, char c);


void	ft_ts(t_list **head);
void	ft_two_short(t_list **head);

void	exe_sa(t_list **head);
void	exe_ra(t_list **head);
void	exe_rra(t_list **head);
void	exe_pa(t_list **head_a, t_list **head_b);

void	exe_sb(t_list **head);
void	exe_rb(t_list **head);
void	exe_rrb(t_list **head);
void	exe_pb(t_list **head_b, t_list **head_a);

void	exe_rrr(t_list **head_a, t_list **head_b);
void	exe_ss(t_list **head_a, t_list **head_b);
void	exe_rr(t_list **head_a, t_list **head_b);
	


#endif
