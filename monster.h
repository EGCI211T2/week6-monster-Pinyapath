#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_HP 100
#define MAX_POTION 10

class monster {
private:
    string name;
    int hp;
    int potion;

public:
    monster(string="Name", int=-1, int=-1);
    void Attack(monster &x);
    void heal();
    void reset_hp();
    void display();
    int get_hp(){ return hp; }
    ~monster();

    void operator+=(int);
    void operator+=(monster &);
    void operator--();
    bool operator>(monster &);
};
monster::monster(string n,int h,int p){
    name = n;
    hp = (h<0)? rand()%MAX_HP +1 : h;
    potion = (p<0)? rand()%MAX_POTION +1 : p;
    cout<<"Monster "<<name<<" is here with HP "<<hp<<" and potion "<<potion<<endl;
}

void monster::Attack(monster &x){
    cout<<name<<" attacks "<<x.name<<endl;
    if(hp > x.hp){
        x.hp -=10;
        if(x.hp<0) x.hp=0;
        hp--;
    } else {
        x.hp -=5;
        if(hp>1) hp--; else hp=0;
    }
}

void monster::heal(){
    if(potion>0){
        potion--;
        hp++;
    }
}

void monster::reset_hp(){
    hp=0;
}

void monster::display(){
    if(hp>0){
        cout<<"Name:"<<name<<" HP:"<<hp<<" Potion:"<<potion<<endl;
    }
}

void monster::operator+=(int a){
    hp += a;
}

void monster::operator+=(monster &x){
    hp += x.hp;
    x.hp=0;
}

void monster::operator--(){
    --hp;
}

bool monster::operator>(monster &x){
    return hp>x.hp;
}

monster::~monster(){
    cout<<name<<" is gone."<<endl;
}

#endif