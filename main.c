#include "include/sl_string.h"
//#include <stdlib.h>

int main() {
    char cpy[14] = "asdasd";
    char* omg = "Create";

    sl_strcat(cpy, omg);

    sl_putstr(1, omg);
    sl_putstr(1, cpy);

    return 0;
}