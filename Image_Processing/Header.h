#pragma once
#include <iostream>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

#include <opencv2/highgui/highgui.hpp> 


using namespace cv;
using namespace std;
using std::string;

void show_histogram(Mat img, string name);

Mat plot_hist(Mat& histogram);


void equilize_gbr_image(Mat img);