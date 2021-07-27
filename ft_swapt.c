
#include "ft_pushswap.h"

void	sa(t_list *stacks)
{
	int	temp;

	temp = stacks->sA[0];
	if (stacks->sA[1] == 0)
		return ;
	stacks->sA[0] = stacks->sA[1];
	stacks->sA[1] = temp;
	ft_print("sa\n");
}

void	sb(t_list *stacks)
{
	int	temp;

	temp = stacks->sB[find_first(stacks) + 1];
	stacks->sB[find_first(stacks) + 1] = stacks->sB[find_first(stacks) + 2];
	stacks->sB[find_first(stacks) + 2] = temp;
	ft_print("sb\n");
}

void	rra(t_list *stacks)
{
	int	i;
	int	j;
	int	last;

	last = find_last(stacks);
	i = last;
	j = stacks->sA[last];
	while (i > 0)
	{
		stacks->sA[i] = stacks->sA[i - 1];
		i--;
	}
	stacks->sA[0] = j;
	ft_print("rra\n");
}

void	rrb(t_list *stacks)
{
	int	i;
	int	j;

	j = stacks->sB[stacks->size];
	i = stacks->size;
	while (i > 0)
	{
		stacks->sB[i] = stacks->sB[i - 1];
		i--;
	}
	stacks->sB[find_first(stacks)] = j;
	ft_print("rrb\n");
}

void	pa(t_list *stacks)
{
	int	i;
	int	save;

	save = stacks->sB[find_first(stacks) + 1];
	if (save == 0)
		return ;
	stacks->sB[find_first(stacks) + 1] = 0;
	i = stacks->size;
	while (i > 0)
	{
		stacks->sA[i] = stacks->sA[i - 1];
		i--;
	}
	stacks->sA[i] = save;
	ft_print("pa\n");
}
