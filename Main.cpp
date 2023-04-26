#include<iostream>
#include"TuringMachineState.h"
#include"DenseTuringMachine.h"
#include "TuringTape.h"
#include "MenuSystem.h"
#include "SparseTuringMachine.h"
#include<vector>
using namespace std;
void checkFirst() {
    TuringMachineState t1(1,2,3,4,"->");
    TuringMachineState t2(5,6,7,8,"<-");
    cout<<t1.getCurrentState()<<" "<<t1.getCurrentContent()<<" "<<t1.getNextState()<<" "<<t1.getNextContent()<<" "<<t1.getMoveDirection()<<endl;
    cout<<t2.getCurrentState()<<" "<<t2.getCurrentContent()<<" "<<t2.getNextState()<<" "<<t2.getNextContent()<<" "<<t2.getMoveDirection()<<endl;
}
void checkSecond() {
    TuringMachineState t1(1,2,3,4,"->");
    cout <<t1<<endl;
    TuringMachineState t2(5,6,7,8,"<-");
    cout <<t2<<endl;
    cin >> t1;
    cin >> t2;
    cout<<t1.getCurrentState()<<" "<<t1.getCurrentContent()<<" "<<t1.getNextState()<<" "<<t1.getNextContent()<<" "<<t1.getMoveDirection()<<endl;
    cout<<t2.getCurrentState()<<" "<<t2.getCurrentContent()<<" "<<t2.getNextState()<<" "<<t2.getNextContent()<<" "<<t2.getMoveDirection()<<endl;
}
void testAll(vector<TuringMachineState> vec) {
    for (auto s: vec) {
        for (auto t:vec) {
            cout << (s<t)<<(s>t)<<(s==t)<<endl;
        }
    }
}
void checkThird() {
    vector<TuringMachineState> vec;
    vec.push_back(TuringMachineState(1,2,3,4,"->"));
    vec.push_back(TuringMachineState(2,1,7,8,"<-"));
    vec.push_back(TuringMachineState(2,1,3,4,"->"));
    vec.push_back(TuringMachineState(1,1,10,10,"<-"));
    testAll(vec);
}

bool compareState(TuringMachineState s1, TuringMachineState s2) {
    return (s1.getCurrentState()<s2.getCurrentState())||(s1.getCurrentState()==s2.getCurrentState())&&s1.getCurrentContent()<s2.getCurrentContent();
}

void checkFourth(){
    DenseTuringMachine t(10,10);
    TuringMachineState s1(5,6,7,8,"<-");
    t.add(s1);
    TuringMachineState s2(1,2,3,4,"->");
    t.add(s2);
    cout << *t.find(1,2);
    cout << *t.find(5,6)<<endl;
    cout << (t.find(1,3)==NULL)<<endl;
    vector<TuringMachineState> vec=*t.getAll();
    *t.getAll();
    sort(vec.begin(),vec.end(),compareState);
    for (auto s: *t.getAll()) cout << s;
}

void checkFifth(){
    TuringTape t(10);
    cout<<t.moveLeft();
    for (int i=0;i<10;i++) {
        cout<<t.moveRight();
        t.setContent(i);
    }
    for (int i=0;i<10;i++) {
        cout<<t.moveLeft();
        cout<<t.getContent();
    }
}

void checkSixth(){
    MenuSystem m;
    m.menu();
}

void checkSeventh(){
    SparseTuringMachine s;
    TuringMachineState s1(1,2,3,4,"->");
    s.add(s1);
    TuringMachineState s2(5,6,7,8,"<-");
    s.add(s2);
    cout << *s.find(1,2);
    cout << *s.find(5,6)<<endl;
    cout << (s.find(1,3)==NULL)<<endl;
    vector<TuringMachineState> vec=*s.getAll();
    sort(vec.begin(),vec.end(),compareState);
    for (auto t: *s.getAll()) cout << t;
    MenuSystem m;
    m.menu();
}

void checkEighth(){
    TuringTape t(-1);
    cout<<t.moveLeft();
    for (int i=0;i<10;i++) {
        cout<<t.moveRight();
        t.setContent(i);
    }
    for (int i=0;i<10;i++) {
        cout<<t.moveLeft();
        cout<<t.getContent();
    }
    DenseTuringMachine d(-1,-1);
    TuringMachineState s1(1,2,3,4,"->");
    d.add(s1);
    TuringMachineState s2(5,6,7,8,"<-");
    d.add(s2);
    cout << *d.find(1,2);
    cout << *d.find(5,6)<<endl;
    cout << (d.find(1,3)==NULL)<<endl;
    vector<TuringMachineState> vec=*d.getAll();
    sort(vec.begin(),vec.end(),compareState);
    for (auto s: vec) cout << s;
    MenuSystem m;
    m.menu();
}

int main() {
//checkFirst();
//checkSecond();
//checkThird();
//checkFourth();
//checkFifth();
//checkSixth();
//checkSeventh();
checkEighth();
}

