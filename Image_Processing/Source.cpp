#include "Header.h"


using namespace std;
using namespace cv;

int main()
{
    std::string in;
    string folder("../standard_test_images/");
    string image_name("lena_color_256.tif");
    Mat bilateral_f_image;

    Mat image = imread((folder + image_name), IMREAD_COLOR);
    if (image.empty())
    {
        return -1;
    }

    imshow("Original Image", image);
    
    // Histogram:
    show_histogram(image, "Histogram: Original Image");

    // Image Equalization:
    equilize_gbr_image(image);
    waitKey();


    return 0;
}