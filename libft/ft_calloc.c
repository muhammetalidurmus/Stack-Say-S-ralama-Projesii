/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdurmus <mdurmus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:48:05 by mdurmus          #+#    #+#             */
/*   Updated: 2021/10/06 13:51:18 by mdurmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}
