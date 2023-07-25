#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

/* #define MYPRINTF(c) (write(STDOUT_FILENO, c, my_strlen(c)))*/

#define MYPRINTF(c) do { 
	ssize_t write_status = write(STDOUT_FILENO, c, my_strlen(c)); \
	if (write_status == -1)\
	{ \
		perror("hsh"); \
		return (-1); \
	} \
} while (0)

char *my_strtok(char *str, const char *tok);
unsigned int is_delim(char c, const char *str);
char *my_strncpy(char *dest, char *src, int n);
int my_strlen(char *s);
int _putchar(char c);
int my_atoi(char *s);
void my_puts(char *str);
int my_strcmp(char *s1, char *s2);
int is_alpha(int c);
void array_rev(char *arr, int len);
int my_intlen(int num);
char *my_itoa(unsigned int n);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);
char *my_strchr(char *s, char c);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strdup(char *str);

void free_env(char **env);
void *array_handler(void *j, int k, unsigned int len);
char *my_memcpy(char *dest, char *src, unsigned int n);
void *my_calloc(unsigned int size);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

void prompt(void);
int signal_to_handel(int sig);
char *my_getline(void);
void signal_to_handle(int signum);
int path_handler(char **command);
char *my_getenv(char *name);
char **parse_command(char *command);
int handle_builtin(char **command, int er);
char *build(char *token, char *value);
int check_builtin(char **command);
void environ_var(char **env);
int check_command(char **command, char *input, int c, char **argv);
void read_file(char *file_name, char **argv);
void check_file(char *line, int counter, FILE *fd, char **argv);
void exit_builtin(char **command, char *line, FILE *fd);
void execute_builtin(char **command, char *input, char **argv, int counter);
int env_var_d(__attribute__((unused)) char **c, __attribute__((unused)) int l);

void hashtag_handle(char *buff);
int execute_hist(char *input);
int history_dis(char **command, int er);
int dis_env(char **command, int er);
int change_dir(char **command, int er);
int display_help(char **command, int er);
int echo_bul(char **command, int er);
void exit_bul(char **command, char *input, char **argv, int c);
int ch_dir(char **command, __attribute__((unused)) int last);
int env_var_d(__attribute__((unused)) char **c, __attribute__((unused)) int l);
int builtin_h(char **command, __attribute__((unused))int er);
int builtin_echo(char **command, int last_command);
int execute_echo(char **command);
int exec_hist(__attribute__((unused))char **c, __attribute__((unused))int s);
void print_num(unsigned int n);
void num_putchar(int n);
void print_error(char *input, int counter, char **argv, int *error);
int my_perror(char **argv, int c, char **command);
int main(__attribute__((unused)) int argc, char **argv);

/**
 * struct builtin - contn builtn to hndl and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct builtin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
