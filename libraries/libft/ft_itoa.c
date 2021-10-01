/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:46:18 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/08/11 14:31:22 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len ++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	nbr = n;
	len = nb_len(nbr);
	str = malloc ((len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
