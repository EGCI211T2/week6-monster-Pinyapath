#include <iostream>
#include <cstdlib>
#include "monster.h"
using namespace std;

int main(int argc, char* argv[]) {

    if(argc < 4){
        cout<<"Usage: "<<endl;
        return 1;
    }

    monster You(argv[1], atoi(argv[2]), atoi(argv[3]));

    for(int i = 4; i < argc; i += 3){
        monster *p = new monster(argv[i], atoi(argv[i+1]), atoi(argv[i+2]));
        
        if(*p > You){
            *p += 5;
            --You;
        } else {
            You += 5;
            --(*p);
        }

        delete p;
        You.heal();
    }

    cout<<"Your monster final status:"<<endl;
    You.display();

    return 0;
}

  
  

