#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
extern "C" {
    #include "cModule.h"
    #include "media_info.h"
}

int sum(std::vector<int> v);
int sum(std::queue<int> q);