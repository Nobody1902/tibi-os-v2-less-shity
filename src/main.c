#include "../BareMetal/api/libBareMetal.h"

int cmpstr(char* str1, char* str2, int n);

void _start(void) {

  b_output("Hello World!\n", 13);
  
  char text[100] = {0};
  char goodbye[100] = "goodbye";
  int cursor = 0;

  for(;;) {
    char keyChar = b_input();

    // Enter
    if(keyChar == 0x1C) {
      b_output("\n", 1);
      // Check for goodbye commend
      if(cmpstr(text, goodbye, cursor))
        b_system(SHUTDOWN, 0, 0);
      cursor = 0;
      continue;
    }
    // Backspace
    if(keyChar == 0x0E) {
      b_output("\b", 1);
      if(cursor > 0) cursor--;
      continue;
    }

    if(keyChar){
      text[cursor] = keyChar;
      cursor++;
    }

    b_output(&keyChar, 1);
  }
}
int cmpstr(char* str1, char* str2, int n){
  for(int i = 0; i < n; i++){
    if(str1[i] != str2[i]) return 0;
  }
  return 1;
}
