#include "push_swap.h"

void    ft_printf_list(t_list *head)
{
    if (head == NULL)
        return;

    t_list *current = head;
    while (1)
    {
            printf("Valore: %d\n", current->value);
            current = current->next;
            if (current == head)
                    break;
    }

}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	n;

	a = NULL;
	b = NULL;
	n = 0;
	if(argc == 1)
		return (1);
	if(argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_stack_a(&a, argv);
	n = ft_lenstck(a);
	printf("%d\n", n);
	ft_printf_list(a);
	printf("-----PRIMA----\n");
	if (a != NULL)
	{
		if(ft_lenstck(a) == 2)
			ft_two_short(&a);
		if(ft_lenstck(a) == 3)
			ft_ts(&a);
		else
			insertion_short(&a, &b);
	}
	printf("-----DOPO------\n");
	ft_printf_list(a);

}
