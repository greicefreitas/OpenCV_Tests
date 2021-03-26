#include "Header.h"


using namespace std;
using namespace cv;
using cv::merge;



void show_histogram(Mat img) {
	Mat bgrchannel[3];
	Mat histchannel[3];
    vector<Mat> histimagechannels;
	int histSize = 256;
	float range[] = { 0, 256 }; //the upper boundary is exclusive
	const float* histRange = { range };
    Mat hist_combination;

	//Separating channels:
	split(img, bgrchannel);


	//calcHist(const Mat * images, 		int 	nimages, 		const int* channels, 		InputArray 	mask, 
	//		OutputArray 	hist, 		int 	dims, 		const int* histSize, 		const float** ranges, 
	//		bool 	uniform = true, 		bool 	accumulate = false	)

    for (int i = 0; i < 3; i++) {
        calcHist(&bgrchannel[i], 1, 0, Mat(), histchannel[i], 1, &histSize, &histRange, true, false);
        histimagechannels.push_back(plot_hist(histchannel[i]));
    }

    //To merge, the images has to be in grayscale (CV_8UC1)!
    merge(histimagechannels, hist_combination);

    imshow("Color Histogram", hist_combination);
    
    waitKey();
    

}



Mat plot_hist(Mat & histogram) {
    int histSize = 256;
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0));

    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    //Drawing lines!

    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(histogram.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(histogram.at<float>(i))),
            Scalar(255, 0), 2, 8, 0);
    }

    return histImage;
}