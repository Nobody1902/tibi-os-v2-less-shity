#include "../BareMetal/api/libBareMetal.h"

void _start(void) {
  
  for(;;) {
    char keyChar;
    keyChar = b_input();
    if(keyChar == 'q') {
      b_system(SHUTDOWN, 0, 0);
    }
    b_output("Hello World!\n", 12);
  }
}
