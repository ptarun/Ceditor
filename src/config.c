#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>






// variable to store original terminal state
struct termios original_termios;


void die(const char *error_message){
    perror(error_message);
    exit(1);
}

void disableRawMode(void){
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios) == -1)
        die("Error disabling raw mode!");
}


void enableRawMode(void){

    if(tcgetattr(STDIN_FILENO, &original_termios) == -1)
        die("Error reading terminal config!");

    //enable raw mode
    struct termios raw = original_termios;

    /* 
        disable echoing the text we input
        disable canonical mode (read byte by byte)
        disable cntrl c z v
    */
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN); 
    // disable cntrl s q m
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    // disable output processing
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);

    //TODO
    //raw.c_cc[VMIN] = 0;
    //raw.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        die("Error enabling raw mode!");

    //disable raw mode at exit
    atexit(disableRawMode);

    return;

}




