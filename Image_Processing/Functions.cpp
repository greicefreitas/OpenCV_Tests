#include "Header.h"


using namespace std;
using namespace cv;
using cv::merge;



void show_histogram(Mat img, string name) {
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
    
    //Getting maximum values:
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;

    cout << name << endl;
    cout << endl;


    for (int i = 0; i < 3; i++) {
        calcHist(&bgrchannel[i], 1, 0, Mat(), histchannel[i], 1, &histSize, &histRange, true, false);
        histimagechannels.push_back(plot_hist(histchannel[i]));

        minMaxLoc(bgrchannel[i], &minVal, &maxVal, &minLoc, &maxLoc);
        cout << "Channel: " << i << endl;
        cout << "\t \t min val: " << minVal << endl;
        cout << "\t \t max val: " << maxVal << endl;

    }

    cout << "____________________" << endl;


    //To merge, the images has to be in grayscale (CV_8UC1)!
    merge(histimagechannels, hist_combination);

    imshow(name, hist_combination);
    

    

}



Mat plot_hist(Mat & histogram) {
    int histSize = 256;
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0));



    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());

 

    for (int i = 1; i < histSize; i++)
    {

        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(histogram.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(histogram.at<float>(i))),
            Scalar(255,0,0), 2, 8, 0);
           
        
    }

    return histImage;
}



void equilize_gbr_image(Mat img) {
    

    Mat img_yuv;
    vector<Mat> img_yuv_sep;
    vector<Mat> img_bgr_sep;
    Mat eq_img;
    Mat y;
    //Conversion to YUV color map: 
    cvtColor(img, img_yuv, COLOR_BGR2YUV);
    split(img_yuv, img_yuv_sep);
    //Equilization on Y (brightness of the image):
    equalizeHist(img_yuv_sep[0], y);

    img_yuv_sep[0] = y;
    //Merging back the image
    merge(img_yuv_sep, img_yuv);

    cvtColor(img_yuv, eq_img, COLOR_YUV2BGR);

 
    imshow("Image After Equalization", eq_img);
  

    show_histogram(eq_img, "Histogram: Eq Image");

    split(eq_img, img_bgr_sep);

    imshow("B after", img_bgr_sep[0]);
    imshow("G after", img_bgr_sep[1]);
    imshow("R after", img_bgr_sep[2]);



    waitKey();



}