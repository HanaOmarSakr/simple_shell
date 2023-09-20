#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAXLINE 512
#define MAXARG 10
#define DELIM
#define INFO_INIT {0, NULL, NULL, NULL, 0}
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1




/**
 * struct info - ......
 * @arg: a string generated from getline containing arguments.
 * @argc: the argument count.
 * @argv: an array of string generated from arg.
 * @env: linked list local copy of environ.
 * @env_changed: ......
 * @environ: custom modified copy of environ from LL env.
 * @status: the return status of the last exec'd command.
 * Description: ...
 */

typedef struct info
{
	char *arg;
	char **argv;
	int argc;
	list_t *env; 
	char **environ;
	int status;
	int env_changed;
	list_t *history;
	list_t *alias;

} info_t;

<<<<<<< HEAD
/**
 * struct liststr - singly linked list.
 * @numb: the number field.
 * @str: a string.
 * @next: points to the next node.
 */
typedef struct list_s
{
	unsigned int len;
	char *str;
	struct list_s *next;
} list_t;

=======
char* _strcat(char* dest, const char* src);
>>>>>>> 763428efc6510452c1e5adab6c5a3c769ad1a5dd
ssize_t _getline(char **line);
void execute(char **argv);
char **split_line(char *str, char *delim);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *buffer);
char *_strdup(const char *);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void wait_child(pid_t pid);
void execute_command(char *args[], char *envp[]);
int main(void);
char **my_strtok(char *str);
int is_delim(char b);
void _eputs(char *);
int _eputchar(char);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);
int _myexit(info_t *);
int _putchar(char);
void _puts(char *);
int _strcmp(char *, char *);
char *_strchr(char *, char);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char **strtow(char *, const char *);


/*Printf declarations*/
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024



#define _MINUS 1
#define _PLUS 2
#define _ZERO 4
#define _HASH 8
#define _SPACE 16
#define _LONG 2
#define _SHORT 1

/**
 * struct fmt - struct op
 * @fmt: the format
 * @func: the function
*/
struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: the format
 * @fmt_t: the function
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_p(const char *f, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int p_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_pct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_bit(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_uns(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);
int p_non_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int p_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_w_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int w_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int w_num(int ind, char bff[], int flags, int width, int precision,
	int len, char padd, char extra_c);
int w_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int w_uns(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int conv_size_num(long int num, int size);
long int conv_size_uns(unsigned long int num, int size);
#endif
