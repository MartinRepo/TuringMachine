#include "SparseTuringMachine.h"
#include "TuringMachineState.h"
#include<iostream>

TuringMachineState *SparseTuringMachine::find(int x, int y) {
    for(int i = 0; i<trackIndex; i++){
        // make it O(zlogz), like space exchange time.
        temp = &sparseTM[i];
        if(temp->getCurrentState()==x && temp->getCurrentContent()==y){
            return temp;
        }
    }
    return NULL;
}

void SparseTuringMachine::add(TuringMachineState &s) {
    // insert is O(zlogz)
    sparseTM.insert(pair<int, TuringMachineState>(trackIndex, s));
    trackIndex+=1;
}

std::vector<TuringMachineState> *SparseTuringMachine::getAll() {
    finalSparseTM.resize(trackIndex, TuringMachineState(-1,-1,-1,-1,""));
    for(int i = 0; i<trackIndex; i++){
        // vector access element is O(1), map access element is O(logz)
        finalSparseTM[i] = sparseTM[i];
    }
    return &finalSparseTM;
}