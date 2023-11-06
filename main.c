#include <check_result.h>
#include <stdio.h>
#include <string.h>

struct CheckResult is_all_value(const void* mem, size_t size, char value) {
  struct CheckResult result = {1, ""};
  const char* p = mem;
  for (size_t i = 0; i < size; i++) {
    if (p[i] != value) {
      result.ok = 0;
      snprintf(result.emsg, sizeof(result.emsg), "mem[%zu] = %d", i, p[i]);
      break;
    }
  }
  return result;
}

int main() {
  char mem[100];
  struct CheckResult result = is_all_value(mem, sizeof(mem), 0);
  if (!result.ok) {
    printf("NG: %s\n", result.emsg);
    return 1;
  }

  memset(mem, 1, sizeof(mem));
  result = is_all_value(mem, sizeof(mem), 1);
  if (!result.ok) {
    printf("NG: %s\n", result.emsg);
    return 1;
  }
  return 0;
}
