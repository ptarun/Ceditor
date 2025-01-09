#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

// variable to store original terminal state
struct termios original_termios;

void disableRawMode(void){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}


void enableRawMode(void){

    tcgetattr(STDIN_FILENO, &original_termios);

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

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    //disable raw mode at exit
    atexit(disableRawMode);

    return;

}



