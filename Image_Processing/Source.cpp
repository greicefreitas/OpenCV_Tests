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

    show_histogram(image);


    //bilateralFilter(image, bilateral_f_image, -1, 10, 1, BORDER_DEFAULT);
    //imshow("Filtered Image: Bilateral Filter", bilateral_f_image);

    //waitKey();

    return 0;
}