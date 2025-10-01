/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:38:58 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/18 22:14:58 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# define SKIP 1
# define NOSKIP 0

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7
# define HEREDOC 8

# define BUFF_SIZE 4096
# define EXPANSION -36
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 12

# define ERROR 1
# define SUCCESS 0

/* Token types for lexical analysis */
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_HEREDOC,
	TOKEN_SEMICOLON,
	TOKEN_EOF,
	TOKEN_ERROR
}	t_token_type;

/* Basic structures */
typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;

typedef struct s_expansions
{
	char			*new_arg;
	int				i;
	int				j;
}				t_expansions;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

/* Parser structures */
typedef struct s_parser_token
{
	t_token_type			type;
	char					*value;
	struct s_parser_token	*next;
}	t_parser_token;

typedef struct s_parser
{
	char			*input;
	int				position;
	t_env			*env;
	t_parser_token	*current_token;
}	t_parser;

typedef struct s_mini
{
	t_token			*start;
	t_env			*env;
	t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				pid;
	int				charge;
	int				parent;
	int				last;
	int				ret;
	int				exit;
	int				no_exec;
}				t_mini;

typedef struct s_expand
{
	const char	*str;
	int			*i;
	t_env		*env;
	char		**result;
}	t_expand;

typedef struct s_quotes
{
	const char	*str;
	int			*i;
	int			*in_dquotes;
	int			*in_squotes;
	char		**result;
}	t_quotes;

typedef struct s_exp_args
{
	char	*arg;
	int		*i;
	char	*result;
	int		*j;
}	t_exp_args;

typedef struct s_quote_state
{
	int	in_single;
}	t_quote_state;

typedef struct s_expand_vars
{
	int				*i;
	t_env			*env;
	int				ret;
	t_quote_state	*quotes;
}	t_expand_vars;

/* Global signal variable */
extern t_sig	g_sig;

/* BUILTINS */
int				ft_echo(char **args);
int				ft_cd(char **args, t_env *env);
int				ft_pwd(void);
int				ft_env(t_env *env);
int				ft_export(char **args, t_env *env, t_env *secret_env);
int				ft_unset(char **args, t_mini *mini);
void			mini_exit(t_mini *mini, char **cmd);

/* LEXER & TOKENIZATION */
void			lexer_skip_whitespace(t_parser *parser);
t_parser_token	*create_token(t_token_type type, char *value);
t_parser_token	*lexer_get_next_token(t_parser *parser);
t_parser_token	*handle_word(t_parser *parser);
t_parser_token	*extract_word_value(t_parser *parser, int start, int len);
t_parser_token	*process_word_token(t_parser *parser, char *value);
t_parser_token	*handle_redirects(t_parser *parser, char current);
char			*expand_env_vars(const char *str, t_env *env);

void			handle_quotes(t_quotes *q);
void			handle_env_expansion(t_expand *exp);
void			append_char(const char *str, int *i, char **result);

/* PARSER & CONVERSION */
t_parser		*parser_init(char *input);
t_parser		*parser_init_with_env(char *input, t_env *env);
t_parser_token	*parser_parse_command(t_parser *parser);
void			parser_free(t_parser *parser);
t_token			*convert_to_mini_tokens(t_parser_token *parser_tokens);
void			free_parser_tokens(t_parser_token *tokens);
int				convert_token_type(t_token_type type);

/* ENVIRONMENT */
int				check_line(t_mini *mini, t_token *token);
char			*env_to_str(t_env *lst);
int				env_init(t_mini *mini, char **env_array);
int				secret_env_init(t_mini *mini, char **env_array);
char			*get_env_value(char *arg, t_env *env);
char			*env_value(char *env);
int				env_value_len(const char *env);
int				is_env_char(int c);
int				is_valid_env(const char *env);
void			print_sorted_env(t_env *env);
void			increment_shell_level(t_env *env);
size_t			size_env(t_env *lst);
int				is_in_env(t_env *env, char *args);
int				env_add(const char *value, t_env *env);
char			*get_env_name(char *dest, const char *src);

/* ENV Utils */
char			*extract_env_name(const char *str);
int				is_valid_env_char(char c);
int				get_env_name_len(const char *str);

/* EXEC */
void			process_command(t_mini *mini, t_token *token);
char			**create_command_array(t_token *start);
int				execute_external(char **args, t_env *env, t_mini *mini);
int				execute_builtin(char **args, t_mini *mini);
int				verify_builtin(const char *command);
char			*find_command_path(char *cmd, char **dirs);
int				exec_cmd(char *path, char **args, t_env *env, t_mini *mini);

/* SIGNAL HANDLING */
void			handle_sigint(int code);
void			handle_sigquit(int code);
void			initialize_signals(void);

/* REDIRECTION */
void			handle_output_redirect(t_mini *mini, t_token *token, int type);
void			handle_input_redirect(t_mini *mini, t_token *token);
int				setup_pipe(t_mini *mini);
int				handle_heredoc(t_mini *mini, t_token *delimiter);
int				setup_redirections(t_mini *mini, t_token *token, int type);
void			process_redirections_and_execute(t_mini *mini, t_token *token);

/* PARSING */
void			parse(t_mini *mini);
t_token			*get_tokens(char *line);
void			squish_args(t_mini *mini);
int				is_last_valid_arg(t_token *token);
int				quotes(char *line, int index);
void			type_arg(t_token *token, int separator);
int				is_sep(char *line, int i);
int				ignore_sep(char *line, int i);

/* EXPANSIONS */
int				ret_size(int ret);
int				get_var_len(const char *arg, int pos, t_env *env, int ret);
char			*get_var_value(const char *arg, int pos, t_env *env, int ret);
char			*expansions(char *arg, t_env *env, int ret);

void			process_char_with_vars(char *result, int *j, char *arg, \
				t_expand_vars *vars);
void			handle_var_expansion(char *result, int *j, char *arg, \
				t_expand_vars *vars);
char			*remove_quotes(char *str);
void			init_expansion_args(t_exp_args *args, char *arg, \
				int *i, int *j);
void			handle_env_variable(t_exp_args args, t_env *env, int ret);
void			reset_quote_state(void);
void			handle_single_quote(char *result, int *j, char *arg, int *i);
void			copy_char(char *result, int *j, char *arg, int *i);

/* MINISHELL */
/* Legacy redirection function names for compatibility
	- call the new functions */
void			redir(t_mini *mini, t_token *token, int type);
void			input(t_mini *mini, t_token *token);
int				minipipe(t_mini *mini);

void			init_mini_main(t_mini *mini);
void			custom_parse(t_mini *mini);
void			redir_and_exec(t_mini *mini, t_token *token);
void			minishell(t_mini *mini);

void			init_mini_sh(t_mini *mini);

/* TOOLS */
void			reset_std(t_mini *mini);
void			close_fds(t_mini *mini);
void			ft_close(int fd);
void			reset_fds(t_mini *mini);
int				ft_itoa_buf(int n, char *buf);

void			free_token(t_token *start);
void			free_env(t_env *env);
void			free_tab(char **tab);
void			free_token_and_null(t_token **token_ptr);

int				is_type(t_token *token, int type);
int				is_t(t_token *token, char *types);
int				has_type(t_token *token, int type);
t_token			*next_type(t_token *token, int type, int skip);
int				str_case_cmp(const char *s1, const char *s2);

t_token			*next_sep(t_token *token, int skip);
t_token			*prev_sep(t_token *token, int skip);
t_token			*next_run(t_token *token, int skip);
int				error_message(char *path);
void			display_lets_go(void);
int				handle_quoted_variable(t_mini *mini, char *line);

int				calculate_args_count(t_token *start);
char			**construct_command_array(t_token *start, int size);

void			extract_name(char *name, char *arg, int *i, int start);
void			copy_var_to_result(char *result, int *j, char *val);
void			handle_question_mark(char *result, int *j, int *i, int ret);
void			hand_sing_quot(char *result, int *j, char *arg, \
				t_expand_vars *vars);
void			cpy_char(char *result, int *j, char *arg, int *i);

/* SIGNAL */
/* Legacy signal function names for compatibility - call the new functions */
void			sig_int(int code);
void			sig_quit(int code);
void			sig_init(void);

/* Function to check if command is special and should be caught early */
int				handle_special_command(t_mini *mini, char *line);
void			create_tokens(t_mini *mini, char *line);

// Add declaration for expand_args
void			expand_args(char **cmd, t_mini *mini);

/* dollar.c */
int				is_only_quotes(const char *str);
int				count_consecutive_quotes(const char *str, int start);
char			*handle_quoted_dollar(t_mini *mini, char *line);

/* Parsing functions */
int				handle_uppercase_command(t_parser *parser, int start);

/* Parser Functions */
void			initialize_signals(void);
t_parser		*parser_init(char *input);
t_parser		*parser_init_with_env(char *input, t_env *env);
int				convert_token_type(t_token_type type);
void			parser_free(t_parser *parser);
void			parse(t_mini *mini);
int				validate_token_syntax(t_token *tokens);

/* Debug functions */
void			debug_print_tokens(t_token *start);
void			print_token_type(int type);

#endif
