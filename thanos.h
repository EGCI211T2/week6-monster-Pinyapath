#ifndef THANOS_H
#define THANOS_H

#include "monster.h"
#include <iostream>
using namespace std;

class Thanos {
private:
    int stones;
    int hp;

public:
    Thanos(int=0,int=1000);
    ~Thanos();
    void snap_finger(monster m[], int n);
    void operator++();
};

Thanos::Thanos(int s,int h){
    stones = s;
    hp = h;
    cout<<"I am Thanos"<<endl;
}

Thanos::~Thanos(){
    cout<<"Thanos is gone"<<endl;
}

void Thanos::operator++(){
    stones++;
}

void Thanos::snap_finger(monster m[], int n){
    if(stones<6){
        cout<<"Sorry you don't have enough power"<<endl;
        return;
    }

    int half = n/2;
    cout<<"Snap finger! Half monsters' HP set to 0"<<endl;
    for(int i=0;i<half;i++){
        m[i].reset_hp();
    }
}

#endif