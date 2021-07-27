
#include "ft_pushswap.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*to_find == 0)
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((to_find[j] == str[i + j]) && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
