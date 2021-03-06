#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

#include <iostream>
#include <stdio.h>
using namespace std;



int main()
{
    Mat frame;
    Mat out_R;
    Mat out_G;
    Mat out_B;


    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API



    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
       
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);


        //BGR order - Bitmap
        extractChannel(frame, out_B, 0);
        imshow("B_channel", out_B);

        extractChannel(frame, out_G, 1);
        imshow("G_channel", out_G);

        extractChannel(frame, out_R, 2);
        imshow("R_channel", out_R);
       
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}