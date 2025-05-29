/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 06:01:47 by knakto            #+#    #+#             */
/*   Updated: 2025/05/29 15:32:24 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// #include "../parser/parser.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <stdlib.h>
#include <strings.h>
//
// volatile sig_atomic_t	g_signal = 0;
//
// t_redirect	*ft_new_re(char *eof, int type)
// {
// 	t_redirect	*re;
//
// 	re = malloc(sizeof(t_redirect)); re->value = NULL;
// 	if (eof)
// 		re->value = ft_strdup(eof);
// 	re->next = NULL;
// 	re->type = type;
// 	return (re);
// }
//
// t_process	*ft_new_proc(char **cmd, t_redirect *re)
// {
// 	t_process	*proc;
//
// 	proc = malloc(sizeof(t_process));
// 	// proc->redirect = ft_new_re("a", WRITE_FILE);
// 	proc->redirect = re;
// 	proc->cmd = cmd;
// 	proc->next = NULL;
// 	return (proc);
// }

// int	main()
// {
// 	int	code;
// 	int	temp_code;
// 	int	pid;
// 	int	pid_temp;

// 	// while
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		exit(0);
// 	}
// 	pid = fork();
// 	{
// 		exit(1);
// 	}
// 	// while
// 	pid_temp = wait(&temp_code);
// 	if (pid_temp == pid)
// 	{
// 		code = temp_code;
// 	}
// 	pid_temp = wait(&temp_code);
// 	if (pid_temp == pid)
// 	{
// 		code = temp_code;
// 	}
// }

// void	while_ft(t_redirect *re)
// {
// 	int	fd;
//
// 	while (re)
// 	{
// 		if (re->type == HERE_DOC)
// 		{
// 			ft_heredoc(re);
// 			// fd = open(re->value, O_RDONLY);
// 			// if (fd < 0)
// 			// {
// 			// 	pnf("Error: fd\n");
// 			// 	return 1;
// 			// }
// 			// line = get_next_line(fd);
// 			// while (line)
// 			// {
// 			// 	pnf("%s", line);
// 			// 	free(line);
// 			// 	line = get_next_line(fd);
// 			// }
// 			// unlink(re->value);
// 			// free(re->value);
// 			// free(re);// int	main()
// {
// 	int	code;
// 	int	temp_code;
// 	int	pid;
// 	int	pid_temp;

// 	// while
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		exit(0);
// 	}
// 	pid = fork();
// 	{
// 		exit(1);
// 	}
// 	// while
// 	pid_temp = wait(&temp_code);
// 	if (pid_temp == pid)
// 	{
// 		code = temp_code;
// 	}
// 	pid_temp = wait(&temp_code);
// 	if (pid_temp == pid)
// 	{
// 		code = temp_code;
// 	}
// }

// void	while_ft(t_redirect *re)
// {
// 	int	fd;
//
// 	while (re)
// 	{
// 		if (re->type == HERE_DOC)
// 		{
// 			ft_heredoc(re);
// 			// fd = open(re->value, O_RDONLY);
// 			// if (fd < 0)
// 			// {
// 			// 	pnf("Error: fd\n");
// 			// 	return 1;
// 			// }
// 			// line = get_next_line(fd);
// 			// while (line)
// 			// {
// 			// 	pnf("%s", line);
// 			// 	free(line);
// 			// 	line = get_next_line(fd);
// 			// }
// 			// unlink(re->value);
// 			// free(re->value);
// 			// free(re);
// 		}
// 		re = re->next;
// 	}
// 		}
// 		re = re->next;
// 	}

// void	ft_add_proc(t_process **proc, t_process *new)
// {
// 	t_process	*node;
//
// 	if (!*proc)
// 	{
// 		*proc = new;
// 		return ;
// 	}
// 	node = *proc;
// 	while (node->next)
// 	{
// 		printf("%s\n", *node->cmd);
// 		node = node->next;
// 	}
// 	node->next = new;
// }
//
// void	get_cmd(char *line)
// {
// 	t_process	*proc;
// 	int			i;
// 	char		**all_block_cmd;
//
// 	if (!ft_strchr(line, '|'))
// 	{
// 		proc = ft_new_proc(ft_split(line, ' '), NULL);
// 		*get_t_process() = proc;
// 		return ;
// 	}
// 	all_block_cmd = ft_split(line, '|');
// 	i = 0;
// 	while (all_block_cmd[i])
// 		ft_add_proc(get_t_process(), ft_new_proc(ft_split(all_block_cmd[i++], ' '), NULL));
// }
//
// int	check_cd(void)
// {
// 	t_process	*proc;
// 	char		*nextpath;
// 	char		thispath[1024];
//
// 	proc = *get_t_process();
// 	if (!ft_strncmp(proc->cmd[0], "cd", 3) && proc->cmd[1] && !proc->cmd[2] && !proc->next)
// 	{
// 		getcwd(thispath, sizeof(thispath));
// 		nextpath = ft_strjoin(thispath, "/");
// 		nextpath = fjoin(nextpath, proc->cmd[1]);
// 		if (chdir(nextpath) != 0)
// 			pnf_fd(2, "bash: cd: %s: No such file or directory\n", proc->cmd[1]);
// 		free(nextpath);
// 		return (1);
// 	}
// 	return (0);
// }
// void print_word_list(t_word_struct **head)
// {
// 	while (*head)
// 	{
// 		printf("word : %s, type : %d\n", (*head)->word, (*head)->word_type);
// 		*head = (*head)->next_word;
// 	}
// }
//
// void	get_line(void)
// {
// 	char	*line;
// 	char	get_path[1024];
// 	char	*path;
// 	t_word_struct	*word_struct;
// 	t_process		*process;
//
// 	word_struct = NULL;
// 	while (is_exit(0))
// 	{
// 		if (!getcwd(get_path, sizeof(get_path)))
// 			return ;
// 		path = ft_strjoin(ft_strrchr(get_path, '/'), "> ");
// 		line = readline(path);
// 		if (!line)
// 			return ;
// 		if (!syntax_check(line))
// 			continue ;
// 		//Debug_syntax print
// 		printf("syntax is correct\n");
// 		string_extraction(line, &word_struct);
// 		// word_to_process(&word_struct, &process);
// 		//Debug_string_extraction print
// 		printf("===== Token List =====\n");
// 		print_word_list(&word_struct);
// 		printf("======================\n");
// 		// word_struct = NULL;
// 		// get_cmd(line);
// 		// process();
// 		// clear_t_process();
// 		// free(path);
// 		// free(line);
// 		// จริงๆจะเช็ค syntax ด้วยก็ได้ เพราะ มันมีเคส ที่ มี " ติดมาตัวท้ายด้วย
// 		// ตัวอย่าง
// 		// /real_minishell_v3> ads "asd"""asdas"
// 		// ===== Token List =====
// 		// word : ads, type : 0
// 		// word : asd, type : 2
// 		// word : , type : 2
// 		// word : asdas", type : 0
// 		// ======================
// 		// ตามนี้
// 		clear_word_list(word_struct);
// 	}
// }

# include "parser.h"
void	prompt(void)
{
	char	*line;
	int		std_in;

	std_in = dup(0);
	while (is_exit(0))
	{
		dup2(std_in, 0);
		line = readline("minishell> ");
		if (!line)
			break ;
		add_history(line);
		if (parser(line))
			process();
		clear_t_process();
	}
	rl_clear_history();
}

// NOTE: 
// -sort export, export unset in other case ==>clear
// -error case
// -exit code								==>clear
// -memory leak								==>clear
// NOTE: day 15/4 5:44 Updated
// -finish ft_echo, ft_env, ft_export, ft_pwd, ft_unset and add redirect to it
// -finish all of env, it can read add change and delete
// -finish some leak and big error of memory
// -finish shell level in almost all case (dont have grep case and I dont do it lol)
// -check norm and push update this day
// NOTE: day 25/5 - 29/5 11.25 Update
// - after 4 day I doing parser and now I finish parser to execute struct
// and not leak ok after all I have only one process is a "signal" todo before
// try to submit
// - issue signal, check testcase
int	main(int c, char **v, char **envp)
{
	char	*line;
	// *env() = envp;
	init_env(envp);
	// print_env();
	// line = ft_strdup(v[1]);
	// parser(line);
	// free(line);
	prompt();
	// get_cmd("cd ..");
	// get_line();
	// cmd = ft_split("ls", ' ');
	// *get_t_process() = ft_new_proc(cmd, NULL);
	// process();
	// clear_t_process();
	clear_env();
	return (0);
}
