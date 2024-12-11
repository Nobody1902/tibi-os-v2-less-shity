#include "../BareMetal/api/libBareMetal.h"

int main() {
  b_output("Hello World!", 11);

  for(;;) {
    b_system(DELAY, 1, 1);
  }
  return 0;
}
