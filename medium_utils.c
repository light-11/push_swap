/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:51 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 22:14:56 by miida            ###   ########.fr       */
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

void	rb_or_rrb(t_list **stack_b, int target_idx,
					t_command_flag *command_flag)
{
	int	total;

	total = count_node(stack_b);
	if (target_idx <= total / 2)
	{
		while (target_idx-- > 0)
			rotate_b(stack_b, command_flag);
	}
	else
	{
		while (target_idx++ < total)
			reverse_rotate_b(stack_b, command_flag);
	}
}
