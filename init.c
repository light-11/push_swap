/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:36 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 21:48:20 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_command_flag(t_command_flag *command_flag)
{
	command_flag->sa = 0;
	command_flag->sb = 0;
	command_flag->ss = 0;
	command_flag->pa = 0;
	command_flag->pb = 0;
	command_flag->ra = 0;
	command_flag->rb = 0;
	command_flag->rr = 0;
	command_flag->rra = 0;
	command_flag->rrb = 0;
	command_flag->rrr = 0;
	command_flag->is_bench = 0;
	command_flag->is_simple = 0;
	command_flag->is_medium = 0;
	command_flag->is_complex = 0;
	command_flag->is_adaptive = 0;
}

int	free_stack(t_list **stack)
{
	t_list	*now_node;
	t_list	*next_node;

	now_node = *stack;
	while (now_node != NULL)
	{
		next_node = now_node->next;
		free(now_node);
		now_node = next_node;
	}
	*stack = NULL;
	return (0);
}
