/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:44:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 18:34:03 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		nb_cmd;
	t_pipe	pipex;

	pipex.env = envp;
	nb_cmd = 2;
	pipex.file_open = open(argv[1], O_RDONLY);
	pipex.file_close = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipe(pipex.fd);
	while (nb_cmd < argc - 1)
	{
		pipex.argv = ft_split(argv[nb_cmd], ' ');
		pipex.path_to_command = find(envp, pipex.argv[0]);
		exec_cmd(&pipex, nb_cmd, argc);
		ft_free_chartable(pipex.argv);
		free(pipex.path_to_command);
		nb_cmd++;
	}
	return (0);
}
