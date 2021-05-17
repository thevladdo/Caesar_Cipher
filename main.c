/* Author: Vlad Dogariu */

#include <stdio.h>
#include "cipher.h"
#include <string.h>

int main() {
    char string[64];
    strcpy(string, "Insert string here");
    encode(string, 3);
    printf("%s\n",string);
    decode(string, 3);
    printf("%s\n",string);
    return 0;
}