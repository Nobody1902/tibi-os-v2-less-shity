#include "string.h"
#include "math.h"

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

  //Start converting the integer to string
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

// char buffer[50] is sufficent for float
void ftos(float value, char *buffer) {
    // Handle negative values
    bool is_negative = false;
    if (value < 0) {
        is_negative = true;
        value = -value; // Make value positive for processing
    }

    // Convert integer part to string
    int integer_part = (int)value;
    float fractional_part = value - integer_part;

    // Start converting the integer part
    int index = 0;
    do {
        buffer[index++] = (integer_part % 10) + '0'; // Get last digit and convert to character
        integer_part /= 10; // Remove last digit
    } while (integer_part > 0);

    // Add negative sign if necessary
    if (is_negative) {
        buffer[index++] = '-';
    }

    // Null-terminate the string after the integer part
    buffer[index] = '\0';

    // Reverse the integer part of the string
    for (int i = 0; i < index / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[index - i - 1];
        buffer[index - i - 1] = temp;
    }

    // Add decimal point if there is a fractional part
    if (fractional_part > 0) {
        buffer[index++] = '.'; // Add decimal point

        // Convert fractional part to string
        while (fractional_part > 0) {
            fractional_part *= 10;
            int frac_digit = (int)fractional_part;
            buffer[index++] = frac_digit + '0'; // Convert digit to character
            fractional_part -= frac_digit; // Remove the digit from fractional part

            // Limit the number of digits in the fractional part to avoid infinite loop
            if (index >= 50) { // Assuming buffer size is at least 50
                break;
            }
        }
    }

    // Null-terminate the final string
    buffer[index] = '\0';
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
