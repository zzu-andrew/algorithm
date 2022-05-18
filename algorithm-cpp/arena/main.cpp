//
// Created by wangyz38535 on 2022/5/5.
//
#include <iostream>
#include "arena.h"
#include <map>
#include <string>
#include <memory>


using namespace std;



class B {
public:
    B() {
        cout << "Construct B " << endl;
    }
};

B b;


int main(int argc, char* argv[]) {

    cout << "main Run" << endl;


    return 0;
}
