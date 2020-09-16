/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:26:13 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/09/16 22:35:32 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (n > 0)
		{
			((char *)s)[i] = '\0';
			++i;
			--n;
		}
	}
	else
		return ;
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void		*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
