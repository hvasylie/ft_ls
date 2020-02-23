/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:15:56 by hvasylie          #+#    #+#             */
/*   Updated: 2019/05/10 22:34:57 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	a;

	ch = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
		if (*(ch++) == (unsigned char)c)
			return (ch - 1);
	return (NULL);
}
