/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:51 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 16:13:55 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rb_or_rrb(t_list **stack_b, int target_idx, t_command *command)
{
	int	total;

	total = count_node(stack_b);
	if (target_idx <= total / 2)
	{
		while (target_idx-- > 0)
			rotate_b(stack_b, command);
	}
	else
	{
		while (target_idx++ < total)
			reverse_rotate_b(stack_b, command);
	}
}
