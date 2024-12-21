#include "../BareMetal/api/libBareMetal.h"
#include "print.h"
#include "string.h"

void print(const char* text) {
  size_t len = strlen(text);

  for(int i = 0; i < len; i++) {
    if(print_char(text[i])) {
      for(int j = 0; j < i; j++) {
        print_char('\b');
      }
    }
  }
}

int print_char(char c) {
  b_output(&c, 1);
  return c == '\n';
}

void clear_screen(void) {
  for(int i = 0; i < 16; i++) {
    b_output("\n\n\n\n\n", 5);
  }
}
