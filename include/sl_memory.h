#include <stdlib.h>

void*   setMemory(void *s, int c, size_t n);
void    setMemoryToZero(void *s, size_t n);
void*   memoryCopy(void *, const void *, size_t);
void*   memoryCopybyC(void*, const void*, int, size_t);
void*   memoryMove(void*, const void*, size_t);
void*   memoryFindC(const void*, int, size_t);
int     memoryCompare(const void*, const void*, size_t);
void*   memoryAlloc(size_t);
void    memoryDestroy(void **ap);


