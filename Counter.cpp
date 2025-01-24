#include "Counter.h"  // Include the header file
#include <iostream>
using namespace std;
// Define and initialize the static variables outside the class
int Counter::addSubCounter = 0;   // Initialize addSubCounter
int Counter::multDivCounter = 0;  // Initialize multDivCounter

void Counter::DisplayCounters() {
    cout << "add/sub " << Counter::addSubCounter << endl;
    cout << "mult/div " << Counter::multDivCounter << endl;
}