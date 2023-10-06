#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern char *replace_char(char *input_string);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // Create a c string from fuzzer data (with an additional byte set to '\0')
  char *str = (char *)malloc(sizeof(char) * size + 1); // Create a c-string of length size + 1
  memcpy(str, data, size);                             // Copy fuzzer data to string
  str[size] = '\0';                                    // Set last byte of allocated string to '\0'

  char *result = replace_char(str);

  /* added after fuzzing to prevent memory leak */
  if (result) {
    free(result);
  }

  free(str);

  return 0;
}