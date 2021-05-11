#include "include/sl_memory.h"
#include "include/sl_boolean.h"
#include <stdio.h>
#include <string.h>
/*
void*   setMemory(void *s, int c, size_t n); check
void    setMemoryToZero(void *s, size_t n); 
void*   memoryCopy(void *, const void *, size_t);
void*   memoryCopybyC(void*, const void*, int, size_t);
void*   memoryMove(void*, const void*, size_t);
void*   memoryFindC(const void*, int, size_t);
int     memoryCompare(const void*, const void*, size_t);
void*   memoryAlloc(size_t);
void    memoryDestroy(void **ap);
*/
int main() {
    int errors = FALSE;
    char*   testChar;
    int*    testInt;
    //Verify memoryAlloc for char
    testChar = memoryAlloc(1);
    if (testChar == NULL)
    {
        fprintf(stderr, "Can't alloc 1 char!\n");
        errors = TRUE;
    }
    testChar = memoryAlloc(3242);
    if (testChar == NULL)
    {
        fprintf(stderr, "Can't alloc multiple char!\n");
        errors = TRUE;
    }
    testChar = memoryAlloc(0);
    if (testChar != NULL)
    {
        fprintf(stderr, "Allocate if is 0!\n");
        errors = TRUE;
    }

    //Verify memoryAlloc for int
    testInt = memoryAlloc(sizeof(int));
    if (testInt == NULL)
    {
        fprintf(stderr, "Can't alloc 1 char!\n");
        errors = TRUE;
    }
    testInt = memoryAlloc(3242);
    if (testInt == NULL)
    {
        fprintf(stderr, "Can't alloc multiple char!\n");
        errors = TRUE;
    }
    testInt = memoryAlloc(0);
    if (testInt != NULL)
    {
        fprintf(stderr, "Allocate if is 0!\n");
        errors = TRUE;
    }

    //verify setMemoryToZero and setMemory

    testChar = "test this";
    setMemoryToZero(testChar, 3);
    if (testChar[0] != '\0' && testChar[1] != '\0' && testChar[2] != '\0' && testChar[3] == '\0')
    {
        fprintf(stderr, "Can't set to zero par of string\n");
        errors = TRUE;
    }
    
    testChar = "test this";
    setMemoryToZero(testChar, 0);
    if (testChar[0] == 0)
    {
        fprintf(stderr, "Set to zero when is 0\n");
        errors = TRUE;
    }

    if (errors == FALSE)
        printf("Don't have problems\n");
    return 0;
}