#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

// definitions
void readInput(char* input_char){

     while (1) {
       
        if(read(STDIN_FILENO, input_char, 1) == -1 && errno != EAGAIN) 
            die("Error reading input!");

        if (iscntrl(*input_char)) {
            printf("%d\r\n", *input_char);
        } 
        else {
            printf("%d ('%c')\r\n", *input_char, *input_char);
        }
        if (*input_char == 'q') break;
    }

    return;
}
