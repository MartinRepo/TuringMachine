#include "SparseTuringMachine.h"
#include "TuringMachineState.h"
#include<iostream>

TuringMachineState *SparseTuringMachine::find(int x, int y) {
    for(int i = 0; i<trackIndex; i++){
        if(sparseTM[i].getCurrentState()==x && sparseTM[i].getCurrentContent()==y){
            return &sparseTM[i];
        }
    }
    return NULL;
}

void SparseTuringMachine::add(TuringMachineState &s) {
    sparseTM.insert(pair<int, TuringMachineState>(trackIndex, s));
    trackIndex+=1;
}

std::vector<TuringMachineState> *SparseTuringMachine::getAll() {
    finalSparseTM.resize(trackIndex, TuringMachineState(-1,-1,-1,-1,""));
    for(int i = 0; i<trackIndex; i++){
        finalSparseTM[i] = sparseTM[i];
    }
    return &finalSparseTM;
}