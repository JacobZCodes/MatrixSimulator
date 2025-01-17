#include "Entry.h"
Entry::Entry(float value, tuple<int,int> position) {
    value = value;
    position = position;
}

Entry::Entry() {
    value = 0;
    position = make_tuple(0,0); 
}