#ifndef GAMESLIST_H
#define GAMESLIST_H

#include <QDialog>

namespace Ui {
class GamesList;
}

class GamesList : public QDialog
{
    Q_OBJECT

public:
    explicit GamesList(QWidget *parent = 0);
    ~GamesList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GamesList *ui;
};

#endif // GAMESLIST_H
