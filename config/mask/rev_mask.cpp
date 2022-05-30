#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat image;
    image = imread("/home/kingmoon/Documents/MasterA/catkin_ws/src/VINS-Mono/config/mask/mask.jpg");
    /*Mat out_image = image.clone();
    for (size_t i = image.rows; i < image.rows; i++)
    {
        for (size_t j = 0; j < image.cols; j++)
        {
            cout << image.at<uchar>(i, j) << endl;
            out_image.at<uchar>(i, j) = 255-image.at<uchar>(i, j);
        }
        
    }*/
    bitwise_not(image, image);
    
    imwrite("fisheye_mask1.jpg", image);
    imshow("reverse_mask", image);
    waitKey(0);
    return 0;
}
