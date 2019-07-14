#include "tests.hpp"
#include <iostream>

#include "array_tests_units/array_tests_unit_1.hpp"
#include "array_tests_units/array_tests_unit_2.hpp"
#include "array_tests_units/array_tests_unit_3.hpp"
#include "array_tests_units/array_tests_unit_4.hpp"
#include "array_tests_units/array_tests_unit_5.hpp"

#include "list_tests_units/list_tests_unit_1.hpp"
#include "list_tests_units/list_tests_unit_2.hpp"
#include "list_tests_units/list_tests_unit_3.hpp"
#include "list_tests_units/list_tests_unit_4.hpp"
#include "list_tests_units/list_tests_unit_5.hpp"

void test_prepare(int *test_id, bool *test_ok){
    (*test_ok) = false;
    (*test_id)++;
    
    cout<<"[TESTING] Test #"<<*test_id<<": ";
}

void test_result(bool test_ok){
    if (test_ok == true){
        cout<<"OK.\n";
    } else {
        cout<<"ERROR.\n";
    }
}

void run_all_sequence_tests(){
    run_array_tests();
    run_list_tests();
}

void run_array_tests() {
    run_array_tests_unit_1();
    run_array_tests_unit_2();
    run_array_tests_unit_3();
    run_array_tests_unit_4();
    run_array_tests_unit_5();
}

void run_list_tests(){
    run_list_tests_unit_1();
    run_list_tests_unit_2();
    run_list_tests_unit_3();
    run_list_tests_unit_4();
    run_list_tests_unit_5();
}
