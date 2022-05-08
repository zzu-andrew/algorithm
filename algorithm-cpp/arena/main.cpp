//
// Created by wangyz38535 on 2022/5/5.
//
#include <iostream>
#include "arena.h"
#include <map>
#include <string>
#include <memory>


using namespace std;



int main(int argc, char* argv[]) {


    std::string  name;


    std::shared_ptr<std::string> strPtr(::new std::string);
    int32_t dataSize = 0;
    std::to_string(dataSize);


     int * const data = &dataSize;


    char buf[120];
    name = "data";
    name.copy(buf, name.size());

    printf("buf= %s\n", buf);

    std::cout << name << std::endl;
    return 0;
}
