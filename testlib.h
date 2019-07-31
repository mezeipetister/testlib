#include <stdio.h>
#include <stdlib.h>

#define TEST(expr)                                                      \
  static char fname[50];                                                \
  sprintf(fname, "%s", __FUNCTION__);                                   \
  if ((expr)){                                                          \
    add_test(fname, 1);                                                 \
  } else {                                                              \
    add_test(fname, 0);                                                 \
  }

#define QUICKTEST(test_name)                    \
  set_test_name(test_name);                     \
  print_test_results();

typedef struct test* Test;

void set_test_name(char* test_name);
void print_test_results();
void add_test(char* function_name, int _result);
