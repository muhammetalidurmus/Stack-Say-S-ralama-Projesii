/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurmus <mdurmus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:18:28 by mdurmus          #+#    #+#             */
/*   Updated: 2021/10/01 12:18:28 by mdurmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar )
{
	while (*string)
	{
		if (*string == (char) searchedChar)
			return ((char *) string);
		++string;
	}
	if ((char) searchedChar == '\0')
		return ((char *) string);
	else
		return (NULL);
}
