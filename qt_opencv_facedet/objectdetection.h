#ifndef OBJECTDETECTION_H
#define OBJECTDETECTION_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


class ObjectDetection
{
public:
    ObjectDetection();
    /** Function Headers */
    void detectAndDisplay( Mat frame );

    /** Global variables */
    //-- Note, either copy these two files from opencv/data/haarscascades to your current folder, or change these locations
    String face_cascade_name = "../../data/haarcascades/haarcascade_frontalface_alt.xml";
    String eyes_cascade_name = "../../data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    string window_name = "Capture - Face detection";
//    RNG rng(12345);

};

#endif // OBJECTDETECTION_H
