/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:44:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/11/22 23:55:51 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0 || 1 <= 0 || read(fd, 0, 0) < 0)
	{
		perror("Error ");
		close(fd);
		return (0);
	}
	return (fd);
}

void	ft_norminette_v2(t_pipe *pipex)
{
	if (pipex->argv)
		ft_free_chartable(pipex->argv);
	if (pipex->path_to_command)
		free(pipex->path_to_command);
	pipex->path_to_command = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int		nb_cmd;
	t_pipe	pipex;

	if (print_arg(argc))
		return (0);
	ft_memset(&pipex, 0, sizeof(pipex));
	pipex.env = envp;
	nb_cmd = 2;
	pipex.file_open = check_file(argv[1]);
	pipex.file_close = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pipe(pipex.fd);
	while (nb_cmd < argc - 1)
	{
		pipex.argv = ft_split(argv[nb_cmd], ' ');
		if (*envp && access(pipex.argv[0], F_OK))
		{
			pipex.path_to_command = find(envp, pipex.argv[0]);
			if (!pipex.path_to_command && pipex.argv[0])
				pipex.path_to_command = ft_strdup(pipex.argv[0]);
		}
		exec_cmd(&pipex, nb_cmd, argc);
		ft_norminette_v2(&pipex);
		nb_cmd++;
	}
}
