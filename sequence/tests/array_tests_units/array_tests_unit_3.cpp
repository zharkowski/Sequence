#include "array_tests_unit_3.hpp"

/*
 Модуль 3: Тестирование удаление элементов из последовательность
 
 Тест 1: попытка удалениия элемента из пустого списка
 Тест 2: попытка удаления элемента, которого нет, из последовательности
 Тест 3: удаление первого элемента последовательности
 Тест 4: удаление последнего элемента последовательности
 Тест 5: удаление среднего элемента последовательности
 Тест 6: удаление единственного элемента в последовательности
 Тест 7: удаление элемента последовательности по несуществующему индексу
 Тест 8: удаленииие первого элемента последовательности по индексу
 Тест 9: удаленииие последнего элемента последовательности по индексу
 Тест 10: удаленииие среднего элемента последовательности по индексу
 */

void run_array_tests_unit_3() {
    cout<<"[ARRAY CLASS TESTING] UNIT 3 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Remove(123);
        
        if (seq.getIsEmpty() == 1) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(1);
        seq.Append(1);
        seq.Append(1);
        seq.Remove(123);
        
        if (seq.getLength() == 4) {
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
        
        seq.Remove(1);

        if ((seq.getLength() == 3) && (seq.Get(0) == 2) && (seq.Get(1) == 3) && (seq.Get(2) == 4)) {
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
        
        seq.Remove(4);

        if ((seq.getLength() == 3) && (seq.Get(0) == 1) && (seq.Get(1) == 2) && (seq.Get(2) == 3)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 5
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);

        seq.Remove(3);
        
        if ((seq.getLength() == 3) && (seq.Get(0) == 1) && (seq.Get(1) == 2) && (seq.Get(2) == 4)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 6
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        
        seq.Remove(1);
        
        if (seq.getIsEmpty()) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 7
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        
        try {
            seq.RemoveByIndex(10);
        } catch (std::out_of_range exep) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 8
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        
        seq.RemoveByIndex(0);
        
        if ((seq.getLength() == 3) && (seq.Get(0) == 2) && (seq.Get(1) == 3) && (seq.Get(2) == 4)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 9
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        
        seq.RemoveByIndex(3);
        
        if ((seq.getLength() == 3) && (seq.Get(0) == 1) && (seq.Get(1) == 2) && (seq.Get(2) == 3)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    //TECT 10
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Append(2);
        seq.Append(3);
        seq.Append(4);
        
        seq.RemoveByIndex(2);
        
        if ((seq.getLength() == 3) && (seq.Get(0) == 1) && (seq.Get(1) == 2) && (seq.Get(2) == 4)) {
            test_ok = true;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 10 && test_ok == true) {
        cout<<"\n[TESTING] Unit 3 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 3 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
