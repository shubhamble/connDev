#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
extern "C" {
    #include "cModule.h"
    #include "media_info.h"
}

// #define ANIMAL
// #define FFMPEG_VIDEO
#define GST_VIDEO

int sum(std::vector<int> v);
int sum(std::queue<int> q);
