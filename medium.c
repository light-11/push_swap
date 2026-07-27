/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:03:19 by miida             #+#    #+#             */
/*   Updated: 2026/07/27 16:06:04 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **stack_a, t_list **stack_b, int min, int max,
		t_command *command)
{
	int	moved;
	int	target_count;

	moved = 0;
	target_count = max - min + 1;
	while (moved < target_count && *stack_a)
	{
		if ((*stack_a)->rank >= min && (*stack_a)->rank <= max)
		{
			push_b(stack_a, stack_b, command);
			moved++;
		}
		else
			rotate_a(stack_a, command);
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

void	return_to_a(t_list **stack_a, t_list **stack_b, t_command *command)
{
	int	target;
	int	idx;

	target = find_max_rank(*stack_b);
	idx = find_target_index(*stack_b, target);
	rb_or_rrb(stack_b, idx, command);
	push_a(stack_a, stack_b, command);
}

void	medium(t_list **stack_a, t_list **stack_b, t_command *command)
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
		move_to_b(stack_a, stack_b, min_rank, max_rank, command);
		min_rank += chunk_size;
		max_rank += chunk_size;
	}
	max_rank = total - 1;
	min_rank = max_rank - chunk_size;
	while (*stack_b)
		return_to_a(stack_a, stack_b, command);
	while (*stack_b)
		push_a(stack_a, stack_b, command);
}
