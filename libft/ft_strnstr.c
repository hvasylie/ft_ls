/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:31:50 by hvasylie          #+#    #+#             */
/*   Updated: 2019/05/13 17:46:36 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	unsigned int		pstn;

	pstn = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[pstn] && pstn < len)
	{
		if (haystack[pstn] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[pstn + i] == needle[i] \
				&& (i + pstn) < len)
				i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[pstn]);
		}
		pstn++;
	}
	return (0);
}
