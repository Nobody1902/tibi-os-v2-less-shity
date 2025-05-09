#include "../BareMetal/api/libBareMetal.h"

#include "string.h"
#include "mem.h"
#include "print.h"
#include "math.h"

void _start(void) {

  print("Welcome to the new world!\n");

  char text[80] = {0};
  int cursor = 0;
  
  // log test
  {
    float l10 = log(10);
    float l1010 = log10(10);
    print_float(l10);
    print("\n");
    print_float(l1010);
  }

  // itos test
  {
    i64 num = -1234567890123456789;
    char buff[21];
    itos(num, buff);

    print(buff);
    print("\n");
  }

  // ftos test
  {
    float num = -12345.6789f;
    char buff[50];
    ftos(num, buff);
    print(buff);
    print("\n");
  }

  // hex2u64 test
  {
    u64 test = hex2u64("11");
    for(int i = 0; i < test; i++)
      print("I");
    print("\n");

    for(int i = 0; i < test; i++) {
      print("\b");
    }
  }

  for(;;) {
    char keyChar = b_input();

    // Enter
    if(keyChar == 0x1C) {

      if(strcmp(text, "exit")) {
        b_system(SHUTDOWN, 0, 0);
        continue;
      }
      if(strcmp(text, "clear")) {
        clear_screen();
      }

      for(int i = 0; i < cursor; i++) {
        print("\b");
      }

      cursor = 0;
      memset(text, 0, strlen(text)*sizeof(char));

      print("\n");

      continue;
    }

    // Backspace
    if(keyChar == 0x0E) {
      if(strlen(text) <= 0) {
        continue;
      }
      print("\b \b");
      if(cursor > 0) cursor--;
      text[cursor] = ' ';
      continue;
    }

    if(keyChar && (keyChar < 32 || keyChar > 126)) {
      print("\nUnknown key pressed: ");
      char c[21];
      itos(keyChar, c);
      print(c);
      print("\n");
      for(int i = 0; i < 23; i++) {
        print("\b");
      }
      memset(text, 0, strlen(text));
      cursor = 0;
      continue;
    }

    if(keyChar){
      text[cursor] = keyChar;
      print(&text[cursor]);
      cursor++;
    }
  }
}
