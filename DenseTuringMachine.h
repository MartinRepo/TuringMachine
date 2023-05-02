#ifndef DENSETURINGMACHINE_H_
#define DENSETURINGMACHINE_H_
#include "TuringMachine.h"
#include "TuringMachineState.h"
#include <vector>
#include <map>
class DenseTuringMachine : public TuringMachine {
public:
    DenseTuringMachine(int x, int y);
    TuringMachineState* find(int x,int y);
    void add(TuringMachineState& s);
    std::vector<TuringMachineState>* getAll();
private:
    vector<vector<TuringMachineState>> turingMachineStates;
    vector<TuringMachineState> allTuringMachineStates;
    bool isMinusOne = false;
};
#endif /* DENSETURINGMACHINE_H_ */