/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:52:11 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/11 11:58:56 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	test;

	i = 0;
	test = c;
	while (str[i])
	{
		if (str[i] == test)
			return ((char*)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char*)str + i);
	else
		return (NULL);
}
