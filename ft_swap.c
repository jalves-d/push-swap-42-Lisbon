
#include "ft_pushswap.h"

int	find_first(t_list *stacks)
{
	int	i;

	i = 0;
	i = stacks->size;
	while (stacks->sB[i])
		i--;
	return (i);
}

int	find_last(t_list *stacks)
{
	int	i;

	i = 0;
	while (stacks->sA[i])
		i++;
	while (stacks->sA[i] == 0)
		i--;
	return (i);
}

void	ra(t_list *stacks)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = stacks->sA[0];
	last = find_last(stacks);
	while (i <= last)
	{
		stacks->sA[i] = stacks->sA[i + 1];
		i++;
	}
	stacks->sA[last] = j;
	ft_print("ra\n");
}

void	rb(t_list *stacks)
{
	int	first;
	int	i;

	first = stacks->sB[find_first(stacks) + 1];
	i = find_first(stacks) + 1;
	while (i <= stacks->size)
	{
		stacks->sB[i] = stacks->sB[i + 1];
		i++;
	}
	stacks->sB[stacks->size] = first;
	ft_print("rb\n");
}

void	pb(t_list *stacks)
{
	int	i;
	int	temp;


	i = 0;
	temp = stacks->sA[0];
	if (temp == 0)
		exit(0);
	while (i <= stacks->size)
	{
		stacks->sA[i] = stacks->sA[i + 1];
		i++;
	}
	stacks->sB[find_first(stacks)] = temp;
	ft_print("pb\n");
}
