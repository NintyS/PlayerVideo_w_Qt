#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lay = new QVBoxLayout(this);
    player = new QMediaPlayer(this);
    video = new QVideoWidget(ui->videoWidget);

    lay->addWidget(video);

    player->setVideoOutput(video);

    player->setMedia(QUrl::fromLocalFile("/Users/nintyswinty/Downloads/hit.mp4"));

    //Jakieś connecty tu wjebać

    player->play();

}

void MainWindow::resizeEvent(QResizeEvent* event) {

    x = this->size().width();

    y = this->size().height();

    ui->videoWidget->setGeometry(0, 0, x, y);
    video->setGeometry(0,0, x, y);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    player->play();
}

void MainWindow::on_pushButton_clicked()
{
    player->pause();
}

void MainWindow::on_pushButton_8_clicked()
{
    //Now don't work
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //player->set
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    player->setVolume(value);
}
