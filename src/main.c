#include "../BareMetal/api/libBareMetal.h"

int cmpstr(char* str1, char* str2, int len);
void memwb(u8* addr, u8 byte);
u8 memrb(u8* addr);
u64 hex2u64(char* str, int len);

void _start(void) {

  b_output("Welcome to the new world!\n", 26);
  
  char text[100] = {0};
  char goodbye[100] = "goodbye";
  int cursor = 0;

  //Memory write and read test
  {
    memwb((u8*)0x002E0000, 'A');
    char test = memrb((u8*)0x002E0000);
    b_output(&test, 1);
    b_output("\n", 1);
    b_output((char*)0x002E0000,1);
    b_output("\n", 1);
  }
  //hex2u64 test
  {
    u64 test = hex2u64("11",2);
    for(int i = 0; i < test; i++)
      b_output("I",1);
    b_output("\n", 1);
  }


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
void memwb(u8* addr, u8 byte){
  *addr = byte;
}
u8 memrb(u8* addr){
  return *addr;
}
u64 hex2u64(char* str, int n){
  u64 out = 0;
  for(int i = 0; i < n; i++){
    out *= 16;
    if(str[i] >= '0' && str[i] <= '9')
      out += *str - '0';
    if(str[i] >= 'a' && str[i] <= 'f')
      out += (*str - 'a') + 0xA;
    if(str[i] >= 'A' && str[i] <= 'F')
      out += (*str - 'A') + 0xA;
  }
  return out;
}

