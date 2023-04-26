#ifndef TURINGMACHINESTATE_H_
#define TURINGMACHINESTATE_H_
#include<string>
using namespace std;
/*
current state
current content
next state
next content
move direction
*/
class TuringMachineState{
public:
    TuringMachineState();
    TuringMachineState(int currentState, int currentContent, int nextState, int nextContent, string moveDirection);

    int getCurrentState() const;
    int getCurrentContent() const;
    int getNextState() const;
    int getNextContent() const;
    string getMoveDirection() const;
    void setCurrentState(int newCurrentState);
    void setCurrentContent(int newCurrentContent);
    void setNextState(int newNextState);
    void setNextContent(int newNextContent);
    void setMoveDirection(string newMoveDirection);

    //输出操作符重载
    friend ostream& operator<<(ostream& os, TuringMachineState& state);

    //输入操作符号重载
    friend istream& operator>>(istream& is, TuringMachineState& state);

    //小于号重载
    friend bool operator<(TuringMachineState& prev, TuringMachineState& next);

    //大于号重载
    friend bool operator>(TuringMachineState& prev, TuringMachineState& next);

    //等于号重载
    friend bool operator==(TuringMachineState& prev, TuringMachineState& next);

private:
    int currentState;
    int currentContent;
    int nextState;
    int nextContent;
    string moveDirection;
};

#endif
