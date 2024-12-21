#include "string.h"

int strcmp(const char* s1, const char* s2) {
  while(*s1 && *s2 && (*s1 == *s2)) {
      s1++;
      s2++;
  }
  return *(const unsigned char*)s1 - *(const unsigned char*)s2 == 0;
}

size_t strlen(const char *str) {
  const char *s;

  for (s = str; *s; ++s);
  return (s - str);
}
// char buffer[21] is sufficent for i64
void itos(i64 value, char *buffer) {
  // Handle negative values
  bool is_negative = false;
  if (value < 0) {
    is_negative = true;
    value = -value; // Make value positive for processing
  }

  // Start converting the integer to string
  int index = 0;
  do {
    buffer[index++] = (value % 10) + '0'; // Get last digit and convert to character
    value /= 10; // Remove last digit
  } while (value > 0);

  // Add negative sign if necessary
  if (is_negative) {
    buffer[index++] = '-';
  }

  // Null-terminate the string
  buffer[index] = '\0';

  // Reverse the string since digits are in reverse order
  for (int i = 0; i < index / 2; i++) {
    char temp = buffer[i];
    buffer[i] = buffer[index - i - 1];
    buffer[index - i - 1] = temp;
  }
}

u64 hex2u64(char* str){
  u64 out = 0;
  for(int i = 0; i < strlen(str); i++){
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
