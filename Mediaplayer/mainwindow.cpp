#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameslist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pl = new QMediaPlayer(this);
    vv = new QVideoWidget(this);
    pl->setVideoOutput(vv);
    this->setCentralWidget(vv);

    pb = new QProgressBar(this);
    slide = new QSlider(Qt::Horizontal, this);

    ui->statusBar->addPermanentWidget(slide);
    ui->statusBar->addPermanentWidget(pb);

    connect(pl,&QMediaPlayer::durationChanged,slide,&QSlider::setMaximum);
    connect(pl,&QMediaPlayer::positionChanged,slide,&QSlider::setValue);
    connect(slide,&QSlider::sliderMoved,pl,&QMediaPlayer::setPosition);

    connect(pl,&QMediaPlayer::durationChanged,pb,&QProgressBar::setMaximum);
    connect(pl,&QMediaPlayer::positionChanged,pb,&QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open","Games","Media File (*.mp4; *.mp3; *.jpg; *.jpeg)");
    on_actionStop_triggered();

    pl->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    pl->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    pl->pause();
    ui->statusBar->showMessage("Paused");
}

void MainWindow::on_actionStop_triggered()
{
    pl->stop();
    ui->statusBar->showMessage("Stopped");
}

void MainWindow::on_actionReplay_triggered()
{
    pl->stop();
    pl->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionfullscreen_triggered()
{
    if(isFullScreen())
    {
        setWindowState(Qt::WindowNoState);
        ui->actionfullscreen->setIcon(QPixmap("icons/2817-200.png"));
    }
    else
    {
        setWindowState(Qt::WindowFullScreen);
        ui->actionfullscreen->setIcon(QPixmap("icons/img_1900.png"));
    }
}

void MainWindow::on_actionList_triggered()
{
    GamesList list;
    list.setModal(true);
    list.exec();
}

void MainWindow::on_actionMute_triggered()
{
    if(pl->isMuted())
    {
        pl->setMuted(false);
        ui->statusBar->showMessage("Unmuted");
        ui->actionMute->setIcon(QPixmap("icons/muted.png"));

    }
    else
    {
        pl->setMuted(true);
        ui->statusBar->showMessage("Muted");
        ui->actionMute->setIcon(QPixmap("icons/512px-Volume_up_font_awesome.svg.png"));
    }
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}
