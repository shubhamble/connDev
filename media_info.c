// media_info.c
#include <stdio.h>
#include <libavformat/avformat.h>
#include "media_info.h"

int print_media_info(const char *filename) {
    AVFormatContext *fmt_ctx = NULL;

    // Open the input file
    if (avformat_open_input(&fmt_ctx, filename, NULL, NULL) < 0) {
        fprintf(stderr, "Could not open source file %s\n", filename);
        return -1;
    }

    // Retrieve stream information
    if (avformat_find_stream_info(fmt_ctx, NULL) < 0) {
        fprintf(stderr, "Could not find stream information\n");
        avformat_close_input(&fmt_ctx);
        return -1;
    }

    // Print detailed information about the input file
    av_dump_format(fmt_ctx, 0, filename, 0);

    // Close the input file and free resources
    avformat_close_input(&fmt_ctx);
    return 0;
}
