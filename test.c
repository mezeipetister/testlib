#include <stdio.h>
#include "testlib.h"

void false_test() {
  TEST((1==2));
}

void true_test() {
  TEST((2==2));
}

void true_test2() {
  TEST((1==1));
}

void this_is_a_demo_test_function_very_long() {
  TEST((1==1));
}

int main() {
  false_test();
  true_test();
  true_test();
  true_test();
  true_test();
  true_test();
  true_test2();
  this_is_a_demo_test_function_very_long();
  QUICKTEST("demo_peti");
}