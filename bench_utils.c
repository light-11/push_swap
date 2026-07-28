/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:44 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 21:46:12 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_1(t_command_flag *command_flag)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr(command_flag ->sa);
	write(2, " sb: ", 5);
	ft_putnbr(command_flag ->sb);
	write(2, " ss: ", 5);
	ft_putnbr(command_flag ->ss);
	write(2, " pa: ", 5);
	ft_putnbr(command_flag ->pa);
	write(2, " pb: ", 5);
	ft_putnbr(command_flag ->pb);
	write(2, "\n", 1);
}

void	command_2(t_command_flag *command_flag)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr(command_flag ->ra);
	write(2, " rb: ", 5);
	ft_putnbr(command_flag ->rb);
	write(2, " rr: ", 5);
	ft_putnbr(command_flag ->rr);
	write(2, " rra: ", 6);
	ft_putnbr(command_flag ->rra);
	write(2, " rrb: ", 6);
	ft_putnbr(command_flag ->rrb);
	write(2, " rrr: ", 6);
	ft_putnbr(command_flag ->rrr);
	write(2, "\n", 1);
}
