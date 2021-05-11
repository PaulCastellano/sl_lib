#include "../include/sl_memory.h"

void    setMemoryToZero(void *s, size_t n)
{
    setMemory(s, 0, n);
}

void*   memoryAlloc(size_t size)
{
    void* memmory;

    memmory = (void*)malloc(size);
    setMemoryToZero(memmory, size);

    return memmory;
}

void*   memoryCopybyC(void* dest, const void* src, int c, size_t n)
{
   int i = -1;
   
   while (++i < n || ((unsigned char*)src)[i] != c)
   {
       ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
   }
   
   return dest;
}

void*   memoryFindC(const void* s, int c, size_t n)
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

int     memoryCompare(const void* s1, const void* s2,size_t n)
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

void*   memoryCopy(void *dest, const void *src, size_t n)
{
   int i = -1;
   
   while (++i < n)
   {
        ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
   }
 
    return dest;
}

void    memoryDestroy(void **ap)
{
    if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void*   memoryMove(void *dest, const void *src, size_t n)
{
    unsigned char tmp[n];
    memoryCopy(tmp,src,n);
    memoryCopy(dest,tmp,n);
    return dest;
}

void*   setMemory(void *s, int c, size_t n)
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