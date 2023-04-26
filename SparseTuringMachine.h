#ifndef SPARSETURINGMACHINE_H_
#define SPARSETURINGMACHINE_H_
#include "TuringMachine.h"
//#include <vector>
#include<map>
class SparseTuringMachine : public TuringMachine {
public:
    TuringMachineState* find(int x,int y);
    void add(TuringMachineState& s);
    std::vector<TuringMachineState>* getAll();

private:
    vector<TuringMachineState> finalSparseTM;
    map<int, TuringMachineState> sparseTM;
    int trackIndex = 0;
};
#endif /* SPARSETURINGMACHINE_H_ */
