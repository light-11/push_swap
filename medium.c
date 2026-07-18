/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:03:19 by miida             #+#    #+#             */
/*   Updated: 2026/07/15 22:52:24 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_approx_sqrt(int nodes)
{
	int	i;

	i = 1;
	if (nodes <= 0)
		return (0);
	while (i <= nodes / i)
		i++;
	return (i - 1);
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	moved;
	int	target_count;

	moved = 0;
	target_count = max - min + 1;
	while (moved < target_count && *stack_a)
	{
		if ((*stack_a)->rank >= min && (*stack_a)->rank <= max)
		{
			push_b(stack_a, stack_b);
			moved++;
		}
		else
			rotate_a(stack_a);
	}
}

int	find_max_rank(t_list *stack_b)
{
	int	max;

	max = -1;
	while (stack_b)
	{
		if (stack_b->rank > max)
			max = stack_b->rank;
		stack_b = stack_b->next;
	}
	return (max);
}

int	find_target_index(t_list *stack_b, int target)
{
	int	index;

	index = 0;
	while (stack_b)
	{
		if (stack_b->rank == target)
			return (index);
		stack_b = stack_b->next;
		index++;
	}
	return (-1);
}

void	rb_or_rrb(t_list **stack_b, int target_idx)
{
	int	total;

	total = count_node(stack_b);
	if (target_idx <= total / 2)
	{
		while (target_idx-- > 0)
			rotate_b(stack_b);
	}
	else
	{
		while (target_idx++ < total)
			reverse_rotate_b(stack_b);
	}
}

void	return_to_a(t_list **stack_a, t_list **stack_b)
{
	int	target;
	int	idx;

	target = find_max_rank(*stack_b);
	idx = find_target_index(*stack_b, target);
	rb_or_rrb(stack_b, idx);
	push_a(stack_a, stack_b);
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	int	min_rank;
	int	max_rank;
	int	total;

	total = count_node(stack_a);
	chunk_size = get_approx_sqrt(total);
	min_rank = 0;
	max_rank = chunk_size - 1;
	while (min_rank < total)
	{
		move_to_b(stack_a, stack_b, min_rank, max_rank);
		min_rank += chunk_size;
		max_rank += chunk_size;
	}
	max_rank = total - 1;
	min_rank = max_rank - chunk_size;
	while (*stack_b)
		return_to_a(stack_a, stack_b);
	while (*stack_b)
        push_a(stack_a, stack_b);
}
