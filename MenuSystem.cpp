#include "MenuSystem.h"
#include<iostream>
#include<algorithm>
#include<limits>
#include <sstream>

void MenuSystem::case1() {
    std::cout<<"What is the maximum state and what is the maximum content?"<<endl;
    int inputState;
    int inputContent;
    while(true){
        cin>>inputState>>inputContent;
        if(inputState!=0 && inputContent!=0){
            maxState = inputState;
            maxContent = inputContent;
            break;
        } else {
            cout<<"Invalid input, try again"<<endl;
        }
    }
    // denseTM指针指向新创建的DenseTuringMachine
    denseTM = new DenseTuringMachine(maxState, maxContent);
}

void MenuSystem::case2() {
    sparseTM = new SparseTuringMachine();
}

void MenuSystem::case3() {
    std::cout<<"What state do you wish to add?"<<endl;
    TuringMachineState TMState;
    while(true){
        std::cin>>TMState;
        if(TMState.getCurrentState()>=0 && TMState.getCurrentContent()>=0 && TMState.getNextState()>=0 && TMState.getNextContent()>=0){
            if(TMState.getMoveDirection()=="->" || TMState.getMoveDirection()=="<-"){
                break;
            } else {
                std::cout<<"Invalid input, try again"<<endl;
            }
        } else {
            std::cout<<"Invalid input, try again"<<endl;
        }
    }

    if(TMState.getCurrentState()>maxState && maxState!=-1){
        sparseTM->add(TMState);
    } else {
        denseTM->add(TMState);
    }

}

void MenuSystem::case4() {
    // 获取所有的 TuringMachineStates
    std::vector<TuringMachineState>* vecTMStates;
    if(sparseTM != nullptr){
        vecTMStates = sparseTM->getAll();
    } else {
        vecTMStates = denseTM->getAll();
    }

    // Collect all unique states and contents, separately.
    std::set<int> uniqueStates, uniqueContents;
    for (auto& state : *vecTMStates) {
        uniqueStates.insert(state.getCurrentState());
        uniqueStates.insert(state.getNextState());
        uniqueContents.insert(state.getCurrentContent());
        uniqueContents.insert(state.getNextContent());
    }

    // define a mapping rule for unique states and contents.
    std::map<int, int> stateMapping, contentMapping;
    int stateIndex = 0;
    for (int state : uniqueStates) {
        stateMapping[state] = stateIndex++;
    }
    int contentIndex = 0;
    for (int content : uniqueContents) {
        contentMapping[content] = contentIndex++;
    }

    // rename states using the mapping rule.
    for (auto& state : *vecTMStates) {
        state.setCurrentState(stateMapping[state.getCurrentState()]);
        state.setCurrentContent(contentMapping[state.getCurrentContent()]);
        state.setNextState(stateMapping[state.getNextState()]);
        state.setNextContent(contentMapping[state.getNextContent()]);
    }

    // declare a new dense turing machine using rename states.
    auto* newDenseTM = new DenseTuringMachine(stateIndex, contentIndex);
    for (auto& state : *vecTMStates) {
        newDenseTM->add(state);
    }
    denseTM = newDenseTM;
}

void MenuSystem::findNextState(TuringTape* tape, vector<TuringMachineState>* vec){
    //寻找下一个状态所在位置
    int findState = (*vec)[stateLocation].getNextState();
    int findContent = tape->getContent();
    auto it = std::find_if((*vec).begin(), (*vec).end(), [findState, findContent](const TuringMachineState& FindTMState){
        return FindTMState.getCurrentState() == findState && FindTMState.getCurrentContent() == findContent;
    });
    if(it!=(*vec).end()){
        //找到了，更新location
        stateLocation = std::distance((*vec).begin(), it);
        if(tape->getPosition() > maxPosition){
            maxPosition = tape->getPosition();
        }
    } else {
        //没找到，error
        tape->setPosition(-1);
    }
}

void MenuSystem::case5(TuringTape* tape) {
    int steps;
    std::cout<<"How many steps do you wish to execute? \n";
    std::cin>>steps;

    while(steps==0){
        cout<<"Invalid input, try it again."<<endl;
        std::cin>>steps;
    }

    vector<TuringMachineState> vec;
    if(denseTM != nullptr){
        vec = *denseTM->getAll();
        while (steps == -1 || steps-- > 0 || steps==1 ) {
            currentStep+=1;
            if(denseTM->find(vec[stateLocation].getCurrentState(), vec[stateLocation].getCurrentContent()) != NULL && tape->getPosition()>-1){
                //Ensure the direction of tape moving
                if(vec[stateLocation].getMoveDirection()=="->"){
                    tape->moveRight();
                    if(denseTM->find(vec[stateLocation].getNextState(), tape->getContent()) != NULL){
                        tape->moveLeft();
                        tape->setContent(vec[stateLocation].getNextContent());
                        tape->moveRight();
                        findNextState(tape, &vec);
                    } else {
                        tape->setPosition(-1);
                    }

                } else if(vec[stateLocation].getMoveDirection()=="<-"){
                    tape->moveLeft();
                    if(denseTM->find(vec[stateLocation].getNextState(), tape->getContent()) != NULL){
                        //change the content of tape's current position
                        tape->moveRight();
                        tape->setContent(vec[stateLocation].getNextContent());
                        tape->moveLeft();
                        findNextState(tape, &vec);
                    } else {
                        tape->setPosition(-1);
                    }
                }
            } else {
                std::cout<<"In step "<< currentStep <<", the position is "<< tape->getPosition() <<", but that is outside the tape."<<endl;
                break;
            }
            currentState = vec[stateLocation].getCurrentState();
        }
    } else {
        vec = *sparseTM->getAll();
        while (steps == -1 || steps-- > 0 || steps==1) {
            currentStep+=1;
            if(sparseTM->find(vec[stateLocation].getCurrentState(), vec[stateLocation].getCurrentContent()) != NULL && tape->getPosition()>-1){
                //先确定纸带移动方向
                if(vec[stateLocation].getMoveDirection()=="->"){
                    tape->moveRight();
                    if(sparseTM->find(vec[stateLocation].getNextState(), tape->getContent()) != NULL){
                        tape->moveLeft();
                        tape->setContent(vec[stateLocation].getNextContent());
                        tape->moveRight();
                        findNextState(tape, &vec);
                    } else {
                        tape->setPosition(-1);
                    }

                } else if(vec[stateLocation].getMoveDirection()=="<-"){
                    tape->moveLeft();
                    if(sparseTM->find(vec[stateLocation].getNextState(), tape->getContent()) != NULL){
                        //改变当前格子内容
                        tape->moveRight();
                        tape->setContent(vec[stateLocation].getNextContent());
                        tape->moveLeft();
                        findNextState(tape, &vec);
                    } else {
                        tape->setPosition(-1);
                    }
                }
            } else {
                std::cout<<"In step "<< currentStep <<", the position is "<< tape->getPosition() <<", but that is outside the tape."<<endl;
                break;
            }
            currentState = vec[stateLocation].getCurrentState();
        }
    }
}

void MenuSystem::case6(TuringTape* tape) {
    vector<TuringMachineState> vec;

    if(denseTM!= nullptr){
        vec=*denseTM->getAll();
    } else {
        vec=*sparseTM->getAll();
    }
    int tapePointer = tape->getPosition();
    std::cout<<"The current state is "<<currentState<<"."<<endl;
    std::cout<<"The current position is "<<tape->getPosition()<<"."<<endl;
    std::cout<<"The content of the tape is ";
    for(int i = 0; i<=maxPosition; i++) {
        tape->setPosition(i);
        cout<<tape->getContent();
    }
    tape->setPosition(tapePointer);
    std::cout<<"."<<endl;
    std::cout<<"The Turing machine has states: ";
    for (auto s: vec) cout << "<" << s << ">";
    std::cout<<endl;
}

void MenuSystem::menu() {
    std::cout<<"How long should the tape be?"<<std::endl;
    TuringTape* tape;
    while(true){
        std::cin >> tapeLength;
        if(tapeLength==0){
            cout<<"Invalid input, try it again"<<endl;
        } else {
            tape = new TuringTape(tapeLength);
            break;
        }
    }

    bool exit = false;
    bool flag = true;
    while(!exit){
        if(flag){
            std::cout << "1. Create dense Turing machine" << std::endl;
            std::cout << "2. Create sparse Turing machine" << std::endl;
            std::cout << "3. Add state to Turing machine" << std::endl;
            std::cout << "4. Compact Turing machine" << std::endl;
            std::cout << "5. Execute Turing machine" << std::endl;
            std::cout << "6. Output current information" << std::endl;
            std::cout << "Write q or Q to quit" << std::endl;
            std::cout << "Enter Option "<<std::endl;
        } else {
            std::cout << "Enter Option "<<std::endl;
        }
        flag=true;

        std::string input;
        std::cin >> input;
        if (input == "q" || input == "Q") {
            exit = true;
        } else if (input=="1" || input=="2" || input=="3" || input=="4" || input=="5" || input=="6"){
            int option = std::stoi(input);
            switch(option){
                case 1:
                    // Create dense Turing machine
                    case1();
                    break;
                case 2:
                    // Create sparse Turing machine
                    case2();
                    break;
                case 3:
                    // Add state to Turing machine
                    case3();
                    break;
                case 4:
                    // Compact Turing machine
                    case4();
                    break;
                case 5:
                    // Execute Turing machine
                    case5(tape);
                    break;
                case 6:
                    // Output current information
                    case6(tape);
                    break;
                default:
                    std::cout << "Invalid choice, enter again please." << std::endl;
            }
        } else {
            flag=false;
        }
    }
}