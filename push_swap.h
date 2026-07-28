/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:42:29 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/28 21:59:59 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct s_command_flag
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				is_bench;
	int				is_simple;
	int				is_medium;
	int				is_complex;
	int				is_adaptive;
}					t_command_flag;

int					ft_atoi(char *nptr);
int					ft_strlen(char *s);
int					ft_strncmp(char *s1, char *s2);
int					ft_isdigit(char c);
void				coordinate_compression(t_list **stack_a);
void				initialize_command_flag(t_command_flag *command_flag);
int					make_stack_a(int argc, char *argv[], t_list **stack_a);
void				is_flag(int argc, char *argv[],
						t_command_flag *command_flag);
int					flag_branch(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag, float disorder);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, int content);
t_list				*ft_lstlast(t_list *lst);
int					count_node(t_list **stack);
int					free_stack(t_list **stack);
int					check_duplication(t_list **stack_a, int value);
int					check_number(char *nptr);
float				compute_disorder(t_list **stack_a);
void				check_adaptive(float disorder, t_list **stack_a,
						t_list **stack_b, t_command_flag *command_flag);
int					push_swap(int argc, char *argv[]);
void				simple(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
void				medium(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
int					get_approx_sqrt(int nodes);
void				move_to_b(t_list **stack_a, t_list **stack_b, int min,
						int max, t_command_flag *command_flag);
int					find_max_rank(t_list *stack_b);
int					find_target_index(t_list *stack_b, int target);
void				rb_or_rrb(t_list **stack_b, int target_idx,
						t_command_flag *command_flag);
void				return_to_a(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
void				complex(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
int					small_search(t_list **stack);
void				small_top(t_list **stack_a, t_command_flag *command_flag,
						int small_content_count);
void				swap_a(t_list **stack, t_command_flag *command_flag);
void				swap_b(t_list **stack, t_command_flag *command_flag);
void				push_a(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
void				push_b(t_list **stack_a, t_list **stack_b,
						t_command_flag *command_flag);
void				rotate_a(t_list **stack, t_command_flag *command_flag);
void				rotate_b(t_list **stack, t_command_flag *command_flag);
void				reverse_rotate_a(t_list **stack,
						t_command_flag *command_flag);
void				reverse_rotate_b(t_list **stack,
						t_command_flag *command_flag);
void				bench(t_command_flag *command_flag, float disorder);
void				char_disorder(float disorder);
void				strategy(t_command_flag *command_flag);
int					total_command(t_command_flag *command_flag);
void				ft_putnbr(int n);
void				total_ops(t_command_flag *command_flag);
void				command_1(t_command_flag *command_flag);
void				command_2(t_command_flag *command_flag);

#endif
