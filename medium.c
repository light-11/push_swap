/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:03:19 by miida             #+#    #+#             */
/*   Updated: 2026/07/12 23:11:11 by miida            ###   ########.fr       */
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

void	move_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	moved;
	int	target_count;

	moved = 0;
	target_count = max - min + 1;
	while (moved < target_count && *stack_a)
	{
		if ((*stack_a)->rank >= min && (*stack_a)->rank <= max)
		{
			push_b(stack_a, stack_b);
			moved++;
		}
		else
			rotate_a(stack_a);
	}
}

void	medium(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	int	min_rank;
	int	max_rank;
	int	total;

	total = count_node(stack_a);
	chunk_size = get_approx_sqrt(total);
	min_rank = 0;
	max_rank = chunk_size - 1;
	while (min_rank < total)
	{
		move_to_b(stack_a, stack_b, min_rank, max_rank);
		min_rank += chunk_size;
		max_rank += chunk_size;
	}
}
/*
テスト用：push_bまでできた部分のテスト。スタックの内容を表示する関数
stack_bに逆順でチャンクごと、ランク順で入っていることの確認

100個の数字でテスト
cc medium.c push_swap.c -o push_swap_test
./push_swap_test 78 45 12 99 3 56 23 88 41 7 62 19 34 51 90 6 82 15 48 37 94 2 59 27 74 11 85 44 9 68 31 77 4 96 22 55 18 81 40 14 71 29 93 8 65 36 50 89 5 73 21 61 39 84 43 10 70 33 97 26 53 16 87 46 13 69 35 91 24 58 20 83 42 1 76 30 95 25 54 17 86 47 13 67 38 92 28 60 21 75 32 98 34 52 19 80 49 14 72 63
*/

//↓↓テスト用コード↓↓
/*
#include <stdio.h>
#include <stdlib.h>


void print_stack(t_list *stack, char *name) {
    printf("Stack %s: ", name);
    while (stack) {
        printf("%d(r:%d) ", stack->content, stack->rank);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
	int i = 1;

    while (i < argc) {
        if (stack_a == NULL)
            stack_a = ft_lstnew(ft_atoi(argv[i]));
        else
            ft_lstadd_back(&stack_a, ft_atoi(argv[i]));
        i++;
    }

	coordinate_compression(&stack_a);
	
    printf("--- Before Sorting ---\n");
    print_stack(stack_a, "A");

    // 2. 実装した medium 関数の実行
    medium(&stack_a, &stack_b);

    printf("--- After move_to_b ---\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    return (0);
}
*/