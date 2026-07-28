/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 17:40:57 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_1(t_command *command)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr(command->sa);
	write(2, " sb: ", 5);
	ft_putnbr(command->sb);
	write(2, " ss: ", 5);
	ft_putnbr(command->ss);
	write(2, " pa: ", 5);
	ft_putnbr(command->pa);
	write(2, " pb: ", 5);
	ft_putnbr(command->pb);
	write(2, "\n", 1);
}

void	command_2(t_command *command)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr(command->ra);
	write(2, " rb: ", 5);
	ft_putnbr(command->rb);
	write(2, " rr: ", 5);
	ft_putnbr(command->rr);
	write(2, " rra: ", 6);
	ft_putnbr(command->rra);
	write(2, " rrb: ", 6);
	ft_putnbr(command->rrb);
	write(2, " rrr: ", 6);
	ft_putnbr(command->rrr);
	write(2, "\n", 1);
}
