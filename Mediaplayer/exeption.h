#ifndef EXEPTION_H
#define EXEPTION_H
#pragma once
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include <QTextStream>
using namespace std;

class Exeption
{
public:
    QString name;
    Exeption(QString Ename)
    {
        name = Ename;
    }

    virtual ~Exeption()
    {
    }

    void error_type(QString file)
    {
        QMessageBox err;
        err.setText(file);
        err.exec();
    }
};
#endif // EXEPTION_H
