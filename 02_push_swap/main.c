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
	int	n;

	a = NULL;
	n = 0;
	if(argc == 1)
		return (1);
	if(argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_stack_a(&a, argv);
	n = ft_lenstck(a);
	printf("%d", n);
	ft_printf_list(a);
/*	if ( *qualcosa*)
	{
		if(ft_lenstck(a) == 2)
		if(ft_lenstck(a) == 3)
			
		else
	}*/ 

}
