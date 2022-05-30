#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat image = Mat::zeros(1080, 1280, CV_8UC1 );
    circle(image, cv::Point2f(640, 540), 690, Scalar(255), -1, 8, 0);
    for (size_t i = image.rows / 2 - 50; i < image.rows; i++)
    {
        for (size_t j = 0; j < image.cols; j++)
        {
            image.at<uchar>(i, j) = 0;
        }
        
    }
    
    imwrite("fisheye_mask.jpg", image);
    imshow("circle", image);
    waitKey(0);
    return 0;
}
