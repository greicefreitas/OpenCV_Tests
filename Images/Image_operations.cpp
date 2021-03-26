#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>


using namespace std;
using namespace cv;
int main(){
	cout << "Generating basic image: " << endl; 
	Mat test;
	Mat M(5, 3, CV_8UC3, Scalar(1, 2, 3)); //creates a 3 channels (9UC3) matrix 5 rows, 2 columns.  
	// Scalar(0, 0, 255) initializes the matrix using values 0, 0 and 255 in the last channel. (in type)

	//Taking only the first channel:
	extractChannel(M, test, 0);


	cout << "M = " << endl << " " << M << endl << endl;

	cout << "Only first dimention:" << endl;

	cout << "M(1) = " << endl << " " << test << endl << endl;


	return 0;
}