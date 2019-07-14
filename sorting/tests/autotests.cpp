#include "autotests.hpp"

void runSortTests() {
    cout<<"\nPress\n";
    cout<<" 1. to run random tests\n";
    cout<<" 2. to run input tests\n";
    
    int menu_item;
    cin>>menu_item;
    while (menu_item != 1 && menu_item != 2){
        cout<<"Invalid command\n\n";
        cout<<"\nPress\n";
        cout<<" 1. to run random tests\n";
        cout<<" 2. to run input tests\n";
    }
    
    switch (menu_item) {
        case 1:
        {
            runRandomSortTests();
        }
            break;
            
        case 2:
        {
            runInputSortTests();
        }
            break;
            
        default:
            cout<<"Invalid command\n\n";
            break;
    }
}

void runRandomSortTests() {
    int length, min, max;
    cout<<"Enter \n";
    cout<<"length: ";
    length = cin_int();
    cout<<"minimum: ";
    min = cin_int();
    cout<<"maximum: ";
    max = cin_int();
    cout<<"\n";
    
    ArraySequence<int> genArraySeq1 = generateIntSequence<ArraySequence>(length, min, max);
    ListSequence<int> genListSeq1 = generateIntSequence<ListSequence>(length, min, max);
    
    // ТЕСТИРОВАНИЕ СОРТИРОВСКИИ СЛИЯНИЕМ
    cout<<"[ARRAY MERGE SORT TESTING]: \n";
    cout<<"Input: ";
    genArraySeq1.print();
    auto start = std::chrono::system_clock::now();
    mergeSort(genArraySeq1);
    auto finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    genArraySeq1.print();
    
    std::chrono::duration<double> elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n";
    
    cout<<"[LIST MERGE SORT TESTING]: \n";
    cout<<"Input: ";
    genListSeq1.print();
    start = std::chrono::system_clock::now();
    mergeSort(genListSeq1);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    genListSeq1.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n\n";
    
    //ТЕСТИРОВАНИИЕ СОРТИРОВКИ БИНАРНЫМИ ВСТАВКАМИ
    
    ArraySequence<int> genArraySeq2 = generateIntSequence<ArraySequence>(length, min, max);
    ListSequence<int> genListSeq2 = generateIntSequence<ListSequence>(length, min, max);
    
    cout<<"[ARRAY BINARY INSERTIONS SORT TESTING]: \n";
    cout<<"Input: ";
    genArraySeq2.print();
    start = std::chrono::system_clock::now();
    insertionSort(genArraySeq2);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    genArraySeq2.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n";
    
    cout<<"[LIST BINARY INSERTIONS SORT TESTING]: \n";
    cout<<"Input: ";
    genListSeq2.print();
    start = std::chrono::system_clock::now();
    insertionSort(genListSeq2);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    genListSeq2.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n\n";
}

void runInputSortTests() {
    string inputStr;
    int input;
    
    ArraySequence<int> inpArraySeq1;
    ListSequence<int> inpListSeq1;
    ArraySequence<int> inpArraySeq2;
    ListSequence<int> inpListSeq2;
    while (cin >> inputStr) {
        try {
            input = stoi(inputStr);
            
            inpArraySeq1.Append(input);
            inpListSeq1.Append(input);
            inpArraySeq2.Append(input);
            inpListSeq2.Append(input);
        } catch (std::invalid_argument) {
            break;
        }
    }
    
    // ТЕСТИРОВАНИЕ СОРТИРОВСКИИ СЛИЯНИЕМ
    cout<<"[ARRAY MERGE SORT TESTING]: \n";
    cout<<"Input: ";
    inpArraySeq1.print();
    auto start = std::chrono::system_clock::now();
    mergeSort(inpArraySeq1);
    auto finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    inpArraySeq1.print();
    
    std::chrono::duration<double> elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n";
    
    cout<<"[LIST MERGE SORT TESTING]: \n";
    cout<<"Input: ";
    inpListSeq1.print();
    start = std::chrono::system_clock::now();
    mergeSort(inpListSeq1);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    inpListSeq1.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n\n";
    
    //ТЕСТИРОВАНИИЕ СОРТИРОВКИ БИНАРНЫМИ ВСТАВКАМИ
    cout<<"[ARRAY BINARY INSERTIONS SORT TESTING]: \n";
    cout<<"Input: ";
    inpArraySeq2.print();
    start = std::chrono::system_clock::now();
    insertionSort(inpArraySeq2);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    inpArraySeq2.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n";
    
    cout<<"[LIST BINARY INSERTIONS SORT TESTING]: \n";
    cout<<"Input: ";
    inpListSeq2.print();
    start = std::chrono::system_clock::now();
    insertionSort(inpListSeq2);
    finish = std::chrono::system_clock::now();
    
    cout<<"\nOutput: ";
    inpListSeq2.print();
    
    elapsed_seconds = finish - start;
    
    cout<<"Elapsed time: " << elapsed_seconds.count() << "s\n\n\n";
}

template <template<class> class T1>
T1<int> generateIntSequence(int length, int min, int max) {
    T1<int> seq;
    
    srand (time(NULL));
    for (int i = 0; i < length; i++) {
        int randomNumber = rand() % (max-min+1) + min;
        seq.Append(randomNumber);
    }
    
    return seq;
}


int cin_int() {
    int N;
    while (true) {
        cout<<flush;    //очистка потока
        if ((cin >> N).good()) return N;
        if (cin.fail()) {
            cin.clear();    //очищает флаг ошибки, но часть введенной строки при этом остается
            cout << "Invalid input.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    //пропустить все символы в потоке до \n, после этого можно начинать считывать новое значение
    }
}
