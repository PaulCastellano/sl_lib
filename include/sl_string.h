#include <unistd.h>
#include "sl_memory.h"

#define TRUE    1
#define FALSE   0

//return TRUE FALSE
int     sl_isalnum(int);
int     sl_isalpha(int);
int     sl_isascii(int);
int     sl_isblank(int);
int     sl_iscntrl(int);
int     sl_isdigit(int);
int     sl_isgraph(int);
int     sl_islower(int);
int     sl_isprint(int);
int     sl_isspace(int);
int     sl_isupper(int);
int     sl_isxdigit(int);

//return number
int     sl_toupper(int);
int		sl_tolower(int);
int     sl_putchar(int, char);
int     sl_putstr(int, char*);
int     sl_strlen(char*);
int     sl_strcmp(const char*, const char*);
int     sl_strncmp(const char*, const char*, size_t);
int     sl_atoi(const char *);
int		sl_strequ(char const *, char const *);
int 	sl_strnequ(char const *, char const *, size_t );
int		sl_fill_word(char *, int , const char *, int );
int		sl_word_length(int, const char *, char *);
int		sl_n_words(const char *, char *);
int		sl_in_set(char, char *);
int		sl_number_lenght(int );
int     sl_putnbr(int, int);
int     ft_putendl(int, char const*);


//return adress to char
char*   sl_strdup(const char*);
char*   sl_strcpy(char*, const char*);
char*   sl_strncpy(char*, const char*, size_t);
char*   sl_strcat(char*, const char*);
char*   sl_strncat( char *, const char *, size_t);
char*   sl_strchr(const char*, int);
char*   sl_strstr(const char*, const char*);
char*   sl_strnstr(const char*, const char*, size_t);
char*   sl_strnew(size_t);
char*	sl_strmap(char const *, char (*)(char));
char*	sl_strmapi(char const *, char (*)(unsigned int, char));
char*	sl_strsub(char const *, unsigned int, size_t);
char*   sl_strjoin(char const *, char const*);
char*   sl_strtrim(char const *);
char*	ft_itoa(int);


//return adress to adress of char
char**	ft_strsplit(char const*, char);



//just set without return
void    sl_strdel(char **);
void    sl_strclr(char *);
void    sl_striter(char *, void (*)(char *));
void    sl_striteri(char *, void (*f)(unsigned int, char *));
