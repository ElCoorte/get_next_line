/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:55:29 by yzakharc          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:19 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r')\
		|| (c == ' '))
		return (1);
	return (0);
}
