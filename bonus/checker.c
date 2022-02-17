#include "../push_swap.h"
#include "bonus.h"

int	main(int argc, char **argv)
{
	char				***arguments;
	unsigned int		*stack;
	int					*tmp;
	unsigned long long	length;

	if (argc > 1)
	{
		arguments = ft_collect_arguments(argc, argv);
		length = ft_get_arguments_count(arguments);
		stack = malloc(sizeof(unsigned int) * (length));
		if (!stack)
			ft_error("Memory allocation error!\n");
		tmp = ft_to_int(length, arguments);
		if (ft_duplicate_exist(tmp, length))
			ft_error("Error\n");
		//--------
		ft_execute_commands(stack, length);
	}
	return (0);
}