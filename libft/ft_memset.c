/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:16:47 by hvasylie          #+#    #+#             */
/*   Updated: 2019/05/06 21:31:25 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char i;

	ptr = b;
	i = (unsigned char)c;
	while (len != 0)
	{
		len--;
		*ptr = (unsigned char)i;
		ptr++;
	}
	return (b);
}
