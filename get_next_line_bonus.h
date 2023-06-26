/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:02:01 by jsoulet           #+#    #+#             */
/*   Updated: 2023/03/10 11:22:43 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lst
{
	char			*content;
	struct s_list	*next;
}				t_lst;

char	*get_next_line(int fd);

int		chearch_endline(t_list *stack);

void	read_stack(int fd, t_list **stack);

void	go_to_stack(t_list **stack, char *buffer, int r_read);

t_list	*lst_getlast(t_list *stack);

int		ft_srlen(const char *s);

void	extract_line(t_list *stack, char **line);

void	generate_line(t_list *stack, char **line);

void	free_stack(t_list *stack);

void	clean_stack(t_list **stack);

#endif
