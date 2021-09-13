/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:47:13 by jalves-d          #+#    #+#             */
/*   Updated: 2021/09/13 16:00:55 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swapt(t_list *stacks)
{
	int	last;
	int	middle;
	int	first;

	first = stacks->sa[0];
	middle = stacks->sa[1];
	last = stacks->sa[2];
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

	while (stacks->sa[0] < middle)
		pb(stacks);
	size = sizes(stacks, 'a');
	ft_hl(stacks, middle);
	while (ft_hl(stacks, middle))
	{
		while (stacks->sa[0] < middle)
			pb(stacks);
		if (stacks->pos > size / 2)
			rra(stacks);
		else
			ra(stacks);
		while (stacks->sa[0] < middle)
			pb(stacks);
	}
}

void	swapb(t_list *stacks)
{
	int	new_size;
	int	dist;

	if (find_first(stacks) + 2 < ft_len(stacks->sb))
		if (stacks->sb[find_first(stacks) + 2] == stacks->sb[find_big(stacks)])
			if (sizes(stacks, 'b') > 3)
				sb(stacks);
	new_size = sizes(stacks, 'b');
	new_size = new_size / 2;
	dist = (find_big(stacks) - find_first(stacks));
	while (stacks->sb[find_first(stacks) + 1]
		!= stacks->sb[find_big(stacks)])
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
	stacks->sa = ft_calloc(stacks->size + 1, sizeof(int));
	stacks->sb = ft_calloc(stacks->size + 1, sizeof(int));
	while (++i < stacks->size)
	{
		stacks->sa[i] = ft_atoi(argv[j]);
		if (ft_atoi(argv[j]) == 0)
			stacks->sa[i] = -1;
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
	else if (stacks.size > 2)
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
	checklastwo(&stacks);
	free(stacks.sa);
	free(stacks.sb);
}
