/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:47:46 by yfawzi            #+#    #+#             */
/*   Updated: 2023/01/18 23:05:47 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	s = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 2)));
	j = 0;
	while (s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	s[j] = '/';
	j++;
	i = 0;
	while (s2[i])
	{
		s[j + i] = s2[i];
		i++;
	}
	s[j + i] = '\0';
	return (s);
}
