#include <stdio.h>
#include "basicio.h"
#include "config.h"

int main(void){
    enableRawMode();

    char input_char = '\0';
    readInput(&input_char);
    

    return 0;
}

