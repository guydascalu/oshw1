#include <stdio.h>
#include "defines.h"
#include "functions.h"

int main (void)
{
    printf(WELCOME_STRING, get_num());
    return 0;
}