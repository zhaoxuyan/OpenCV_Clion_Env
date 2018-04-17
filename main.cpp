#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void IplImageDoThis(IplImage *image);

void MatDoThis(Mat mat);

int main(int argc, char **argv) {

    IplImage *image = cvLoadImage("taaarannn.png");
    Mat mat = imread("taaarannn.png");
    cout << "1. IplImage" << endl;
    cout << "2. Mat" << endl;
    int choice;
    cout << "Please input your choice:" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            IplImageDoThis(image);
            break;
        case 2:
            MatDoThis(mat);
            break;
        default:
            break;
    }

    return 0;
}

void MatDoThis(Mat mat) {
    CvPoint center;
    double scale = -3;
    if (mat.empty()) {
        exit(0);
    }

    center = cvPoint(mat.cols / 2, mat.rows / 2);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            double dx = (double) (j - center.x) / center.x;
            double dy = (double) (j - center.y) / center.y;
            double weight = exp((dx * dx + dy * dy) * scale);
            uchar *ptr_mat = &mat.at<uchar>(cvPoint(j * 3, i));
            ptr_mat[0] = static_cast<uchar>(cvRound(ptr_mat[0] * weight));
            ptr_mat[1] = static_cast<uchar>(cvRound(ptr_mat[1] * weight));
            ptr_mat[2] = static_cast<uchar>(cvRound(ptr_mat[2] * weight));
        }
    }
    imwrite("taaarannn_magic_Mat.png", mat);
    namedWindow("taaarannn_magic_Mat", 1);
    imshow("taaarannn_magic_Mat", mat);
    waitKey(0);
}

void IplImageDoThis(IplImage *image) {
    CvPoint center;
    double scale = -3;
    if (!image)
        exit(0);
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
    cvSaveImage("taaarannn_magic_IplImage.png", image);
    cvNamedWindow("taaarannn_magic_IplImage", 1);
    cvShowImage("taaarannn_magic_IplImage", image);
    cvWaitKey();
}