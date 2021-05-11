#include <stdlib.h>

void*   sl_memset(void *s, int c, size_t n);
void    sl_bzero(void *s, size_t n);
void*   sl_memcpy(void *, const void *, size_t);
void*   sl_memccpy(void*, const void*, int, size_t);
void*   sl_memmove(void*, const void*, size_t);
void*   sl_memchr(const void*, int, size_t);
int     sl_memcmp(const void*, const void*, size_t);
void*   sl_memalloc(size_t);
void    sl_memdel(void **ap);


