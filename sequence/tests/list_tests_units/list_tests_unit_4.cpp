#include "list_tests_unit_4.hpp"

/*
 Модуль 3: Тестирование получение подпоследовательности
 
 Тест 1: попытка получения подпоследовательности с некорректнымии индексами (начальный больше конечного)
 Тест 2: попытка получения подпоследовательности с некорректнымии индексами (выход индексов за границы)
 Тест 3: получение полной подпоследовательности из списка
 Тест 4: получение частичной подпоследовательности из списка
 
 */

void run_list_tests_unit_4() {
    cout<<"[LIST CLASS TESTING] UNIT 4 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ListSequence<int> seq;
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
    
    //TECT 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ListSequence<int> seq;
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
    
    //TECT 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ListSequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        
        ListSequence<int> subseq = seq.GetSubsequence(0, 2);
        if ((subseq.getLength() == 3) && (subseq.Get(0) == 1) &&(subseq.Get(1) == 2) &&(subseq.Get(2) == 3)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ListSequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        seq.Append(5);
        seq.Append(6);
        
        ListSequence<int> subseq = seq.GetSubsequence(2, 4);
        if ((subseq.getLength() == 3) && (subseq.Get(0) == 3) &&(subseq.Get(1) == 4) &&(subseq.Get(2) == 5)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 4 && test_ok == true) {
        cout<<"\n[TESTING] Unit 4 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 4 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
