/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/12 22:52:24 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	check_number(char *nptr)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if ('0' <= nptr[i] && nptr[i] <= '9')
			num = num * 10 + (nptr[i] - '0');
		else
			return (0);
		i++;
		if (-2147483648 > num * minus || num * minus > 2147483647)
			return (0);
	}
	if ((minus == -1 && i < 2) || i < 1)
		return (0);
	return (1);
}

int	ft_atoi(char *nptr)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(num * minus));
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **stack, int content)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew(content);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

float	compute_disorder(t_list **stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*now_node;
	t_list	*next_node;

	mistakes = 0;
	total_pairs = 0;
	now_node = *stack_a;
	next_node = (*stack_a)->next;
	while (now_node->next != NULL)
	{
		while (next_node != NULL)
		{
			if ((now_node->content) > (next_node->content))
				mistakes++;
			total_pairs++;
			next_node = next_node->next;
		}
		now_node = now_node->next;
		next_node = now_node->next;
	}
	return (mistakes / total_pairs);
}

int	check_duplication(t_list **stack_a, int value)
{
	t_list	*check_node;

	check_node = *stack_a;
	if (check_node == NULL)
		return (1);
	while (check_node->next != NULL)
	{
		if (check_node->content == value)
			return (0);
		check_node = check_node->next;
	}
	if (check_node->content == value)
		return (0);
	return (1);
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	coordinate_compression(t_list **stack_a)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

	if (stack_a == NULL || *stack_a == NULL || ((*stack_a)->next == NULL))
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		rank = 0;
		compare = *stack_a;
		while (compare != NULL)
		{
			if (current->content > compare->content)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

void	check_adaptive(float disorder, t_list **stack_a, t_list **stack_b,
		t_command *command, t_flag *flag)
{
	if (count_node(stack_a) <= 30)
	{
		flag->is_simple = 1;
		simple(stack_a, stack_b, command);
	}
	else
	{
		if (disorder < 0.2)
		{
			flag->is_simple = 1;
			simple(stack_a, stack_b, command);
		}
		if (0.2 <= disorder && disorder < 0.5)
		{
			flag->is_medium = 1;
			// medium(stack_a, stack_b, command);
		}
		if (0.5 <= disorder)
		{
			flag->is_complex = 1;
			complex(stack_a, stack_b, command);
		}
	}
}
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
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
int	push_swap(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	float		disorder;
	t_command	command;
	t_flag		flag;

	initialize_command(&command);
	initialize_flag(&flag);
	stack_a = NULL;
	stack_b = NULL;
	if (!make_stack_a(argc, argv, &stack_a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	disorder = compute_disorder(&stack_a);
	if (disorder == 0)
		return (0);
	coordinate_compression(&stack_a);
	is_flag(argc, argv, &flag);
	flag_branch(&stack_a, &stack_b, &command, &flag, disorder);
	return (0);
}
int	make_stack_a(int argc, char *argv[], t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			i++;
		else
		{
			if (!check_number(argv[i]))
				return (0);
			if (*stack_a == NULL)
				*stack_a = ft_lstnew(ft_atoi(argv[i]));
			else
			{
				if (!check_duplication(stack_a, ft_atoi(argv[i])))
					return (0);
				ft_lstadd_back(stack_a, ft_atoi(argv[i]));
			}
			i++;
		}
	}
	return (1);
}
void	is_flag(int argc, char *argv[], t_flag *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench"))
			flag->is_bench++;
		if (ft_strncmp(argv[i], "--simple"))
			flag->is_simple++;
		if (ft_strncmp(argv[i], "--medium"))
		  flag->is_medium++;
		if (ft_strncmp(argv[i], "--complex"))
			flag->is_complex++;
		if (ft_strncmp(argv[i], "--adaptive"))
			flag->is_adaptive++;
		i++;
	}
}
int	flag_branch(t_list **stack_a, t_list **stack_b, t_command *command,
		t_flag *flag, float disorder)
{
	if (flag->is_simple == 1)
		simple(stack_a, stack_b, command);
	else if (flag->is_medium == 1))
	  medium(stack_a, stack_b, command);
	else if (flag->is_complex == 1)
		complex(stack_a, stack_b, command);
	else if (flag->is_adaptive == 1)
		check_adaptive(disorder, stack_a, stack_b, command, flag);
	else if (flag->is_simple == 0 && flag->is_medium == 0
		&& flag->is_complex == 0 && flag->is_adaptive == 0)
	{
		flag->is_adaptive = 1;
		check_adaptive(disorder, stack_a, stack_b, command, flag);
	}
	else
		return (0);
	if (flag->is_bench == 1)
		bench(command, flag, disorder);
	return (0);
}

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

int	count_node(t_list **stack)
{
	t_list	*first_node;
	int		count;

	count = 0;
	first_node = *stack;
	if (*stack == NULL)
		return (0);
	while ((*stack)->next != NULL)
	{
		count++;
		*stack = (*stack)->next;
	}
	count++;
	*stack = first_node;
	return (count);
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
	int	count;
	int	i;

	node_count = count_node(stack_a);
	max_rank = node_count - 1;
	count = 0;
	i = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank / 2;
		count++;
	}
	while (count - i > 0)
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
	if (flag->is_adaptive == 1)
	{
		if (flag->is_simple == 1)
			write(2, "[bench] strategy: Adaptive / O(n^2)\n", 36);
		if (flag->is_medium == 1)
			write(2, "[bench] strategy: Adaptive / O(n*sqrt(n))\n", 42);
		if (flag->is_complex == 1)
			write(2, "[bench] strategy: Adaptive / O(n log n)\n", 40);
	}
	else
	{
		if (flag->is_simple == 1)
			write(2, "[bench] strategy: simple / O(n^2)\n", 34);
		if (flag->is_medium == 1)
			write(2, "[bench] strategy: medium / O(n*sqrt(n))\n", 40);
		if (flag->is_complex == 1)
			write(2, "[bench] strategy: Complex / O(n log n)\n", 39);
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

void	ft_putnbr(int n)
{
	char	char_n;

	if (n >= 10)
		ft_putnbr(n / 10);
	char_n = n % 10 + '0';
	write(2, &char_n, 1);
}

void	total_ops(t_command *command)
{
	int	total;

	total = total_command(command);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr(total);
	write(2, "\n", 1);
}

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

void	bench(t_command *command, t_flag *flag, float disorder)
{
	char_disorder(disorder);
	strategy(flag);
	total_ops(command);
	command_1(command);
	command_2(command);
}

void	swap_a(t_list **stack, t_command *command)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	write(1, "sa\n", 3);
	command->sa++;
}

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

void	push_a(t_list **stack_a, t_list **stack_b, t_command *command)
{
	t_list	*b_first_node;

	b_first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	b_first_node->next = *stack_a;
	*stack_a = b_first_node;
	write(1, "pa\n", 3);
	command->pa++;
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

void	rotate_a(t_list **stack, t_command *command)
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
	write(1, "ra\n", 3);
	command->ra++;
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

void	reverse_rotate_a(t_list **stack, t_command *command)
{
	t_list	*first_node;
	t_list	*next_last_node;
	t_list	*last_node;

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
	write(1, "rra\n", 4);
	command->rra++;
}

void	reverse_rotate_b(t_list **stack, t_command *command)
{
	t_list	*first_node;
	t_list	*next_last_node;
	t_list	*last_node;

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

int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
	// tmp = *stack_a;
	// while (tmp)
	// {
	// 	printf("%d\n", tmp->content);
	// 	tmp = tmp->next;
	// }
	// printf("%d\n", command->pa);
	// printf("%d\n", command->pb);
	// printf("%d\n", command->sa);
	// printf("%d\n", command->sb);
	// printf("%d\n", command->ra);
	// printf("%d\n", command->rra);
}
