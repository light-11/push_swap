/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:29 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 23:00:22 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack, t_command_flag *command_flag)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	write(1, "sa\n", 3);
	command_flag->sa++;
}

void	push_a(t_list **stack_a, t_list **stack_b, t_command_flag *command_flag)
{
	t_list	*b_first_node;

	b_first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	b_first_node->next = *stack_a;
	*stack_a = b_first_node;
	write(1, "pa\n", 3);
	command_flag->pa++;
}

void	rotate_a(t_list **stack, t_command_flag *command_flag)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next == NULL)
		return ;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	first_node->next = NULL;
	(*stack)->next = first_node;
	*stack = second_node;
	write(1, "ra\n", 3);
	command_flag->ra++;
}

void	reverse_rotate_a(t_list **stack, t_command_flag *command_flag)
{
	t_list	*first_node;
	t_list	*next_last_node;
	t_list	*last_node;

	first_node = *stack;
	last_node = *stack;
	if ((*stack)->next == NULL)
		return ;
	while (last_node->next != NULL)
	{
		next_last_node = last_node;
		last_node = last_node->next;
	}
	next_last_node->next = NULL;
	last_node->next = first_node;
	*stack = last_node;
	write(1, "rra\n", 4);
	command_flag->rra++;
}
