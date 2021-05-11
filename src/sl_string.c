#include "../include/sl_string.h"

int     sl_putchar(int file, char c)
{
    return write(file, &c, 1);
}

int     sl_putstr(int file, char* string)
{
    if (*string) {
        return sl_putchar(file, *string) + sl_putstr(file, string + 1);
    }
    return 0;
}

char*   sl_strcat(char *destination, const char *append)
{
    sl_strcpy(destination + sl_strlen((char*)append), append);
    return destination;
}

char*   sl_strchr(const char *s, int c)
{
    s = sl_memchr(s, c, sl_strlen(s));
    return s;
}

char*   sl_strcpy(char *dst, const char *src)
{
   char *save = dst;

   while(*dst++ = *src++)
    ;

   return save;
}

char*   sl_strdup(const char* str)
{
    char*	dublicate;
	int		len;

	len = sl_strlen((char*)str);
    dublicate = sl_memalloc(len);
    sl_memcpy(dublicate, str, len);
    return dublicate;
}

int     sl_strlen(char* str)
{
    if (*str)
        return 1 + sl_strlen((char*)(str + 1));
        
    return 0;
}

char*   sl_strncat( char *dest, const char *src, size_t count)
{
    sl_strncpy(dest + sl_strlen((char*)src), src, count);
    return dest;
}

char*   sl_strncpy(char* dst, const char* src, size_t len)
{
	int destinationLen = sl_strlen((char*)dst);
	int sourceLen = sl_strlen((char*)src);


    if (destinationLen != len) {
        if (sourceLen > len) {
            dst = sl_memalloc(len);
        } else {
            len = sourceLen;
            dst = sl_memalloc(len);
        }
    }
    sl_memcpy(dst, src, len);

    return dst;
}

char*   sl_strstr(const char* haystack, const char* needle)
{
	int needleLength;

	needleLength = sl_strlen(needle);
	while (*haystack)
	{
		if (!sl_memcmp(haystack, needle, needleLength))
			return haystack;
		haystack++;
	}
	return 0;
}

char*   sl_strnstr(const char* haystack, const char* needle, size_t n)
{
	int needleLength;

	needleLength = sl_strlen(needle);
	while (*haystack || n--)
	{
		if (!sl_memcmp(haystack, needle, needleLength))
			return haystack;
		haystack++;
	}
	return 0;
}

int     sl_strcmp(const char* str1, const char* str2)
{
	return sl_memcmp(str1, str2, sl_strlen(str1));
}

int     sl_strncmp(const char* str1, const char* str2, size_t n)
{
	return sl_memcmp(str1, str2, n);
}

int     sl_atoi(const char *nptr)
{
	int result = 0;
	int isNegative = FALSE;

	while (*nptr && (sl_isspace(*nptr) || *nptr == '-'))
	{
		if (*nptr == '-')
			isNegative == TRUE;
		nptr++;
	}
	
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	if (isNegative)
		result *= -1;

	return result;
}

int     sl_isalnum(int c)
{
	return sl_isalpha(c) || sl_isdigit(c);
}

int     sl_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' &&  c <= 'Z'));
}

int     sl_isascii(int c)
{
	return c >= 32;
}

int     sl_isblank(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n');
}

int     sl_iscntrl(int c)
{
	return  (c == '\0' || c == '\a' || c == '\b' || c == '\t' ||
			c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int     sl_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int     sl_isgraph(int c)
{
	return (c >= 33 && c <= 127);
}

int     sl_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int     sl_isprint(int c)
{
	return (c >= 32 && c <= 127);
}

int     sl_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == ' ');
}

int     sl_isupper(int c)
{
	return (!sl_iscntrl(c) && !sl_isdigit(c) && !sl_ispunct(c) && !sl_isspace(c));
}
int     sl_isxdigit(int c)
{
	return (sl_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int     sl_toupper(int ch)
{
	if (sl_islower(ch))
		return ch - 32;
	return ch;
}

int		sl_tolower(int ch)
{
	if (sl_isupper(ch))
		return ch + 32;
	return ch;
}

char*   sl_strnew(size_t size)
{
	return sl_memalloc(sizeof(char) * size);
}

void    sl_strdel(char **as)
{
	return sl_memdel(as);
}

void    sl_strclr(char *s)
{
	sl_bzero(s, sl_strlen(s));
}

void    sl_striter(char *s, void (*f)(char *))
{
	char* tmp;

	tmp = s;
	while (*tmp)
	{
		f(tmp);
		tmp++;
	}
}

void    sl_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	index = -1;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

char*	sl_strmap(char const *s, char (*f)(char))
{
	char*	newString;
	int		i;
	int		len;

	len = sl_strlen(s);

	newString = sl_strnew(len + 1);
	while (++i < len)
		newString[i] = f(s[i]);
	return newString;
}

char*	sl_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char*	newString;
	int		i;
	int		len;

	len = sl_strlen(s);

	newString = sl_strnew(len + 1);
	while (++i < len)
		newString[i] = f(i, s[i]);
	return newString;
}

int		sl_strequ(char const *s1, char const *s2)
{
	if (sl_strcmp(s1, s2))
		return FALSE;
	return TRUE;
}

int 	sl_strnequ(char const *s1, char const *s2, size_t n)
{
	if (sl_strncmp(s1, s2, n))
		return FALSE;
	return TRUE;
}

char*	sl_strsub(char const *s, unsigned int start, size_t len)
{
	char*	newString;
	int index;

	newString = sl_strnew(len);
	index = 0;
	while (*(s + start + index))
	{
		newString[index] = *(s + start + index);
		index++;
	}
	return newString;
}

char* sl_strjoin(char const *s1, char const*s2)
{
	char*	newString;
	int		len1;
	int		len2;
	int		index;

	len1 = sl_strlen(s1);
	len2 = sl_strlen(s2);
	newString = sl_strnew(len1 + len2);
	newString = sl_strcpy(newString, s1);
	index = 0;
	while (*(s2 + index))
	{
		newString[len1 + index] = *(s2 + index);
		index++;
	}
	return newString;
}

char*   sl_strtrim(char const *s)
{
	char*	newString;
	int		index;
	int		len;
	int		i;

	index = 0;
	while (sl_isspace(*(s + index)))
		index++;
	len = sl_strlen(newString);
	while (sl_isspace(*(s + len - 1)))
		len--;
	
	newString = sl_strnew(len - index + 2);
	i = 0;
	while (i + index < len)
	{
		newString[i] = *(s + i + index);
		i++;
	}
	return newString;
}

int		sl_in_set(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
     	if (c == charset[i])
            return (1);
        ++i;
    }
    return (0);
}

int		sl_n_words(const char *str, char *charset)
{
    int     i;
    int     j;
    int     words;

    words = 0;
    i = 0;
    while (str[i])
    {
        if (in_set(str[i], charset) == 1)
            while (in_set(str[i], charset) == 1)
                ++i;
        else
        {
            j = i;
            while (in_set(str[i], charset) == 0 && str[i])
                ++i;
            if (i > j)
                ++words;
        }
    }
    return (words);
}

int		sl_word_length(int i, const char *str, char *charset)
{
    int l;

    l = 0;
    while (in_set(str[i], charset) == 0 && str[i])
    {
     	++l;
        ++i;
    }
    return (l);
}

int		sl_fill_word(char *arr, int i, const char *str, int l)
{
    int k;

    k = 0;
    while (k < l)
    {
        arr[k] = str[i];
        ++k;
        ++i;
    }
    arr[k] = '\0';
    return (i);
}

char**	sl_strsplit(char const *s, char c)
{
    char    **tab;
    int     i;
    int     j;
    int     l;

    if (!(tab = (char**)malloc(sizeof(char*) * (n_words(s, c) + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (in_set(s[i], c) == 1)
            ++i;
        else
        {
            l = word_length(i, s, c);
            if (!(tab[j] = (char*)malloc(sizeof(char) * (l + 1))))
                return (NULL);
            if ((i = fill_word(tab[j++], i, s, l)) == -1)
                return (NULL);
        }
    }
    tab[j] = 0;
    return (tab);	
}

int		sl_number_lenght(int n)
{
	int len;

	len = 0;

	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return len + 1;
}

char*	ft_itoa(int n)
{
	char*	result;
	int		len;
	int		i;

	len = 1;
	if (n > 0)
		len = 2;
	len += sl_number_lenght(n);
	result = sl_strnew(len);
	i = 0;
	while (n > 9)
	{
		result[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	result[i] = (n % 10) + '0';
	return result;
}

int     sl_putnbr(int file, int nbr)
{
	return sl_putstr(file, ft_itoa(nbr));
}
int     ft_putendl(int file, char const *str)
{
	return sl_putstr(file, str) + sl_putchar(file, '\n');
}
