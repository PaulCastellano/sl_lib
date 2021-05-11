#include <unistd.h>
#include "sl_boolean.h"
#include "sl_memory.h"

//return TRUE FALSE
int     isAlphaOrDigit(int);
int     isAlpha(int);
int     isAscii(int);
int     isBlank(int);
int     isControl(int);
int     isDigit(int);
int     isGraph(int);
int     isLowerCase(int);
int     isPrinting(int);
int     isSpace(int);
int     isUpperCase(int);
int     isXDigit(int);
int		isInSet(char, char *);

//return number
int     toUpperCase(int);
int		toLowerCase(int);
int     printChar(int, char);
int     printString(int, char*);
int     getStringLength(char*);
int     stringCompare(const char*, const char*);
int     stringComparebyN(const char*, const char*, size_t);
int     convertStringToInteger(const char *);
int		isStringEqual(char const *, char const *);
int 	isStringEqualByN(char const *, char const *, size_t );
int		fillWord(char *, int , const char *, int );
int		getWordLength(int, const char *, char *);
int		getNumberOfWords(const char *, char *);
int		getNumberLenght(int );
int     printNumber(int, int);
int     printByEndLine(int, char const*);


//return adress to char
char*   getStringDublicate(const char*);
char*   getStringCopy(char*, const char*);
char*   getStringCopybyN(char*, const char*, size_t);
char*   getStringConcat(char*, const char*);
char*   getStringConcatbyN( char *, const char *, size_t);
char*   getStringByChar(const char*, int);
char*   findSubstringInString(const char*, const char*);
char*   findSubstringInStringByN(const char*, const char*, size_t);
char*   getNewString(size_t);
char*	UseFunctionInString(char const *, char (*)(char));
char*	UseFunctionInStringbyI(char const *, char (*)(unsigned int, char));
char*	findSubstringbyStringLen(char const *, unsigned int, size_t);
char*   getStringAfterJoinStrings(char const *, char const*);
char*   trimString(char const *);
char*	convertFromIntegertoChar(int);


//return adress to adress of char
char**	splitByChar(char const*, char);



//just set without return
void    stringDestory(char **);
void    clearString(char *);
void    useFunctionToString(char *, void (*)(char *));
void    useFunctionToStringbyI(char *, void (*f)(unsigned int, char *));
