#include "TuringTape.h"
#include<iostream>

TuringTape::TuringTape(int n) {
    if(n!=-1){
        tape.resize(n);
        iter = tape.begin();
        std::fill(tape.begin(), tape.end(), 0);
    } else {
        tape.resize(10);
        iter = tape.begin();
        isMinusOne = true;
    }
}

bool TuringTape::moveRight() {
    if(isMinusOne){
        //Check if pointer is out of bound, if yes, expand it.
        if(pointer>tape.size()){
            size+=10;
            tape.resize(size);
        }
        pointer++;
        if(iter!=tape.end()){
            ++iter;
        }
        if(pointer<0){
            return false;
        }
        return true;
    } else {
        pointer++;
        if(iter!=tape.end()){
            ++iter;
        }
        if(pointer>tape.size() || pointer<0){
            return false;
        }
        return true;
    }
}

bool TuringTape::moveLeft() {
    if(isMinusOne){
        if(pointer>tape.size()){
            size+=10;
            tape.resize(size);
        }
        pointer--;
        if(iter!=tape.begin()){
            --iter;
        }
        if(pointer<0){
            return false;
        }
        return true;
    } else {
        pointer--;
        if(iter!=tape.begin()){
            --iter;
        }
        if(pointer>tape.size() || pointer<0){
            return false;
        }
        return true;
    }
}

int TuringTape::getContent() const{
    if(pointer<=tape.size() && pointer>=0){
          return *iter;
    } else {
        return 0;
    }
}

int TuringTape::getPosition() const{
    return pointer;
}

void TuringTape::setContent(int c) {
        *iter = c;
}

void TuringTape::setPosition(int newPointer) {
    iter = tape.begin();
    iter+=newPointer;
}

std::ostream& operator<<(std::ostream& out,const TuringTape& s){
    out << s.getContent() << s.getPosition();
    return out;
}
