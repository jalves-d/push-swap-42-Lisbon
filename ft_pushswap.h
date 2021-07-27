
#ifndef	FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
	int		*sA;
	int		*sB;
	int		size;
	int		pos;
	int		ch;
}			t_list;

void	ft_sort(int size, int *array);
int	find_big(t_list *stacks);
int	find_small(t_list *stacks);
int	check_dup(char **argv);
int	check_char(char **argv);
int	ft_mop(t_list *stacks, int cnum);
int	ft_hl(t_list *stacks, int mid);
int	sizes(t_list *stacks, char st);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_strlen(const char *str);
int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int	ft_isdigit(int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	ft_print(char *str);
int	find_first(t_list *stacks);
int	find_last(t_list *stacks);
void	ra(t_list *stacks);
void	rb(t_list *stacks);
void	pb(t_list *stacks);
void	sa(t_list *stacks);
void	sb(t_list *stacks);
void	rra(t_list *stacks);
void	rrb(t_list *stacks);
void	pa(t_list *stacks);
void	swapt(t_list *stacks);
void	swapa(t_list *stacks, int middles);
void	swapb(t_list *stacks);
int		ft_checkord(t_list *stacks);

#endif
