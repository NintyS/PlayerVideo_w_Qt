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

    connect(player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        videoDuration = dur;

        ui->horizontalSlider->setMaximum(dur);

        int seconds = (dur/1000) % 60;
        int minutes = (dur/60000) % 60;
        int hours = (dur/3600000) % 24;

        ui->label->setText(QString::number(hours) + ":" + QString::number(minutes) + ":" + QString::number(seconds));

    });

    connect(player, &QMediaPlayer::positionChanged, this, [&](qint64 dur) {
        nowDur = dur;

        ui->horizontalSlider->setValue( dur );

        int seconds = (dur/1000) % 60;
        int minutes = (dur/60000) % 60;
        int hours = (dur/3600000) % 24;

        ui->label_2->setText(QString::number(hours) + ":" + QString::number(minutes) + ":" + QString::number(seconds));

    });

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
    if(!fullScreen) {
        ui->centralwidget->setParent( NULL );
        ui->centralwidget->showFullScreen();
        fullScreen = true;
    } else {
        ui->centralwidget->showNormal();
        fullScreen = false;
    }
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::on_pushButton_7_clicked()
{
    QFileDialog dialog;
    dialog.setDirectory("C:/");//or another default folder

    QString path1 = dialog.getOpenFileName(this,"Choose file");
    player->setMedia(QUrl::fromLocalFile(path1));

    player->play();

}

void MainWindow::on_pushButton_3_clicked()
{
    player->setPosition( nowDur - 15448);
}

void MainWindow::on_pushButton_6_clicked()
{
    player->setPosition( nowDur + 15448);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}
