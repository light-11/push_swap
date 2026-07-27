/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:08 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 16:12:22 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack, t_command *command)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	write(1, "sb\n", 3);
	command->sb++;
}

void	push_b(t_list **stack_a, t_list **stack_b, t_command *command)
{
	t_list	*a_first_node;

	a_first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	a_first_node->next = *stack_b;
	*stack_b = a_first_node;
	write(1, "pb\n", 3);
	command->pb++;
}

void	rotate_b(t_list **stack, t_command *command)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	first_node->next = NULL;
	(*stack)->next = first_node;
	*stack = second_node;
	write(1, "rb\n", 3);
	command->rb++;
}

void	reverse_rotate_b(t_list **stack, t_command *command)
{
	t_list *first_node;
	t_list *next_last_node;
	t_list *last_node;

	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
	{
		next_last_node = last_node;
		last_node = last_node->next;
	}
	next_last_node->next = NULL;
	last_node->next = first_node;
	*stack = last_node;
	write(1, "rrb\n", 4);
	command->rrb++;
}