#include "../include/sl_string.h"

int     printChar(int file, char c)
{
    return write(file, &c, 1);
}

int     printString(int file, char* string)
{
    if (*string) {
        return printChar(file, *string) + printString(file, string + 1);
    }
    return 0;
}

char*   getStringConcat(char *destination, const char *append)
{
    getStringCopy(destination + getStringLength((char*)append), append);
    return destination;
}

char*   getStringByChar(const char *s, int c)
{
    s = memoryFindC(s, c, getStringLength(s));
    return s;
}

char*   getStringCopy(char *dst, const char *src)
{
   char *save = dst;

   while(*dst++ = *src++)
    ;

   return save;
}

char*   getStringDublicate(const char* str)
{
    char*	dublicate;
	int		len;

	len = getStringLength((char*)str);
    dublicate = memoryAlloc(len);
    sl_memcpy(dublicate, str, len);
    return dublicate;
}

int     getStringLength(char* str)
{
    if (*str)
        return 1 + getStringLength((char*)(str + 1));
        
    return 0;
}

char*   getStringConcatbyN( char *dest, const char *src, size_t count)
{
    getStringCopybyN(dest + getStringLength((char*)src), src, count);
    return dest;
}

char*   getStringCopybyN(char* dst, const char* src, size_t len)
{
	int destinationLen = getStringLength((char*)dst);
	int sourceLen = getStringLength((char*)src);


    if (destinationLen != len) {
        if (sourceLen > len) {
            dst = memoryAlloc(len);
        } else {
            len = sourceLen;
            dst = memoryAlloc(len);
        }
    }
    sl_memcpy(dst, src, len);

    return dst;
}

char*   findSubstringInString(const char* haystack, const char* needle)
{
	int needleLength;

	needleLength = getStringLength(needle);
	while (*haystack)
	{
		if (!memoryCompare(haystack, needle, needleLength))
			return haystack;
		haystack++;
	}
	return 0;
}

char*   findSubstringInStringByN(const char* haystack, const char* needle, size_t n)
{
	int needleLength;

	needleLength = getStringLength(needle);
	while (*haystack || n--)
	{
		if (!memoryCompare(haystack, needle, needleLength))
			return haystack;
		haystack++;
	}
	return 0;
}

int     stringCompare(const char* str1, const char* str2)
{
	return memoryCompare(str1, str2, getStringLength(str1));
}

int     stringComparebyN(const char* str1, const char* str2, size_t n)
{
	return memoryCompare(str1, str2, n);
}

int     convertStringToInteger(const char *nptr)
{
	int result = 0;
	int isNegative = FALSE;

	while (*nptr && (isSpace(*nptr) || *nptr == '-'))
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

int     isAlphaOrDigit(int c)
{
	return isAlpha(c) || isDigit(c);
}

int     isAlpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' &&  c <= 'Z'));
}

int     isAscii(int c)
{
	return c >= 32;
}

int     isBlank(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n');
}

int     isControl(int c)
{
	return  (c == '\0' || c == '\a' || c == '\b' || c == '\t' ||
			c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int     isDigit(int c)
{
	return (c >= '0' && c <= '9');
}

int     isGraph(int c)
{
	return (c >= 33 && c <= 127);
}

int     isLowerCase(int c)
{
	return (c >= 'a' && c <= 'z');
}

int     isPrinting(int c)
{
	return (c >= 32 && c <= 127);
}

int     isSpace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == ' ');
}

int     isUpperCase(int c)
{
	return (!isControl(c) && !isDigit(c) && !sl_ispunct(c) && !isSpace(c));
}
int     isXDigit(int c)
{
	return (isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int     toUpperCase(int ch)
{
	if (isLowerCase(ch))
		return ch - 32;
	return ch;
}

int		toLowerCase(int ch)
{
	if (isUpperCase(ch))
		return ch + 32;
	return ch;
}

char*   getNewString(size_t size)
{
	return memoryAlloc(sizeof(char) * size);
}

void    stringDestory(char **as)
{
	return memoryDestroy(as);
}

void    clearString(char *s)
{
	setMemoryToZero(s, getStringLength(s));
}

void    useFunctionToString(char *s, void (*f)(char *))
{
	char* tmp;

	tmp = s;
	while (*tmp)
	{
		f(tmp);
		tmp++;
	}
}

void    useFunctionToStringbyI(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	index = -1;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

char*	UseFunctionInString(char const *s, char (*f)(char))
{
	char*	newString;
	int		i;
	int		len;

	len = getStringLength(s);

	newString = getNewString(len + 1);
	while (++i < len)
		newString[i] = f(s[i]);
	return newString;
}

char*	UseFunctionInStringbyI(char const *s, char (*f)(unsigned int, char))
{
	char*	newString;
	int		i;
	int		len;

	len = getStringLength(s);

	newString = getNewString(len + 1);
	while (++i < len)
		newString[i] = f(i, s[i]);
	return newString;
}

int		isStringEqual(char const *s1, char const *s2)
{
	if (stringCompare(s1, s2))
		return FALSE;
	return TRUE;
}

int 	isStringEqualByN(char const *s1, char const *s2, size_t n)
{
	if (stringComparebyN(s1, s2, n))
		return FALSE;
	return TRUE;
}

char*	findSubstringbyStringLen(char const *s, unsigned int start, size_t len)
{
	char*	newString;
	int index;

	newString = getNewString(len);
	index = 0;
	while (*(s + start + index))
	{
		newString[index] = *(s + start + index);
		index++;
	}
	return newString;
}

char* getStringAfterJoinStrings(char const *s1, char const*s2)
{
	char*	newString;
	int		len1;
	int		len2;
	int		index;

	len1 = getStringLength(s1);
	len2 = getStringLength(s2);
	newString = getNewString(len1 + len2);
	newString = getStringCopy(newString, s1);
	index = 0;
	while (*(s2 + index))
	{
		newString[len1 + index] = *(s2 + index);
		index++;
	}
	return newString;
}

char*   trimString(char const *s)
{
	char*	newString;
	int		index;
	int		len;
	int		i;

	index = 0;
	while (isSpace(*(s + index)))
		index++;
	len = getStringLength(newString);
	while (isSpace(*(s + len - 1)))
		len--;
	
	newString = getNewString(len - index + 2);
	i = 0;
	while (i + index < len)
	{
		newString[i] = *(s + i + index);
		i++;
	}
	return newString;
}

int		isInSet(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
     	if (c == charset[i])
            return (TRUE);
        ++i;
    }
    return (FALSE);
}

int		getNumberOfWords(const char *str, char *charset)
{
    int     i;
    int     j;
    int     words;

    words = 0;
    i = 0;
    while (str[i])
    {
        if (isInSet(str[i], charset) == 1)
            while (isInSet(str[i], charset) == 1)
                ++i;
        else
        {
            j = i;
            while (isInSet(str[i], charset) == 0 && str[i])
                ++i;
            if (i > j)
                ++words;
        }
    }
    return (words);
}

int		getWordLength(int i, const char *str, char *charset)
{
    int l;

    l = 0;
    while (isInSet(str[i], charset) == 0 && str[i])
    {
     	++l;
        ++i;
    }
    return (l);
}

int		fillWord(char *arr, int i, const char *str, int l)
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

char**	splitByChar(char const *s, char c)
{
    char    **tab;
    int     i;
    int     j;
    int     l;

    if (!(tab = (char**)malloc(sizeof(char*) * (getNumberOfWords(s, c) + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (isInSet(s[i], c) == 1)
            ++i;
        else
        {
            l = getWordLength(i, s, c);
            if (!(tab[j] = (char*)malloc(sizeof(char) * (l + 1))))
                return (NULL);
            if ((i = fillWord(tab[j++], i, s, l)) == -1)
                return (NULL);
        }
    }
    tab[j] = 0;
    return (tab);	
}

int		getNumberLenght(int n)
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

char*	convertFromIntegertoChar(int n)
{
	char*	result;
	int		len;
	int		i;

	len = 1;
	if (n > 0)
		len = 2;
	len += getNumberLenght(n);
	result = getNewString(len);
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

int     printNumber(int file, int nbr)
{
	return printString(file, convertFromIntegertoChar(nbr));
}
int     printByEndLine(int file, char const *str)
{
	return printString(file, str) + printChar(file, '\n');
}
