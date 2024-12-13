#include "../BareMetal/api/libBareMetal.h"

void _start(void) {
  for(;;) {
    b_output("Hello World!", 11);
  }
}
