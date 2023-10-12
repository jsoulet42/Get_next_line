/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:02:01 by jsoulet           #+#    #+#             */
/*   Updated: 2023/10/12 17:34:10 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}				t_lst;

char	*get_next_line(int fd);

int		chearch_endline(t_lst *stack);

void	read_stack(int fd, t_lst **stack);

void	go_to_stack(t_lst **stack, char *buffer, int r_read);

t_lst	*lst_getlast(t_lst *stack);

int		ft_strlen(const char *s);

void	extract_line(t_lst *stack, char **line);

void	generate_line(t_lst *stack, char **line);

void	free_stack(t_lst *stack);

void	clean_stack(t_lst **stack);

#endif
