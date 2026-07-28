/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:03:19 by miida             #+#    #+#             */
/*   Updated: 2026/07/28 22:13:55 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **stack_a, t_list **stack_b, int max,
					t_command_flag *command_flag)
{
	int	moved;
	int	chunk_size;
	int	min;
	int	total;

	moved = 0;
	total = count_node(stack_a) + count_node(stack_b);
	chunk_size = get_approx_sqrt(total);
	min = max - chunk_size + 1;
	while (moved < chunk_size && *stack_a)
	{
		if ((*stack_a)->rank >= min && (*stack_a)->rank <= max)
		{
			push_b(stack_a, stack_b, command_flag);
			moved++;
		}
		else
			rotate_a(stack_a, command_flag);
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

void	return_to_a(t_list **stack_a, t_list **stack_b,
					t_command_flag *command_flag)
{
	int	target;
	int	idx;

	target = find_max_rank(*stack_b);
	idx = find_target_index(*stack_b, target);
	rb_or_rrb(stack_b, idx, command_flag);
	push_a(stack_a, stack_b, command_flag);
}

void	medium(t_list **stack_a, t_list **stack_b, t_command_flag *command_flag)
{
	int	chunk_size;
	int	max_rank;
	int	total;

	total = count_node(stack_a);
	chunk_size = get_approx_sqrt(total);
	max_rank = chunk_size - 1;
	while ((max_rank - chunk_size + 1) < total)
	{
		move_to_b(stack_a, stack_b, max_rank, command_flag);
		max_rank += chunk_size;
	}
	while (*stack_b)
		return_to_a(stack_a, stack_b, command_flag);
	while (*stack_b)
		push_a(stack_a, stack_b, command_flag);
}
