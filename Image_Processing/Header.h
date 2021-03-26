#pragma once
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

#include <opencv2/highgui/highgui.hpp> 


using namespace cv;

void show_histogram(Mat img);

Mat plot_hist(Mat& histogram);