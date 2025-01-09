#include <gst/gst.h>
#include "media_info.h"

int videoPlayer() {
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;  

    int argc = 0;
    char **argv = NULL;

    // Initialize GStreamer
    gst_init(&argc, &argv); // Correct function call

    // Provide a valid file URI
    /* Choosing the Right URI
    Use V4L2 for USB webcams.
    Use RTSP or HTTP for IP cameras.
    Use CSI for Raspberry Pi cameras.
    Use Test Source for simulation.
    */
    pipeline = gst_parse_launch("playbin uri=file:///home/amantya/Pictures/bbb%20sunflower%202160p%2060fps%20normal(720P_HD).mp4", NULL);
    if (!pipeline) {
        g_printerr("Failed to create pipeline.\n");
        return -1;
    }

    // Set the pipeline to PLAYING state
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    // Wait until an error or end-of-stream (EOS)
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    // Free resources
    if (msg != NULL) {
        gst_message_unref(msg);
    }
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
