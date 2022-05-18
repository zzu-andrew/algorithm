//
// Created by andrew on 2022/5/18.
//

#include <iostream>
#include "lru_cache.h"


using namespace std;


int main(int argc, char* argv[]) {

    LruCache<int, int> lruCache(100);

    lruCache.Put(1, 1234);
    lruCache.Put(2, 1234);
    lruCache.Put(3, 1234);
    lruCache.Put(5, 1234);
    lruCache.Put(4, 1234);
    lruCache.Put(5, 1234);
    lruCache.Put(7, 1234);
    lruCache.Put(1, 1234);


    auto lit = lruCache.GetLruList();

    std::cout << lruCache.Exists(1) << std::endl;


    return 0;
}

