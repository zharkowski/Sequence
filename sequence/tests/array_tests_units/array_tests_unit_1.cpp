#include "array_tests_unit_1.hpp"

/*
 Модуль 1: Тестирование создания списка
 
 Тест 1: создание списка
 */

void run_array_tests_unit_1() {
    cout<<"[ARRAY CLASS TESTING] UNIT 1 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        
        if (seq.getLength() == 0) {
            try {
                seq.Get(0);
            } catch (std::out_of_range exep) {
                test_ok = true;
            }
            
        }
        else test_ok = false;
        
        test_result(test_ok);
    }
    
    if (test_id == 1 && test_ok == true) {
        cout<<"\n[TESTING] Unit 1 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 1 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
