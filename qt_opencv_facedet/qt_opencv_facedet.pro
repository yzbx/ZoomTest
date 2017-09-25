#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T12:46:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_opencv_facedet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectdetection.cpp

HEADERS  += mainwindow.h \
    objectdetection.h

FORMS    += mainwindow.ui

INCLUDEPATH += "D:/Programing Tools/OpenCV/opencv/build/include"
LIBS += -L"D:/Programing Tools/OpenCV/opencv/build/x64/vc12/lib"
LIBS += -lopencv_calib3d249 \
-lopencv_contrib249 \
-lopencv_core249 \
-lopencv_features2d249 \
-lopencv_flann249 \
-lopencv_gpu249 \
-lopencv_highgui249 \
-lopencv_imgproc249 \
-lopencv_legacy249 \
-lopencv_ml249 \
-lopencv_nonfree249 \
-lopencv_objdetect249 \
-lopencv_ocl249 \
-lopencv_photo249 \
-lopencv_stitching249 \
-lopencv_superres249 \
-lopencv_video249 \
-lopencv_videostab249

