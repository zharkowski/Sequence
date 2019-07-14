#include "UI.hpp"

void run_UI() {
    int menu_item = 0;
    while (menu_item != 5){
        cout<<"\nPress\n";
        cout<<" 1. to run array tests\n";
        cout<<" 2. to run list tests\n";
        cout<<" 3. to run array and list tests\n";
        cout<<" 4. to run sorting autotests\n";
        cout<<" 5. to exit\n";
        menu_item = cin_int();
        switch (menu_item) {
            case 1:
            {
                run_array_tests();
            }
                break;
                
            case 2:
            {
                run_list_tests();
            }
                break;
                
            case 3:
            {
                run_all_sequence_tests();
            }
                break;
                
            case 4:
            {
                runSortTests();
            }
                break;
                
            case 5:
                break;
                
            default:
                cout<<"Invalid command\n\n";
                break;
        }
    }
}
