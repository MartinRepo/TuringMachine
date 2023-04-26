#include <iostream>
#include "TuringMachineState.h"
using namespace std;
TuringMachineState::TuringMachineState() {
    setCurrentState(-1);
    setCurrentContent(-1);
    setNextState(-1);
    setNextContent(-1);
    setMoveDirection("");
}

TuringMachineState::TuringMachineState(int currentState, int currentContent, int nextState, int nextContent, string moveDirection) {
    setCurrentState(currentState);
    setCurrentContent(currentContent);
    setNextState(nextState);
    setNextContent(nextContent);
    setMoveDirection(moveDirection);
}

ostream& operator<<(ostream& os, TuringMachineState& state){
    os << state.getCurrentState() << " " << state.getCurrentContent() << " "
       << state.getNextState() << " " << state.getNextContent() << " " << state.getMoveDirection();
    return os;
}

istream& operator>>(istream& is, TuringMachineState& state){
    int current_state, current_content, next_state, next_content;
    string move_direction;
    is >> current_state >> current_content >> next_state >> next_content >> move_direction;
    state.setCurrentState(current_state);
    state.setCurrentContent(current_content);
    state.setNextState(next_state);
    state.setNextContent(next_content);
    state.setMoveDirection(move_direction);
    return is;
}

bool operator<(TuringMachineState& prev, TuringMachineState& next){
    if(prev.getCurrentState()<next.getCurrentState()){
        return true;
    }else if(prev.getCurrentState()==next.getCurrentState()){
        if(prev.getCurrentContent()<next.getCurrentContent()){
            return true;
        }
    }
    return false;
}

bool operator>(TuringMachineState& prev, TuringMachineState& next){
    if(prev.getCurrentState()>next.getCurrentState()){
        return true;
    }else if(prev.getCurrentState()==next.getCurrentState()){
        if(prev.getCurrentContent()>next.getCurrentContent()){
            return true;
        }
    }
    return false;
}

bool operator==(TuringMachineState& prev, TuringMachineState& next){
    if(prev.getCurrentState()==next.getCurrentState() && prev.getCurrentContent()==next.getCurrentContent()){
        return true;
    }
    return false;
}

int TuringMachineState::getCurrentState() const {
    return currentState;
}
int TuringMachineState::getCurrentContent() const {
    return currentContent;
}
int TuringMachineState::getNextState() const {
    return nextState;
}
int TuringMachineState::getNextContent() const {
    return nextContent;
}
string TuringMachineState::getMoveDirection() const {
    return moveDirection;
}
void TuringMachineState::setCurrentState(int newCurrentState) {
    currentState=newCurrentState;
}
void TuringMachineState::setCurrentContent(int newCurrentContent) {
    currentContent=newCurrentContent;
}
void TuringMachineState::setNextState(int newNextState) {
    nextState=newNextState;
}
void TuringMachineState::setNextContent(int newNextContent) {
    nextContent=newNextContent;
}
void TuringMachineState::setMoveDirection(string newMoveDirection) {
    moveDirection=newMoveDirection;
}

