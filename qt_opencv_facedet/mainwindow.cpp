#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_and_detect(QString filename)
{
    cv::Mat image=cv::imread(filename.toStdString());
    if(image.empty()){
        return;
    }
    cv::cvtColor(image,image,cv::COLOR_BGR2RGB);
    QPixmap qpixmap=QPixmap::fromImage(QImage((unsigned char*) image.data, image.cols, image.rows, QImage::Format_RGB888));
    ui->label->setPixmap(qpixmap);

    ObjectDetection det=ObjectDetection();
    det.detectAndDisplay(image);
}
//browse image
void MainWindow::on_pushButton_clicked()
{
    QString image_file_name = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
    if(image_file_name.isEmpty()){
        QMessageBox::warning(this,"empty file name","cannot load and detect a empty filename");
    }
    else{
        ui->lineEdit->setText(image_file_name);
    }
}
//load and detect image
void MainWindow::on_pushButton_2_clicked()
{
    QString image_file_name=ui->lineEdit->text();
    load_and_detect(image_file_name);
}
