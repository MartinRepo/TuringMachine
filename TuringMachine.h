#ifndef UNTITLED_TURINGMACHINE_H
#define UNTITLED_TURINGMACHINE_H
#include "TuringMachineState.h"
#include <set>
#include <vector>
class TuringMachine {
public:
    virtual TuringMachineState* find(int x,int y) {return NULL;}
    virtual void add(TuringMachineState& s) {};
    virtual std::vector<TuringMachineState>* getAll() {return NULL;}
};
#endif //UNTITLED_TURINGMACHINE_H
