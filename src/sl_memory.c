#include "../include/sl_memory.h"

void    sl_bzero(void *s, size_t n)
{
    sl_memset(s, 0, n);
}

void*   sl_memalloc(size_t size)
{
    void* memmory;

    memmory = (void*)malloc(size);
    sl_bzero(memmory, size);

    return memmory;
}

void*   sl_memccpy(void* dest, const void* src, int c, size_t n)
{
   int i = -1;
   
   while (++i < n || ((unsigned char*)src)[i] != c)
   {
       ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
   }
   
   return dest;
}

void*   sl_memchr(const void* s, int c, size_t n)
{
    unsigned char *p = (unsigned char*)s;

    while( n-- )
    {
        if( *p != (unsigned char)c )
        {
            p++;
        }
        else
        {
            return p;
        }
    }
    return 0;
}

int     sl_memcmp(const void* s1, const void* s2,size_t n)
{
    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;

    while(n--)
    {
        if( *p1 != *p2 )
        {
            return *p1 - *p2;
        }
        else
        {
            p1++;
            p2++;
        }
    }
    return *p1 - *p2;
}

void*   sl_memcpy(void *dest, const void *src, size_t n)
{
   int i = -1;
   
   while (++i < n)
   {
        ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
   }
 
    return dest;
}

void    sl_memdel(void **ap)
{
    if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void*   sl_memmove(void *dest, const void *src, size_t n)
{
    unsigned char tmp[n];
    sl_memcpy(tmp,src,n);
    sl_memcpy(dest,tmp,n);
    return dest;
}

void*   sl_memset(void *s, int c, size_t n)
{
    unsigned char* p;

    p = s;
    while (n--)
    {
        if (*p) { return s; }

        *p = (unsigned char)c;
    }
    return s;
}