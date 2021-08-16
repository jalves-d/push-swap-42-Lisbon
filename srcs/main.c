#include "pushswap.h"

void	swapt(t_list *stacks)
{
	int	last;
	int	middle;
	int	first;

	first = stacks->sA[0];
	middle = stacks->sA[1];
	last = stacks->sA[2];
	if (first > middle && middle < last && last > first)
		sa(stacks);
	else if (first > middle && middle > last && last < first)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > middle && middle < last && last < first)
		ra(stacks);
	else if (first < middle && middle > last && last > first)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first < middle && middle > last && last < first)
		rra(stacks);
}

void	swapa(t_list *stacks, int middle)
{
	int	size;

	while (stacks->sA[0] < middle)
		pb(stacks);
	size = sizes(stacks, 'a');
	ft_hl(stacks, middle);
	while (ft_hl(stacks, middle))
	{
		while (stacks->sA[0] < middle)
			pb(stacks);
		if (stacks->pos > size / 2)
			rra(stacks);
		else
			ra(stacks);
		while (stacks->sA[0] < middle)
			pb(stacks);
	}
}

void	swapb(t_list *stacks)
{
	int	new_size;
	int	dist;

	if (stacks->sB[find_first(stacks) + 2] == stacks->sB[find_big(stacks)]
		&& sizes(stacks, 'b') > 3)
		sb(stacks);
	new_size = sizes(stacks, 'b');
	new_size = new_size / 2;
	dist = (find_big(stacks) - find_first(stacks));
	while (stacks->sB[find_first(stacks) + 1]
		!= stacks->sB[find_big(stacks)])
	{
		if (dist > new_size)
			rrb(stacks);
		else
			rb(stacks);
	}
	pa(stacks);
}

void	ft_parssing(t_list *stacks, char **argv, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	stacks->size = size;
	stacks->pos = 0;
	stacks->ch = 0;
	if (check_dup(argv) || check_char(argv))
		exit(0);
	stacks->sA = ft_calloc(stacks->size + 1, sizeof(int));
	stacks->sB = ft_calloc(stacks->size + 1, sizeof(int));
	while (++i < stacks->size)
	{
		stacks->sA[i] = ft_atoi(argv[j]);
		if (ft_atoi(argv[j]) == 0)
			stacks->sA[i] = -1;
		j++;
	}
	if (!ft_checkord(stacks))
		exit(0);
}

int	main(int argc, char **argv)
{
	t_list	stacks;
	int		middle;

	ft_parssing(&stacks, argv, argc - 1);
	if (argc == 4)
		swapt(&stacks);
	else
	{
		while (sizes(&stacks, 'a') > 3)
		{
			if (argc - 1 <= 101)
				middle = ft_mop(&stacks, 2);
			else
				middle = ft_mop(&stacks, 10);
			swapa(&stacks, middle);
		}
		swapt(&stacks);
		while (sizes(&stacks, 'b') > 0)
			swapb(&stacks);
	}
	free(stacks.sA);
	free(stacks.sB);
}
