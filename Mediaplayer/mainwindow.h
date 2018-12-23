#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

    void on_actionOpen_triggered();

    void on_actionReplay_triggered();

    void on_actionfullscreen_triggered();

    void on_actionList_triggered();

    void on_actionMute_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *pl;
    QVideoWidget *vv;
    QProgressBar *pb;
    QSlider *slide;
};

#endif // MAINWINDOW_H
