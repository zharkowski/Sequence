#include "array_tests_unit_5.hpp"

/*
 Модуль 5: сборный сценарий
 
 Тесты описаны в ТЗ
 */

void run_array_tests_unit_5() {
    cout<<"[ARRAY CLASS TESTING] UNIT 5 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    ArraySequence<int> seq;
    
    //TECT 1
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        if (seq.getLength() == 0) test_ok = true;
        
        test_result(test_ok);
    }
    seq.Append(23);
    
    //TECT 2
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        test_ok = true;
        
        if (seq.getLength() != 1) test_ok = false;
        if (seq.GetFirst() != 23) test_ok = false;
        if (seq.GetLast() != 23) test_ok = false;
        if (seq.Get(0) != 23) test_ok = false;
        
        test_result(test_ok);
    }
    
    //TECT 3
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(-1);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 4
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(1);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    seq.Append(43);
    
    //TECT 5
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        test_ok = true;
        
        if (seq.getLength() != 2) test_ok = false;
        if (seq.GetFirst() != 23) test_ok = false;
        if (seq.GetLast() != 43) test_ok = false;
        if (seq.Get(0) != 23) test_ok = false;
        if (seq.Get(1) != 43) test_ok = false;
        
        test_result(test_ok);
    }
    
    //TECT 6
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(-1);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 7
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(2);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    seq.Prepend(53);
    
    //TECT 8
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        test_ok = true;
        
        if (seq.getLength() != 3) test_ok = false;
        if (seq.GetFirst() != 53) test_ok = false;
        if (seq.GetLast() != 43) test_ok = false;
        if (seq.Get(0) != 53) test_ok = false;
        if (seq.Get(1) != 23) test_ok = false;
        
        test_result(test_ok);
    }
    
    //TECT 9
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(-1);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 10
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        try {
            seq.Get(3);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 11
    if (test_ok == true) {
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> subseq = seq.GetSubsequence(1, 1);
        
        if (subseq.getLength() == 1 && subseq.GetFirst() == 23 && subseq.GetLast()) test_ok = true;
        
        test_result(test_ok);
    }
    
    if (test_id == 11 && test_ok == true) {
        cout<<"\n[TESTING] Unit 5 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 5 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
