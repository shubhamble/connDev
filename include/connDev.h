#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
extern "C" {
    #include "cModule.h"
    #include "media_info.h"
}

// #define ANIMAL
// #define ENABLE_FFMPEG_VIDEO
#define ENABLE_GST_VIDEO

int sum(std::vector<int> v);
int sum(std::queue<int> q);
void mapProc(void);



