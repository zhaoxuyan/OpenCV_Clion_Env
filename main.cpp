#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc, char **argv) {



    CvPoint center;
    double scale = -3;
    IplImage* image = cvLoadImage("taaarannn.png");
    if (!image)
        return -1;
    center = cvPoint(image->width / 2, image->height / 2);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double dx = (double) (j - center.x) / center.x;
            double dy = (double) (j - center.y) / center.y;
            double weight = exp((dx * dx + dy * dy) * scale);
            uchar *ptr = &CV_IMAGE_ELEM(image, uchar, i, j * 3);
            ptr[0] = static_cast<uchar>(cvRound(ptr[0] * weight));
            ptr[1] = static_cast<uchar>(cvRound(ptr[1] * weight));
            ptr[2] = static_cast<uchar>(cvRound(ptr[2] * weight));
        }
    }
    cvSaveImage("taaarannn_magic.png", image);
    cvNamedWindow("taaarannn",1);
    cvShowImage("taaarannn",image);
    cvWaitKey();
    return 0;
}