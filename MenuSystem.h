#include "DenseTuringMachine.h"
#include "TuringTape.h"
#include "TuringMachineState.h"
#include "SparseTuringMachine.h"
#ifndef MENUSYSTEM_H_
#define MENUSYSTEM_H_
class MenuSystem {
public:
    void menu();
private:
    int tapeLength;
    int maxState=-2, maxContent=-2;
    int currentState = 0;
    int stateLocation = 0;
    int currentStep = 0;
    int maxPosition = 0;
    DenseTuringMachine* denseTM = nullptr;
    SparseTuringMachine* sparseTM = nullptr;
    void case1();
    void case2();
    void case3();
    void case4();
    void case5(TuringTape* tape);
    void findNextState(TuringTape* tape, vector<TuringMachineState>* vec);
    void case6(TuringTape* tape);
};
#endif /* MENUSYSTEM_H_ */
