#include "DenseTuringMachine.h"
#include<vector>
#include<iostream>
DenseTuringMachine::DenseTuringMachine(int x, int y){
    if(x==-1 || y==-1){
        // tape is infinite
        isMinusOne=true;
    } else {
        turingMachineStates.resize(x + 1, std::vector<TuringMachineState>(y + 1, TuringMachineState(-1, -1, -1, -1, "")));
        for(int i = 0; i<=x; i++){
            for(int j = 0; j<=y; j++){
                turingMachineStates[i][j] = TuringMachineState(i,j,0,0, " ");
            }
        }
    }
}

TuringMachineState* DenseTuringMachine::find(int x, int y) {
    if(isMinusOne){
        for(int i = 0; i<trackInfiniteIndex; i++){
            if(infiniteTuringMachineStates[i].getCurrentState()==x && infiniteTuringMachineStates[i].getCurrentContent()==y){
                return &infiniteTuringMachineStates[i];
            }
        }
        return NULL;
    } else {
        if (x >= 0 && x <= turingMachineStates.size() && y >= 0 && y <= turingMachineStates[0].size()) {
            if(turingMachineStates[x][y].getMoveDirection()!=" "){
                return &turingMachineStates[x][y];
            }
        }
        return NULL;
    }
}

void DenseTuringMachine::add(TuringMachineState &s) {
    if(isMinusOne){
        infiniteTuringMachineStates.push_back(s);
        trackInfiniteIndex+=1;
    } else {
        if (s.getCurrentState() >= 0 && s.getCurrentState() <= turingMachineStates.size() && s.getCurrentContent() >= 0 && s.getCurrentContent() <= turingMachineStates[0].size()) {
            turingMachineStates[s.getCurrentState()][s.getCurrentContent()] = s;
        }
    }
}

std::vector<TuringMachineState> *DenseTuringMachine::getAll() {
    if(isMinusOne){
          return &infiniteTuringMachineStates;
    } else {
        int z = 0;
        int rows = (int)turingMachineStates.size();
        int columns = (int)turingMachineStates[0].size();
        allTuringMachineStates.resize(rows*columns, TuringMachineState(-1, -1, -1, -1, ""));
        //move turingmachinestates into vector allTuringMachineStates.
        for (auto& row : turingMachineStates) {
            for (auto& state : row) {
                if (state.getMoveDirection()!=" ") {
                    allTuringMachineStates[z] = state;
                    z++;
                }
            }
        }
        // delete data which is empty
        for(int i = rows*columns; i>=0; i--){
            if(allTuringMachineStates[i].getCurrentState()==-1){
                allTuringMachineStates.pop_back();
            }
        }
        return &allTuringMachineStates;
        // time complexity: xy+xy-h = 2xy-h = O(xy), which h is the number of existed turingmachinestates.
    }
}