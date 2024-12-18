#include "../BareMetal/api/libBareMetal.h"

int cmpstr(char* str1, char* str2, int n);
void memw(char* addr, char byte);
char memr(char* addr);

void _start(void) {

  b_output("Welcome to the new world!\n", 26);
  
  char text[100] = {0};
  char goodbye[100] = "goodbye";
  int cursor = 0;

  //Memory write and read test
  memw((char*)0x002E0000, 'A');
  char test = memr((char*)0x002E0000);
  b_output(&test, 1);
  b_output("\n", 1);
  b_output((char*)0x002E0000,1);
  b_output("\n", 1);


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
void memw(char* addr, char byte){
  *addr = byte;
}
char memr(char* addr){
  return *addr;
}
