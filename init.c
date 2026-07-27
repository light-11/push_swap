/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:36 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 16:13:40 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_command(t_command *command)
{
	command->sa = 0;
	command->sb = 0;
	command->ss = 0;
	command->pa = 0;
	command->pb = 0;
	command->ra = 0;
	command->rb = 0;
	command->rr = 0;
	command->rra = 0;
	command->rrb = 0;
	command->rrr = 0;
}
void	initialize_flag(t_flag *flag)
{
	flag->is_bench = 0;
	flag->is_simple = 0;
	flag->is_medium = 0;
	flag->is_complex = 0;
	flag->is_adaptive = 0;
}

int	free_stack(t_list **stack)
{
	t_list *now_node;
	t_list *next_node;

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