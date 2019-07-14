#ifndef tests_hpp
#define tests_hpp

#include <stdio.h>

using namespace std;

void run_all_sequence_tests();
void run_array_tests();
void run_list_tests();

void test_prepare(int *test_id, bool *test_ok);
void test_result(bool test_ok);

#endif /* tests_hpp */
