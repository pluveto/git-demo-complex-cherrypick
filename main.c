#include <stdio.h>
#include <string.h>
#include "check_result.h"

struct CheckResult has_any_value(const void* mem, size_t size, char value) {
  struct CheckResult result = {0, "value not found"};
  const char* p = mem;
  for (size_t i = 0; i < size; i++) {
    if (p[i] == value) {
      result.ok = 1;
      result.emsg[0] = '\0';
      break;
    }
  }
  return result;
}

int main() {
  char mem[100];
  struct CheckResult result = has_any_value(mem, sizeof(mem), 'f');
  if (!result.ok) {
    printf("NG: %s\n", result.emsg);
    return 1;
  }

  return 0;
}
