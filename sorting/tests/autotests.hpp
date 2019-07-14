#ifndef autotests_hpp
#define autotests_hpp

#include <cstdlib>
#include <chrono>
#include <ctime>
#include <cmath>
#include "../../sequence/array/array.hpp"
#include "../../sequence/list/list.hpp"
#include "../../UI.hpp"
#include "../sorting.hpp"

using namespace std;


void runSortTests();
void runRandomSortTests();
void runInputSortTests();
int cin_int();


template <template<class> class T1>
T1<int> generateIntSequence(int length, int min, int max);

#include "autotests.cpp"

#endif /* autotests_hpp */
