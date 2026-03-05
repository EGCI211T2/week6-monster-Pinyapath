#include <iostream>
#include <cstdlib>
#include "monster.h"
#include "thanos.h"
using namespace std;

int main() {
    srand(time(0));

    int n;
    cout << "How many monsters? ";
    cin >> n;

    string names[] = {"James","Michael","Sarah","Amy","Sam","John","Lily","Alex","Bob","Carol"};
    if(n>10) n=10;

    monster **m = new monster*[n];
    for(int i=0;i<n;i++){
        m[i] = new monster(names[i]); 
    }

    Thanos T;
    for(int i=0;i<6;i++) ++T;
    T.snap_finger(*m, n);

    cout << "\nSurviving monsters:\n";
    for(int i=0;i<n;i++){
        m[i]->display();
    }

    for(int i=0;i<n;i++) delete m[i];
    delete [] m;

    return 0;
}