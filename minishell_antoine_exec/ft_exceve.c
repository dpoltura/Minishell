/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exceve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:15:40 by aduriez           #+#    #+#             */
/*   Updated: 2024/06/10 16:35:00 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	dump_pipe_to_terminal(int read_fd[], t_excev *base)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	(void)base;
	printf("Je passe par le dump_pipe_to_terminal\n");
	// Lecture depuis le tube (pipe)
	while ((bytes_read = read(read_fd[0], buffer, sizeof(buffer))) > 0)
	{
		// Écriture dans le terminal (stdout)
		if (write(STDOUT_FILENO, buffer, bytes_read) == -1)
		{
			perror("Erreur lors de l'écriture dans le terminal");
		}
	}
	close(base->fd_origin[0]);
	close(base->fd_origin[1]);
	if (bytes_read == -1)
	{
		perror("Erreur lors de la lecture depuis le tube");
	}
	dup2(base->save_fd, 0);
	dup2(base->save_fd_origin, 1);
}

void	ft_next_infile(t_excev *base, t_data *data)
{
	data = data->next;
	if (data->token == L_CHEV)
	{
		data = data->next;
		if (data->token == INFILE)
		{
			ft_init_open_file(base, data);
			base->pipe_filled = 1;
			ft_next_infile(base, data);
		}
	}
	else
		data = data->prev;
}

void	ft_init_open_file(t_excev *base, t_data *data)
{
	printf("FT_INIT_OPEN_FILE|%s|\n", data->value);
	base->open_file = open(data->value, O_RDONLY);
	base->infile_nbr++;
	if (base->open_file < 0)
	{
		printf("IL y a un probleme ca ne marche pas \n");
	}
	printf("NBR_OUVERTURE|INFILE|%d|", base->infile_nbr);
}
void	ft_init_outfile(t_excev *base, t_data *data)
{
	base->open_outfile = open(data->value, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (base->open_outfile < 0)
	{
		printf("Erreur ca ne marche pas OUTFILE\n");
	}
}

// void	ft_init_outfile(t_base *base, char *arg[], int arc)
// {

// 	data->open_outfile = open(arg[arc - 1], O_RDWR | O_CREAT | O_TRUNC,
// 0644);
// 	if (base->open_outfile < 0)
// 	{
// 		perror(arg[arc - 1]);
// 	}
// }
// void	ft_exceve_outfile(t_data *data, char *envp[], int fd_origin[])
// {
// 	int	pfd;

// 	(void)envp;

// 	pfd = fork();
// 	if ((pfd) < 0)
// 	{
// 		printf("ERROPR\n");
// 	}
// 	if (pfd == 0)
// 	{
// 		dup2(fd_origin[0], 0);
// 		dup2(data->open_outfile, 1);
// 		close(fd_origin[0]);
// 		close(fd_origin[1]);
// 		if (data->open_file > 0)
// 			close(data->open_file);
// 		if (data->open_outfile > 0)
// 			close(data->open_outfile);
// 		// execve(data->arg[1].path, base->arg[1].tab_arg, envp);
// 		// ft_free_arg(base);
// 		// ft_free_base(base);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pfd > 0)
// 	{
// 		if (data->open_file > 0)
// 			close(data->open_file);
// 		close(data->open_outfile);
// 		close(fd_origin[0]);
// 		close(fd_origin[1]);
// 	}
// }
void	ft_fork_one(t_excev *base, char *envp[], t_data *data)
{
	int	fd;

	base->cmd++;
	fd = fork();
	base->pipe_filled = 1;
	if (fd < 0)
	{
		printf("La pipe ne marche pas");
		return ;
	}
	if (fd == 0)
	{
		dup2(base->open_file, 0);
		dup2(base->fd_origin[1], 1);
		close(base->open_file);
		close(base->fd_origin[1]);
		execve(data->path, data->arg, envp);
		exit(EXIT_FAILURE);
	}
	// waitpid(fd, NULL, 0);
	close(base->fd_origin[1]);
	close(base->open_file);
}

void	ft_init_base(t_excev *base)
{
	base->open_file = 0;
	base->open_outfile = 0;
	base->pipe_filled = 0;
	base->cmd = 0;
	base->infile_nbr = 0;
	base->save_fd = dup(0);
	base->save_fd_origin = dup(1);
}

void	dump_pipe_to_file(t_excev *base)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		output_fd;

	printf("|DUMP_PIPE_TO_FILE|");
	output_fd = 0;
	// Rediriger la sortie standard vers le descripteur de fichier du fichier de sortie
	if (dup2(base->open_outfile, STDOUT_FILENO) == -1)
	{
		perror("Erreur lors de la redirection de la sortie standard");
		exit(EXIT_FAILURE);
	}
	// Lecture depuis le tube (pipe) et écriture dans le descripteur de fichier du fichier de sortie
	while ((bytes_read = read(base->fd_origin[0], buffer, sizeof(buffer))) > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) == -1)
		{
			perror("Erreur lors de l'écriture dans le fichier de sortie");
			exit(EXIT_FAILURE);
		}
	}
	if (bytes_read == -1)
	{
		perror("Erreur lors de la lecture depuis le tube");
		exit(EXIT_FAILURE);
	}
	// Fermeture du descripteur de fichier du fichier de sortie
	if (close(output_fd) == -1)
	{
		perror("Erreur lors de la fermeture du fichier de sortie");
		exit(EXIT_FAILURE);
	}
	dup2(base->save_fd, 0);
	dup2(base->save_fd_origin, 1);
}

void	ft_fork_arg_pipe(t_data *data, char *envp[], t_excev *base)
{
	int	pfd;

	printf("\n|ft_fork_arg_pipe|\n");
	// while (base->arg[base->count_arg].verif == 0)
	// 	base->count_arg++;
	pfd = fork();
	if (pfd < 0)
	{
		printf("Il y a une erreur");
		return ;
	}
	if (pfd == 0)
	{
		dup2(base->fd_origin[0], STDIN_FILENO);
		dup2(base->fd[1], STDOUT_FILENO);
		close(base->fd_origin[0]);
		close(base->fd_origin[1]);
		close(base->fd[0]);
		close(base->fd[1]);
		execve(data->path, data->arg, envp);
	}
	base->fd_origin[0] = base->fd[0];
	base->fd_origin[1] = base->fd[1];
	close(base->fd_origin[1]);
	// Je viens de le retirer a verifier si on le retire
	// waitpid(pfd, NULL, 0);
}

void	sort_envp(char **copy_envp)
{
	char	*tmp;
	int		num_envp;

	int i, j;
	num_envp = 0;
	// Calculer le nombre d'éléments dans copy_envp
	while (copy_envp[num_envp] != NULL)
	{
		num_envp++;
	}
	// Tri à bulles (bubble sort) basé sur strcmp
	for (i = 0; i < num_envp - 1; i++)
	{
		for (j = 0; j < num_envp - i - 1; j++)
		{
			if (strcmp(copy_envp[j], copy_envp[j + 1]) > 0)
			{
				// Échanger les pointeurs
				tmp = copy_envp[j];
				copy_envp[j] = copy_envp[j + 1];
				copy_envp[j + 1] = tmp;
			}
		}
	}
}
char	*ft_strchr(char *s, int c)
{
	int		count;
	int		count_search;
	char	*str;

	count = 0;
	if (c > 256)
		c = c - 256;
	count_search = 0;
	str = (char *)s;
	while (str[count] != '\0')
		count++;
	while (count_search <= count)
	{
		if (str[count_search] == c)
			return (&str[count_search]);
		count_search++;
	}
	return (0);
}
// void	ft_strchr_copy_envp(char *str, char  *copy_envp[])
// {
// 	int i;
// 	i = 0;

// 	while(str[i]== '$')
// 		i++;

// }
// void	ft_display_echo(t_excev *base,t_data *data,char *copy_envp[])
// {
// 	int i;

// 	char *tmp = data->value;
// 	i= 0;
// 	while(tmp[i])
// 	{
// 		if(tmp[i] = '$')
// 		{
// 			ft_strchr_copy_envp(tmp, copy_envp);
// 		}
// 		else
// 			write(1, &tmp[i], 1);
// 		i++;

// 	}

// }
void	ft_display_envp(char *copy_envp[])
{
	int	i;

	// int		j;
	i = 0;
	sort_envp(copy_envp);
	printf("\n 1er|%s|\n", copy_envp[0]);
	while (copy_envp[i])
	{
		printf("declare -x %s\n", copy_envp[i]);
		i++;
	}
}

void	ft_display_echo(t_data *data)
{
	printf("|ECHO|\n");
	data = data->next;
	// IL faut alors faire avvaancer t_data jusqu'a la commande d'apres
	printf("|VALUE= %s|\n", data->value);
	if (data->token == D_QUOTE)
	{
		data = data->next;
		// A changer apres le parsing
		if (data->token == CMD)
		{
			printf("\nVALUE== |%s|\n", data->value);
			data = data->next;
			printf("Je suis la prochaine commande %s", data->value);
		}
	}
}

void	ft_display_echo_arg_n(t_data *data)
{
	printf("|ECHO_N|");
	data = data->next;
	// IL faut alors faire avvaancer t_data jusqu'a la commande d'apres
	if (data->token == D_QUOTE)
	{
		data = data->next;
		// A changer apres le parsing
		if (data->token == CMD)
		{
			printf("VALUE== |%s|", data->value);
			data = data->next;
		}
	}
}

char	**new_tab_envp(char *copy_envp[], char *include_envp)
{
	int		i;
	char	**new_envp;

	// Compter tous les éléments du simple tableau de envp
	i = 0;
	while (copy_envp[i])
		i++;
	// Allouer de la mémoire pour le nouveau tableau de envp
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
	{
		// Gérer l'erreur d'allocation mémoire
		return (NULL);
	}
	// Copier tous les éléments de la copy_envp
	i = 0;
	while (copy_envp[i])
	{
		new_envp[i] = copy_envp[i];
		i++;
	}
	// Allouer de la mémoire pour la chaîne de caractères include_envp
	new_envp[i] = malloc(sizeof(char) * (strlen(include_envp) + 1));
	if (!new_envp[i])
	{
		// Gérer l'erreur d'allocation mémoire
		free(new_envp);
		return (NULL);
	}
	// Copier la chaîne de caractères include_envp dans le nouveau tableau de envp
	strcpy(new_envp[i], include_envp);
	// Ajouter un élément NULL à la fin du nouveau tableau de envp
	new_envp[i + 1] = NULL;
	printf("\nJe suis la place dans le tableau inserer %d\n", i);
	// free(copy_envp);
	return (new_envp);
}
char	**ft_display_envp_insert(t_data *data, char *copy_envp[])
{
	printf("Je suis rentre dans|FT_DISPLAY_ENVP_INSERT|");
	// Il faut alors faire une conditions si celui d'apres est
	if (data->next != NULL)
		data = data->next;
	if (data->token == CMD)
	{
		printf("|NEW_VARIRABE EXPORT|VALUE|%s|", data->value);
		copy_envp = new_tab_envp(copy_envp, data->value);
		// IL  faut alors commencer a la mettre dans l'environnement a la suite dans la copy
	}
	return (copy_envp);
}

int	ft_search_unset(char **copy_envp, char *search)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	// Verrfifier que la variables existent dans envp
	while (copy_envp[i])
	{
		if (strstr(copy_envp[i], search) != NULL)
		{
			printf("|SEARCH_UNSET|");
			check = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
void	**ft_delete_unset(char **copy_envp, char *search)
{
	int	i;

	(void)search;
	i = 0;
	printf("\n|DELETEUNSET|\n");
	while (copy_envp[i])
	{
		printf("\n|%s|", copy_envp[i]);
		if (strncmp(copy_envp[i], search, strlen(search)) == 0)
		{
			printf("\n|DELEATE|\n%s\n|\n", copy_envp[i]);
			copy_envp[i] = NULL;
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_current_dir(void)
{
	char	*cwd;
	size_t	size;

	size = 1024;
	cwd = malloc(size);
	if (cwd == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	if (getcwd(cwd, size) == NULL)
	{
		free(cwd);
		perror("getcwd");
		return (NULL);
	}
	return (cwd);
}

int	ft_directory_exist_not_path(char *save)
{
	//Il faut verfifier si on acces
	//Il faut ensuite verifier les frees
	DIR		*dir;
	char	*path;
	char *new_path;

	path = ft_get_current_dir();
	dir = opendir(save);
	printf("\n|Directory_exist_not_path|\n");
	if (dir == NULL)
	{
		printf("|PATH_NOT_EXIST|\n");
		return (-1);
	}
	printf("|PATH_EXIST|\n");
	new_path = ft_strjoin(path, "/");
	new_path = ft_strjoin(new_path, save);
	if (chdir(new_path) == -1)
	{
		closedir(dir);
		printf("\n|CHDIRNOTACCES|\n");
		return(-1);
	}
	printf("|CHDORACCES|\n");
	closedir(dir);
	return (1);
}

void	ft_execve(t_data *data, char *envp[])
{
	t_excev		base;
	static char	**copy_envp;
	int			i;
	int			count;

	printf("|token|%s", data->value);
	count = 0;
	// L'export est bon il faut regler la static avant lexecv
	// Pour export
	// printf("|1er=%s|\n", data->value);
	// data = data->next;
	// printf("|2er=%s|\n", data->value);
	// data = data->prev;
	// printf("|1er=%s|\n", data->value);
	copy_envp = envp;
	ft_init_base(&base);
	(void)envp;
	if (pipe(base.fd_origin) == -1)
		printf("ERROR");
	// Creation de la boucle
	while (data != NULL)
	{
		if (data->token == INFILE)
		{
			ft_init_open_file(&base, data);
			data = data->next;
		}
		if (data->token == CMD) // IL faut mettre 3
		{
			printf("\n|CMD|  %s\n\n", data->value);
			// Cela permet de creer une bouccat le permettant d'ouvrir tous les infiles
			while (data->next != NULL)
			{
				data = data->next;
				// Il faut faire le here_doc
				if (data->token == D_L_CHEV)
				{
					printf("\n|HEREDOC|\n");
					data = data->next;
					break ;
				}
				if (data->token != INFILE)
				{
					printf("Je viens de casser la boucle| \n");
					break ;
				}
				printf("\n|Jesuisbcl|INFILE|\n");
				printf("\n|CMD|APRES  %s\n\n", data->value);
				ft_init_open_file(&base, data);
				// Cela permet de compter toutes les fois ou on ouvre pour revenir a la commande par la suite
			}
			// Il vat falloir refaire cette boucle car il y a un probleme pour revenir a la cmd
			while (count < (base.infile_nbr))
			{
				printf("\n|RETOUR ARRIRERE|\n");
				data = data->prev;
				count++;
			}
			printf("\n|NEWCMD|%s|", data->value);
			// IL faut fai++re une conditions pour savoir si avant il y a
			// IL faut faire une conditions si apres il y a un  infile
			// if (data->next != NULL)
			// 	ft_next_infile(&bas5e, data);
			// Apres avoir vu si il y avait un infile faire un excev
			ft_fork_one(&base, envp, data);
			count = 0;
			while (count < (base.infile_nbr))
			{
				printf("\n|RETOUTAVA|\n");
				data = data->next;
				count++;
			}
			printf("\n|NEWCMD|%s|\n\n", data->value);
			printf("Je suis la derniere valeur de la commande |%s|\n",
				data->value);
			//
			// if (data->next != NULL)
			// 	data = data->next;
			// printf("Je suis la derniere valeur de la commande |%s|\n",
			// 	data->value);
		}
		if (data->token == PIPE)
		{
			printf("\n|PIPE|");
			data = data->next;
			if (data->token == CMD)
			{
				printf("\n|CMDPIPE|\n");
				if (pipe(base.fd) == -1)
					printf("ERROR");
				base.pipe_filled = 1;
				ft_fork_arg_pipe(data, envp, &base);
			}
		}
		if (data->token == ECHO)
		{
			printf("\n|ECHO|\n");
			data->echo = 1;
			// ft_verifquotation(data);
			// iL doit afficher a l'ecran
			base.pipe_filled = 0;
			if (data->arg == NULL)
			{
				printf("\n|FTDISPLAY|\n");
				ft_display_echo(data);
			}
			else
			{
				printf("\n|FTDISPLAYN|\n");
				ft_display_echo_arg_n(data);
			}
		}
		// POUR EXPORT LE PROCESSUS EST ALORS MIS PLUS HAUT Mise en place d'un export plus haut dans le processus.
		if (data->token == OUTFILE)
		{
			printf("\n|OUTFILE|\n");
			ft_init_outfile(&base, data);
			dump_pipe_to_file(&base);
			// Il faut faire une conditions si il n'y a que une seul commande.
			// ft_exceve_outfile(&base, envp, base.fd_origin);
			// if (base.cmd >= 1 && base.infile_nbr >= 1)
			// {
			// 	base.pipe_filled = 0;
			// }
		}
		if (data->token == ENV)
		{
			printf("\n|ENVP|\n");
			i = 0;
			while (copy_envp[i])
			{
				printf("\n%s\n", copy_envp[i]);
				i++;
			}
		}
		if (data->token == UNSET)
		{
			// IL permet d'enlever une variable la copy_envp
			printf("\n|UNSET|\n");
			if (data->next != NULL)
				data = data->next;
			if (data->token == CMD)
			{
				if (ft_search_unset(copy_envp, data->value) == 1)
				{
					printf("\n|itsok|EXIST|\n");
					ft_delete_unset(copy_envp, data->value);
					// ft_display_envp(copy_envp);
					// IL faut alors commencer a chercher dans l'environnement la variable ZDOTDIR
				}
				else
				{
					// Il faut faire un exitcode
					printf("\n|itsnotok|NOTEXIST|\n");
				}
			}
		}
		if (data->token == CD)
		{
			printf("|CD|");
			// Il faut commencer a pouvoir rentrer dans le repertoire
			// Voir si apres la CMD CD IL A le fichier dans la premiere arborescance
			if (data->next != NULL)
				data = data->next;
			if (data->token == CMD)
			{
				// IL faut commencer alors a rechercher si il existe dans les repertoires
				printf("|CD_SEARCH|%s|", data->value);
				// C'est un cd sans chemin;
				ft_directory_exist_not_path(data->value);
				// Soit je fais une fonction exterireur qui fais un ls pour savoir si le CD vat marcher
			}
		}
		data = data->next;
	}
	printf("Je suis horsde la boucle |%d| ", base.pipe_filled);
	//
	// La conditions permettant de voir si le fd_origin est pleins et qu'il n'y a pas de outfile et que la pipe est remplit
	if (base.pipe_filled == 1)
	{
		printf("|OUTFILETERMINAL|");
		// IL faut alors deverser la pipe dans le terminal
		dump_pipe_to_terminal(base.fd_origin, &base);
	}
}
