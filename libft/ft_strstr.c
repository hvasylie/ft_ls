/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 23:22:05 by hvasylie          #+#    #+#             */
/*   Updated: 2019/05/13 17:41:04 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int pstn;

	pstn = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[pstn])
	{
		if (haystack[pstn] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[pstn + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char*)&haystack[pstn]);
		}
		pstn++;
	}
	return (0);
}
