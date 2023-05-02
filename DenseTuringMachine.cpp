#include "DenseTuringMachine.h"
#include<vector>
#include<iostream>
DenseTuringMachine::DenseTuringMachine(int x, int y){
    if(x==-1 || y==-1){
        // tape is infinite
        isMinusOne=true;
        turingMachineStates.resize(1, std::vector<TuringMachineState>(1, TuringMachineState(-1, -1, -1, -1, "")));
        for(int i = 0; i<1; i++){
            for(int j = 0; j<1; j++){
                turingMachineStates[i][j] = TuringMachineState(i,j,-1,-1, " ");
            }
        }
    } else if(x>0 && y>0){
        turingMachineStates.resize(x + 1, std::vector<TuringMachineState>(y + 1, TuringMachineState(-1, -1, -1, -1, "")));
        for(int i = 0; i<=x; i++){
            for(int j = 0; j<=y; j++){
                turingMachineStates[i][j] = TuringMachineState(i,j,-1,-1, " ");
            }
        }
    } else {
        std::cout<<"Fail to create turing machine, please try again."<<std::endl;
    }
}

TuringMachineState* DenseTuringMachine::find(int x, int y) {
        if (x >= 0 && x <= turingMachineStates.size() && y >= 0 && y <= turingMachineStates[0].size()) {
            if(turingMachineStates[x][y].getMoveDirection()!=" "){
                return &turingMachineStates[x][y];
            }
        }
        return NULL;
}

void DenseTuringMachine::add(TuringMachineState &s) {
    if(isMinusOne){
        int row = (int)turingMachineStates.size();
        int column = (int)turingMachineStates[0].size();
        if(s.getCurrentState()>=row-1){
            turingMachineStates.resize(s.getCurrentState() + 1, std::vector<TuringMachineState>(column + 1, TuringMachineState(-1, -1, -1, -1, "")));
            for(int i = row; i<=s.getCurrentState(); i++){
                for(int j = 0; j<=column; j++){
                    turingMachineStates[i][j] = TuringMachineState(i,j,-1,-1, " ");
                }
            }
        }
        if(s.getCurrentContent()>=column-1){
            int rowNumber=0;
            for(auto& rows : turingMachineStates){
                rows.resize(s.getCurrentContent()+1, TuringMachineState(-1, -1, -1, -1, ""));
                for(int j = column; j<=s.getCurrentContent(); j++){
                    rows[j] = TuringMachineState(rowNumber,j,-1,-1, " ");
                }
                rowNumber++;
            }
        }
        turingMachineStates[s.getCurrentState()][s.getCurrentContent()]=s;
    } else {
        if (s.getCurrentState() >= 0 && s.getCurrentState() <= turingMachineStates.size() && s.getCurrentContent() >= 0 && s.getCurrentContent() <= turingMachineStates[0].size() && s.getNextState() <= turingMachineStates.size() && s.getNextContent() <= turingMachineStates[0].size()) {
            turingMachineStates[s.getCurrentState()][s.getCurrentContent()] = s;
        } else {
            cout<<"Failed to add, out of turing machine boundary"<<endl;
        }
    }
}

std::vector<TuringMachineState> *DenseTuringMachine::getAll() {
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