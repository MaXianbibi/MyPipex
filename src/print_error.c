/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:04:16 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/11 21:49:29 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*print_error(void)
{
	perror("ERROR ");
	return (NULL);
}

int	print_error_int(void)
{
	perror("ERROR ");
	return (1);
}

int	print_arg(int n)
{
	if (n != 5)
	{
		ft_putstr_fd("Error: The number of arguments is invalid\n", 2);
		return (1);
	}
	return (0);
}
