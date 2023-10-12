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


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
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
 * struct leest_strng - my linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node  liststr  leest_strng
 */
typedef struct leest_strng
{
	int num;
	char *str;
	struct leest_strng *next;
} leest_ti;

/**
 *struct UserInfo - contains pseudo-arguements to pass into a function,
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
 *@histcount: the history line number count passinfo  UserInfo
 */
typedef struct UserInfo
{
	int mrge_varsn; 
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
	leest_ti *env;
	leest_ti *history;
	leest_ti *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
	char *merge_h;
} DataInfo_tii;

#define INFO_INIT \
{0, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0, NULL}

/**
 *struct cmdHandler - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function  builtin_table cmdHandler
 */
typedef struct cmdHandler
{
	char *type;
	int (*func)(DataInfo_tii *);
} cmdHandler_table;

int shell_main_process(DataInfo_tii *, char **);
int search_builtin_cmd(DataInfo_tii *);
void lookup_cmd(DataInfo_tii *);
void execute_command(DataInfo_tii *);
char *copy_str(char *, char *);
char *duplicate_strng(const char *);
void write_string(char *);
int write_char(char);
int command_check(DataInfo_tii *, char *);
char *replicate_chars(char *, int, int);
char *get_path(DataInfo_tii *, char *, char *);
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
ssize_t getUserCommand(DataInfo_tii *);
int commandLineReader(DataInfo_tii *, char **, size_t *);
void sigintHandler(int);
int interactive(DataInfo_tii *);
int delimiterCheck(char, char *);
int checkAlphabetic(int);
int convertStrToInt(char *);
ssize_t readBufferContent(DataInfo_tii *info, char *buf, size_t *i);
int printAliasString(leest_ti *node);
int initializeAlias(DataInfo_tii *info, char *str);
ssize_t manageInputBuffer(DataInfo_tii *info, char **buf, size_t *len);
int resetAlias(DataInfo_tii *info, char *str);
int atoiWithErrHandling(char *);
void echo_error(DataInfo_tii *, char *);
int writeDecimal(int, int);
char *changeNumberBase(long int, int, int);
void remove_comments(char *);

int terminateShell(DataInfo_tii *);
int switchDirectory(DataInfo_tii *);
int helpGuide(DataInfo_tii *);

int retrieveHistory(DataInfo_tii *);
int aliasHandler(DataInfo_tii *);
void eraseInfo(DataInfo_tii *);
void defineInfo(DataInfo_tii *, char **);
void deallocateInfo(DataInfo_tii *, int);
char *fetchEnvironVariable(DataInfo_tii *, const char *);
int processEnvironVariable(DataInfo_tii *);
int modifyEnvVar(DataInfo_tii *);
int clearEnvVar(DataInfo_tii *);
int populate_env_list(DataInfo_tii *);
char **get_environ(DataInfo_tii *);
int resetEnvVar(DataInfo_tii *, char *);
int defineEnvVar(DataInfo_tii *, char *, char *);
char *get_history_file(DataInfo_tii *info);
int write_history(DataInfo_tii *info);
int loadCommandHistory(DataInfo_tii *info);
int create_history_node(DataInfo_tii *info, char *buf, int linecount);
int renumber_history(DataInfo_tii *info);
leest_ti *add_node_to_head(leest_ti **, const char *, int);
leest_ti *add_node_to_tail(leest_ti **, const char *, int);
size_t print_string_nodes(const leest_ti *);
int delete_node_at_index(leest_ti **, unsigned int);
void deallocate_list(leest_ti **);
size_t get_node_count(const leest_ti *);
char **list_to_strings(leest_ti *);
size_t print_list_nodes(const leest_ti *);
leest_ti *node_starts_with(leest_ti *, char *, char);
ssize_t get_node_index(leest_ti *, leest_ti *);

int check_chain_delimiter(DataInfo_tii *, char *, size_t *);
void examine_chain(DataInfo_tii *, char *, size_t *, size_t, size_t);
int replace_alias(DataInfo_tii *);
int updateVariableValues(DataInfo_tii *);
int replace_string(char **, char *);

#endif
