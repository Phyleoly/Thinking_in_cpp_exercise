// PStash.cpp
#include "PStash.h"
#include <iostream>
#include <cstring> 
using namespace std;

int PStash::add(void* element) {
    const int inflateSize = 10;
    if(next >= quantity)
        inflate(inflateSize);
    storage[next++] = element;
    return(next - 1); 
}

PStash::~PStash() {
    for(int i = 0; i < next; i++) {
        if(storage[i] != 0)
            cerr << "PStash not cleaned up";
    }
    delete []storage;
}

void* PStash::operator[](int index) const {
    if(index < 0)
        std::cerr <<  "PStash::operator[] index negative";
    if(index >= next)
        return 0; 
    return storage[index];
}

void* PStash::remove(int index) {
    void* v = operator[](index);
    if(v != 0) storage[index] = 0;
    return v;
}

void PStash::inflate(int increase) {
    const int psz = sizeof(void*);
    void** st = new void*[quantity + increase];
    memset(st, 0, (quantity + increase) * psz);
    memcpy(st, storage, quantity * psz);
    quantity += increase;
    delete []storage; 
    storage = st; 
}