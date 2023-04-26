#include "TuringTape.h"
#include<iostream>
#include<limits>
TuringTape::TuringTape(int n) {
    if(n!=-1){
        tape.resize(n);
        std::fill(tape.begin(), tape.end(), 0);
    } else {
        tape.resize(10);
        isMinusOne = true;
    }
}

bool TuringTape::moveRight() {
    if(isMinusOne){
        //判断指针是否越界，越界再扩容
        if(pointer>tape.size()){
            size+=10;
            tape.resize(size);
        }
        incrementPosition();
        if(pointer<0){
            return false;
        }
        return true;
    } else {
        incrementPosition();
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
        decreasePosition();
        if(pointer<0){
            return false;
        }
        return true;
    } else {
        decreasePosition();
        if(pointer>tape.size() || pointer<0){
            return false;
        }
        return true;
    }
}

int TuringTape::getContent() const{
    if(pointer<=tape.size() && pointer>=0){
        return tape[pointer];
    } else {
        return 0;
    }
}

int TuringTape::getPosition() const{
    return pointer;
}

void TuringTape::setContent(int c) {
    tape[pointer] = c;
}

void TuringTape::incrementPosition() {
    pointer+=1;
}

void TuringTape::decreasePosition() {
    pointer-=1;
}

void TuringTape::setPosition(int newPointer) {
    pointer=newPointer;
}

std::ostream& operator<<(std::ostream& out,const TuringTape& s){
    out << s.getContent() << s.getPosition();
    return out;
}
