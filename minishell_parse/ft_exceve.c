
#include "minishell_parse.h"

void	ft_init_open_file(t_excev *base, t_data *data)
{
	printf("Je suis ce qu'il faut ouvir |%s|\n", data->value);
	base->open_file = open(data->value, O_RDONLY);
	if (base->open_file < 0)
	{
		printf("IL y a un probleme ca ne marche pas \n");
	}
}

// void	ft_init_outfile(t_base *base, char *arg[], int arc)
// {

// 	data->open_outfile = open(arg[arc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (base->open_outfile < 0)
// 	{
// 		perror(arg[arc - 1]);
// 	}
// }
// void	ft_exceve_outfile(t_data *data, char *envp[], int fd_origin[])
// {
// 	int	pfd;

// 	(void)envp;
// 	if (data->open_outfile < 0)
// 	{
// 		return ;
// 	}
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

void	ft_fork_cmd(t_data *data, int fd[], char *envp[], int fd_origin[])
{
	int	pfd;

	(void)envp;
	pfd = fork();
	if (pfd < 0)
	{
		printf("error\n");
	}
	if (pfd == 0)
	{
		if (data->open_file != 0)
			dup2(data->open_file, 0);
		else
			printf("Il n'y a pas d'ouverture");
		dup2(fd[1], 1);
		// if (data->open_file > 0)
		// 	close(data->open_file);
		close(fd[0]);
		close(fd[1]);
		// execve(base->arg[0].path, base->arg[0].tab_arg, envp);
		exit(EXIT_FAILURE);
	}
	else if (pfd > 0)
	{
		if (data->open_file > 0)
			close(data->open_file);
		close(fd[0]);
		close(fd[1]);
		waitpid(pfd, NULL, 0);
		fd_origin[0] = fd[0];
		fd_origin[1] = fd[1];
	}
}
// void	ft_find_last_l_chev(t_data *data)
// {
// 	data->token = data->next;
// 	if (data->next->token = L_CHEV)
// 	{
// 		data->token = data->next;
// 		ft_find_last_l_chev;
// 	}
// 	return ;
// }

void	ft_init_base(t_excev *base)
{
	base->open_file = 0;
	base->open_outfile= 0;
}

void	ft_execve(t_data *data, char *envp[])
{
	int		fd[2];
	int		fd_origin[2];
	t_excev	base;

	ft_init_base(&base);
	(void)envp;
	if (pipe(fd_origin) == -1)
		printf("ERROR");
	// A chaque boucle il faut reverser la pipe 'origine
	if (data->token == L_CHEV)
	{
		printf("1\n");
		data = data->next;
		if (data->token == INFILE)
		{
			printf("2\n");
			ft_init_open_file(&base, data);
		}
		data = data->next;
	}
	if (data->token == CMD) // IL faut mettre 3
	{
		// Il faut sauvegarder la place dans la chaine
		// if (data->next->token == L_CHEV || data->next->token == INFILE)
		// {
		// 	if (data->next->token == L_CHEV)
		//		ft_find_last_l_chev(data);
		//	if(data->next->token == INFILE)
		//		ft_init_open_file(data);
		//	else
		//		write(1, "er notinf", 10);
		// }
		// if (pipe(fd) == -1)
		// 	printf("ERROR\n");
		ft_fork_cmd(data, fd, envp, fd_origin);
		// close(fd[0]);
		// close(fd[1]);
		data->pipe_filled = 1;
	}
	if (data->pipe_filled == 3) // C'est R_CHEVR
	{
		// if (data->token->next == OUTFILE)
		//{
		//		ft_init_outfile()
		//		ft_exceve_outfile(data, envp)
		//}
	}
	// IL faut faire avancer le token ici
}
// if (data->next != NULL && data->token == OUTFILE)
// {
// 	// Il faut voir si le token marche ou pas.
// }
// if (data->next != NULL && data->token == PIPE)
// {
// 	// Creation alors de la pipe()
// 	// ft_execve_pipe(data, fd);
// 	// Si apres la pipe ce n'est pas un pipe il faut alors mettre l'erreur
// }
// if (data->next != NULL && data->token == L_CHEV)
// {
// 	// IL faut boucler pour voir si il y a d'autre chevrons
// 	// Et prendre ainsi le dernier chevrons
// 	// Il suffit juste de mettre  un token_dessus;
// 	// Explication il faut alors au dernier chevrons pour ensuite prendre le infile et la commande et le remttre dans le terminal
// }
// if (data->next != NULL && data->token == R_CHEV)
// {
// 	// Il faut alors prendre La commande a partir de rien ou non  et supprimer le contenu pour y mettre le nouveau contenbu
// }
// if (data->next != NULL && data->token == D_R_CHEV)
// {
// 	// Il faut alors prendre La commande a partir de rien ou non  et rajouter le contenu pour y mettre le nouveau contenbu
// }
// if (data->next != NULL && data->token == D_L_CHEV)
// {
// 	// C'est l'utilisation du here_doc
// }
// if (data->next != NULL && data->token == D_L_CHEV)
// {
// 	//
// }