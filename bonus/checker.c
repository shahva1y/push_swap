#include "bonus.h"

static t_stack	*ft_parse_arguments(int argc, char **argv)
{
	char				***arguments;
	unsigned int		*stack;
	int					*tmp;
	unsigned long long	length;

	arguments = ft_collect_arguments(argc, argv);
	length = ft_get_arguments_count(arguments);
	stack = malloc(sizeof(unsigned int) * (length));
	if (!stack)
		ft_error("Memory allocation error!\n");
	tmp = ft_to_int(length, arguments);
	if (ft_duplicate_exist(tmp, length))
		ft_error("Error\n");
	ft_index(&tmp, stack, length);
	return (create_stack(stack, length));
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = ft_parse_arguments(argc, argv);
		ft_execute_commands(&stack_a, &stack_b);
		if (stack_a->value != 0 || !ft_is_sorted(stack_a) || stack_b != NULL)
			ft_error("KO\n");
		write(1, "OK\n", 3);
	}
	return (0);
}
