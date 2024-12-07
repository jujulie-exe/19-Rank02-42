#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

typedef	struct s_list
{
	int		value;
	int		index;
	int		final_index;
	int		push_price;
	bool	above_median;
	bool	cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

void		rra(t_list **head);
void		rrb(t_list **head);
void		rrr(t_list **head_a, t_list **head_b);

void		sa(t_list **head);
void		sb(t_list **head);
void		ss(t_list **head_a, t_list **head_b);

void		pa(t_list **head_a, t_list **head_b);
void		pb(t_list **head_b, t_list **head_a);

void		ra(t_list **head);
void		rb(t_list **head);
void		rr(t_list **head_a, t_list **head_b);

t_list		*lstnew(int value);
void		lstadd(t_list **head, int value);
void		lstadd_head(t_list **head, int value);
void		lstdelone(t_list **head, t_list *node);
void		lstclear(t_list **head);
int		ft_lenstck(t_list *head);
void		ft_stack_a(t_list **head_a, char **argv);

long long	ft_atol(const char	*str);
char		**ft_split(char const *s, char c);

void		shell_short(t_list **head_a, t_list **head_b);
void		insertion_short(t_list **head_a, t_list **head_b);
int		is_sorted(t_list **head);
int		empty(t_list **head);
void		ft_ts(t_list **head);
void		ft_two_short(t_list **head);

//*** ft_set_value.c ***

void		set_index(t_list **head);
t_list		*find_best_match(t_list **head_a, t_list *head_b);
void		set_target(t_list **head_a, t_list **head_b);
void		set_price(t_list **head_a, t_list **head_b);
void		set_cheapest(t_list	**head_b);

//** ft_utils_list.c ***

int		ft_lenstck(t_list *head);
t_list		*find_smallest(t_list **head);
t_list	*	return_cheapest(t_list **head);

//** ft_init_.c ***

void		ft_stack_init(t_list **head_a, char **argv, bool control);
void		init(t_list **head_a, t_list **head_b);

//** push_swap.c ***

void		push_swap(t_list **head_a, t_list **head_b);
void		rot_both_rev(t_list **head_a, t_list **head_b, t_list *cheapest, char a);
void		end_rot(t_list **head, t_list *top, char n);
int		move(t_list **head_a, t_list **head_b);

//** exit_and_free ***

void		ft_check_double(t_list **head,char **argv, bool control);
void		exit_and_free(t_list **head, char **argv, bool control);
int		ft_istrdigit(char *s);
void		free_argv(char **str);
void		free_stack(t_list **head);



#endif
