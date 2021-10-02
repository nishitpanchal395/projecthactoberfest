// project1 c++ program for face detection.

// headers

#include <objdetect.hpp>
#include <highgui.hpp>
#include <ImgUtil.h>
#include <iostream>

using namespace std;
using namespace cv;

// function for face detection.
void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale);
