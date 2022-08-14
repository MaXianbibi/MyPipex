/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:44:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/13 20:20:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"
# include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	char *path_to_command;
	// int id;
	// int fd[2];
	// int file_read;
	int nb_cmd;
	char **cmd;
	char *read_file;
	(void)argc;

	// Crée ou ecrit dans un dossier
	// 0777 permission + 0 = translation octale

	// jouvre mon fd en [1] parce quil doit write

	// if (pipe(fd) == -1)
	// 	return (1);
	
	// if (argc < 5)
	// {
	// 	ft_putstr_fd("Error : less than 4 args\n", 2);
	// 	return (1);
	// }
	// file_read = open("test.text", O_RDONLY);
	
	
	read_file = argv[1];
	nb_cmd = 2;
	while (nb_cmd < argc)
	{
		cmd = ft_split(argv[nb_cmd], ' ');
		path_to_command = find(envp, cmd[0]);
		if (path_to_command == NULL)
			return (0);
		if (execute(path_to_command, cmd, envp, read_file) == 1)
			return (0);
		ft_printf("\n");
		ft_free_chartable(cmd);
		free(path_to_command);
		nb_cmd++;
	}

	// printf("allo");


	return (0);
}
	// fork pour chaque commande
	
	// read(0) == scanf ?
	
	// file = open("new_text.txt", O_WRONLY | O_CREAT, 0777);
	// 	dup2(file, STDOUT_FILENO);
	// int id2 = fork();
	// if (id2 == 0)
	// {
	// id = fork();
	// if (id < 0)
	// 	return (2);
	// if (id == 0)
	// {
	// 	// child process
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);		
	// }
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(file);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execlp("wc", "wc", NULL);
	// }
	// close(fd[0]);
	// close(fd[1]);
	// close(file);

	// waitpid(id, NULL, 0);
	// waitpid(id2, NULL, 0);