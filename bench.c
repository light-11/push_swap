/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:59 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 17:26:52 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench(t_command *command, t_flag *flag, float disorder)
{
	char_disorder(disorder);
	strategy(flag);
	total_ops(command);
	command_1(command);
	command_2(command);
}

void	char_disorder(float disorder)
{
	int		int_disorder;
	char	char_disorder[5];
	int		i;

	int_disorder = (int)(disorder * 10000);
	if (int_disorder == 10000)
		write(2, "[bench] disorder: 100.00%\n", 26);
	else
	{
		write(2, "[bench] disorder: ", 18);
		i = 4;
		while (i >= 0)
		{
			if (i == 2)
				char_disorder[i] = '.';
			else
			{
				char_disorder[i] = (int_disorder % 10) + '0';
				int_disorder /= 10;
			}
			i--;
		}
		write(2, char_disorder, 5);
		write(2, "%\n", 2);
	}
}
void	strategy(t_flag *flag)
{
	if (flag->is_adaptive == 0)
	{
		if (flag->is_simple == 1)
			write(2, "[bench] strategy: simple / O(n^2)\n", 34);
		else if (flag->is_medium == 1)
			write(2, "[bench] strategy: medium / O(n*sqrt(n))\n", 40);
		else if (flag->is_complex == 1)
			write(2, "[bench] strategy: Complex / O(n log n)\n", 39);
	}
	else
	{
		if (flag->is_simple == 1)
			write(2, "[bench] strategy: Adaptive / O(n^2)\n", 36);
		else if (flag->is_medium == 1)
			write(2, "[bench] strategy: Adaptive / O(n*sqrt(n))\n", 42);
		else if (flag->is_complex == 1)
			write(2, "[bench] strategy: Adaptive / O(n log n)\n", 40);
	}
}

int	total_command(t_command *command)
{
	int	total;

	total = command->sa + command->sb + command->ss + command->pa + command->pb
		+ command->ra + command->rb + command->rr + command->rra + command->rrb
		+ command->rrr;
	return (total);
}

void	total_ops(t_command *command)
{
	int	total;

	total = total_command(command);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr(total);
	write(2, "\n", 1);
}
