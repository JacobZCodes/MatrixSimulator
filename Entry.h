#ifndef ENTRY
#define ENTRY
#include <tuple>
using namespace std;
class Entry {
    public:
        Entry();
        Entry(float value, tuple<int,int> position);
        ~Entry();
        float value;
        tuple<int,int> position;

};
#endif
