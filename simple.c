/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:15:20 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 16:15:22 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_search(t_list **stack)
{
	t_list	*first_node;
	int		small_content;
	int		count;
	int		small_content_count;

	count = 0;
	small_content_count = 0;
	first_node = *stack;
	small_content = (*stack)->content;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		count++;
		if ((*stack)->content < small_content)
		{
			small_content = (*stack)->content;
			small_content_count = count;
		}
	}
	*stack = first_node;
	return (small_content_count);
}

void	small_top(t_list **stack_a, t_command *command, int small_content_count)
{
	int	i;

	i = 0;
	if (small_content_count >= count_node(stack_a) - small_content_count)
	{
		while (count_node(stack_a) - small_content_count > i)
		{
			reverse_rotate_a(stack_a, command);
			i++;
		}
	}
	else
	{
		while (small_content_count > i)
		{
			rotate_a(stack_a, command);
			i++;
		}
	}
}

void	simple(t_list **stack_a, t_list **stack_b, t_command *command)
{
	int	small_content_count;
	int	node_count;

	node_count = count_node(stack_a);
	while (count_node(stack_a) > 2)
	{
		small_content_count = small_search(stack_a);
		small_top(stack_a, command, small_content_count);
		push_b(stack_a, stack_b, command);
	}
	if (small_search(stack_a) > 0)
		swap_a(stack_a, command);
	while (node_count > 2)
	{
		push_a(stack_a, stack_b, command);
		node_count--;
	}
}

void	complex(t_list **stack_a, t_list **stack_b, t_command *command)
{
	int	node_count;
	int	max_rank;
	int	i;

	node_count = count_node(stack_a);
	max_rank = node_count - 1;
	i = 0;
	while ((max_rank >> i) > 0)
	{
		while (node_count > 0)
		{
			if (((*stack_a)->rank >> i) & 1)
				rotate_a(stack_a, command);
			else
				push_b(stack_a, stack_b, command);
			node_count--;
		}
		while (count_node(stack_b) > 0)
			push_a(stack_a, stack_b, command);
		node_count = count_node(stack_a);
		i++;
	}
}
