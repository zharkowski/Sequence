#include "array_tests_unit_2.hpp"

/*
 Модуль 2: Тестирование добавления элементов в последовательность
 
 Тест 1: добавлениие одного элемента в конец последевательности
 Тест 2: добавлениие одного элемента в начало последевательности
 Тест 3: добавлениие одного элемента по индексу в последлвательность
 */

void run_array_tests_unit_2() {
    cout<<"[ARRAY CLASS TESTING] UNIT 2 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TECT 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(5);
        if (seq.getLength() == 1 && seq.Get(0) == 5) test_ok = true;
        
        test_result(test_ok);
    }
    
    //TECT 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Prepend(4);
        if (seq.getLength() == 1 && seq.Get(0) == 4) test_ok = true;
        
        test_result(test_ok);
    }
    
    //TECT 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        ArraySequence<int> seq;
        seq.Append(5);
        seq.Append(4);
        seq.Append(3);

        seq.InsertAt(1, 6);
        if (seq.getLength() == 4 && seq.Get(0) == 5 && seq.Get(1) == 6 && seq.Get(2) == 4 && seq.Get(3) == 3) test_ok = true;
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 2 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 2 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
