#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - my linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	int merge_v;
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int merge_t;
	int merge_r;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
	char *merge_h;
} info_t;

#define INFO_INIT \
{0, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0, NULL}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int shell_main_process(info_t *, char **);
int search_builtin_cmd(info_t *);
void lookup_cmd(info_t *);
void execute_command(info_t *);
char *copy_str(char *, char *);
char *duplicate_strng(const char *);
void write_string(char *);
int write_char(char);
int command_check(info_t *, char *);
char *replicate_chars(char *, int, int);
char *get_path(info_t *, char *, char *);
void errorOutput(char *);
int writeErrorChar(char);
int outputCharToFD(char c, int fd);
int outputStrToFD(char *str, int fd);
void swap_int(int a, int b);
void print_rev(char *s);
void prints_half(char *str);


int stringlength(char *);
int string_compare(char *, char *);
char *prefix_match(const char *, const char *);
char *merge_strings(char *, char *);

char *copyLimitedString(char *, char *, int);
char *concatenateLimitedString(char *, char *, int);
char *searchCharInStr(char *, char);

char **tokenize_string(char *, char *);
char **tokenize_string_v2(char *, char);

char *assign_memory(char *, char, unsigned int);
void free_string_array(char **);
void *resize_memory(void *, unsigned int, unsigned int);

int freePtr_and_null(void **);
ssize_t getUserCommand(info_t *);
int commandLineReader(info_t *, char **, size_t *);
void sigintHandler(int);
int interactive(info_t *);
int delimiterCheck(char, char *);
int checkAlphabetic(int);
int convertStrToInt(char *);
ssize_t readBufferContent(info_t *info, char *buf, size_t *i);
int printAliasString(list_t *node);
int initializeAlias(info_t *info, char *str);
ssize_t manageInputBuffer(info_t *info, char **buf, size_t *len);
int resetAlias(info_t *info, char *str);
int atoiWithErrHandling(char *);
void echo_error(info_t *, char *);
int writeDecimal(int, int);
char *changeNumberBase(long int, int, int);
void remove_comments(char *);

int terminateShell(info_t *);
int switchDirectory(info_t *);
int helpGuide(info_t *);

int retrieveHistory(info_t *);
int aliasHandler(info_t *);
void eraseInfo(info_t *);
void defineInfo(info_t *, char **);
void deallocateInfo(info_t *, int);
char *fetchEnvironVariable(info_t *, const char *);
int processEnvironVariable(info_t *);
int modifyEnvVar(info_t *);
int clearEnvVar(info_t *);
int populate_env_list(info_t *);
char **get_environ(info_t *);
int resetEnvVar(info_t *, char *);
int defineEnvVar(info_t *, char *, char *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int loadCommandHistory(info_t *info);
int create_history_node(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
list_t *add_node_to_head(list_t **, const char *, int);
list_t *add_node_to_tail(list_t **, const char *, int);
size_t print_string_nodes(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void deallocate_list(list_t **);
size_t get_node_count(const list_t *);
char **list_to_strings(list_t *);
size_t print_list_nodes(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int check_chain_delimiter(info_t *, char *, size_t *);
void examine_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int updateVariableValues(info_t *);
int replace_string(char **, char *);

#endif
