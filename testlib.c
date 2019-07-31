#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdlib.h>

#define COLOR_DEFAULT	"\033[0m"
#define COLOR_GREEN		"\033[0;36m"
#define COLOR_RED			"\033[0;31m"

/*
Test name
We are going to use it in the statistics*/
static char TEST_NAME[50];

/*
Test result variable.
0 false (test fail), 1 true (test pass)*/
static int TEST_RESULT = 1;

typedef struct test Test;

struct test {
  char	function_name[50];
  int		result;
  Test*	next;
};

Test* result = NULL;

/*
Set test name, max 50 char literal*/
void set_test_name(char test_name[50]) {
  strcpy(TEST_NAME,test_name);
}

static Test* create_new_test() {
  Test* new_test = malloc(sizeof(Test));
  new_test->next = NULL;
  return new_test;
}

Test* get_last_test_ptr(Test* test){
  if (test == NULL)
    return NULL;

  // Traverse the linked list 
  while (test != NULL) { 
  
    // Check if the current node  is the 
    // second last node or not 
    if (test->next == NULL) 
      return test;
  
    // If not then move to the next node 
    test = test->next; 
  } 
}

// TODO: Ugly code, clean it!
void add_test(char function_name[50], int _result) {
  // If test result is 0, then the main TEST_RESULT
  // must be 0;
  if(_result == 0)
    TEST_RESULT = 0;

  Test* new_test = create_new_test();

  // If this is the first test
  if (result == NULL) {
    result = new_test;
  } else {
    Test* last_test = get_last_test_ptr(result);
    last_test->next = new_test;
  }

  strcpy(new_test->function_name ,function_name);
  new_test->result = _result;
  new_test->next = NULL;
}

/*
Print test results
Currently there is no input param*/
void print_test_results() {
  char res_msg[30] = "PASS";
  if (TEST_RESULT == 0)
    strcpy(res_msg,COLOR_RED "FAIL" COLOR_DEFAULT);

  char welcome_msg[100] = "\n\n\
--------------------------\n\
|   Unit tests results   |\n\
--------------------------\n\
\n\n";
  
  printf("%s", welcome_msg);	/*Print test name*/
  printf("Test: %s\n", TEST_NAME);
  printf("Test: %s\n", res_msg);

  printf("Result\tName\n");
  printf("---------------------------\n");
  Test* test = result;
  while(1){
    char _res[30] = "(OK)";
    if(test->result == 0)
      strcpy(_res, COLOR_RED "(FAIL)" COLOR_DEFAULT);
    
    printf("%s\t%s\n", _res, test->function_name);

    if (test->next == NULL)
      break;
    
    test = test->next;
  }

  if (TEST_RESULT == 0)
    exit(1);

  exit(0);
}
