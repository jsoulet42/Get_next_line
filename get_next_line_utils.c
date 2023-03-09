#include "get_next_line.h"

t_list	*lst_getlast(t_list *stack)
{
	t_list *new_temp;

	new_temp = stack;
	while (new_temp && new_temp->next)
		new_temp = new_temp->next;
	return (new_temp);
}

int	chearch_endline(t_list *stack)
{
	int		i;
	t_list	*new_temp;

	if (!stack)
		return (0);
	new_temp = lst_getlast(stack);
	i = 0;
	while (new_temp->content[i])
	{
		if (new_temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);

}

void	generate_line(t_list *stack, char **line)
{
	int	len;
	int	i;

	len = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stack = stack->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	free_stack(t_list *stack)
{
	t_list	*new_temp;
	t_list	*next;

	new_temp = stack;
	while (new_temp)
	{
		free(new_temp->content);
		next = new_temp->next;
		free(new_temp);
		new_temp = next;
	}
}