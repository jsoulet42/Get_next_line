#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // a virer avant de push
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char *get_next_line(int fd);

int	chearch_endline(t_list *stack);

void	read_stack(int fd, t_list **stack);

void	go_to_stack(t_list **stack, char *buffer, int r_read);

t_list	*lst_getlast(t_list *stack);

int	ft_strlen(const char *s);

void	extract_line(t_list *stack, char **line);

void	generate_line(t_list *stack, char **line);

void	free_stack(t_list *stack);

void	clean_stack(t_list **stack);

#endif