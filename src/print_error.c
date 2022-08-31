/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:04:16 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 18:34:36 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*print_error(void)
{
	ft_printf("Error\n");
	return (NULL);
}

int	print_error_int(void)
{
	ft_printf("Error\n");
	return (1);
}
