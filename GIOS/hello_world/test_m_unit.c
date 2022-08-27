// #include "munit/munit.c"
#include "munit.h"

void your_function(int foo, int bar) { munit_assert_int(foo, ==, bar); }
int main(void) {
  /* Use µnit here. */
  your_function(1, 2);
  return EXIT_SUCCESS;
}
