#include "array_tests_unit_4.hpp"

/*
 Модуль 3: Тестирование получение подпоследовательности
 
 Тест 1: попытка получения подпоследовательности из пустого списка
 Тест 2: попытка получения подпоследовательности с некорректнымии индексами (начальный больше конечного)
 Тест 3: попытка получения подпоследовательности с некорректнымии индексами (выход индексов за границы)
 Тест 4: получение полной подпоследовательности из списка
 Тест 5: получение частичной подпоследовательности из списка

 */

void run_array_tests_unit_4() {
    cout<<"[ARRAY CLASS TESTING] UNIT 4 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        
        try {
            seq.GetSubsequence(0, 0);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        seq.Append(5);
        seq.Append(6);
        
        try {
            seq.GetSubsequence(4, 1);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        seq.Append(5);
        seq.Append(6);
        
        try {
            seq.GetSubsequence(17, 20);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        
        ArraySequence<int> subseq = seq.GetSubsequence(0, 2);
        if ((subseq.getLength() == 3) && (subseq.Get(0) == 1) &&(subseq.Get(1) == 2) &&(subseq.Get(2) == 3)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        seq.Append(5);
        seq.Append(6);
        
        ArraySequence<int> subseq = seq.GetSubsequence(2, 4);
        if ((subseq.getLength() == 3) && (subseq.Get(0) == 3) &&(subseq.Get(1) == 4) &&(subseq.Get(2) == 5)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 5 && test_ok == true) {
        cout<<"\n[TESTING] Unit 4 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 4 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
