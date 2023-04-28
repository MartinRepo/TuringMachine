#include<iostream>
#include<vector>
#include "TuringMachineState.h"
#ifndef TURINGTAPE_H_
#define TURINGTAPE_H_
class TuringTape {
public:
    TuringTape(int n);
    bool moveRight();
    bool moveLeft();
    int getContent() const;
    void setContent(int c);
    int getPosition() const;
    void incrementPosition();
    void decreasePosition();
    void setPosition(int newPointer);
    friend std::ostream& operator<<(std::ostream& out,const TuringTape& s);
private:
    std::vector<int> tape;
    std::vector<int>::iterator iter;
    int pointer = 0;
    bool isMinusOne = false;
    int size = 10;
};
#endif /* TURINGTAPE_H_ */
