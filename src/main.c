#include "../BareMetal/api/libBareMetal.h"

void _start(void) {

  b_output("Hello World!\n", 13);
  
  char text[100];
  int cursor = 0;

  for(;;) {
    char keyChar = b_input();

    // Enter
    if(keyChar == 0x1C) {
      b_output("\n", 1);
      continue;
    }
    // Backspace
    if(keyChar == 0x0E) {
      b_output("\b", 1);
      continue;
    }
    if(keyChar == 'q') {
      b_system(SHUTDOWN, 0, 0);
    }

    cursor++;
    text[cursor] = keyChar;

    b_output(&keyChar, 1);
  }
}
