#include "gameslist.h"
#include "ui_gameslist.h"
#include "input.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <vector>
#include <list>

using namespace std;

GamesList::GamesList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamesList)
{
    ui->setupUi(this);
    setFixedSize(343,291);
}

GamesList::~GamesList()
{
    delete ui;
}

void GamesList::on_pushButton_clicked()
{
   QFile F("GamesList.txt");
   vector <QString> lists;
   QString str = "", sting = "";
   try
   {
       int j = 0;
       if(!F.open(QIODevice::ReadOnly))
           throw Input("Error №001: Cant open the file");
       while(!F.atEnd())
       {
           str = F.readLine();
           lists.push_back(str);
           j++;
       }
       for(int z = 0; z < j; z++)
       {
          sting = sting + lists.at(z);
       }
       ui->textBrowser->setPlainText(sting);

   }

   catch(Input &obj)
   {
       obj.error_type(obj.name);
   }

   catch(...)
   {
       QMessageBox err;
       err.setText("Unknown error");
       err.exec();
   }
}

void GamesList::on_pushButton_3_clicked()
{
    QFile Fl("Authority.txt");
    list <QString> lists;
    list <QString>::iterator lists_it;
    QString str = "", sting = "";
    try
    {
        int j = 0;
        if(!Fl.open(QIODevice::ReadOnly))
            throw Input("Error №001: Cant open the file");;
        while(!Fl.atEnd())
        {
            str = Fl.readLine();
            lists.push_back(str);
            j++;
        }
        for(int z = 0; z < j; z++)
        {
           lists_it = lists.begin();
           sting = sting + *lists_it;
           lists.pop_front();
        }
        ui->textBrowser->setPlainText(sting);

    }

    catch(Input &obj)
    {
        obj.error_type(obj.name);
    }

    catch(...)
    {
        QMessageBox err;
        err.setText("Unknown error");
        err.exec();
    }
}

void GamesList::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
}
