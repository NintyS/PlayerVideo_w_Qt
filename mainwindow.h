#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_sliderPressed();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;

    QMediaPlayer* player;
    QVideoWidget* video;
    QVBoxLayout* lay;

    int x;
    int y;

    int nowDur = 0;

    int videoDuration = 0;

};
#endif // MAINWINDOW_H
